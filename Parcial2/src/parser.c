
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "arcade.h"
#include "parser.h"
#define TRUE 1
#define FALSE 0

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade)
{
	//id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game
	eArcade* pArcadeAuxiliar;
	int retorno = FALSE;
	if(pFile != NULL && pArrayListArcade != NULL)
	{

		char nacionalidad[256];
		int tipoDeSonido [256];
		int idArcade[256];
		char nombreDelSalon[256];
		int cantidadDeJugadores[256];
		int cantidadMaximaDeFichas[256];
		char nombreDelJuego[256];

		if(pFile!=NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idArcade,nacionalidad,tipoDeSonido,cantidadDeJugadores,cantidadMaximaDeFichas,nombreDelSalon,nombreDelJuego); // salteo la 1era
			do{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idArcade,nacionalidad,tipoDeSonido,cantidadDeJugadores,cantidadMaximaDeFichas,nombreDelSalon,nombreDelJuego)==7)
				{
					pArcadeAuxiliar = eArcade_newParametros(tipoDeSonido, idArcade, cantidadDeJugadores, cantidadMaximaDeFichas,nombreDelSalon , nacionalidad, nombreDelJuego);
					if(pArcadeAuxiliar != NULL)
					{
						ll_add(pArrayListArcade,pArcadeAuxiliar);
						retorno = TRUE;
					}
					else{
						eArcade_delete(pArcadeAuxiliar);
						break;
					}
				}
			}while(feof(pFile) == 0);
		}
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
int parser_eArcadeFromBinary(FILE* pFile , LinkedList* pArrayListArcade)
{
	eArcade* pArcadeAuxiliar;
	int retorno = FALSE;
	if(pFile != NULL && pArrayListArcade != NULL)
	{
		do{
			pArcadeAuxiliar = eArcade_new();
			if(fread(pArcadeAuxiliar,sizeof(eArcade),1,pFile) == 1)
			{
				ll_add(pArrayListArcade,pArcadeAuxiliar);
				retorno = TRUE;
			}
			else{
				eArcade_delete(pArcadeAuxiliar);
				break;
			}
		}while(feof(pFile) == 0);
	}
	return retorno;
}
