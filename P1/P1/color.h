#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
} eColor;

#endif // COLOR_H_INCLUDED

int listarColores(eColor colores[], int tamCol);
int validarColores(eColor colores[], int tamCol, int id);
int buscarColores(eColor colores[], int tamCol, int id, int* pIndice);
int cargarDescripcionColores(eColor colores[], int tamCol, int id, char descripcion[]);
