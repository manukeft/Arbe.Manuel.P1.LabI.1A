#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

int listarServicios(eServicio servicios[], int tamSer);
int validarServicios(eServicio servicios[], int tamSer, int id);
int buscarServicios(eServicio servicios[], int tamSer, int id, int* pIndice);
int cargarDescripcionServicios(eServicio servicios[], int tamSer, int id, char descripcion[]);
