#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT_PERSONAS 20
#include "utn.h"

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona lista[CANT_PERSONAS];
    persona_init(lista,CANT_PERSONAS);
    int auxDni;

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                persona_alta(lista,CANT_PERSONAS);
                break;
            case 2:
                getValidInt("Ingrese dni","error",&auxDni,1,99999999,2);
                persona_baja(lista,CANT_PERSONAS,auxDni);
                break;
            case 3:
                persona_ordenar(lista,CANT_PERSONAS,1);
                persona_mostrar(lista,CANT_PERSONAS);
                break;
            case 4:
                imprimir_grafico(lista,CANT_PERSONAS);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
