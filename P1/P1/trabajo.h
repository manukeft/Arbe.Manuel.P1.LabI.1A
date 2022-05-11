#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "mascota.h"
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"

typedef struct{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int inicializarTrabajos(eTrabajo trabajos[], int tamTra);
int buscarTrabajoLibre(eTrabajo trabajos[], int tamTra, int* pIndex);
int altaTrabajo(eTrabajo trabajos[], int tamTra, eMascota lista[], int tamMas, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eServicio servicios[], int tamSer, int* pIdTrabajo);
int listarTrabajos(eTrabajo trabajos[], int tamTra, eMascota lista[], int tamMas, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eServicio servicios[], int tamSer);
