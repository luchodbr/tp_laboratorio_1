#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
int obtenerEspacioLibre(EPersona* lista, int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(lista[i].estado==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int persona_init(EPersona* lista,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            lista[i].estado=1;
        }
    }
    return retorno;
}
int persona_alta(EPersona* lista,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    int edad;
    int dni;

    if(limite > 0 && lista != NULL)
    {
        i = obtenerEspacioLibre(lista,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidInt("\nedad? ","\n eso no es una edad",&edad,1,200,2))
                {
                     if(!getValidInt("\ndni? ","\n eso no es un dni",&dni,1,99999999,2))


                            retorno = 0;
                            strcpy(lista[i].nombre,nombre);
                            lista[i].edad=edad;
                            lista[i].dni=dni;

                            //------------------------------
                            //------------------------------
                            lista[i].estado = 0;


                }
            }
            else
            {
                retorno = -3;
            }
        }


    }
    return retorno;
}
int buscarPorDni(EPersona* lista,int limite,int dni)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!lista[i].estado && lista[i].dni==dni)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int persona_baja(EPersona* lista,int limite, int dni)
{
    int retorno = -1;
    int posBaja;
    if(limite > 0 && lista != NULL)
    {
        retorno = -2;
       posBaja=buscarPorDni(lista,limite,dni);
            if(!lista[posBaja].estado && lista[posBaja].dni==dni)
            {
                lista[posBaja].estado = 1;
                retorno = 0;
            }

    }
    return retorno;
}
int persona_ordenar(EPersona* lista,int limite,int orden)
{
int retorno = -1;
    int i;
    int flagSwap;
    EPersona auxiliarEstructura;

    if(limite > 0 && lista != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!lista[i].estado && !lista[i+1].estado)
                {
                    if((strcmp(lista[i].nombre,lista[i+1].nombre) > 0 && orden) || (strcmp(lista[i].nombre,lista[i+1].nombre) < 0 && !orden))
                    {
                        auxiliarEstructura = lista[i];
                        lista[i] = lista[i+1];
                        lista[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}
int persona_mostrar(EPersona* lista,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!lista[i].estado)
                printf("[RELEASE] -Nombre %s -Edad %d -Dni %d -EstaVacio %d\n",lista[i].nombre, lista[i].edad, lista[i].dni, lista[i].estado);
        }
    }
    return retorno;
}
int imprimir_grafico(EPersona* lista, int limite)
{

    int retorno = -1;
    int i;
    int j;
    int contadorMenores= 0;
    int contadorIntermedio= 0;
    int contadorMayores= 0;
    int maximoAsterisco= 0;

    int imprimirPosiciones[3];

    if (limite>0 && lista !=NULL)
    {
        for (i=0;i<limite;i++)
        {
            if (!lista[i].estado)
            {
                if(lista[i].edad>0 && lista[i].edad<=18)
                    contadorMenores++;

                else if(lista[i].edad>18 && lista[i].edad<=35)
                    contadorIntermedio++;

                else
                    contadorMayores++;
            }

        }
    }

    imprimirPosiciones[0]=contadorMenores;
    imprimirPosiciones[1]=contadorIntermedio;
    imprimirPosiciones[2]=contadorMayores;

    for (i=0;i<3;i++)
    {

        if (imprimirPosiciones[i]>maximoAsterisco)
            maximoAsterisco = imprimirPosiciones[i];

    }
    for (i=maximoAsterisco;i>0;i--)
    {
        for (j=0;j<3;j++)
        {
            if(i<=imprimirPosiciones[j])
                printf(" *   ");

            else
                printf("     ");
        }
        printf("\n");
    }

    printf("<18 18-35 >35\n\n");
    return retorno =0;
}
