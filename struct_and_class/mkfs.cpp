#include "mkfs.h"
#include "method_and_function.h"

using std::string, std::cout, std::endl;

Mkfs::Mkfs(string _id, string _tipo, string _fs){
  id = _id;
  tipo = _tipo;
  fs = _fs;
}

void Mkfs::ejecutarComando(){
  //validamos el parametro obligatorio
  if(id == ""){
    cout<<"Error, parametro obligatorio vacio "<<endl;
    return;
  }
  // validamos el tipo
  if(tipo == ""){
    tipo = "full";
  }
  std::transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);
  if(tipo != "full"){
    cout<<"Error, el valor del parametro no es valido"<<endl;
    return;
  }
  //validamos el sistema de archivos a formatear
  if(fs == ""){
    fs = "2fs";
  }
  itemMount item;
  //buscamos el id de la particion montada
  for (size_t i = 0; i < particionMontada.size(); i++){
    if(id.compare(particionMontada[i].id)==0){
      item = particionMontada[i];
    }
  }
  if(item.id == ""){
    cout<<"Error, no existe una particion montada con ese id"<<endl;
    return;
  }
  

  std::transform(fs.begin(), fs.end(), fs.begin(), ::tolower);
  if (fs == "2fs"){
    //se formatea a ext2
    formateoExt2(item);
  }else if (fs == "3fs"){
    // se formatea a ext3
    formateoExt3(item);
  }else{
    cout<<"Error, el valor para el parametro fs no es valido"<<endl;
    return;
  }
}

