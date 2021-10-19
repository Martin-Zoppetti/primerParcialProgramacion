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
 * 1) ALTA DE SAL�N
Se deber� dar de alta un sal�n con los siguientes datos: Nombre, direcci�n y tipo.
Se generar� un ID �nico para gestionar los SALONES.
Este sal�n se imprimir� por pantalla si el alta es correcta
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