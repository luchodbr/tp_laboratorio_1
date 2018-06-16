#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peli.h"
#include "utn.h"




EMovie* peli_new(void)
{
    EMovie* returnAux = (EMovie*) malloc(sizeof(EMovie));
    return returnAux;
}


EMovie* peli_newParameters(char* titulo, char* genero, int duracion, char* descripcion, float puntaje, char* linkImagen)
{
    EMovie* this = peli_new();
    if( !peli_setTitulo(this, titulo) &&
        !peli_setGenero(this, genero) &&
        !peli_setDuracion(this, duracion) &&
        !peli_setDescripcion(this, descripcion) &&
        !peli_setPuntaje(this, puntaje) &&
        !peli_setLinkImagen(this, linkImagen))
    {
        return this;
    }
    peli_delete(this);
    return NULL;
}


void peli_delete(EMovie* this)
{
    if(this != NULL)
        free(this);
}


int peli_save(EMovie* this)
{
    FILE *pFile;
    if((pFile=fopen("pelis.txt","ab")) != NULL && this != NULL)
    {
        fwrite(this,sizeof(EMovie),1,pFile);
        fclose(pFile);
        return 0;
    }
    return -1;
}


int peli_saveArray(EMovie** this, int cantActual)
{
    int i;
    FILE *pFile;
    if((pFile=fopen("pelis.txt","wb")) != NULL && this != NULL)
    {
        for(i=0; i<cantActual; i++)
            if(*(this+i) != NULL)
                fwrite(*(this+i),sizeof(EMovie),1,pFile);
        fclose(pFile);
        return 0;
    }
    return -1;
}


int peli_read(EMovie** this, int* cantActual, int cantMaxima)
{
    int r, i=0;
    *cantActual=0;
    FILE* pFile;
    if((pFile=fopen("pelis.txt","rb")) != NULL && this != NULL)
    {
        while(!feof(pFile))
        {
            *(this+i) = peli_new();
            r = fread(*(this+i),sizeof(EMovie),1,pFile);
            if((*cantActual) == cantMaxima || r != 1)
            {
                peli_delete(*(this+i));
                break;
            }
            (*cantActual)++;
            i++;
        }
        fclose(pFile);
        return 0;
    }
    return -1;
}


//------------------------------------------------------------------------------------------------------------


int peli_alta(EMovie** this, int* cantActual, int cantMaxima)
{
    char titulo[4096];
    char genero[4096];
    int duracion;
    char descripcion[4096];
    int puntaje;
    char linkImagen[4096];
    peli_read(this, cantActual, cantMaxima);

    if((*cantActual) < cantMaxima && this != NULL)
    {
        if( !getValidStringAlfaNumerico("\nTitulo: ","","",titulo,21,1) &&
            peli_getByTitulo(this, (*cantActual), titulo) == -1 &&
            !getValidString("\nGenero: ","","",genero,21,1) &&
            !getValidInt("\nDuracion: ","",&duracion,60,380,1) &&
            !getValidDescripcion("\nDescripcion: ","",descripcion,201,1) &&
            !getValidInt("\nPuntaje[1-10]: ","",&puntaje,1,10,1) &&
            !getValidLink("\nLink de la img: ","","",linkImagen,201,1))
        {
            *(this + (*cantActual)) = peli_newParameters(titulo,genero,duracion,descripcion,puntaje,linkImagen);
            peli_save(*(this + (*cantActual)));
            (*cantActual)++;
            printf("\nPelicula agregada\n");
            return 0;
        }
        else
        {
            printf("\nError, datos ingresados incorrectamente\n");
            return -2;
        }
    }
    printf("\nError, no hay espacio para mas peliculas\n");
    return -1;
}


