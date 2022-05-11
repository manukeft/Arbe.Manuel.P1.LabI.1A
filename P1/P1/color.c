#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"

int listarColores(eColor colores[], int tamCol)
{
    int todoOk = 0;

    if(colores != NULL && tamCol > 0)
    {
     // system("cls");
        printf("   *** Lista de Colores  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tamCol; i++)
        {
            printf("   %4d    %10s\n", colores[i].id, colores[i].nombreColor);
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int validarColores(eColor colores[], int tamCol, int id)
{
    int esValido = 0;
    int indice;

    buscarColores(colores, tamCol, id, &indice);

    if(indice != -1)
    {
        esValido = 1;
    }

    return esValido;
}

int buscarColores(eColor colores[], int tamCol, int id, int* pIndice)
{
    int todoOk = 0;
    if(colores != NULL && tamCol > 0 && pIndice != NULL)
    {
        *pIndice = -1;
        for(int i=0; i < tamCol; i++)
        {
            if(colores[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionColores(eColor colores[], int tamCol, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarTipos(colores, tamCol, id, &indice);

    if(descripcion != NULL && indice != -1 )
    {
       strcpy(descripcion, colores[indice].nombreColor);
       todoOk = 1;
    }

    return todoOk;
}
