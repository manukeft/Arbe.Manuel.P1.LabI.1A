#include "tipo.h"
#include "color.h"

#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    char vacunado;
    int isEmpty;
} eMascota;

#endif // MASCOTA_H_INCLUDED

int altaMascota(eMascota vec[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, int* pId);
int buscarMascotaLibre(eMascota lista[], int tamMas, int* pIndex);
int inicializarMascotas(eMascota lista[], int tamMas);
int modificarMascota(eMascota lista[], int tamMas, eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int menuModificarMascota();
int mostrarMascota(eMascota lista, eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int listarMascotas(eMascota lista[], int tamMas, eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int buscarMascota(eMascota lista[], int tamMas, int id, int* pIndex);
int bajaMascota(eMascota lista[], int tamMas, eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int hardcodearMascotas(eMascota lista[], int tamMas, int cant, int* pId);