int peli_mod(EMovie** this, int cantActual, char* titulo)
{
    int i;
    char pTitulo[1028];
    char pGenero[1028];
    int pDuracion;
    char pDescripcion[1028];
    int pPuntaje;
    char pLinkImagen[1028];
    if(this != NULL)
    {
        i = peli_getByTitulo(this, cantActual, titulo);
        if(i != -1)
        {
            if( !getValidStringAlfaNumerico("\nTitulo: ","","",pTitulo,21,1) &&
            peli_getByTitulo(this, cantActual, pTitulo) == -1 &&
            !getValidString("\nGenero: ","","",pGenero,21,1) &&
            !getValidInt("\nDuracion: ","",&pDuracion,60,380,1) &&
            !getValidDescripcion("\nDescripcion: ","",pDescripcion,201,1) &&
            !getValidInt("\nPuntaje[1-10]: ","",&pPuntaje,1,10,1) &&
            !getValidLink("\nLink de la img: ","","",pLinkImagen,201,1))
            {
                if( !peli_setTitulo(*(this + i), pTitulo) &&
                !peli_setGenero(*(this + i), pGenero) &&
                !peli_setDuracion(*(this + i), pDuracion) &&
                !peli_setDescripcion(*(this + i), pDescripcion) &&
                !peli_setPuntaje(*(this + i), pPuntaje) &&
                !peli_setLinkImagen(*(this + i), pLinkImagen))
                {
                    peli_saveArray(this, cantActual);
                    printf("\nPelicula modificada\n");
                    return 0;
                }
            }
            else
            {
                printf("\nError, datos ingresados incorrectamente\n");
                return -2;
            }
        }
        else
        {
            printf("\nError, pelicula no existe\n");
            return -2;
        }
    }
    return -1;
}


int peli_baja(EMovie** arrayMovie, int size, char* titulo)
{
    int retorno=-1;
    int i;
    if(arrayMovie != NULL)
    {
        i = peli_getByTitulo(arrayMovie, size, titulo);
        if(i != -1)
        {
            *(arrayMovie + i) = NULL;
            peli_saveArray(arrayMovie, size);
            retorno=0;
        }
    }
    return retorno;
}


int peli_listar(EMovie** arrayMovie, int size)
{
    int i;
    char bTitulo[1028];
    char bGenero[1028];
    int bDuracion;
    char bDescripcion[1028];
    int bPuntaje;
    char bLinkImagen[1028];
    if(arrayMovie != NULL)
    {
        for(i=0; i<size; i++)
        {
            if((*(arrayMovie+i))!=NULL &&
               !peli_getTitulo(*(arrayMovie+i),bTitulo) &&
               !peli_getGenero(*(arrayMovie+i),bGenero) &&
               !peli_getDuracion(*(arrayMovie+i),&bDuracion) &&
               !peli_getDescripcion(*(arrayMovie+i),bDescripcion) &&
               !peli_getPuntaje(*(arrayMovie+i),&bPuntaje) &&
               !peli_getLinkImagen(*(arrayMovie+i),bLinkImagen))
            {
                printf("\nTitulo: %s | Genero: %s \nDuracion: %d | Puntaje: %d \nDescripcion: %s\nLink Imagen: %s\n\n",bTitulo,bGenero,bDuracion,bPuntaje,bDescripcion,bLinkImagen);
            }
        }
        return 0;
    }
    return -1;
}


int peli_getByTitulo(EMovie** arrayMovie, int size, char* titulo)
{
    int retorno = -1;
    int i;
    char bTitulo[1028];
    if(arrayMovie != NULL)
    {
        for(i=0; i<size; i++)
        {
            if(*(arrayMovie+i) != NULL)
            {
                peli_getTitulo(*(arrayMovie+i),bTitulo);
                if(!strcmp(bTitulo,titulo))
                    retorno = i;
            }
        }
    }
    return retorno;
}


void peli_html(EMovie** arrayMovie,int size)
{
    int i;
    char bTitulo[1028];
    char bGenero[1028];
    int bDuracion;
    char bDescripcion[1028];
    int bPuntaje;
    char bLinkImagen[1028];
    FILE *peli;
    if((peli=fopen("index.html","w")) != NULL && arrayMovie != NULL)
    {
        fprintf(peli,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");
            for(i=0; i<size; i++)
            {
                if((*(arrayMovie+i))!=NULL &&
                !peli_getTitulo(*(arrayMovie+i),bTitulo) &&
                !peli_getGenero(*(arrayMovie+i),bGenero) &&
                !peli_getDuracion(*(arrayMovie+i),&bDuracion) &&
                !peli_getDescripcion(*(arrayMovie+i),bDescripcion)&&
                !peli_getPuntaje(*(arrayMovie+i),&bPuntaje) &&
                !peli_getLinkImagen(*(arrayMovie+i),bLinkImagen))
                {
                    fprintf(peli,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Género:%s</li><li>Puntaje:%d</li><li>Duración:%d</li></ul><p>%s</p></article>",bLinkImagen,bTitulo,bGenero,bPuntaje,bDuracion,bDescripcion);
                }
            }
        fprintf(peli,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
        fclose(peli);
    }
}


//------------------------------------------------------------------------------------------------------------


int peli_setTitulo(EMovie* this, char* titulo)
{
    int returnAux = -1;
    if(this != NULL && titulo != NULL && !isTitulo(titulo))
    {
        strcpy(this->titulo,titulo);
        returnAux = 0;
    }
    return returnAux;
}


int peli_getTitulo(EMovie* this, char* titulo)
{
    int returnAux = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo,this->titulo);
        returnAux = 0;
    }
    return returnAux;
}


int peli_setGenero(EMovie* this, char* genero)
{
    int returnAux = -1;
    if(this != NULL && genero != NULL && !isGenero(genero))
    {
        strcpy(this->genero,genero);
        returnAux = 0;
    }
    return returnAux;
}


int peli_getGenero(EMovie* this, char* genero)
{
    int returnAux = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero,this->genero);
        returnAux = 0;
    }
    return returnAux;
}


