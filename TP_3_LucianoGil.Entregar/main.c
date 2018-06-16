#include <stdio.h>
#include <stdlib.h>
#include "peli.h"
#include "utn.h"

#define CANT_MAXIMA 100


int main()
{
    int opcion=0;
    char auxTit[4096];
    int cantActual=0;
    EMovie* arrayMovie[CANT_MAXIMA];

    do
    {
        printf("1 Agregar pelicula\n");
        printf("2 Borrar pelicula\n");
        printf("3 Modificar pelicula\n");
        printf("4 Generar pagina web\n");
        printf("5 Salir\n");

        getValidInt("\nOpcion: ","\nNo es una opcion\n",&opcion,1,5,1);

        switch(opcion)
        {
            case 1:
                peli_alta(arrayMovie, &cantActual, CANT_MAXIMA);
                break;
            case 2:
                    peli_read(arrayMovie, &cantActual, CANT_MAXIMA);
                    peli_listar(arrayMovie, cantActual);
                    if(!getValidStringAlfaNumerico("\nTitulo: ","","",auxTit,21,1))
                        peli_baja(arrayMovie, cantActual, auxTit);
                break;
            case 3:
                    peli_read(arrayMovie, &cantActual, CANT_MAXIMA);
                    peli_listar(arrayMovie, cantActual);
                    if(!getValidStringAlfaNumerico("\nTitulo: ","","",auxTit,21,1))
                        peli_mod(arrayMovie, cantActual, auxTit);
               break;
            case 4:
                    peli_read(arrayMovie, &cantActual, CANT_MAXIMA);
                    peli_html(arrayMovie, cantActual);
                break;
        }
    }while(opcion != 5);
    return 0;
}
