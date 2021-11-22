/*
 * arcade.h
 *
 *  Created on: 21 nov. 2021
 *      Author: MariaElena
 */

#ifndef ARCADE_H_
#define ARCADE_H_
#define nombreMaximoArcade 63
#include "LinkedList.h"
#define TRUE 1
#define FALSE 0
#define opcionMinima 1
#define opcionMaxima 10
#define Reintentos 5
/*
 * con la nacionalidad,
 *  tipo de sonido,
 *   cantidad de jugadores,
 *    capacidad máxima de fichas,
 *     Nombre del salón al que pertenece
 *      y  nombre  del juego que contiene (hasta 63 caracteres).
 *       Se generará un ID único para gestionar los ARCADE
 */

typedef struct {
	char nacionalidad[nombreMaximoArcade];
	int tipoDeSonido;
	int idArcade;
	char nombreDelSalon[nombreMaximoArcade];
	int cantidadDeJugadores;
	int cantidadMaximaDeFichas;
	char nombreDelJuego[nombreMaximoArcade];


}eArcade;

eArcade* eArcade_new();
void eArcade_delete(eArcade* this);

eArcade* eArcade_newParametros(int* tipoDeSonidoStr,int* idArcadeStr, int* cantidadDeJugadoresStr,int cantidadMaximaDeFichasStr,char* nombreDeSalonStr,char* nacionalidadStr, char* nombreDelJuegoStr);

int eArcade_setId(eArcade* this,int id);
int eArcade_getId(eArcade* this,int* id);

int eArcade_setTipoDeSonido(eArcade* this,int id);
int eArcade_getTipoDeSonido(eArcade* this,int* id);

int eArcade_setCantidadDeJugadores(eArcade* this,int id);
int eArcade_getCantidadDeJugadores(eArcade* this,int* id);

int eArcade_setCantidadMaximaDeFichas(eArcade* this,int id);
int eArcade_getCantidadMaximaDeFichas(eArcade* this,int* id);

int eArcade_setNacionalidad(eArcade* this,char* Nacionalidad);
int eArcade_getNacionalidad(eArcade* this,char* Nacionalidad);

int eArcade_setNombreDelSalon(eArcade* this,char* nombreDelSalon);
int eArcade_get(eArcade* this,char* NombreDelSalon );

int eArcade_setNombreDelJuego(eArcade* this,char* nombreDelJuego);
int eArcade_getNombreDelJuego(eArcade* this,char* NombreDelJuego);

int eArcade_findById(LinkedList *pArrayListArcade,int id);


#endif /* ARCADE_H_ */
