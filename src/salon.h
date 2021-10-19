/*
 * salon.h
 *
 *  Created on: 18 oct. 2021
 *      Author: MariaElena
 */

#ifndef SALON_H_
#define SALON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ingresos.h"
#include "salon.h"
#include "arcade.h"

/*
 * 1) ALTA DE SALÓN
Se deberá dar de alta un salón con los siguientes datos: Nombre, dirección y tipo.
Se generará un ID único para gestionar los SALONES.
Este salón se imprimirá por pantalla si el alta es correcta
 */
int contadorIdSalones=0;
typedef struct {

	char  nombre[128];//PK
	char direccion[130];
	char tipo[10];
	int id;
	int isEmpty=1;


}eSalon[100];


#endif /* SALON_H_ */
