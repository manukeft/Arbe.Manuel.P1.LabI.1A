#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "servicio.h"

int listarServicios(eServicio servicios[], int tamSer)
{
    int todoOk = 0;

    if(servicios != NULL && tamSer > 0)
    {
     // system("cls");
        printf("   *** Lista de Servicios  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tamSer; i++)
        {
            printf("   %4d    %10s\n", servicios[i].id, servicios[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int validarServicios(eServicio servicios[], int tamSer, int id)
{
    int esValido = 0;
    int indice;

    buscarServicios(servicios, tamSer, id, &indice);

    if(indice != -1)
    {
        esValido = 1;
    }

    return esValido;
}

int buscarServicios(eServicio servicios[], int tamSer, int id, int* pIndice)
{
    int todoOk = 0;
    if(servicios != NULL && tamSer > 0 && pIndice != NULL)
    {
        *pIndice = -1;
        for(int i=0; i < tamSer; i++)
        {
            if(servicios[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionServicios(eServicio servicios[], int tamSer, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarTipos(servicios, tamSer, id, &indice);

    if(descripcion != NULL && indice != -1 )
    {
       strcpy(descripcion, servicios[indice].descripcion);
       todoOk = 1;
    }

    return todoOk;
}