int peli_setDuracion(EMovie* this, int duracion)
{
    int returnAux = -1;
    if(this != NULL && !isDuracion(duracion))
    {
        this->duracion = duracion;
        returnAux = 0;
    }
    return returnAux;
}


int peli_getDuracion(EMovie* this, int* duracion)
{
    int returnAux = -1;
    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        returnAux = 0;
    }
    return returnAux;
}


int peli_setDescripcion(EMovie* this, char* descripcion)
{
    int returnAux = -1;
    if(this != NULL && descripcion != NULL && !isDescripcion(descripcion))
    {
        strcpy(this->descripcion,descripcion);
        returnAux = 0;
    }
    return returnAux;
}


int peli_getDescripcion(EMovie* this, char* descripcion)
{
    int returnAux = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(descripcion,this->descripcion);
        returnAux = 0;
    }
    return returnAux;
}


int peli_setPuntaje(EMovie* this, int puntaje)
{
    int returnAux = -1;
    if(this != NULL && !isPuntaje(puntaje))
    {
        this->puntaje = puntaje;
        returnAux = 0;
    }
    return returnAux;
}


int peli_getPuntaje(EMovie* this, int* puntaje)
{
    int returnAux = -1;
    if(this != NULL && puntaje != NULL)
    {
        *puntaje = this->puntaje;
        returnAux = 0;
    }
    return returnAux;
}


int peli_setLinkImagen(EMovie* this, char* linkImagen)
{
    int returnAux = -1;
    if(this != NULL && linkImagen != NULL && !isLinkImagen(linkImagen))
    {
        strcpy(this->linkImagen,linkImagen);
        returnAux = 0;
    }
    return returnAux;
}


int peli_getLinkImagen(EMovie* this, char* linkImagen)
{
    int returnAux = -1;
    if(this != NULL && linkImagen != NULL)
    {
        strcpy(linkImagen,this->linkImagen);
        returnAux = 0;
    }
    return returnAux;
}


//------------------------------------------------------------------------------------------------------------


int isTitulo(char* titulo)
{
    int i = 0;
    if(strlen(titulo) < 21)
    {
        while(titulo[i] != '\0')
        {
            if((titulo[i] == ',') || (titulo[i] == '.'))
                return -1;
            i++;
        }
    }
    return 0;
}


 int isGenero(char* genero)
{
    int i = 0;
    if(strlen(genero) < 21)
    {
        while(genero[i] != '\0')
        {
            if((genero[i] != ' ') && (genero[i] < 'a' || genero[i] > 'z') && (genero[i] < 'A' || genero[i] > 'Z'))
                return -1;
            i++;
        }
    }
    return 0;
}


 int isDuracion(int duracion)
{
    if(duracion < 60 || duracion > 380)
    {
        return -1;
    }
        return 0;
}


 int isDescripcion(char* descripcion)
{
    if(strlen(descripcion) > 201)
    {
    return -1;
    }
    return 0;
}


 int isPuntaje(int puntaje)
{
    if(puntaje < 0 || puntaje > 10.0)
       {
           return -1;
       }
    return 0;
}


 int isLinkImagen(char* linkImagen)
{
    int i = 0;
    if(strlen(linkImagen) < 201)
    {
        while(linkImagen[i] != '\0')
        {
            if(linkImagen[i] == ' ')
                return -1;
            i++;
        }
    }
    return 0;
}


