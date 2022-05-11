#include <stdio.h>
#include <stdlib.h>

#include "mascota.h"
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

#define TAM 10
#define TAMT 5
#define TAMC 5
#define TAMS 3
#define TAMTRA 50

int menu();

int main()
{
    char salir = 'n';
    int proximaId = 10;
    int proximaIdTrabajo = 8000;
    eMascota lista[TAM];
    eTrabajo trabajos[TAMTRA];

    eTipo tipos[TAMT] =
    {
        {1000, "Ave"},
        {1001, "Perro"},
        {1002, "Roedor"},
        {1003, "Gato"},
        {1004, "Pez"},
    };

    eColor colores[TAMC] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Rojo"},
        {5003, "Gris"},
        {5004, "Azul"},
    };

    eServicio servicios[TAMS] =
    {
        {20000, "Corte", 450},
        {20001, "Desparasitado", 800},
        {20002, "Castrado", 600},
    };


    inicializarMascotas(lista, TAM);
    inicializarTrabajos(trabajos, TAMTRA);

    hardcodearMascotas(lista, TAM, 10, &proximaId);

    do
    {
        switch(menu())
        {

        case 'A':
            if( altaMascota(lista, TAM, tipos, TAMT, colores, TAMC, &proximaId))
            {
                printf("Mascota agregada con exito!!!\n");
            }
            else
            {
                printf("Problema al hacer el alta de mascota\n");
            }

            break;
        case 'B':
            if( modificarMascota(lista, TAM, tipos, TAMT, colores, TAMC) == 0)
            {
                printf("Problema al hacer la modificacion de mascota\n");
            }
            break;
        case 'C':
            if( bajaMascota(lista, TAM, tipos, TAMT, colores, TAMC) == 0)
            {
                printf("Problema al hacer la baja de mascota\n");
            }
            break;
        case 'D':
            listarMascotas(lista, TAM, tipos, TAMT, colores, TAMC);
            break;
        case 'E':
            listarTipos(tipos, TAMT);
            break;
        case 'F':
            listarColores(colores, TAMC);
            break;
        case 'G':
            listarServicios(servicios, TAMS);
            break;
        case 'H':
            if(altaTrabajo(trabajos, TAMTRA, lista, TAM, tipos, TAMT, colores, TAMC, servicios, TAMS, &proximaIdTrabajo))
            {
                printf("Trabajo agregado con exito!!!\n");
            }
            else
            {
                printf("Problema al hacer el alta de trabajo\n");
            }
            break;
        case 'I':
            listarTrabajos(trabajos, TAMTRA, lista, TAM, tipos, TAMT, colores, TAMC, servicios, TAMS);
            break;
        case 'J':
            salir = 's';
            break;
        }
        system("pause");

    }
    while(salir != 's');





    return 0;
}


int menu()
{
    char opcion;

    system("cls");
    printf("----------------------------------------\n");
    printf("|        *** ABM VETERINARIA ***       |\n");
    printf("|                                      |\n");
    printf("|  A) ALTA MASCOTA                     |\n");
    printf("|  B) MODIFICAR MASCOTA                |\n");
    printf("|  C) BAJA MASCOTA                     |\n");
    printf("|  D) LISTAR MASCOTAS                  |\n");
    printf("|  E) LISTAR TIPOS                     |\n");
    printf("|  F) LISTAR COLORES                   |\n");
    printf("|  G) LISTAR SERVICIOS                 |\n");
    printf("|  H) ALTA TRABAJO                     |\n");
    printf("|  I) LISTAR TRABAJOS                  |\n");
    printf("|  J) SALIR                            |\n");
    printf("----------------------------------------\n");
    printf("Ingrese opcion (solo mayuscula): ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}
