/*
 * parser.h
 *
 *  Created on: 12 nov. 2021
 *      Author: MariaElena
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade);
int parser_eArcadeFromBinary(FILE* pFile , LinkedList* pArrayListArcade);

#endif /* PARSER_H_ */


