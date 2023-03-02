#ifndef Structs__
#define Structs__
#include <chrono>
#include <vector>
#include <string>
#include <ctime>

typedef struct{
    char part_status = '0'; //activa o no
    char part_type; //tipo primaria o extendida
    char part_fit; //w,f o b
    int part_start=0; //indica en que byte del disco inicia la particion
    int part_s=0; //tamaño de la particion siempre en bytes
    char part_name[16];

}PARTITION;

typedef struct{
    int mbr_tamano=0; // siembre en kb
    time_t mbr_fecha_creacion;
    int mbr_dsk_signature=0;
    char dsk_fit;
    //cuesta mas trabajarlo asi, que con un arreglo pero ahi vamos
    PARTITION mbr_partition_1;
    PARTITION mbr_partition_2;
    PARTITION mbr_partition_3;
    PARTITION mbr_partition_4;

}MBR;

typedef struct{
    char part_status='0';
    char part_fit;
    int part_start=0;
    int part_s=0;
    int part_next=0;
    char part_name[16];

}EBR;

//struct para los montajes
typedef struct{
    PARTITION part; //particion que fue montada, creo que solo neceesito el nombre
    std::string id; //id que identifica la montura
    std::string path; //para saber la ruta del disco, reportes
    MBR mbr; // para tener informacion de las particiones en disco,reportes

}itemMount;

//structura del superbloque
typedef struct{
    int s_filesystem_type=0;
    int s_inodes_count=0;
    int s_blocks_count=0;
    int s_free_blocks_count=0;
    int s_free_inodes_count=0;
    time_t s_mtime;
    time_t s_umtime;
    int s_mnt_count=0;
    int s_magic=0;
    int s_inode_s=0;
    int s_block_s=0;
    int s_firts_ino=0;
    int s_first_blo=0;
    int s_bm_inode_start=0;
    int s_bm_block_start=0;
    int s_inode_start=0;
    int s_block_start=0;

}SUPERBLOQUE;

//estructura para el bloque de inodos
typedef struct{
    int i_uid=0;
    int i_gid=0;
    int i_s=0;
    time_t i_atime;
    time_t i_ctime;
    time_t i_mtime;
    int i_block=0;
    char i_type='0';
    int i_perm=0;

}B_INODO;

//estructura para el bloque de contenido
typedef struct{
    char b_name[12];
    int b_inodo=0; 
}B_CONTENIDO;

//estructura para el bloque de carpeta
typedef struct{
    B_CONTENIDO b_content[4];
}B_CARPETA;



//estructura para el bloque de archivo
typedef struct{
    char b_content[64];
}B_ARCHIVO;

//estructura para el bloque de apuntadores
typedef struct{
   int b_pointers[16] = {0}; 
}B_APUNTADOR;

//este vector lo usare para los montajes y desmontajes en memoria
extern std::vector<itemMount> particionMontada;

#endif