#include "arcade.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Ingresos.h"


	/*
	 * 	char nacionalidad[nombreMaximoArcade];
	int tipoDeSonido;
	int idArcade;
	char nombreDelSalon[nombreMaximoArcade];
	int cantidadDeJugadores;
	int cantidadMaximaDeFichas;
	char nombreDelJuego[nombreMaximoArcade];
	 */
//(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)



eArcade* eArcade_new()
{
	eArcade* peArcade = malloc(sizeof(eArcade));
	return peArcade;
}

void eArcade_delete(eArcade* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

eArcade* eArcade_newParametros(int* tipoDeSonidoStr,int* idArcadeStr, int* cantidadDeJugadoresStr,int cantidadMaximaDeFichasStr,char* nombreDeSalonStr,char* nacionalidadStr, char* nombreDelJuegoStr)
{


	int auxID;
	int auxtipoDeSonido;
	int auxcantidadDeJugadores;
	int auxcantidadMaximaDeFichas;
	eArcade* this = NULL;
	this= eArcade_new();
	eArcade* retornoAuxArcade;
	if(idArcadeStr != NULL && nombreDeSalonStr != NULL && tipoDeSonidoStr != NULL && nacionalidadStr != NULL && cantidadDeJugadoresStr != NULL && cantidadMaximaDeFichasStr != NULL)
	{
		if(this!=NULL && idArcadeStr!=NULL && cantidadDeJugadoresStr != NULL && cantidadMaximaDeFichasStr != NULL && idArcadeStr != NULL && tipoDeSonidoStr != NULL )
		{
			auxID = atoi(idArcadeStr);
			auxtipoDeSonido= atoi(tipoDeSonidoStr);
			auxcantidadDeJugadores = atoi(cantidadDeJugadoresStr);
			auxcantidadMaximaDeFichas = atoi(cantidadMaximaDeFichasStr);
			retornoAuxArcade = eArcade_new();
			if(retornoAuxArcade != NULL)
			{
				eArcade_setId(retornoAuxArcade, auxID);
				eArcade_setNacionalidad(this, nacionalidadStr);
				eArcade_setNombreDelSalon(this, nombreDeSalonStr);
				eArcade_setNombreDelJuego(this, nombreDelJuegoStr);
				eArcade_setTipoDeSonido(this, cantidadMaximaDeFichasStr);
				eArcade_setCantidadDeJugadores(this, auxcantidadDeJugadores);
				eArcade_setCantidadMaximaDeFichas(this, cantidadMaximaDeFichasStr);

			}
		}
		else{
			retornoAuxArcade = NULL;
		}
	}
	return retornoAuxArcade;
}

int eArcade_setId(eArcade* this,int id)
{
	int retorno = FALSE;
	if(this != NULL && id >= 0)
	{
		this->idArcade = id;
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_getId(eArcade* this,int* id)
{
	int retorno = FALSE;
	if(this != NULL && id != NULL)
	{
		*id = this->idArcade;
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_setTipoDeSonido(eArcade* this,int id)
{
	int retorno = FALSE;
	if(this != NULL && id >= 0)
	{
		this->tipoDeSonido = id;
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_getTipoDeSonido(eArcade* this,int* id)
{
	int retorno = FALSE;
	if(this != NULL && id != NULL)
	{
		*id = this->tipoDeSonido;
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_setCantidadDeJugadores(eArcade* this,int id)
{
	int retorno = FALSE;
	if(this != NULL && id >= 0)
	{
		this->cantidadDeJugadores = id;
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_getCantidadDeJugadores(eArcade* this,int* id)
{
	int retorno = FALSE;
	if(this != NULL && id != NULL)
	{
		*id = this->cantidadDeJugadores;
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_setCantidadMaximaDeFichas(eArcade* this,int id)
{
	int retorno = FALSE;
	if(this != NULL && id >= 0)
	{
		this->cantidadMaximaDeFichas = id;
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_getCantidadMaximaDeFichas(eArcade* this,int* id)
{
	int retorno = FALSE;
	if(this != NULL && id != NULL)
	{
		*id = this->cantidadMaximaDeFichas;
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_setNacionalidad(eArcade* this,char* Nacionalidad)
{
	int retorno = FALSE;
	if(this != NULL && Nacionalidad != NULL)
	{
		strcpy(this->nacionalidad,Nacionalidad);
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_getNacionalidad(eArcade* this,char* Nacionalidad)
{
	int retorno = FALSE;
	if(this != NULL && Nacionalidad != NULL)
	{
		strcpy(Nacionalidad,this->nacionalidad);
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_setNombreDelSalon(eArcade* this,char* nombreDelSalon)
{
	int retorno = FALSE;
	if(this != NULL && nombreDelSalon != NULL)
	{
		strcpy(this->nombreDelSalon,nombreDelSalon);
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_get(eArcade* this,char* NombreDelSalon )
{
	int retorno = FALSE;
	if(this != NULL && NombreDelSalon != NULL)
	{
		strcpy(NombreDelSalon,this->nombreDelSalon);
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_setNombreDelJuego(eArcade* this,char* nombreDelJuego)
{
	int retorno = FALSE;
	if(this != NULL && nombreDelJuego != NULL)
	{
		strcpy(this->nombreDelJuego,nombreDelJuego);
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_getNombreDelJuego(eArcade* this,char* NombreDelJuego)
{
	int retorno = FALSE;
	if(this != NULL && NombreDelJuego != NULL)
	{
		strcpy(NombreDelJuego ,this->nombreDelJuego);
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_findById(LinkedList *pArrayListArcade,int id)
{
	int retorno = -1;
	int tamanoLista;
	if(id>=0 && pArrayListArcade!=NULL)
	{
		tamanoLista = ll_len(pArrayListArcade);
		for(int i=0;i<tamanoLista;i++)
		{
			eArcade* pAuxiliarEmpleado=ll_get(pArrayListArcade, i);
			if(id == pAuxiliarEmpleado->cantidadDeJugadores)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}







