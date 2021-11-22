
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "arcade.h"
#include "parser.h"
#include "Ingresos.h"
#include "Controller.h"

#define VERDADERO 1
#define FALSO 0
#define Tamano 128
#define menu_ModificacionesMin 1
#define menu_ModificacionesMax 4
#define reintentos 5
#define minimoArcadeCargados 1

/** \brief La función se encarga de comparar los datos recibidos por parámetro.
 *
 * \param pFirstArcade puntero a los datos de un Arcade
 * \param pSecondArcade puntero a los datos de un Arcade
 * \return int Devuelve VERDADERO si se debe hacer un swap o FALSO si sucede lo contrario.
 *
 */

int compareArcades(eArcade* pFirstArcade,eArcade* pSecondArcade,int orden)
{
	int retornoSwap = FALSO;
	char auxNombreUno[Tamano];
	char auxNombreDos[Tamano];
	if(pFirstArcade != NULL && pSecondArcade != NULL && orden > 0)
	{
		eArcade_getNombreDelJuego(pFirstArcade, auxNombreUno);
		eArcade_getNombreDelJuego(pSecondArcade, auxNombreDos);
		switch(orden)
		{
		case 1:
			if(strcmp(auxNombreUno,auxNombreDos) > 0)
			{
				retornoSwap = VERDADERO;
			}
			break;
		case 2:
			if(strcmp(auxNombreUno,auxNombreDos) < 0)
			{
				retornoSwap = VERDADERO;
			}
			break;
		}
	}
	return retornoSwap;
}

/** \brief La función se encarga de contar la cantidad de datos en los archivos para llevar un control de cual es la última ID registrada.
 *
 * \param pArrayListeArcade lista de punteros
 * \return int Devuelve el contador de datos registrados en el archivo.
 *
 */

int controller_dataCount(LinkedList* pArrayListeArcade)
{
	static int contador;
	FILE* file = fopen("data.csv","r");
	char nacionalidad[256];
	char tipoDeSonido [256];
	char idArcade[256];
	char nombreDelSalon[256];
	char cantidadDeJugadores[256];
	char cantidadMaximaDeFichas[256];
	char nombreDelJuego[256];
	if(pArrayListeArcade != NULL){
		fscanf(file,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idArcade,nacionalidad,tipoDeSonido,cantidadDeJugadores,cantidadMaximaDeFichas,nombreDelSalon,nombreDelJuego); // salteo la 1era
		do{
			if(fscanf(file,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idArcade,nacionalidad,tipoDeSonido,cantidadDeJugadores,cantidadMaximaDeFichas,nombreDelSalon,nombreDelJuego)==7)
			{
				contador++;
			}
		}while(feof(file) == 0);
	}
	return contador;
}

/** \brief La función se encarga de desplegar y utilizar un menú de modificaciones para los datos del empleado.
 *
 * \param respuestaUsuario contiene la respuesta ingresada por el usuario para usarla en el switch.
 * \param ArcadeMod puntero con la dirección de memoria a los datos que queremos modificar.
 * \return int Retorna VERDADERO si los parámetros son correctos o FALSO en caso contrario.
 *
 */

