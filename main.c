#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    char opcion;
    float resultado;
    int numeroUno;
    int numeroDos;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

         fflush(stdin);
        getChar("\nIngrese el numero de la operacion que desear realizar\n","no es un numero valido",5,'49','57',&opcion);

      //  scanf("%c",&opcion);

        switch(opcion)
        {
            case '1':
                if(!getInt("Ingrese el primer numero\n", "El numero ingresado es incorrecto", 0,-32768,32767,&numeroUno))
                    printf("El numero ingresado es %d\n\n",numeroUno);
                break;
            case '2':
                 if(!getInt("Ingrese el segundo numero\n", "El numero ingresado es incorrecto", 5,-32768,32767,&numeroDos))
                    {
                        printf("El numero ingresado es %d \n\n",numeroDos);
                    }
                break;
            case '3':
                 if(!sumaEnteros(numeroUno ,numeroDos ,&resultado))
                {
                    printf("El resultado de la suma es: %.2f \n" ,resultado);
                }
                else
                {
                    printf("Error en el calculo \n");
                }
                break;
            case '4':
                if(!restaEnteros(numeroUno,numeroDos,&resultado))
                {
                    printf("El resultado en la resta es: %.2f \n" ,resultado);

                }
                else
                {
                    printf("Error en el calculo \n");
                }
                break;
            case '5':
                if(!divideEnteros((float)numeroUno,numeroDos, &resultado))
                {
                    printf("El resultado de la division es: %.2f \n" ,resultado);
                }
                else
                {
                    printf("Error en el calculo \n");
                }
                break;
            case '6':
               if(!multiplicaEnteros(numeroUno,numeroDos, &resultado))
                {
                    printf("El resultado de la multiplicacion es: %.2f \n" ,resultado);
                }
                else
                {
                    printf("Error en el calculo \n");
                }
                break;
            case '7':
                if(!factorial(numeroUno,&resultado))
                {
                    printf("El resultado del factorial es %.2f \n",resultado);
                }
                else
                {
                    printf("Error en el calculo \n");
                }
                break;
            case '8':
                 if(!sumaEnteros(numeroUno ,numeroDos ,&resultado))
                {
                    printf("El resultado de la suma es: %.2f \n" ,resultado);
                }
                else
                {
                    printf("Error en el calculo de la suma \n");
                }

                if(!restaEnteros(numeroUno,numeroDos,&resultado))
                {
                    printf("El resultado de la resta es: %.2f \n" ,resultado);

                }
                else
                {
                    printf("Error en el calculo de la resta \n");
                }
                if(!divideEnteros((float)numeroUno,numeroDos, &resultado))
                {
                    printf("El resultado de la division es: %.2f \n" ,resultado);
                }
                else
                {
                    printf("Error en el calculo de la division \n");
                }
                 if(!multiplicaEnteros(numeroUno,numeroDos, &resultado))
                {
                    printf("El resultado de la multiplicacion es : %.2f \n" ,resultado);
                }
                else
                {
                    printf("Error en el calculo de la multiplicacion \n");
                }
                 if(!factorial(numeroUno,&resultado))
                {
                    printf("El resultado del factorial es: %.2f \n",resultado);
                }
                else
                {
                    printf("Error en el calculo del factorial \n");
                }
                break;
            case '9':
                seguir = 'n';
                break;
        }
    }


    return 0;
}
