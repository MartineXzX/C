/*
 * UTN.h
 *
 *  Created on: 16 abr. 2020
 *      Author: User
 */

#ifndef UTN_H_
#define UTN_H_

/** \brief mostrar opcion 3,4 y 5 del menu principal en consola
*
* \param
* \return muestra opcion 3,4 y 5 del menu principal en consola
*
*/
void mostrarMenu(double a, double b);

/** \brief Obtiene un entero
 *
 * \param texto[] char mensaje a mostrar
 * \param error[] char mensaje de error
 * \param minimo int
 * \param maximo int
 * \return int devuelve el numero obtenido
 *
 */
int GetInt(char texto[], char error[], int minimo, int maximo);

/** \brief Obtiene un flotante
 *
 * \param texto[] char mensaje a mostrar
 * \param error[] char mensaje de error
 * \param minimo int
 * \param maximo int
 * \return int devuelve el numero obtenido
 *
 */
float getFloat(char texto[], char error[], int minimo, int maximo);

/** \brief suma dos numeros
 *
 * \param operador1 double
 * \param operador2 double
 * \return double la suma de los numeros
 *
 */
double Suma(double operador1, double operador2);

/** \brief resta dos numeros
 *
 * \param operador1 double
 * \param operador2 double
 * \return devuelve la resta
 *
 */
double Resta(double operador1, double operador2);

/** \brief multiplica 2 numeros
 *
 * \param operador1 double
 * \param operador2 double
 * \return double devuelve la multiplicacion
 *
 */
double Multiplica(double operador1, double operador2);

/** \brief  realiza la division de dos numeros
 *
 * \param  respuesta, guarda el valor
 * \param operador1 double
 * \param operador2 double
 * \return 0 si el segundo numero es un 0, 1 si la operacion es correcta
 *
 */
int Divide(double * respuesta, double operador1, double operador2);

/** \brief valida operador ingresado
*
* \param char mensaje a mostrar; pide numero
* \param char mensaje a mostrar; error numero invalido
* \return operador validado, o 0 segun corresponda
*
*/
double getOperadorValido(char mensaje[],char mensajeError[]);

/** \brief obtiene factorial
*
* \param numero/s a operar
* \return factorial del o los operadores
*
*/
double factorial(double operador);

#endif /* UTN_H_ */
