/*
 * utn.h
 *
 *  Created on: 15 may. 2020
 *      Author: User
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * \brief Pide un n?mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n?mero ingresado
 *
 */
 int getInt(char* mensaje);

/**
 * \brief Verifica si el valor recibido es flotante(o int)
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n?merico y 0 si no lo es
 *
 */
int isFloat(char str[]);

/**
 * \brief Verifica si el valor recibido es num?rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n?merico y 0 si no lo es
 *
 */
int isNumber(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int onlyLetters(char str[]);




/**
 * \brief Solicita un texto num?rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar? el texto ingresado
 * \return 1 si el texto contiene solo n?meros
 */
int getFloatString(char mensaje[],char input[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n?mero ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void);

/**
 * \brief Pide un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar? el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);

/**
 * \brief Pide un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar? el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Solicita un texto num?rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar? el texto ingresado
 * \return 1 si el texto contiene solo n?meros
 */
int getStringNumeros(char mensaje[],char input[]);
/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar? el texto ingresado
 * \return -
 *
 */

void getValidString(char requestMessage[],char errorMessage[], char input[]);

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n?mero ingresado por el usuario
 *
 */
int getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

#endif /* UTN_H_ */
