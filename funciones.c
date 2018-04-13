#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
 /** \brief toma un entero y valida que este entre el rango minimo y maximo, devuelve verdadero o falso
  *
  * \param
  * \param
  * \return
  *
  */
 int getInt(char* mensaje,
               char* mensajeError,
               int reintentos,
               int minimo,
               int maximo,
               int* resultado)
    {
        int retorno=-1;
        long auxiliar;
        do
        {
            reintentos--;
            printf("%s" ,mensaje);
            scanf("%ld" ,&auxiliar);
            if(auxiliar>=minimo && auxiliar<=maximo)
            {
                retorno=0;
                *resultado = (int) auxiliar;
                break;
            }

            printf("%s" ,mensajeError);
            }while(reintentos >= 0);
             return retorno;
    }

    int getChar(char* mensaje,
               char* mensajeError,
               int reintentos,
               char minimo,
               char maximo,
               char* resultado)
    {
        int retorno=-1;
        char auxiliar;
        do
        {
            reintentos--;
            printf("%s" ,mensaje);
            fflush(stdin);
            scanf("%c" ,&auxiliar);
            if(auxiliar>=49 && auxiliar<=57)
            {
                retorno=0;
                *resultado = auxiliar;
                break;
            }

            printf("%s" ,mensajeError);
            }while(reintentos >= 0);
             return retorno;
    }

    int getFloat(char* mensaje,
               char* mensajeError,
               int reintentos,
               float minimo,
               float maximo,
               float* resultado)
    {
        int retorno=-1;
        double auxiliar;
        do
        {
            reintentos--;
            printf("%s" ,mensaje);
            scanf("%lf" ,&auxiliar);
            if(auxiliar>=minimo && auxiliar<=maximo)
            {
                retorno=0;
                *resultado = (float) auxiliar;
                break;
            }

            printf("%s" ,mensajeError);
            }while(reintentos >= 0);
             return retorno;
    }

/** \brief toma dos enteros y los suma, devuelve por puntero un resultado y retorno 1, o -1 si algo fallo.
 *
 * \param
 * \param
 * \return
 *
 */
int sumaEnteros (int numeroUno, int numeroDos, float* resultado)
    {
    long resultadoCalculo;
    int retorno= -1;
    resultadoCalculo=numeroUno+numeroDos;
    if(resultadoCalculo < 32767)
    {
        *resultado = resultadoCalculo;
        retorno= 0;
    }
    return retorno;
    }


    /** \brief toma dos enteros y los resta, devuelve por puntero un resultado y retorno 1, o -1 si algo fallo.
     *
     * \param numeroUno int
     * \param numeroDos int
     * \param resultado float*  donde se guardara el resultado de la resta
     * \return int
     *
     */
    int restaEnteros(int numeroUno, int numeroDos, float* resultado)
    {
    long resultadoCalculo;
    int retorno= -1;
    resultadoCalculo=numeroUno-numeroDos;

    if(resultadoCalculo < 32767)
    {
        *resultado=resultadoCalculo;
        retorno=0;
    }
    return retorno;
    }


     /** \brief toma dos enteros y los multiplica, devuelve por puntero un resultado y retorno 1, o -1 si algo fallo.
      *
      * \param numeroUno int
      * \param numeroDos int
      * \param resultado float* donde se guardara el resultado de la multiplicacion.
      * \return int
      *
      */
     int multiplicaEnteros(int numeroUno, int numeroDos, float* resultado)
    {
    long resultadoCalculo;
    int retorno= -1;

    resultadoCalculo=numeroUno*numeroDos;
    if(resultadoCalculo < 32767)
    {
        *resultado=resultadoCalculo;
        retorno=0;
    }
    return retorno;
    }


    /** \brief toma dos enteros y los divide, devuelve por puntero un resultado y retorno 1, o -1 si algo fallo.
     *
     * \param numeroUno int
     * \param numeroDos int
     * \param resultado float*  donde se guardara el resultado de la division.
     * \return int
     *
     */
    int divideEnteros(int numeroUno, int numeroDos, float* resultado)
    {
    float resultadoCalculo;
    int retorno=-1;
    resultadoCalculo=(float)numeroUno/numeroDos;
    if(resultadoCalculo < 32767 && numeroDos!=0)
    {
        *resultado=resultadoCalculo;
        retorno= 0;
    }

    return retorno;
    }

    /** \brief toma un entero, y multiplica a todos los enteros menos a ese, hasta el 1.
     *
     * \param numero int
     * \param resultado float*  donde se guardara el resultado de esta multiplicacion
     * \return int
     *
     */
    int factorial(int numero, float* resultado)
    {
        int retorno=-1;
        long auxiliarResultado;
        auxiliarResultado=numero;
        while(numero>1)
        {
            numero--;
            auxiliarResultado= auxiliarResultado*numero;
        }
        if(auxiliarResultado>=1 && auxiliarResultado<2147483647)
        {
            *resultado=auxiliarResultado;
            retorno=0;
        }
        return retorno;
    }
