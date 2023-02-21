#ifndef Structs__
#define Structs__
#include <chrono>

typedef struct{
    char part_status;
    char part_type;
    char part_fit;
    int part_start;
    int part_s;
    char part_name[16];

}PARTITION;

typedef struct{
    int mbr_tamano;
    time_t mbr_fecha_creacion;
    int mbr_dsk_signature;
    char dsk_fit;
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