void Mkfs::formateoExt2(itemMount _item){
  SUPERBLOQUE sb;
  //no se a que se refiere el system type dek superbloque pero creo que se
  //refiere a si es un sistema ext2 o uno ext3
  sb.s_filesystem_type = 2;
  //calculamos el numero de estructuras
  int n = (_item.part.part_s - sizeof(SUPERBLOQUE))/(1+sizeof(B_INODO)+3+(3*sizeof(B_CARPETA)));
  n = floor(n);
  //cout<<n<<endl;
  //calculamos el numero de bloques e inodos
  sb.s_blocks_count = 3*n;
  sb.s_inodes_count = n;
  //ponemos que la ultima fecha que fue montado es cuando se crea
  auto t_actual = std::chrono::system_clock::now();
  time_t t = std::chrono::system_clock::to_time_t(t_actual);
  sb.s_free_inodes_count = n; // por ahora todos estan vacios
  sb.s_free_blocks_count = 3*n; //por ahora todos estan vacios
  sb.s_mtime = t; //pongo una fecha de montaje porque ya se monto antes del formateo
  sb.s_umtime = 0;
  sb.s_mnt_count = 1; //por lo tanto aqui es uno
  sb.s_magic = 0xEF53;
  sb.s_block_s = sizeof(B_CARPETA);
  sb.s_inode_s = sizeof(B_INODO);
  sb.s_firts_ino = 0; //se pone respecto al bitmap de inodos y bloques que
  sb.s_first_blo = 0; //por el momento no hay nada
  sb.s_bm_inode_start = _item.part.part_start + sizeof(SUPERBLOQUE);
  sb.s_bm_block_start = sb.s_bm_inode_start + n;
  sb.s_inode_start = sb.s_bm_block_start + (3*n);
  sb.s_block_start = sb.s_inode_start+(n*sizeof(B_INODO));
  int posFinal = sb.s_block_start+((3*n)*sizeof(B_CARPETA));
  //vamos a asegurarnos que no pase el espacio
  int tt = sizeof(SUPERBLOQUE)+n+(3*n)+(n*sizeof(B_INODO))+((3*n)*sizeof(B_CARPETA));
  /* if(_item.part.part_s > tt){
    cout<<"todo bien, todo correcto"<<endl;
  }else{
    cout<<"todo mal calculado :("<<endl;
  } */
  // terminado el superbloque se creara el  directorio raiz y el archivo users.txt
  B_INODO bi; //inodo de la raiz
  bi.i_uid = 1;
  bi.i_gid = 1;
  bi.i_atime = t; //por el momento los tiempos son los mismos
  bi.i_ctime = t;
  bi.i_mtime = t;
  bi.i_type = '0';
  bi.i_perm = 644;
  //se aumenta en uno el primer inodo libre
  sb.s_firts_ino++;
  //ahora se crea el bloque de carpeta
  B_CARPETA bc; //primer bloque donde se 
  bc.b_content[0].b_inodo = 0;
  string padre = ".";
  strcpy(bc.b_content[0].b_name, padre.c_str());
  bc.b_content[1].b_inodo = 0;
  padre = "..";
  strcpy(bc.b_content[1].b_name, padre.c_str());
  bc.b_content[2].b_inodo = 1;
  padre = "users.txt";
  strcpy(bc.b_content[2].b_name, padre.c_str());
  sb.s_first_blo++;
  bi.i_block[0] = 0;

  //creamos el inodo del users.txt
  B_INODO bi1;
  bi1.i_uid = 1;
  bi1.i_gid = 1;
  bi1.i_atime = t; //por el momento los tiempos son los mismos
  bi1.i_ctime = t;
  bi1.i_mtime = t;
  bi1.i_type = '1';
  bi1.i_perm = 644;
  bi1.i_block[0] = 1;
  sb.s_firts_ino++;

  B_ARCHIVO ba;
  string users = "1,G,root\n1,U,root,root,123\n";
  bi1.i_s = users.length();
  
  strcpy(ba.b_content, users.c_str());
  sb.s_first_blo++;

  bi1.i_s = users.length();
  sb.s_free_blocks_count = sb.s_free_blocks_count - 2;
  sb.s_free_inodes_count = sb.s_free_inodes_count - 2;

  //hay que escribir en el archivo el inodo y el superbloque

  FILE *archivo = fopen(_item.path.c_str(), "r+b");
  //se escribe el superbloque
  fseek(archivo, _item.part.part_start, SEEK_SET);
  fwrite(&sb, sizeof(SUPERBLOQUE), 1, archivo);
  //se escriben los inodos
  fseek(archivo, sb.s_inode_start, SEEK_SET);
  fwrite(&bi, sizeof(bi), 1, archivo);
  fseek(archivo, sb.s_inode_start+sizeof(bi), SEEK_SET);
  fwrite(&bi1, sizeof(bi1), 1, archivo);
  //se escriben los bloques
  fseek(archivo, sb.s_block_start, SEEK_SET);
  fwrite(&bc, sizeof(bc), 1, archivo);
  fseek(archivo, sb.s_block_start+sizeof(bc), SEEK_SET);
  fwrite(&ba, sizeof(ba), 1, archivo);
  //se agregan los datos al bitmap de inodos y bloques
  fseek(archivo, sb.s_bm_inode_start, SEEK_SET);
  char uno = '1';
  fwrite(&uno, 1, 1, archivo);
  fseek(archivo, sb.s_bm_inode_start+1, SEEK_SET);
  fwrite(&uno, 1,1,archivo);

  fseek(archivo, sb.s_bm_block_start, SEEK_SET);
  fwrite(&uno, 1, 1, archivo);
  fseek(archivo, sb.s_bm_block_start+1, SEEK_SET);
  fwrite(&uno, 1,1,archivo);
  fclose(archivo);
  cout<<"Particion formateada correctamente"<<endl;
}

