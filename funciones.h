#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int sumaEnteros (int numeroUno, int numeroDos, float* resultado);
int restaEnteros(int numeroUno, int numeroDos, float* resultado);
int multiplicaEnteros(int numeroUno, int numeroDos, float* resultado);
int divideEnteros(int numeroUno, int numeroDos, float* resultado);
int factorial(int numero, float* resultado);
 int getFloat(char* mensaje,
               char* mensajeError,
               int reintentos,
               float minimo,
               float maximo,
               float* resultado);

 int getChar(char* mensaje,
               char* mensajeError,
               int reintentos,
               char minimo,
               char maximo,
               char* resultado);

int getInt(char* mensaje,
               char* mensajeError,
               int reintentos,
               int minimo,
               int maximo,
               int* resultado);

#endif // FUNCIONES_H_INCLUDED
