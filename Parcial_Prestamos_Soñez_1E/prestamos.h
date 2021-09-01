#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED
#define PRESTAMOSTAM 50
#define ACTIVO 1
#define INACTIVO 0
#define SALDADO 2
typedef struct
{
    int isEmpty;
    int prestamoId;
    int clienteId;
    float prestamoImporte;
    int prestamoCuotas;
    int prestamoEstado;
} ePrestamos;
#include "clientes.h"

/** \brief Muestra un cabezal con los nombres de los datos del prestamo.
 */
void encabezadoInfoPrestamo();

/** \brief Muestra los datos de un prestamo seleccionado.
 *
 * \param Prestamo es una variable de la estructura eClientes con todoso los datos almacenados de esa posicion.
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.

 *
 */
void listarPrestamo (ePrestamos Prestamo,eClientes vecClientes[],int tamClientes);

/** \brief Muestra una lista con los prestamos saldados y da la opcion de reanudarlos.
 *
 * \param prestamoId es una variable de la estructura eClientes con todoso los datos almacenados de esa posicion.
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 *
 */
int reanudarPrestamo(ePrestamos vecPrestamos[],int tamPrestamos,int prestamoId,eClientes vecClientes[],int tamClientes);

/** \brief Muestra una lista con los prestamos saldados y da la opcion de reanudarlos.
 *
 * \param prestamoId es una variable de la estructura eClientes con todoso los datos almacenados de esa posicion.
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.

 *
 */
int saldarPrestamo(ePrestamos vecPrestamos[],int tamPrestamos,int prestamoId,eClientes vecClientes[],int tamClientes);

/** \brief Muestra a todos los prestamos activos.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 *
 */
void listarPrestamos(ePrestamos vecPrestamos[],int tamPrestamos,eClientes vecClientes[],int tamClientes);

/** \brief Muestra a todos los prestamos cancelados.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 *
 */
void listarPrestamosSaldados(ePrestamos vecPrestamos[],int tamPrestamos,eClientes vecClientes[],int tamClientes);

/** \brief Inicializa todos  los campos del prestamo.
 *
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.

 *
 */
void iniciarPrestamos(ePrestamos vecPrestamos[],int tamPrestamos);

/** \brief Cuenta los prestamos correspondientes a un cliente activo.
 *
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 * \param clienteId es el numero de id de un cliente.
 * \return retorna la cantidad de prestamos activos del cliente.
 */
int cantidadPrestamosCliente(ePrestamos vecPrestamos[],int tamPrestamos,int clienteId);

/** \brief Cuenta los prestamos saldados correspondientes a un cliente activo.
 *
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 * \param clienteId es el numero de id de un cliente.
 * \return retorna la cantidad de prestamos saldados del cliente.
 */
int cantidadPrestamosSaldadosCliente(ePrestamos vecPrestamos[],int tamPrestamos,int clienteId);

/** \brief Muestra los prestamos de un cliente activo.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 * \param clienteId es el numero de id de un cliente.

 */
void listarPrestamosCliente(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos,int* clienteId);

/** \brief Devuelve la cantidad de prestamos activos.
 *
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 * \return retorna la cantidad de prestamos.
 */
int prestamosActivos(ePrestamos vecPrestamos[],int tamPrestamos);

/** \brief Devuelve la cantidad de prestamos saldados.
 *
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 * \return retorna la cantidad de prestamos saldados.
 */
int cantidadPrestamosSaldados(ePrestamos vecPrestamos[],int tamPrestamos);

/** \brief Busca un prestamo mediante su id.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param idCliente es el id del cliente a buscar.
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 * \return retorna el indice del prestamo buscado.
 */
int buscarPrestamoId(ePrestamos vecPrestamos[],int tamPrestamos,int* idPrestamo,eClientes vecClientes[],int tamClientes);

/** \brief Agrega prestamos a un cliente seleccionado.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 * \return retorna el indice del prestamo que fue agregado.
 */
int altaPrestamo(ePrestamos vecPrestamos[],int tamPrestamos,eClientes vecClientes[],int tamClientes);

/** \brief Genera un cliente con datos pasados por parametro y algunos creados de manera automatica.
 *
 * \param clienteId numero de id del cliente.
 * \param prestamoImporte Importe del prestamo.
 * \param prestamoCuotas Cuotas del prestamo.
 * \param prestamoId id generado del prestamo.
 * \return retorna un prestamo creado.
 */
ePrestamos nuevoPrestamo(int clienteId,float prestamoImporte,int prestamoCuotas,int prestamoId);

/** \brief Genera un id automatico.

 * \return retorna el id generado.
 */
int autoIdPrestamos();

/** \brief Busca un prestamo cancelado mediante su id.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param idCliente es el id del cliente a buscar.
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 * \return retorna el indice del prestamo buscado.
 */
int buscarPrestamoSaldadoId(ePrestamos vecPrestamos[],int tamPrestamos,int* idPrestamo,eClientes vecClientes[],int tamClientes);

/** \brief Busca un prestamo activo mediante su id.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param idCliente es el id del cliente a buscar.
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 * \return retorna el indice del prestamo buscado.
 */
int buscarPrestamoActivoId(ePrestamos vecPrestamos[],int tamPrestamos,int* idPrestamo,eClientes vecClientes[],int tamClientes);

/** \brief Devuelve la cantidad de prestamos activos.
 *
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 * \return retorna la cantidad de prestamos activos.
 */
int cantidadPrestamosActivos(ePrestamos vecPrestamos[],int tamPrestamos);


#endif // PRESTAMOS_H_INCLUDED