void Mkfs::formateoExt3(itemMount _item){
  SUPERBLOQUE sb;
  //no se a que se refiere el system type dek superbloque pero creo que se
  //refiere a si es un sistema ext2 o uno ext3
  sb.s_filesystem_type = 3;
  //calculamos el numero de estructuras
  int n = (_item.part.part_s - sizeof(SUPERBLOQUE))/(1+sizeof(B_INODO)+3+(3*sizeof(B_CARPETA)));
  n = floor(n);
  //cout<<n<<endl;
  //calculamos el numero de bloques e inodos
  sb.s_blocks_count = 3*n;
  sb.s_inodes_count = n;
  //ponemos que la ultima fecha que fue montado es cuando se crea
  auto t_actual = std::chrono::system_clock::now();
  time_t t = std::chrono::system_clock::to_time_t(t_actual);
  sb.s_free_inodes_count = n; // por ahora todos estan vacios
  sb.s_free_blocks_count = 3*n; //por ahora todos estan vacios
  sb.s_mtime = t; //pongo una fecha de montaje porque ya se monto antes del formateo
  sb.s_umtime = 0;
  sb.s_mnt_count = 1; //por lo tanto aqui es uno
  sb.s_magic = 0xEF53;
  sb.s_block_s = sizeof(B_CARPETA);
  sb.s_inode_s = sizeof(B_INODO);
  sb.s_firts_ino = 0; //se pone respecto al bitmap de inodos y bloques que
  sb.s_first_blo = 0; //por el momento no hay nada
  sb.s_bm_inode_start = _item.part.part_start + sizeof(SUPERBLOQUE);
  sb.s_bm_block_start = sb.s_bm_inode_start + n;
  sb.s_inode_start = sb.s_bm_block_start + (3*n);
  sb.s_block_start = sb.s_inode_start+(n*sizeof(B_INODO));
  int posFinal = sb.s_block_start+((3*n)*sizeof(B_CARPETA));
  //vamos a asegurarnos que no pase el espacio
  int tt = sizeof(SUPERBLOQUE)+n+(3*n)+(n*sizeof(B_INODO))+((3*n)*sizeof(B_CARPETA));
  /* if(_item.part.part_s > tt){
    cout<<"todo bien, todo correcto"<<endl;
  }else{
    cout<<"todo mal calculado :("<<endl;
  } */
  // terminado el superbloque se creara el  directorio raiz y el archivo users.txt
  B_INODO bi; //inodo de la raiz
  bi.i_uid = 1;
  bi.i_gid = 1;
  bi.i_atime = t; //por el momento los tiempos son los mismos
  bi.i_ctime = t;
  bi.i_mtime = t;
  bi.i_type = '0';
  bi.i_perm = 644;
  //se aumenta en uno el primer inodo libre
  sb.s_firts_ino++;
  //ahora se crea el bloque de carpeta
  B_CARPETA bc; //primer bloque donde se 
  bc.b_content[0].b_inodo = 0;
  string padre = ".";
  strcpy(bc.b_content[0].b_name, padre.c_str());
  bc.b_content[1].b_inodo = 0;
  padre = "..";
  strcpy(bc.b_content[1].b_name, padre.c_str());
  bc.b_content[2].b_inodo = 1;
  padre = "users.txt";
  strcpy(bc.b_content[2].b_name, padre.c_str());
  sb.s_first_blo++;
  bi.i_block[0] = 0;

  //creamos el inodo del users.txt
  B_INODO bi1;
  bi1.i_uid = 1;
  bi1.i_gid = 1;
  bi1.i_atime = t; //por el momento los tiempos son los mismos
  bi1.i_ctime = t;
  bi1.i_mtime = t;
  bi1.i_type = '1';
  bi1.i_perm = 644;
  bi1.i_block[0] = 1;
  sb.s_firts_ino++;

  B_ARCHIVO ba;
  string users = "1,G,root\n1,U,root,root,123\n";
  bi1.i_s = users.length();
  
  strcpy(ba.b_content, users.c_str());
  sb.s_first_blo++;

  bi1.i_s = users.length();
  sb.s_free_blocks_count = sb.s_free_blocks_count - 2;
  sb.s_free_inodes_count = sb.s_free_inodes_count - 2;

  //hay que escribir en el archivo el inodo y el superbloque

  FILE *archivo = fopen(_item.path.c_str(), "r+b");
  //se escribe el superbloque
  fseek(archivo, _item.part.part_start, SEEK_SET);
  fwrite(&sb, sizeof(SUPERBLOQUE), 1, archivo);
  //se escriben los inodos
  fseek(archivo, sb.s_inode_start, SEEK_SET);
  fwrite(&bi, sizeof(bi), 1, archivo);
  fseek(archivo, sb.s_inode_start+sizeof(bi), SEEK_SET);
  fwrite(&bi1, sizeof(bi1), 1, archivo);
  //se escriben los bloques
  fseek(archivo, sb.s_block_start, SEEK_SET);
  fwrite(&bc, sizeof(bc), 1, archivo);
  fseek(archivo, sb.s_block_start+sizeof(bc), SEEK_SET);
  fwrite(&ba, sizeof(ba), 1, archivo);
  //se agregan los datos al bitmap de inodos y bloques
  fseek(archivo, sb.s_bm_inode_start, SEEK_SET);
  char uno = '1';
  fwrite(&uno, 1, 1, archivo);
  fseek(archivo, sb.s_bm_inode_start+1, SEEK_SET);
  fwrite(&uno, 1,1,archivo);

  fseek(archivo, sb.s_bm_block_start, SEEK_SET);
  fwrite(&uno, 1, 1, archivo);
  fseek(archivo, sb.s_bm_block_start+1, SEEK_SET);
  fwrite(&uno, 1,1,archivo);
  fclose(archivo);
  cout<<"Particion formateada correctamente"<<endl;
}
