/*
 * inputDataFunctions.h
 *
 *  Created on: 10 abr. 2020
 *      Author: feder
 */

#ifndef INPUTDATAFUNCTIONS_H_
#define INPUTDATAFUNCTIONS_H_

/*
 * \brief getNumberBetweenTwo asignara una variable, por referencia, el numero ingresado por el usuario que este entre el minimo y el maximo, tendra 3 intentos.
 * \param Una variable, pasada por referencia
 * \param un Mensaje para mostrar al usuario
 * \param Un entero minimo, un entero maximo y por ultimo la cantidad de intentos en total.
 *
 * \return 1 si se ejecuto bien y -1 si se acabaron los intentos.
 *
 */
int getNumberBetweenTwo(int *pResultado, char *msg, int minimo, int maximo,int reintentos);

/*
 * \brief getFloatNumberBetweenTwo asignara una variable, por referencia, el numero ingresado por el usuario que este entre el minimo y el maximo, tendra 3 intentos.
 * \param Una variable, pasada por referencia
 * \param un Mensaje para mostrar al usuario
 * \param Un entero minimo, un entero maximo y por ultimo la cantidad de intentos en total.
 *
 * \return 1 si se ejecuto bien y -1 si se acabaron los intentos.
 *
 */
int getFloatNumberBetweenTwo(float *pResultado, char *msg, int minimo,int maximo, int reintentos);
int getIntNumber(int *pResultado, char *msg, int reintentos);

/*
 * \brief getFloatNumber pedira una direccion de memoria para poder asignar un numero el cual puede ser Float.
 * \param una direccion de memoria float
 * \param un mensaje de carga para el usuario
 * \param un numero de reintentos
 *
 * \return 0 si se ejecuto bien. -1 si se terminaron los intentos
 *
 */
int getFloatNumber(float *pResultado, char *msg, int reintentos);

/*
 * \brief getInt pedira un numero al usuario sin mostrar mensajes
 * \param Una variable Entera, pasada por referencia
 *
 * \return 1 si se ejecuto bien y 0 si se encontraron caracteres que no fueran numeros.
 *
 */
int getInt(int *pResultado);

/*
 * \brief getFloat pedira una direccion de memoria para poder asignar un numero el cual puede ser Float. Asi para
 * despues dejar la carga al usuario y verificar si es un numero
 * \param una direccion de memoria float
 *
 * \return 0 si se ejecuto bien. -1 si se terminaron los intentos
 *
 */
int getFloat(float *pResultado);
void getString(char *msg, char *buffer);

/*
 * \brief isStringFullOfNumbers devolvera -1 si una cadena contiene en todas sus posiciones numeros del 0 al 9
 * o encuentra mas de un .
 * \param un String...
 *
 * \return 1 Si es un numero.
 * \return 2 Si es un Float
 * \return -1 Si es el ingreso contuvo caracteres
 *
 */
int isStringFullOfNumbers(char *str);

/*
 * \brief getCharBetweenTwo tomara un caracter del usuario y comprobara si se encuentra entre el rango de caracteres
 *  pasado (No discrimina minusculas o mayusculas).
 *
 * \param Una variable char, pasada por referencia
 * \param Un mensaje y al mismo tiempo un mensaje de error
 * \param Un caracter minimo y maximo, de acuerdo a la tabla ASCII
 * \param Un numero de intentos en total
 *
 * \return 1 si se ejecuto bien y 0 si se encontraron caracteres que no fueran entre el rango.
 *
 */
int getCharBetweenTwo(char *pResultado, char *msg, char *errormsg, char minimo,char maximo, int reintentos);

/*
 * \brief userConfirm le preguntara al usuario si desea continuar o no. Siendo asi 'S' o 's' como unica salida verdadera
 *
 * \param Un mensaje de muestra al usuario.
 *
 * \return 1 Verdadero, continua el ciclo
 * \return 0 Falso, no continua el ciclo
 *
 */
int userConfirm(char *msg);

/*
 * \brief getArrayInt, una funcion que pedira numeros al usuario y asi llenar el array
 *
 * \param un array de enteros y su indice maximo
 * \param Un mensaje.
 *
 * \return 1 si se ejecuto bien y -1 si el indice maximo es 0
 *
 */
int getArrayInt(int array[], int maxIndex, char *msg);

/*
 * \brief getArrayIntBetweenTwo, una funcion que pedira un numero al usuario y verificara si esta entre dos parametros
 * 		  tendra 2 intentos mas si se equivoca, siendo asi si ingresa una letra o un numero que no esta entre esos parametros
 * 		  saldra de la carga. Ademas si presiona s tambien saldra de la carga.
 *
 * \param un array de enteros y su indice maximo
 * \param Un mensaje.
 *
 * \return 1 si se ejecuto bien y -1 si el indice maximo es 0
 *
 */
int getArrayIntBetweenTwo(int array[], int maxIndex, char *msg, int minimo,int maximo);


int getNameFromUser(char *output, char *msg, int maxWords, int toUpperCase, int reintentos);
int toLowerCaseString(char *str);
int toUpperCaseString(char *str);
int removeSpacesInStr(char *buffer);
int contarPalabras_Y_Uppear(char *buffer, int toUpperCase);
int hasNone_A_to_z_Chars(char *buffer);
int getGender(char *genderInput, char *str);
int countLettersStr(char* buffer);

int loadMatrixIntBetweenTwo(int **array, int maxFiles, int maxColumns,int criterio[][2], char messages[][45]);
void cargarMatrizParalela(int **datosInt, float **datosFloat,char datosString[][40], int maxIndex, char messages[][45],int cantDatosInt, int cantDatosFloat);
void mostrarMatrizParalela(int **datosInt, float **datosFloat,char datosString[][40], int maxIndex, char messages[][45],int cantDatosInt, int cantDatosFloat);

#endif /* INPUTDATAFUNCTIONS_H_ */
