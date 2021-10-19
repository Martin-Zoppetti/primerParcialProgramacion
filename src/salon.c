/*
 * salon.c
 *
 *  Created on: 18 oct. 2021
 *      Author: MariaElena
 */

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

int generarIdSalon(int* pcontadorId,int idMaximo){
	int respuesta=-1;
	if(pcontadorId!=idMaximo){
		*pcontadorId++;
		respuesta=0;
	}
	else
	{
		printf("ya se utilizaron todos los id disponibles");
	}
	return respuesta;
}

int BuscarSalonLibre(eSalon lista[], int tam, int* pcontadorId)
{
	int i;
	int index;
	index= -1;
	for(i=0; i<tam; i++)
	{
		if(lista[i].isEmpty==1)//si esta vacio
		{
			index=i; // el index me da el id libre
			break;

		}
		else{
			printf("no hay ids disponibles \n");
		}

	}
	return index;
}

int inicializarArray(eSalon lista[], int tam)
{
	int i;
	int estado=-1;
	if(lista!=NULL && tam>0){
	for(i=0; i<tam; i++)
	{
		lista[i].isEmpty=1;
		estado=1;
	}
	}
return estado;
}


int altaSalon(eSalon lista[], int tam,int idMaximo,int* idsalon)
{

	int index;

	index = BuscarSalonLibre(lista, tam);
	if(index!=-1)
	{ inicializarArray(lista[index], tam);
		lista[index].id= index;
		UTN_ingresoCharReintentosMinMax(&lista[index].nombre, "escriba el nombre del salon\n", "escribio un nombre de salon incorrecto\n", 0, 128, 5);
		UTN_ingresoCharReintentosMinMax(&lista[index].direccion, "escriba la direccion del salon\n", "escribio una direccion del salon incorrecta\n", 0, 130, 5);
		UTN_ingresoCharReintentosMinMax(&lista[index].tipo, "escriba el tipo del salon\n", "escribio un tipo de salon incorrecto\n",0, 10, 5);
		lista[index].isEmpty=0;

		printf("se dio de alta el salon de nombre %s\n la direccion del salon es %s\n el salon es del tipo %s \n el id del salon es %d \n"
				,lista[index].nombre, lista[index].direccion,lista[index].tipo, lista[index].id);
	}
	else
	{
		printf("no se pudo dar el alta\n");
	}


	return index;
}



/*
 * 2) ELIMINAR SALÓN
Se imprime la lista de salas listando ID, nombre y dirección.
Se ingresa un ID y la misma generará la baja del salón, junto con todos los arcades que lo componen.
 */


int BajaSalon(eSalon lista[], int tam)

{ int id;
int index;
#define pedirIdParaDarBaja="ingrese el id a dar de baja: "
#define mensajeError=" el id no pudo ser ingresado "

mostrarSalon( lista, tam);
UTN_ingresoIntReintentosMinMax(&id, "ingrese el id a dar de baja: ", " el id no pudo ser ingresado ", 0, 100, 5);
index = BuscarSalonPorId( lista, tam, id);
if(index!=-1)
{
	lista[index].isEmpty=1;
	printf("se dio de baja el salon de nombre %s\n la direccion del salon es %s\n el salon es del tipo %s \n el id del salon es %d \n"
					,lista[index].nombre, lista[index].direccion,lista[index].tipo, lista[index].id);
}


return index;//ver que devolvemos... segun la logica que establezca dentro de la funcion
}


void mostrarSalon(eSalon lista[], int tam)
{

	for(int i=0;i<tam; i++)
	{
		printf("\n se encontro el salon de nombre %s\n la direccion del salon es %s\n el salon es del tipo %s \n el id del salon es %d \n"
						,lista[i].nombre, lista[i].direccion,lista[i].tipo, lista[i].id);
	}

}


int BuscarSalonPorId(eSalon lista[],int tam,int id)
{
	int index;
	index=-1;
	int i;

for (i=0; i<tam; i++){
	if( lista [i].id == id && lista[i].isEmpty == 0)
	{
		index=i;
		break;
	}
}
	return index;
}

int verificarIdSalon(eSalon lista[],int tam,int id)
{
	int respuesta;
	respuesta=-1;
	int i;

for (i=0; i<tam; i++){
	if( lista [i].id == id && lista[i].isEmpty == 0)
	{
		respuesta=1;
		break;
	}
}
	return respuesta;
}

/*
 * 3) IMPRIMIR SALONES
Se imprime la lista completa de salas con todos sus datos. Nombre, dirección y tipo.
 */

void mostrarSalon(eSalon lista[], int tam);

/*
 * 4) INCORPORAR ARCADE
Se da de alta un arcade con la nacionalidad, tipo de sonido, cantidad de jugadores, capacidad máxima de
fichas, ID del salón al que pertenece (Validar que exista) y nombre del juego que contiene (hasta 63 caracteres).
Se generará un ID único para gestionar los ARCADE.
 *
 */















