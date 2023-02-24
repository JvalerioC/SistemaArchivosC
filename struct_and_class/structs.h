#ifndef Structs__
#define Structs__
#include <chrono>
#include <vector>

//este vector lo usare para los montajes y desmontajes en memoria
std::vector<itemMount> particionMontada;

//struct para los montajes
typedef struct{
    PARTITION part; //particion que fue montada, creo que solo neceesito el nombre
    string id; //id que identifica la montura
    string path; //para saber la ruta del disco
    MBR mbr; // para tener informacion de las particiones en disco

}itemMount;

typedef struct{
    char part_status; //activa o no
    char part_type; //tipo primaria o extendida
    char part_fit; //w,f o b
    int part_start; //indica en que byte del disco inicia la particion
    int part_s; //tamaño de la particion siempre en bytes
    char part_name[16];

}PARTITION;

typedef struct{
    int mbr_tamano; // siembre en kb
    time_t mbr_fecha_creacion;
    int mbr_dsk_signature;
    char dsk_fit;
    //cuesta mas trabajarlo asi, que con un arreglo pero ahi vamos
    PARTITION mbr_partition_1;
    PARTITION mbr_partition_2;
    PARTITION mbr_partition_3;
    PARTITION mbr_partition_4;

}MBR;

typedef struct{
    char part_status;
    char part_fit;
    int part_start;
    int part_s;
    int part_next;
    char part_name[16];

}EBR;



#endif