#include "rep.h"
#include <fstream>
#include <sys/stat.h>
#include <cmath>


using std::cout, std::endl;


Rep::Rep(string _name, string _path, string _id, string _ruta){
    name = _name;
    path = replaceQuotesMarks(_path);
    id = _id;
    rutaf = _ruta;
};

void Rep::ejecutarComando(){

  if(path == "" || name == "" || id == "" ){
    cout << "Error: Faltan parametros obligatorios" << endl;
    return;
  }

  std::vector<string> carpetas;
  string separador = "/";
  size_t pos = 0;
  string pathTemporal = path;
  // se separa la ruta del nombre del archivo
  while ((pos = pathTemporal.find(separador)) != string::npos) {
    string carpeta = pathTemporal.substr(0, pos);
    carpetas.push_back(carpeta);
    pathTemporal.erase(0, pos + separador.length());
  }
  string ruta;
  // se vuelve a juntar para la creacion de las carpetas
  for (auto c  : carpetas) {
      ruta= ruta + c +"/";
  }
  //creando los directorios
  int status = mkdir(ruta.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  //se valida si se pudo crear el directorio o no
  if (status == -1 && errno != EEXIST) {
    perror("Error creando directorio");
    return;
  }
  //se verifica que el id ingresado sea correcto
  itemMount item;
  for(int i = 0; i < particionMontada.size(); i++){
    if(particionMontada[i].id == id){
      item = particionMontada[i];
      break;
    }
  }
  if(item.id == ""){
    cout << "Error, el parametro id ingresado para el reporte no existe"<<endl;
    return;
  }
  //valida el parametro name para generar el reporte correcto
  if(name.compare("mbr")==0){
    reporteMBR(item);
  }else if (name.compare("disk")==0){
    reporteDisk(item);
  }else if(name.compare("inode")==0){
    //reporteInode();
    cout<<"Entro al reporte de inode"<<endl;
  }else if(name.compare("Journaling")==0){
    //reporteJournaling();
    cout<<"Entro al reporte de journaling"<<endl;
  }else if(name.compare("block")==0){
    //reporteBlock();
    cout<<"Entro al reporte de block"<<endl;
  }else if(name.compare("bm_inode")==0){
    reporteBMInodo(item);
  }else if(name.compare("bm_bloc")==0){
    reporteBMBloque(item);
  }else if(name.compare("tree")==0){
    //reporteTree();
    cout<<"Entro al reporte de tree"<<endl;
  }else if(name.compare("file")==0){
    reporteFile(item);
  }else if(name.compare("sb")==0){
    reporteSuperbloque(item);
  }else if(name.compare("ls")==0){
    //reporteLs();
    cout<<"Entro al reporte de ls"<<endl;
  }

}

void Rep::reporteMBR(itemMount _item){
  MBR mbr;
  FILE *archivo = fopen(_item.path.c_str(), "rb");
  fread(&mbr, sizeof(MBR), 1, archivo);
  string dot = "digraph mbr {\n";
  dot += "  some_node [\n";
  dot += "    shape=plaintext\n";
  dot += "    label=<\n";
  dot += "      <table cellpadding='4' cellborder='1' color='grey' cellspacing='1'>\n";
  dot += "        <tr>\n";
  dot += "          <td  colspan='2' bgcolor='gray'>Reporte MBR</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>mbr_tamanio</td>\n";
  dot += "          <td>"+std::to_string(mbr.mbr_tamano*1024)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>mbr_fecha_creacion</td>\n";
  char buffer[80]; // buffer para almacenar la cadena de texto
  std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", std::localtime(&mbr.mbr_fecha_creacion)); // formatea la fecha y hora en una cadena de texto
  std::string fecha_hora(buffer); // convierte la cadena de texto en un objeto std::string
  dot += "          <td>"+fecha_hora+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>mbr_disk_signature</td>\n";
  dot += "          <td>"+std::to_string(mbr.mbr_dsk_signature)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>disk_fit</td>\n";
  dot += "          <td>"+std::string(1, mbr.dsk_fit)+"</td>\n";
  dot += "        </tr>\n";
  //pasamos a arreglo para crear dot mas facil
  PARTITION arreglo[4];
  arreglo[0] = mbr.mbr_partition_1;
  arreglo[1] = mbr.mbr_partition_2;
  arreglo[2] = mbr.mbr_partition_3;
  arreglo[3] = mbr.mbr_partition_4;
  ordenarTamanio(arreglo);
  for (size_t i = 0; i < 4; i++){
    if(arreglo[i].part_s != 0){
      dot += "        <tr>\n";
      dot += "          <td  colspan='2' bgcolor='lightblue'>Particion</td>\n";
      dot += "        </tr>\n";
      dot += "        <tr>\n";
      dot += "          <td>part_status</td>\n";
      dot += "          <td>"+std::string(1, arreglo[i].part_status)+"</td>\n";
      dot += "        </tr>\n";
      dot += "        <tr>\n";
      dot += "          <td>part_type</td>\n";
      dot += "          <td>"+std::string(1, arreglo[i].part_type)+"</td>\n";
      dot += "        </tr>\n";
      dot += "        <tr>\n";
      dot += "          <td>part_fit</td>\n";
      dot += "          <td>"+std::string(1, arreglo[i].part_fit)+"</td>\n";
      dot += "        </tr>\n"; 
      dot += "        <tr>\n";
      dot += "          <td>part_start</td>\n";
      dot += "          <td>"+std::to_string(arreglo[i].part_start)+"</td>\n";
      dot += "        </tr>\n";
      dot += "        <tr>\n";
      dot += "          <td>part_size</td>\n";
      dot += "          <td>"+std::to_string(arreglo[i].part_s)+"</td>\n";
      dot += "        </tr>\n";
      dot += "        <tr>\n";
      dot += "          <td>part_name</td>\n";
      dot += "          <td>"+string(arreglo[i].part_name)+"</td>\n";
      dot += "        </tr>\n";
      if(arreglo[i].part_type == 'E'){
        
        EBR ebr;
        fseek(archivo, arreglo[i].part_start, SEEK_SET);
        fread(&ebr, sizeof(EBR), 1, archivo);
        while (ebr.part_s != 0){
          dot += "        <tr>\n";
          dot += "          <td  colspan='2' bgcolor='#f0e3ff'>Particion Logica</td>\n";
          dot += "        </tr>\n";
          dot += "        <tr>\n";
          dot += "          <td>part_status</td>\n";
          dot += "          <td>"+std::string(1, ebr.part_status)+"</td>\n";
          dot += "        </tr>\n";
          dot += "        <tr>\n";
          dot += "          <td>part_next</td>\n";
          dot += "          <td>"+std::to_string(ebr.part_next)+"</td>\n";
          dot += "        </tr>\n";
          dot += "        <tr>\n";
          dot += "          <td>part_fit</td>\n";
          dot += "          <td>"+std::string(1, ebr.part_fit)+"</td>\n";
          dot += "        </tr>\n";
          dot += "        <tr>\n";
          dot += "          <td>part_start</td>\n";
          dot += "          <td>"+std::to_string(ebr.part_start)+"</td>\n";
          dot += "        </tr>\n";
          dot += "        <tr>\n";
          dot += "          <td>part_size</td>\n";
          dot += "          <td>"+std::to_string(ebr.part_s)+"</td>\n";
          dot += "        </tr>\n";
          dot += "        <tr>\n";
          dot += "          <td>part_name</td>\n";
          dot += "          <td>"+string(ebr.part_name)+"</td>\n";
          dot += "        </tr>\n";
          if(ebr.part_next != 0){
            fseek(archivo, ebr.part_next, SEEK_SET);
            fread(&ebr, sizeof(EBR), 1, archivo);
          }else{
            ebr.part_s = 0;
          }
          
        }
      }
    }
    
  }
  fclose(archivo);
  dot += "</table>\n";
  dot += ">];\n";
  dot += "}\n";
  

  crearReporte(dot, "mbr");
}

void Rep::reporteDisk(itemMount _item){
  string titulo = path.substr(_item.path.find_last_of("/") + 1);
  string dot = "digraph disk {\n";
  dot += "  tbl [\n";
  dot += "    shape=plaintext\n";
  dot += "    label=<\n";
  dot += "    <table border='0' cellborder='1' color='grey' cellspacing='1'>\n";
  dot += "      <tr>\n";
  dot += "        <td border='0' colspan='3'>"+titulo+"</td>\n";
  dot += "      </tr>\n";
  dot += "      <tr>\n";
  dot += "        <td border='0'>\n";
  dot += "          <table color='gray' cellspacing='3' cellpadding='5'>\n";
  dot += "            <tr>\n";
  dot += "              <td>MBR</td>";

  //se como no tengo las particiones en un arreglo lo convierto aqui y lo ordeno
  std::vector<PARTITION> parts;
  
  PARTITION arreglo[4];
  arreglo[0] = _item.mbr.mbr_partition_1;
  arreglo[1] = _item.mbr.mbr_partition_2;
  arreglo[2] = _item.mbr.mbr_partition_3;
  arreglo[3] = _item.mbr.mbr_partition_4;
  ordenarTamanio(arreglo);
  for (size_t i = 0; i < 4; i++){
    if(arreglo[i].part_s != 0){
      parts.push_back(arreglo[i]);
    }
  }
  

  int inicio = sizeof(MBR);
  //se multiplica porque lo guardo en kb
  double tamanio = _item.mbr.mbr_tamano*1024.0;
  for(int i=0; i<parts.size();i++){
    if(inicio == parts[i].part_start){
      if(parts[i].part_type == 'E'){
        dot += "              <td border='0' cellpadding='0'>\n";
        dot += "                <table cellborder='0' color='gray' cellspacing='0' cellpadding='5'>\n";
        dot += "                  <tr>\n";
        dot += "                    <td border='1' colspan='8'>Extendida</td>\n";
        dot += "                  </tr>\n";
        dot += "                  <tr>\n";
        EBR ebr;
        FILE *archivo = fopen(_item.path.c_str(),"rb+");
        int test = parts[i].part_start;
        int tamanio_temporal = 0;
        do{
          fseek(archivo,test,SEEK_SET);
          fread(&ebr, sizeof(EBR), 1, archivo);
          if(ebr.part_s == 0){
            double espacio = ((parts[i].part_s)*100)/tamanio;
            dot += "                    <td border='1'>Libre";
            dot += "<br/>"+std::to_string(static_cast<int>(std::round(espacio)))+"%</td>\n";
            tamanio_temporal = parts[i].part_s;
          }else{
            dot += "                    <td border='1'>EBR</td>\n";
            double espacio = (ebr.part_s*100)/tamanio;
            dot += "                    <td border='1'>Logica ";
            dot += "<br/>"+std::to_string(static_cast<int>(std::round(espacio)))+"%</td>\n";
            tamanio_temporal += ebr.part_s;
          }
          test = ebr.part_next;
          
        } while (test != 0);
        if(parts[i].part_s > tamanio_temporal){
          double espacio = ((parts[i].part_s - tamanio_temporal)*100)/tamanio;
          dot += "                    <td border='1'>Libre";
          dot += "<br/>"+std::to_string(static_cast<int>(std::round(espacio)))+"%</td>\n";
        }
        dot += "                  </tr>\n";
        dot += "                </table>\n";
        dot += "              </td>\n";
        
        fclose(archivo);
      }else{
        double espacio = (parts[i].part_s*100)/tamanio;
        dot += "              <td>Particion "+std::to_string(i+1);
        dot += "<br/>"+std::to_string(static_cast<int>(std::round(espacio)))+"%</td>\n";
      }
      inicio = inicio + parts[i].part_s;
    }else{
      double espacio = ((parts[i].part_start-inicio)*100)/tamanio;
      dot += "              <td>Libre ";
      dot += "<br/>"+std::to_string(static_cast<int>(std::round(espacio)))+"%</td>\n";
      if(parts[i].part_type == 'E'){
        dot += "              <td border='0' cellpadding='0'>\n";
        dot += "                <table cellborder='0' color='gray' cellspacing='0' cellpadding='5'>\n";
        dot += "                  <tr>\n";
        dot += "                    <td border='1' colspan='8'>Extendida</td>\n";
        dot += "                  </tr>\n";
        dot += "                  <tr>\n";
        EBR ebr;
        FILE *archivo = fopen(_item.path.c_str(),"rb+");
        int test = parts[i].part_start;
        int tamanio_temporal = 0;
        do{
          fseek(archivo,test,SEEK_SET);
          fread(&ebr, sizeof(EBR), 1, archivo);
          if(ebr.part_s == 0){
            double espacio = ((parts[i].part_s)*100)/tamanio;
            dot += "                    <td border='1'>Libre";
            dot += "<br/>"+std::to_string(std::round(espacio))+"%</td>\n";
            tamanio_temporal = parts[i].part_s;
          }else{
            dot += "                    <td border='1'>EBR</td>\n";
            double espacio = (ebr.part_s*100)/tamanio;
            dot += "                    <td border='1'>Logica ";
            dot += "<br/>"+std::to_string(std::round(espacio))+"%</td>\n";
            tamanio_temporal += ebr.part_s;
          }
          test = ebr.part_next;
          
        } while (test != 0);
        if(parts[i].part_s > tamanio_temporal){
          double espacio = ((parts[i].part_s - tamanio_temporal)*100)/tamanio;
          dot += "                    <td border='1'>Libre";
          dot += "<br/>"+std::to_string(std::round(espacio))+"%</td>\n";
        }
        dot += "                  </tr>\n";
        dot += "                </table>\n";
        dot += "              </td>\n";
        
        fclose(archivo);
      }else{
        espacio = (parts[i].part_s*100)/tamanio;
        dot += "              <td>Particion "+std::to_string(i+1);
        dot += "<br/>"+std::to_string(std::round(espacio))+"%</td>\n";
      }
      inicio = inicio + parts[i].part_s;
    }
  }
  if(inicio <_item.mbr.mbr_tamano*1024){
    double espacio = (((_item.mbr.mbr_tamano*1024) - inicio)*100)/tamanio;
    dot += "              <td>Libre ";
    dot += "<br/>"+std::to_string(static_cast<int>(std::round(espacio)))+"%</td>\n";
  }
  dot += "            </tr>\n";
  dot += "          </table>\n";
  dot += "        </td>\n";
  dot += "      </tr>\n";
  dot += "    </table>\n";
  dot += "  >];\n";
  dot += "}";
  crearReporte(dot, "disk");
}

void Rep::reporteSuperbloque(itemMount _item){
  SUPERBLOQUE sb;
  FILE *archivo = fopen(_item.path.c_str(), "rb");
  //se posiciona al inicio de la particion para recuperar el sb
  fseek(archivo, _item.part.part_start, SEEK_SET);
  fread(&sb, sizeof(SUPERBLOQUE), 1, archivo);
  fclose(archivo);
  string dot = "digraph sb {\n";
  dot += "  some_node [\n";
  dot += "    shape=plaintext\n";
  dot += "    label=<\n";
  dot += "      <table cellpadding='4' cellborder='1' color='grey' cellspacing='1'>\n";
  dot += "        <tr>\n";
  dot += "          <td  colspan='2' bgcolor='gray'>Reporte SUPERBLOQUE</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_filesystem_type</td>\n";
  string syste_type = "";
  if(sb.s_filesystem_type == 2){
    syste_type = "EXT2";
  }else if(sb.s_filesystem_type == 3){
    syste_type = "EXT3";
  }
  dot += "          <td>"+syste_type+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_inodes_count</td>\n";
  dot += "          <td>"+std::to_string(sb.s_inodes_count)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_blocks_count</td>\n";
  dot += "          <td>"+std::to_string(sb.s_blocks_count)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_free_inodes_count</td>\n";
  dot += "          <td>"+std::to_string(sb.s_free_inodes_count)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_free_blocks_count</td>\n";
  dot += "          <td>"+std::to_string(sb.s_free_blocks_count)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_mtime</td>\n";
  char buffer[80]; // buffer para almacenar la cadena de texto
  std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", std::localtime(&sb.s_mtime)); // formatea la fecha y hora en una cadena de texto
  std::string fecha_hora(buffer); // convierte la cadena de texto en un objeto std::string
  dot += "          <td>"+fecha_hora+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_umtime</td>\n";
  std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", std::localtime(&sb.s_umtime)); // formatea la fecha y hora en una cadena de texto
  fecha_hora = string(buffer); // convierte la cadena de texto en un objeto std::string
  dot += "          <td>"+fecha_hora+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_magic</td>\n";
  dot += "          <td>"+std::to_string(sb.s_magic)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_inode_s</td>\n";
  dot += "          <td>"+std::to_string(sb.s_inode_s)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_block_s</td>\n";
  dot += "          <td>"+std::to_string(sb.s_block_s)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_firts_ino</td>\n";
  dot += "          <td>"+std::to_string(sb.s_firts_ino)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_firts_blo</td>\n";
  dot += "          <td>"+std::to_string(sb.s_first_blo)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_bm_inode_start</td>\n";
  dot += "          <td>"+std::to_string(sb.s_bm_inode_start)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_bm_block_start</td>\n";
  dot += "          <td>"+std::to_string(sb.s_bm_block_start)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_inode_start</td>\n";
  dot += "          <td>"+std::to_string(sb.s_inode_start)+"</td>\n";
  dot += "        </tr>\n";
  dot += "        <tr>\n";
  dot += "          <td>s_block_start</td>\n";
  dot += "          <td>"+std::to_string(sb.s_block_start)+"</td>\n";
  dot += "        </tr>\n";
  
  dot += "</table>\n";
  dot += ">];\n";
  dot += "}\n";
  

  crearReporte(dot, "sb");
}

void Rep::reporteBMInodo(itemMount _item){
  SUPERBLOQUE sb;
  FILE *archivo = fopen(_item.path.c_str(), "rb");
  fseek(archivo, _item.part.part_start, SEEK_SET);
  fread(&sb, sizeof(SUPERBLOQUE), 1, archivo);
  int final_bm = sb.s_inodes_count;

  string contenido_b = "";
  int contador_i = 0;
  char c = 'a';
  for (size_t i = 0; i < final_bm; i++){
    contador_i ++;
    fseek(archivo, sb.s_bm_inode_start+i, SEEK_SET);
    fread(&c, 1, 1, archivo);
    if(c == '1'){
      contenido_b += c;
    }else{
      contenido_b += '0';
    }
    if(contador_i == 20){
      contenido_b += "\n";
      contador_i = 0;
    }
  }
  fclose(archivo);
  std::ofstream reporte(path.c_str());
  if(reporte.is_open()){
    reporte << contenido_b;
    reporte.close();
  }else{
    cout << "Error al generar el reporte" << endl;
    return;
  }
  cout<<"Reporte creado con exito"<<endl;
}

void Rep::reporteBMBloque(itemMount _item){
  SUPERBLOQUE sb;
  FILE *archivo = fopen(_item.path.c_str(), "rb");
  fseek(archivo, _item.part.part_start, SEEK_SET);
  fread(&sb, sizeof(SUPERBLOQUE), 1, archivo);
  int final_bm = sb.s_blocks_count;
  string contenido_b = "";
  int contador_i = 0;
  char c = 'a';
  for (size_t i = 0; i < final_bm; i++){
    contador_i ++;
    fseek(archivo, sb.s_bm_block_start+i, SEEK_SET);
    fread(&c, 1, 1, archivo);
    if(c == '1'){
      contenido_b += c;
    }else{
      contenido_b += '0';
    }
    
    if(contador_i == 20){
      contenido_b += "\n";
      contador_i = 0;
    }
  }
  fclose(archivo);
  std::ofstream reporte(path.c_str());
  if(reporte.is_open()){
    reporte << contenido_b;
    reporte.close();
  }else{
    cout << "Error al generar el reporte" << endl;
    return;
  }
  cout<<"Reporte creado con exito"<<endl;
}

void Rep::reporteFile(itemMount _item){
  
}

void Rep::crearReporte(string dot, string nombre){
  string nameDot = "dot/"+nombre+".dot";
  std::ofstream archivo(nameDot);

  //se obtiene la imagen a generar este si va a ser png o jpg
  string extension = path.substr(path.find_last_of(".") + 1);
  string formato;

  if (extension == "jpg" || extension == "jpeg") {
      formato = "-Tjpg";
  } else if (extension == "png") {
      formato = "-Tpng";
  }else if(extension == "pdf"){
    formato = "-Tpdf";
  } else {
      std::cout << "La extensión del archivo no es reconocida\n";
  }
  if (archivo.is_open()) {
    archivo << dot;
    archivo.close();
    string comando = "dot "+ formato +" "+ nameDot+" -o "+path;
    std::system(comando.c_str());
    cout << "Reporte generado exitosamente" << endl;
  } else {
    cout << "Error al abrir el archivo." << endl;
  }
}