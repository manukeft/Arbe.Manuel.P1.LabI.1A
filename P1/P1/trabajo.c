#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajo.h"


int inicializarTrabajos(eTrabajo trabajos[], int tamTra)
{
    int todoOk = 0;
    if(trabajos != NULL && tamTra > 0)
    {
        for(int i=0; i < tamTra; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarTrabajoLibre(eTrabajo trabajos[], int tamTra, int* pIndex)
{
    int todoOk = 0;
    if(trabajos != NULL && tamTra > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tamTra; i++)
        {
            if( trabajos[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaTrabajo(eTrabajo trabajos[], int tamTra, eMascota lista[], int tamMas, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eServicio servicios[], int tamSer ,int* pIdTrabajo){
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;
    eFecha fecha;

    if(trabajos != NULL && tipos != NULL && colores != NULL && lista != NULL && servicios != NULL && pIdTrabajo != NULL && tamTra > 0 && tamMas > 0 && tamCol > 0 && tamTip > 0 && tamSer > 0)
    {

        system("cls");
        printf("       *** Alta Trabajo *** \n");
        printf("-------------------------------------------\n\n");


        if( buscarTrabajoLibre(trabajos, tamTra, &indice) )
        {
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                // aca caigo cuando haya lugar
                listarMascotas(lista, tamMas, tipos, tamTip, colores, tamCol);
                printf("Ingrese id mascota\n");
                scanf("%d", &nuevoTrabajo.idMascota);
                buscarMascota(lista, tamMas, nuevoTrabajo.idMascota, &indice);

                while( indice == -1)
                {
                    printf("Mascota invalido. Ingrese id mascota\n");
                    scanf("%d", &nuevoTrabajo.idMascota);
                    buscarMascota(lista, tamMas, nuevoTrabajo.idMascota, &indice);
                }

                listarServicios(servicios, tamSer);
                printf("Ingrese id servicio\n");
                scanf("%d", &nuevoTrabajo.idServicio);

                while( !validarServicios(servicios, tamSer, nuevoTrabajo.idServicio )){
                printf("Servicio invalido. Ingrese id servicio\n");
                scanf("%d", &nuevoTrabajo.idServicio);
                }

                printf("Ingrese Fecha  dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                nuevoTrabajo.fecha = fecha;

                nuevoTrabajo.isEmpty = 0;
                nuevoTrabajo.id = *pIdTrabajo;
                *pIdTrabajo = *pIdTrabajo + 1;
                trabajos[indice] = nuevoTrabajo;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}

int listarTrabajos(eTrabajo trabajos[], int tamTra, eMascota lista[], int tamMas, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eServicio servicios[], int tamSer)
{
    int todoOk = 0;
    int flag = 0;
    char descripcion[20];

     if(trabajos != NULL && tipos != NULL && colores != NULL && lista != NULL && servicios != NULL && tamTra > 0 && tamMas > 0 && tamCol > 0 && tamTip > 0 && tamSer > 0)
    {
        system("cls");
        printf("          *** Listado de Trabajos ***\n\n");
        printf("  Id          IdMascota        Servicio    Fecha\n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i=0; i < tamTra; i++)
        {
            if( !trabajos[i].isEmpty )
            {
                cargarDescripcionServicios(servicios, tamSer, trabajos[i].idServicio, descripcion);
                printf("   %d     %d      %10s          %02d/%02d/%02d\n", trabajos[i].id, trabajos[i].idMascota, descripcion, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay trabajos en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

