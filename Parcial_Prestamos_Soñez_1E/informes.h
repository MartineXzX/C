#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/** \brief Despliega el menu de informes de cliente.
 *
 * \return retorna la opcion seleccionada.
 *
 */
int menuInformesClientes();


/** \brief Utiliza el valor de retorno del menu informes dentro de un switch y ejecuta el informe seleccionado.
 *
 * \param vecClientes vector de clientes de la estructura eClientes.
 * \param vecPrestamos vector de prestamos de la estructura ePrestamos.
 * \param tamClientes tamanio de clientes.
 * \param tamPrestamos tamanio de prestamos.

 *
 */
void informesClientes(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos);

/** \brief Utiliza el valor de retorno del menu informes prestamos dentro de un switch y ejecuta el informe seleccionado.
 *
 *
 * \param vecClientes vector de clientes de la estructura eClientes.
 * \param vecPrestamos vector de prestamos de la estructura ePrestamos.
 * \param tamClientes tamanio de clientes.
 * \param tamPrestamos tamanio de prestamos.
 *
 */
void informesPrestamos(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamPrestamos,int tamClientes);

/** \brief Recorre el vector de prestamos y clientes y muestra al cliente con mas prestamos saldados.
 *
 * \param vecClientes vector de clientes de la estructura eClientes.
 * \param vecPrestamos vector de prestamos de la estructura ePrestamos.
 * \param tamClientes tamanio de clientes.
 * \param tamPrestamos tamanio de prestamos.
 *
 */
void clienteMaxPrestamosSaldados(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos);

/** \brief Despliega el menu de informes de prestamos.
 *
 * \return retorna la opcion seleccionada.
 *
 */
int menuInformesPrestamos();

/** \brief Recorre el vector de prestamos y clientes y muestra al cliente con mas prestamos activos.
 *
 * \param vecClientes vector de clientes de la estructura eClientes.
 * \param vecPrestamos vector de prestamos de la estructura ePrestamos.
 * \param tamClientes tamanio de clientes.
 * \param tamPrestamos tamanio de prestamos.
 *
 */
void clienteMaxPrestamosActivos(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos);


/** \brief Imprime los prestamos mayores a 1000 de una cifra ingresada por el usuario.
 *
 * \param
 * \param
 *
 */
void prestamosMayores1000(ePrestamos vecPrestamos[],eClientes vecClientes[],int tamPrestamos,int tamClientes);

#endif // INFORMES_H_INCLUDED
