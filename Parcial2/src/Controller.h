#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arcade.h"



/** \brief La función se encarga de comparar los datos recibidos por parámetro.
 *
 * \param pFirstArcade puntero a los datos de un Arcade
 * \param pSecondArcade puntero a los datos de un Arcade
 * \return int Devuelve TRUE si se debe hacer un swap o FALSE si sucede lo contrario.
 *
 */
int compareArcades(eArcade* pFirstArcade,eArcade* pSecondArcade,int orden);
/** \brief La función se encarga de contar la cantidad de datos en los archivos para llevar un control de cual es la última ID registrada.
 *
 * \param pArrayListeArcade lista de punteros
 * \return int Devuelve el contador de datos registrados en el archivo.
 *
 */

int controller_dataCount(LinkedList* pArrayListeArcade);

/** \brief La función se encarga de desplegar y utilizar un menú de modificaciones para los datos del empleado.
 *
 * \param respuestaUsuario contiene la respuesta ingresada por el usuario para usarla en el switch.
 * \param ArcadeMod puntero con la dirección de memoria a los datos que queremos modificar.
 * \return int Retorna true si los parámetros son correctos o false en caso contrario.
 *
 */

int controller_modMenu(int respuestaUsuario,eArcade* eArcadeMod);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListeArcade);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListeArcade);
/** \brief Alta de arcades
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_addArcade(LinkedList* pArrayListeArcade);
/** \brief Modificar datos de arcade
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_editArcade(LinkedList* pArrayListeArcade);
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_removeArcade(LinkedList* pArrayListeArcade);
/** \brief Listar arcades
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_ListArcade(LinkedList* pArrayListeArcade);
/** \brief Ordenar arcades
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */

int controller_sortArcade(LinkedList* pArrayListeArcade);

/** \brief Guarda los datos de los arcade en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListeArcade);
int controller_saveAsBinary(char* path , LinkedList* pArrayListeArcade);
