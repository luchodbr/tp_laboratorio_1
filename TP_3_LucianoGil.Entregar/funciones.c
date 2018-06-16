#include "funciones.h"
#include <string.h>
#include <stdlib.h>
static int isValidTitulo(char* titulo);
static int isValidGenero(char* genero);
static int isValidDuracion(int duracion);
static int isValidDescripcion(char* descripcion);
static int isValidPuntaje(int puntaje);
static int isValidLink(char* link);

int movie_setTitulo(EMovie* this, char* titulo){
    int retorno = -1;
    if(this != NULL && titulo != NULL && isValidTitulo(titulo)){
        retorno = 0;
        strcpy(this->titulo, titulo);

    }
    return retorno;
}
static int isValidTitulo(char* titulo)
{
    if(esAlfaNumerico(titulo))
            return 1;

    return 0;

}

int movie_getTitulo(EMovie* this, char* titulo){
    int retorno = -1;
    if(this != NULL && titulo != NULL){
        retorno = 0;
        strcpy(titulo, this->titulo);

    }
    return retorno;
}

int movie_setGenero(EMovie* this, char* genero){
    int retorno = -1;
    if(this != NULL && genero != NULL && isValidGenero(genero)){
        retorno = 0;
        strcpy(this->genero, genero);

    }
    return retorno;
}
static int isValidGenero(char* genero)
{
    if(esSoloLetras(genero))
        return 1;

    return 0;
}

int movie_getGenero(EMovie* this, char* genero){
    int retorno = -1;
    if(this != NULL && genero != NULL){
        retorno = 0;
        strcpy(genero, this->genero);

    }
    return retorno;
}

int movie_getDuracion(EMovie* this, int* duracion)
{
    int retorno = -1;
    if(this !=NULL && duracion !=NULL){
        retorno = 0;
        *duracion = this->duracion;
    }
    return retorno;
}

int movie_setDuracion(EMovie* this, int duracion)
{
    int retorno = -1;
    if(this !=NULL && isValidDuracion(duracion)){
        retorno = 0;
        this->duracion = duracion;
    }
    return retorno;
}

static int isValidDuracion(int duracion)
{
    return 1;
}

int movie_setDescripcion(EMovie* this, char* descripcion){
    int retorno = -1;
    if(this != NULL && descripcion != NULL && isValidDescripcion(descripcion)){
        retorno = 0;
        strcpy(this->descripcion, descripcion);

    }
    return retorno;
}
static int isValidDescripcion(char* descripcion)
{
    return 1;
}

int movie_getDescripcion(EMovie* this, char* descripcion){
    int retorno = -1;
    if(this != NULL && descripcion != NULL){
        retorno = 0;
        strcpy(descripcion, this->descripcion);

    }
    return retorno;
}

int movie_getPuntaje(EMovie* this, int* puntaje)
{
    int retorno = -1;
    if(this !=NULL && puntaje !=NULL){
        retorno = 0;
        *puntaje = this->puntaje;
    }
    return retorno;
}

int movie_setPuntaje(EMovie* this, int puntaje)
{
    int retorno = -1;
    if(this !=NULL && isValidPuntaje(puntaje)){
        retorno = 0;
        this->puntaje = puntaje;
    }
    return retorno;
}

static int isValidPuntaje(int puntaje)
{
    return 1;
}


int movie_setLink(EMovie* this, char* link){
    int retorno = -1;
    if(this != NULL && link != NULL && isValidLink(link)){
        retorno = 0;
        strcpy(this->linkImagen, link);

    }
    return retorno;
}
static int isValidLink(char* link)
{
    return 1;
}

int movie_getLink(EMovie* this, char* link){
    int retorno = -1;
    if(this != NULL && link != NULL){
        retorno = 0;
        strcpy(link, this->linkImagen);

    }
    return retorno;
}
EMovie* emovie_newParametros(char* strTitulo, char* strGenero, char* strDuracion, char* strDescripcion
                             , char* strPuntaje, char* strLinkImagen)
{
    //validar que todos los punteros no sean null

    EMovie* this = NULL;
    int duracion;
    int puntaje;

    duracion = atoi(strDuracion); //falta validar
    puntaje = atoi(strPuntaje);
    this = movie_new();

    //resto de los setters (name, lastname, isempty)
    if(!movie_setTitulo(this, strTitulo) &&
       !movie_setDescripcion(this, strDescripcion) &&
       !movie_setDuracion(this, duracion) &&
       !movie_setPuntaje(this,puntaje) && !movie_setLink(this, strLinkImagen)){
        return this;
    }
    movie_delete(this);
    return NULL;
}

EMovie* movie_new(void)
{

    EMovie* returnAux = (EMovie*) malloc(sizeof(EMovie));

    return returnAux;

}
void movie_delete(EMovie* this)
{
    if(this != NULL) free(this);
}
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
