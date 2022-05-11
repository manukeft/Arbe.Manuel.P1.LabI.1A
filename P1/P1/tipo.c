#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipo.h"


int listarTipos(eTipo tipos[], int tamTip)
{
    int todoOk = 0;

    if(tipos != NULL && tamTip > 0)
    {
     // system("cls");
        printf("   *** Lista de Tipos  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tamTip; i++)
        {
            printf("   %4d    %10s\n", tipos[i].id, tipos[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int validarTipos(eTipo tipos[], int tamTip, int id)
{
    int esValido = 0;
    int indice;

    buscarTipos(tipos, tamTip, id, &indice);

    if(indice != -1)
    {
        esValido = 1;
    }

    return esValido;
}

int buscarTipos(eTipo tipos[], int tamTip, int id, int* pIndice)
{
    int todoOk = 0;
    if(tipos != NULL && tamTip > 0 && pIndice != NULL)
    {
        *pIndice = -1;
        for(int i=0; i < tamTip; i++)
        {
            if(tipos[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionTipos(eTipo tipos[], int tamTip, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarTipos(tipos, tamTip, id, &indice);

    if(descripcion != NULL && indice != -1 )
    {
       strcpy(descripcion, tipos[indice].descripcion);
       todoOk = 1;
    }

    return todoOk;
}