int controller_modMenu(int respuestaUsuario,eArcade* eArcadeMod)
{
	int auxCantidadDeJugadores;
	int auxJuegoNuevo[Tamano];
	int estadoIngresoCantidadDeJugadores;
	int estadoIngresoNombreDelJuego;
	int retorno = FALSO;
	if(respuestaUsuario > 0 && eArcadeMod != NULL){
		retorno = VERDADERO;
		switch(respuestaUsuario){
		case 1:
			estadoIngresoCantidadDeJugadores = UTN_ingresoIntReintentos(auxCantidadDeJugadores,"Escriba la nueva cantidad de jugadores: ", "El valor ingresado es incorrecto, reescriba: ", reintentos);
			if(estadoIngresoCantidadDeJugadores == VERDADERO)
			{
				eArcade_setCantidadDeJugadores(eArcadeMod, auxCantidadDeJugadores);
				puts("¡Operacion exitosa!\n");
			}
			else{
				puts("Error en la modificación, vuelva al menu e intentelo nuevamente.\n");
			}
			break;
		case 2:
			estadoIngresoNombreDelJuego = UTN_ingresoTextoReintentos(auxJuegoNuevo, Tamano,"Escriba el nombre del juego nuevo: \n", "El valor ingresado es incorrecto, reescriba: \n", reintentos);
			if(estadoIngresoNombreDelJuego == VERDADERO){
				eArcade_setNombreDelJuego(eArcadeMod, auxJuegoNuevo);
				puts("¡Operacion exitosa!\n");
			}
			else{
				puts("Error en la modificación, vuelva al menu e intentelo nuevamente.\n");
			}
			break;

		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListeArcade)
{
	int retorno = FALSO;
	if(path != NULL && pArrayListeArcade != NULL)
	{
		FILE* file = fopen(path,"r");
		if(file != NULL)
		{
			parser_ArcadeFromText(file, pArrayListeArcade);
			fclose(file);
			retorno = VERDADERO;
		}
		else{
			printf("ERROR, No se pudo abrir el archivo: %s",path);
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListeArcade)
{
	int retorno = FALSO;
	if(path != NULL && pArrayListeArcade != NULL)
	{
		FILE* file = fopen(path,"rb");
		if(file != NULL)
		{
			parser_eArcadeFromBinary(file, pArrayListeArcade);
			fclose(file);
			retorno = VERDADERO;
		}
		else{
			printf("ERROR, No se pudo abrir el archivo: %s",path);
		}
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_addArcade(LinkedList* pArrayListeArcade)
{
	int retorno = FALSO;
	static int variable = 1;
	int auxID;
	char nuevaID[Tamano];


	char auxTipoDeSonido;
	char auxCantidadDeJugadores;
	char auxCantidadMaximaDeFichas;
	char auxNombreDelJuego[Tamano];
	char auxNombreDelSalon[Tamano];
	char auxNacionalidad[Tamano];
	int estadoTipoDeSonido;
	int estadoCantidadDeJugadores;
	int estadoCantidadMaximaDeFichas;
	int estadoIngresoNombreDelJuego;
	int estadoIngresoNombreDelSalon;
	int estadoNacionalidad;
	eArcade* pArcadeAuxiliar;
	if(pArrayListeArcade != NULL)
	{
		auxID = controller_dataCount(pArrayListeArcade) + variable;
		variable++;
		sprintf(nuevaID,"%d",auxID);
		printf("------------------------ ID: %d ------------------------\n" ,auxID);

		estadoTipoDeSonido=UTN_ingresoTextoReintentos(&auxTipoDeSonido, Tamano, "Escriba el tipo de sonido a continuacion: \n", "ERROR, el valor ingresado es incorrecto, reescriba: \n", reintentos);
		estadoCantidadDeJugadores=UTN_ingresoTextoReintentos(&auxCantidadDeJugadores, Tamano, "Escriba la cantidad de jugadores a continuacion: \n", "ERROR, el valor ingresado es incorrecto, reescriba: \n", reintentos);
		estadoCantidadMaximaDeFichas=UTN_ingresoTextoReintentos(&auxCantidadMaximaDeFichas, Tamano, "Escriba la cantidad maxima de fichas a continuacion: \n", "ERROR, el valor ingresado es incorrecto, reescriba: \n", reintentos);
		estadoIngresoNombreDelJuego=UTN_ingresoTextoReintentos(auxNombreDelJuego, Tamano, "Escriba el nombre del juego a continuacion: \n", "Escriba la cantidad maxima de fichas a continuacion: \n", reintentos);
		estadoIngresoNombreDelSalon=UTN_ingresoTextoReintentos(auxNombreDelSalon, Tamano, "Escriba el nombre del salon a continuacion: \n", "Escriba la cantidad maxima de fichas a continuacion: \n", reintentos);
		estadoNacionalidad=UTN_ingresoTextoReintentos(auxNacionalidad, Tamano, "Escriba la nacionalidad a continuacion: \n", "Escriba la cantidad maxima de fichas a continuacion: \n", reintentos);

		if(estadoIngresoNombreDelJuego  == VERDADERO && estadoIngresoNombreDelSalon == VERDADERO && estadoCantidadDeJugadores == VERDADERO && estadoNacionalidad == VERDADERO && estadoCantidadMaximaDeFichas == VERDADERO && estadoTipoDeSonido  == VERDADERO )
		{
			pArcadeAuxiliar = eArcade_newParametros(auxTipoDeSonido,auxID, auxCantidadDeJugadores, auxCantidadMaximaDeFichas, auxNombreDelSalon, auxNacionalidad, auxNombreDelJuego);
			if(pArcadeAuxiliar != NULL)
			{
				ll_add(pArrayListeArcade,pArcadeAuxiliar);
				retorno = VERDADERO;
				puts("¡Operacion exitosa!\n");
			}
			else{
				puts("Error en la carga de datos, vuelva al menú e intentelo nuevamente.\n");
			}
		}
		else{
			puts("Error en el ingreso de datos, vuelva al menú y cargue los datos nuevamente.");
		}
	}
	return retorno;
}

/** \brief Modificar datos de arcade
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_editArcade(LinkedList* pArrayListeArcade)
{
	int retorno = FALSO;
	int modID;
	int maximoArcadeCargado;
	int respuestaUsuario;
	int indiceMod;
	eArcade* ArcadeMod;
	if(pArrayListeArcade != NULL)
	{
		maximoArcadeCargado = controller_dataCount(pArrayListeArcade);
		puts("--------------------- MENU DE MODIFICACIONES ---------------------\n");
		puts("Bienvenido al menu de modificaciones.\n");
		if(UTN_ingresoIntReintentosMinMax(&modID, "Escriba la ID del empleado del que desea modificar sus datos:", "ERROR, el valor ingresado es incorrecto, reescriba: ", minimoArcadeCargados, maximoArcadeCargado, reintentos) == VERDADERO)
		{
			indiceMod = eArcade_findById(pArrayListeArcade, modID);
			if(indiceMod != -1)
			{
				ArcadeMod = ll_get(pArrayListeArcade,indiceMod);
				if(ArcadeMod != NULL)
				{
					do{
						printf("--------------------- ID seleccionada: %d ---------------------\n" ,modID);
						puts("Seleccione una de las siguientes opciones:\n");
						puts("\t1 - Modificar la cantidad de jugadores");
						puts("\t2 - Modificar nombre del juego");
						puts("\t3 - Salir del menú.");
						if(UTN_ingresoIntReintentosMinMax(&respuestaUsuario, "Escriba su respuesta: ", "ERROR, el valor ingresado es incorrecto, reescriba: ", menu_ModificacionesMin, menu_ModificacionesMax, reintentos) == VERDADERO)
						{
							controller_modMenu(respuestaUsuario,ArcadeMod);
							retorno = VERDADERO;
						}
						else{
							puts("Demasiados intentos en el ingreso de opción, vuelva al menú e intentelo nuevamente\n");
						}
					}while(respuestaUsuario != 3);
				}
			}
			else{
				puts("No se pudo encontrar la ID solicitada, vuelva al menú e intentelo nuevamente\n");
			}
		}
		else{
			puts("Error en el ingreso de ID, vuelva al menú e intentelo nuevamente\n");
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_removeArcade(LinkedList* pArrayListeArcade)
{
	int retorno = FALSO;
	int bajaID;
	int maximoArcadeCargado;
	int indiceBaja;
	maximoArcadeCargado = controller_dataCount(pArrayListeArcade);
	eArcade* arcadeDown;
	if(pArrayListeArcade != NULL)
	{
		if(UTN_ingresoIntReintentosMinMax(&bajaID,"Escriba la ID del arcade a dar de baja:","ERROR, el valor ingresado es incorrecto, reescriba: ",minimoArcadeCargados,maximoArcadeCargado,reintentos) == VERDADERO)
		{
			indiceBaja = eArcade_findById(pArrayListeArcade, bajaID);
			if(indiceBaja != -1)
			{
				arcadeDown = ll_get(pArrayListeArcade,indiceBaja);
				if(arcadeDown != NULL)
				{
					free(arcadeDown);
					ll_remove(pArrayListeArcade,indiceBaja);
					puts("¡Operacion exitosa!\n");
					retorno = VERDADERO;
				}
				else{
					puts("Error en la busqueda del arcade, vuelva al menú e intentelo nuevamente.\n");
				}
			}
			else{
				puts("No se pudo encontrar al arcade con la ID solicitada, vuelva al menú e intentelo nuevamente.\n");
			}
		}
		else{
			puts("Supero la cantidad de intentos disponibles, vuelva al menú e intentelo nuevamente");
		}
	}
	return retorno;
}

/** \brief Listar arcades
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_ListArcade(LinkedList* pArrayListeArcade)
{
	int retorno = FALSO;
	int tamanoLista;
	if(pArrayListeArcade != NULL)
	{
		tamanoLista = ll_len(pArrayListeArcade);
		for(int i = 0;i<tamanoLista;i++)
		{
			eArcade* pAuxiliarEmpleado = ll_get(pArrayListeArcade,i);
			printf("-----------------------------------\n");
			printf("ID arcade: %d\n",pAuxiliarEmpleado->idArcade);
			printf("Nombre Del Juego: %s\n",pAuxiliarEmpleado->nombreDelJuego);
			printf("Nombre Del Salon: %s\n",pAuxiliarEmpleado->nombreDelSalon);
			printf("Tipo De Sonido: %d\n",pAuxiliarEmpleado->tipoDeSonido);
			printf("Nacionalidad: %s\n",pAuxiliarEmpleado->nacionalidad);
			printf("Cantidad De Jugadores: %d\n",pAuxiliarEmpleado->cantidadDeJugadores);
			printf("Cantidad Maxima De Fichas: %d\n",pAuxiliarEmpleado->cantidadMaximaDeFichas);
			puts("----------------------\n");
			retorno = VERDADERO;
		}
	}
	return retorno;
}

/** \brief Ordenar arcades
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */

int controller_sortArcade(LinkedList* pArrayListeArcade)
{
	eArcade* pArcadeAuxiliar;
	eArcade* pArcadeAuxiliarDos;
	eArcade* pArcadeAuxiliarTres;
	int flagSwap;
	int tamanoLista;
	int retorno = FALSO;
	int respuestaUsuario;
	int estadoRespuestaUsuario;
	tamanoLista = ll_len(pArrayListeArcade);
	if(pArrayListeArcade != NULL)
	{
		puts("Escriba el numero de opcion para el orden que desea en su lista de arcades :\n 1 - Ascendente | 2 - Descendente");
		estadoRespuestaUsuario = UTN_ingresoIntReintentosMinMax(&respuestaUsuario, "Escriba su respuesta: ", "ERROR, el valor ingresado es incorrecto, reescriba su opcion: ", 1, 2, reintentos);
		if(estadoRespuestaUsuario == VERDADERO)
		{
			do{
				flagSwap = FALSO;
				for(int i=0; i<tamanoLista-1; i++)
				{
					pArcadeAuxiliar = ll_get(pArrayListeArcade,i);
					pArcadeAuxiliarDos = ll_get(pArrayListeArcade,i+1);
					if( compareArcades(pArcadeAuxiliar, pArcadeAuxiliarDos,respuestaUsuario) == VERDADERO)
					{
						flagSwap = VERDADERO;
						pArcadeAuxiliarTres = pArcadeAuxiliar;
						ll_set(pArrayListeArcade, i, pArcadeAuxiliarDos);
						ll_set(pArrayListeArcade, i+1, pArcadeAuxiliarTres);
						retorno = VERDADERO;
					}
				}
			}while(flagSwap == VERDADERO);
		}
		else{
			puts("Supero la cantidad de intentos disponibles, vuelva al menu e intentelo de nuevo.");
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los arcade en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListeArcade)
{
	FILE* file = fopen(path,"w");
	eArcade* pArcadeAuxiliar;
	int tamanoLista;
	int retorno = FALSO;
	if(path != NULL && pArrayListeArcade != NULL)
	{
		if(file != NULL)
		{
			fprintf(file,"id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n");
			tamanoLista = ll_len(pArrayListeArcade);
			for(int i=0; i<tamanoLista; i++)
			{
				pArcadeAuxiliar = ll_get(pArrayListeArcade,i);
				if(fprintf(file,"%d,%s,%d,%d,%d,%s,%s\n",pArcadeAuxiliar->idArcade, pArcadeAuxiliar->nacionalidad ,pArcadeAuxiliar->tipoDeSonido ,pArcadeAuxiliar->cantidadDeJugadores ,pArcadeAuxiliar->cantidadMaximaDeFichas ,pArcadeAuxiliar->nombreDelSalon ,pArcadeAuxiliar->nombreDelJuego) > 0)
				{
					retorno = VERDADERO;
				}

			}
			fclose(file);
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los arcade en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListeArcade)
{
	FILE* file = fopen(path,"wb");
	int tamanoLista;
	int retorno = FALSO;
	int i;
	if(file != NULL)
	{
		tamanoLista = ll_len(pArrayListeArcade);
		for(i = 0;i<tamanoLista+1;i++)
		{
			fwrite(ll_get(pArrayListeArcade,i),sizeof(eArcade),1,file);
			retorno = VERDADERO;
		}
	}
	fclose(file);
	return retorno;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
