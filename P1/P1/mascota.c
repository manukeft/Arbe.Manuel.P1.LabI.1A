#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mascota.h"

int altaMascota(eMascota lista[], int tamMas, eTipo tipos[], int tamTip, eColor colores[], int tamCol, int* pId)
{
    int todoOk = 0;
    int indice;
    char auxCad[100];
    eMascota nuevaMascota;

    if(lista != NULL && tamMas > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0 && pId != NULL)
    {
        if( buscarMascotaLibre(lista, tamMas, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                // aca caigo cuando haya lugar

                printf("Ingrese el nombre de la mascota: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevaMascota.nombre, auxCad);

                listarTipos(tipos, tamTip);//tipos
                printf("Ingrese Id Tipo: ");
                scanf("%d", &nuevaMascota.idTipo);
                while( !validarTipos(tipos, tamTip, nuevaMascota.idTipo))
                {
                    printf("Tipo invalido.Ingrese Id sector: ");
                    scanf("%d", &nuevaMascota.idTipo);
                }

                listarColores(colores, tamCol);//colores
                printf("Ingrese Id Color: ");
                scanf("%d", &nuevaMascota.idColor);
                while( !validarColores(colores, tamCol, nuevaMascota.idColor))
                {
                    printf("Color invalido.Ingrese Id Color: ");
                    scanf("%d", &nuevaMascota.idColor);
                }

                printf("Ingrese edad: ");
                scanf("%d", &nuevaMascota.edad);

                printf("Esta vacunado? Ingrese 's' o 'n': ");
                fflush(stdin);
                scanf("%c", &nuevaMascota.vacunado);
                while(nuevaMascota.vacunado != 's' || nuevaMascota.vacunado != 'n' || nuevaMascota.vacunado != 'S' || nuevaMascota.vacunado != 'N')
                {
                    printf("error. respuesta invalida, ingrese 's' si esta vacunado o 'n' si no lo esta: ");
                    fflush(stdin);
                    scanf("%c", &nuevaMascota.vacunado);
                }


                nuevaMascota.isEmpty = 0;
                nuevaMascota.id = *pId;
                *pId = *pId + 1;
                lista[indice] = nuevaMascota;
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

int buscarMascotaLibre(eMascota lista[], int tamMas, int* pIndex)
{
    int todoOk = 0;
    if(lista != NULL && tamMas > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tamMas; i++)
        {
            if( lista[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int inicializarMascotas(eMascota lista[], int tamMas)
{
    int todoOk = 0;
    if(lista != NULL && tamMas > 0)
    {
        for(int i = 0; i < tamMas; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int modificarMascota(eMascota lista[], int tamMas, eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';
    //char auxCad[100];

    if(lista != NULL && tamMas > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0)
    {
        listarMascotas(lista, tamMas, tipos, tamTip, colores, tamCol);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( buscarMascota(lista, tamMas, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una mascota con id %d\n", id);
            }
            else
            {
                mostrarMascota(lista[indice], tipos, tamTip, colores, tamCol);


                do
                {
                    switch(menuModificarMascota())
                    {

                    case 1:
                        listarTipos(tipos, tamTip);//tipos
                        printf("Ingrese nuevo Id Tipo: ");
                        scanf("%d", &lista->idTipo);
                        while( !validarTipos(tipos, tamTip, lista->idTipo))
                        {
                            printf("Tipo invalido.Ingrese Id sector: ");
                            scanf("%d", &lista->idTipo);
                        }
                        printf("tipo modificado con exito\n");
                        break;

                    case 2:
                        printf("ingrese nueva vacuna ('s' o 'n'): ");
                        fflush(stdin);
                        scanf("%c", &lista->vacunado);
                        while(lista->vacunado != 's' || lista->vacunado != 'n' || lista->vacunado != 'S' || lista->vacunado != 'N')
                        {
                            printf("error. respuesta invalida, ingrese 's' si esta vacunado o 'n' si no lo esta: ");
                            fflush(stdin);
                            scanf("%c", &lista->vacunado);
                        }
                        printf("se ha modificado con exito\n");
                        break;

                    case 3:
                        salir = 's';
                        break;
                    }
                    system("pause");

                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int menuModificarMascota()
{
    int opcion;

    printf("     *** Campos a modificar ***\n");
    printf("1- Tipo\n");
    printf("2- Vacunado\n");
    printf("3- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int mostrarMascota(eMascota lista, eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    int todoOk = 0;
    char descTipos[20];
    char descColores[20];

    if(tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0)
    {
        cargarDescripcionTipos(tipos, tamTip, lista.idTipo, descTipos);
        cargarDescripcionColores(colores, tamCol, lista.idColor, descColores);

        printf("  %2d       %20s       %20s      %20s      %2d    %c\n",
               lista.id,
               lista.nombre,
               descTipos,
               descColores,
               lista.edad,
               lista.vacunado
              );
        todoOk = 1;
    }
    return todoOk;
}


int listarMascotas(eMascota lista[], int tamMas, eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    int todoOk = 0;
    int flag = 0;
    if(lista != NULL && tamMas > 0)
    {
        system("cls");
        printf("          *** Listado de Mascotas ***\n\n");
        printf(" ID          Nombre        tipo    Color    edad      vacuna\n");
        printf("------------------------------------------------------------------------\n");
        for(int i=0; i < tamMas; i++)
        {
            if( !lista[i].isEmpty )
            {
                mostrarMascota(lista[i], tipos, tamTip, colores, tamCol);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay mascotas en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int buscarMascota(eMascota lista[], int tamMas, int id, int* pIndex)
{
    int todoOk = 0;

    if(lista != NULL && tamMas > 0 && pIndex != NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tamMas; i++)
        {
            if( lista[i].isEmpty == 0 &&  lista[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int bajaMascota(eMascota lista[], int tamMas, eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(lista != NULL && tamMas > 0)
    {
        listarMascotas(lista, tamMas, tipos, tamTip, colores, tamCol);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( buscarMascota(lista, tamMas, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una mascota con id %d\n", id);
            }
            else
            {
                mostrarMascota(lista[indice], tipos, tamTip, colores, tamCol);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    lista[indice].isEmpty = 1;
                    printf("Baja realizada con el exito!!!\n");
                    todoOk = 1;
                }
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar mascota\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int hardcodearMascotas(eMascota lista[], int tamMas, int cant, int* pId)
{

    int todoOk = 0;
    eMascota hardcodeadas[] =
    {
        {0, "Pipo", 1000, 5000, 4, 's'},
        {0, "Morty", 1004, 5003, 1, 'n'},
        {0, "Kira", 1003, 5001, 6, 'n'},
        {0, "Haku", 1002, 5002, 2, 's'},
        {0, "Taiki", 1000, 5003, 3, 's'},
        {0, "Mora", 1005, 5001, 8, 'n'},
        {0, "Miga", 1002, 5004, 2, 's'},
        {0, "Garfield", 1004, 5000, 5, 's'},
        {0, "Ernesto", 1003, 5003, 8, 's'},
        {0, "Diente", 1003, 5002, 1, 'n'}
    };

    if(lista != NULL && tamMas > 0 && pId != NULL && cant > 0 && cant <= tamMas)
    {

        for(int i=0; i < cant; i++)
        {
            lista[i] = hardcodeadas[i];
            lista[i].id = *pId;
            *pId = *pId +1;

        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarMascotasNombreAsc(eMascota lista[], int tamMas)
{
    int todoOk = 0;
    eMascota auxMascota;
    if(lista != NULL && tamMas > 0)
    {
        for(int i=0; i < tamMas -1; i++)
        {
            for(int j= i + 1; j < tamMas; j++)
            {
                if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
                {
                    auxMascota = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxMascota;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

listarMascotasXTipoYNombre(eMascota lista[], int tamMas, eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    int todoOk = 0;
    int flag = 0;
    if(lista != NULL && tamMas > 0)
    {
        system("cls");
        printf("          *** Listado de Mascotas ***\n\n");
        printf(" ID          Nombre        tipo    Color    edad      vacuna\n");
        printf("------------------------------------------------------------------------\n");

        ordenarMascotasNombreAsc(lista, tamMas);

        for(int i=0; i < tamMas; i++)
        {
           if( !lista[i].isEmpty )
            {
                mostrarMascota(lista[i], tipos, tamTip, colores, tamCol);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay mascotas en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}



