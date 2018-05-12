
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona* lista, int limite);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona* lista,int limite,int dni);


/** \brief Inicializa la estructura
 *
 * \param lista EPersona* reprensenta la estructura de una persona
 * \param limite int cantidad maxima de personas que puede haber
 * \return int
 *
 */
int persona_init(EPersona* lista,int limite);


/** \brief da de alta una persona ingresando sus datos
 *
 * \param lista EPersona* reprensenta la estructura de una persona
 * \param limite int    cantidad maxima de personas que puede haber
 * \return int
 *
 */
int persona_alta(EPersona* lista,int limite);


/** \brief da de baja una persona ingresando su dni
 *
 * \param lista EPersona*   reprensenta la estructura de una persona
 * \param limite int    cantidad maxima de personas que puede haber
 * \param dni int    el id de la persona que desea borrar
 * \return int
 *
 */
int persona_baja(EPersona* lista,int limite, int dni);


/** \brief ordena el array de personas por nombre
 *
 * \param lista EPersona* reprensenta la estructura de una persona
 * \param limite int    cantidad maxima de personas que puede haber
 * \param orden int ordena alfabeticamente ascendente si es 1 y descendente si es 0
 * \return int
 *
 */
int persona_ordenar(EPersona* lista,int limite,int orden);


/** \brief muestra el array de personas
 *
 * \param lista EPersona*   reprensenta la estructura de una persona
 * \param limite int    cantidad maxima de personas que puede haber
 * \return int
 *
 */
int persona_mostrar(EPersona* lista,int limite);


/** \brief imprime un grafico que muestra la cantidad de personas con determinado parametro de edad
 *
 * \param persona EPersona* reprensenta la estructura de una persona
 * \param limite int    cantidad maxima de personas que puede haber
 * \return int
 *
 */
int imprimir_grafico(EPersona* persona, int limite);

#endif // FUNCIONES_H_INCLUDED

