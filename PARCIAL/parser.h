/*
 * parser.h
 *
 *  Created on: 18 jun. 2020
 *      Author: feder
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int parser_ArticulosFromText(FILE* pFile , LinkedList* pArrayListArticulos);


#endif /* PARSER_H_ */
