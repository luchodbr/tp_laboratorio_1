#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED


typedef struct{
    char titulo[21];
    char genero[21];
    int duracion;
    char descripcion[201];
    int puntaje;
    char linkImagen[201];
}EMovie;


/** \brief Aloca una nueva arrayList en la cantidad actual de peliculas
 * \param void
 * \return EMovie* Retorna NULL si hubo error, retorna puntero a la nueva arrayList  si no hay problemas
 *
 */
EMovie* peli_new(void);

/** \brief Aloca una nueva arrayList en la cantidad actual de peliculas
 * \param titulo Es el titulo de la pelicula a setear
 * \param genero Es el genero de la pelicula a setear
 * \param duracion Es la duracion de la pelicula a setear
 * \param descripcion Es la descripcion de la pelicula a setear
 * \param puntaje Es el puntaje de la pelicula a setear
 * \param linkImagen Es el link de la imagen de la pelicula a setear
 * \return EMovie* Retorna NULL si hubo error, retorna puntero a la nueva arrayList si no hay problemas
 */
EMovie* peli_newParameters(char* titulo, char* genero, int duracion, char* descripcion, float puntaje, char* linkImagen);

/** \brief Libera un espacio de memoria
 * \param this Puntero al espacio de memoria que se desea eliminar
 * \return Retorna [-1] si hubo error, retorna [0] si no hay problemas
 */
void peli_delete(EMovie* this);

/** \brief Escribe en un archivo una pelicula
 * \param this Puntero al espacio de memoria en el que se almacena la pelicula
 * \return Retorna [-1] si hubo error, retorna [0] si no hay problemas
 */
int peli_save(EMovie* this);

/** \brief Escribe en un archivo un arrayList de peliculas
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacena las peliculas
 * \param cantActual Cantidad actual de peliculas
 * \return Retorna [-1] si hubo error, retorna [0] si no hay problemas
 */
int peli_saveArray(EMovie** this, int cantActual);

/** \brief Lee de un archivo un arrayList de peliculas
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantActual Cantidad actual de peliculas
 * \param cantMaxima Cantidad maxima de peliculas a agregar
 * \return Retorna [-1] si hubo error, retorna [0] si no hay problemas
 */
int peli_read(EMovie** this, int* cantActual, int cantMaxima);

/** \brief Da de alta a una pelicula
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantActual Cantidad actual de peliculas
 * \param cantMaxima Cantidad maxima de peliculas a agregar
 * \return Retorna [-2] Datos ingresados incorrectamente,[-1] No hay espacio para mas peliculas,[0] si no hay problemas
 */
int peli_alta(EMovie** this, int* cantActual, int cantMaxima);

/** \brief Modifica una pelicula
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantActual Cantidad actual de peliculas
 * \param titulo Titulo dela pelicula a modificar
 * \return Retorna [-2] Datos ingresados incorrectamente,[-1] El titulo de la pelicula no existe,[0] si no hay problemas
 */
int peli_mod(EMovie** this, int cantActual, char* titulo);

/** \brief Da de baja una pelicula
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantActual Cantidad actual de peliculas
 * \param titulo Titulo dela pelicula a eliminar
 * \return Retorna [-2] El titulo de la pelicula no existe,[-1] ERROR,[0] si no hay problemas
 */
int peli_baja(EMovie** this, int cantActual, char* titulo);

/** \brief Lista por consola las peliculas
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantActual Cantidad actual de peliculas
 * \return Retorna [-1] ERROR,[0] si no hay problemas
 */
int peli_listar(EMovie** this, int cantActual);

/** \brief Obtiene elindice de la posicion de una pelicula por su titulo
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantActual Cantidad actual de peliculas
 * \param titulo Titulo dela pelicula a buscar
 * \return Retorna [-1] ERROR, [Mayor a -1] indice de la posicion de la pelicula
 */
int peli_getByTitulo(EMovie** this, int cantActual, char* titulo);

/** \brief Genera un index.html donde mostrara las peliculas cargadas
 * \param this Puntero al espacio de memoria del arrayLits en el que se almacenaran las peliculas
 * \param cantActual Cantidad actual de peliculas
 * \return Retorna [-1] ERROR,[0] si no hay problemas
 */
void peli_html(EMovie** arrayMovie,int size);


/** \brief Setea el titulo de una pelicula
 * \param this Puntero al espacio de memoria en el que se almacenara la pelicula
 * \param titulo Titulo de la pelicula a guardar
 * \return Retorna [-1] ERROR,[0] si no hay problemas
 */
int peli_setTitulo(EMovie* this, char* titulo);
/** \brief Devuelve el titulo de una pelicula
 * \param this Puntero al espacio de memoria de la pelicula
 * \param titulo Titulo que devolvera de la pelicula
 * \return Retorna [-1] ERROR,[0] si no hay problemas
 */
int peli_getTitulo(EMovie* this, char* titulo);
int peli_setGenero(EMovie* this, char* genero);
int peli_getGenero(EMovie* this, char* genero);
int peli_setDuracion(EMovie* this, int duracion);
int peli_getDuracion(EMovie* this, int* duracion);
int peli_setDescripcion(EMovie* this, char* descripcion);
int peli_getDescripcion(EMovie* this, char* descripcion);
int peli_setPuntaje(EMovie* this, int puntaje);
int peli_getPuntaje(EMovie* this, int* puntaje);
int peli_setLinkImagen(EMovie* this, char* linkImagen);
int peli_getLinkImagen(EMovie* this, char* linkImagen);

 int isTitulo(char* titulo);
 int isGenero(char* genero);
 int isDuracion(int duracion);
 int isDescripcion(char* descripcion);
 int isPuntaje(int puntaje);
 int isLinkImagen(char* linkImagen);

#endif // MOVIE_H_INCLUDED
