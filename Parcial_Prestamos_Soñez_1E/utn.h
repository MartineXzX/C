#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/** \brief Obtiene un caracter valido.
 *
 * \param pResult es el caracter a ser evaluado.
 * \param message es el mensaje a ser leido por el usuario.
 * \param errorMessage es el mensaje a ser leido por el usuario en caso de haber error.
 * \param minimum es el minimo caracter a ser ingresado.
 * \param maximum es el maximo caracter a ser ingresado.
 * \param retries es la cantidad de reintentos permitidos.

 * \return retorna 0 si se pudo copiar, -1 si no se pudo copiar.
 *
 */
int utn_getChar(char* pResult,char* message,char* errorMessage,char minimum,char maximum,int retries);


/** \brief Obtiene un string valido.
 *
 * \param pAux Es el string a ser validado.
 * \param limit es el limite de caracteres para el string.
 * \param retries es la cantidad de reintentos permitidos.
 * \param msj es el mensaje a ser leido por el usuario.
 * \param msjError es el mensaje a mostrar en caso de haber ingresado caracteres incorrectos.

 * \return retorna 0 si se pudo copiar, -1 si no se pudo copiar.
 *
 */
int utnGetString(char *pAux,int limit,int retries,char* msj,char*msjError);


/** \brief valida que los caracteres de una cadena sean letras.
 *
 * \param pAux cadena a ser evaluada.
 *  \return retorna 0 si se pudo copiar, -1 si no se pudo copiar.
 *
 */
int sonLetras(char*pAux);

/** \brief Evalua si un string no supera el limite y copia su valor.
 *
 * \param pAux Es la variable destino a portar el string si la validacion es correcta.
 * \param limit es el limite de caracteres permitidos.
 * \return retorna 0 si se pudo copiar -1 si no se pudo copiar.
 *
 */
int getString(char* pAux,int limit);

/** \brief ingresa una cadena de caracteres, si esta cumple con las condiciones la convierte a float.
 *
 * \param str cadena a ser evaluada como float.
 * \return retorna 0 si se pudo copiar -1 si no se pudo copiar.
 *
 */
int validFloat(char str[]);

/** \brief Pide un dato al usuario y lo valida como float.
 *
 * \param message es el mensaje que se le muestra al usuario.
 * \param max es el valor maximo permitido.
 * \return retorna el valor ingresado.
 *
 */
float inputValidFloat(char message[], int max);

/** \brief Pide un string y lo guarda.
 *
 * \param mensaje es el mensaje que se le muestra al usuario.
 * \param str cadena a ser guardada.
 *
 */
void inputStr(char* mensaje, char* str);

/** \brief Ingresa un int y lo valida.
 *
 * \param message es el mensaje a ser leido por el usuario.
 * \param errorMessage es el mensaje a ser leido por el usuario en caso de haber error.
 * \param minimum es el minimo valor a ser ingresado.
 * \param maximum es el maximo valor a ser ingresado.
 * \param retries es la cantidad de reintentos permitidos.
 *
 */
int inputValidInt(char* message,char* errorMessage,int minimum,int maximum,int retries);

/** \brief Pide un numero al usuario.
 *
 * \param string es el mensaje para pedir el dato al usuario.
 * \return retorna el numero ingresado.
 *
 */
int inputInt(char* string);

/** \brief Valida que los caracteres de una cadena sean numericos.
 *
 * \param cadena a ser evaluada.
 * \return retorna 1 si todo es correcto y 0 si no es correcta la cadena.
 *
 */
int esNumerico(char* string);

/** \brief Manera abreviada de mostrar un mensaje sin mascaras.
 *
 * \param cadena es el mensaje a ser mostrado.
 *
 */
void mensaje(char* cadena);




/** \brief Despliega el menu de opciones.
 * \return retorna la opcion seleccionada.
 *
 */
int menu();


/** \brief confirma una accion.
 *
 * \param mensaje es el pedido de confirmacion.
 * \return retorna la respuesta en un caracter.
 *
 */
char confirma(char* mensaje);

/** \brief Ingresa un caracter.
 *
 * \param mensaje es el mensaje a ser leido por el usuario.
 * \return retorna el caracter.
 *
 */
char getCaracter(char* mensaje);

/** \brief Ingresa un float.
 *
 * \param mensaje es el mensaje a ser leido por el usuario.
 * \return retorna el float.
 *
 */
float inputFloat(char* string);

/** \brief Valida un cuit con los guiones.
 *
 * \param cadena es el cuit a ser ingresado.
 * \param mensaje es el mensaje a ser mostrado al usuario.
 * \param mensajeError es el mensaje a ser mostrado al usuario en caso de tener caracteres incorrectos.
 * \param reintentos es la cantidad de reintentos permitidos para ingresar el cuit.

 *
 */
void cuilValido(char* cadena,char* mensaje,char* mensajeError,int reintentos);


#endif // UTN_H_INCLUDED
