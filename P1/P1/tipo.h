#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eTipo;

#endif // TIPO_H_INCLUDED

int listarTipos(eTipo tipos[], int tamTip);
int validarTipos(eTipo tipos[], int tamTip, int id);
int buscarTipos(eTipo tipos[], int tamTip, int id, int* pIndice);
int cargarDescripcionTipos(eTipo tipos[], int tamTip, int id, char descripcion[]);
