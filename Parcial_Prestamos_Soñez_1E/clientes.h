#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#define NOMBRETAM 20
#define APELLIDOTAM 20
#define CLIENTESTAM 50
#define CUIL 15
typedef struct
{
    int isEmpty;
    int clienteId;
    char cuil[CUIL];
    char nombre[NOMBRETAM];
    char apellido[NOMBRETAM];
} eClientes;

/** \brief Genera un cliente con datos pasados por parametro.
 *
 * \param clienteId Numero de id del cliente.
 * \param nombre Nombre del cliente.
 * \param apellido Apellido del cliente.
 * \param cuil Cuil del cliente.
 * \return retorna Cliente creado.
 *
 */
eClientes nuevoCliente(int clienteId,char nombre[],char apellido[],char cuil[]);

/** \brief Inicializa los campos de Clientes.
 *
 * \param vecClientes recorre la estructura clientes.
 * \param tamClientes tamaño clientes.

 *
 */
void iniciarClientes(eClientes vecClientes[],int tamClientes);

/** \brief Obtiene el primer espacio libre que encuentra.
 *
 * \param vecClientes recorre estructura clientes.
 * \param tamClientes tamaño clientes.

 *\return retorna el indice libre.
 */
int buscarLibre(eClientes vecClientes[],int tamClientes);

/** \brief Genera un id automatico.

 * \return retorna el id generado.
 */
int autoIdClientes();

/** \brief Obtiene cantidad de clientes activos.
 *
 * \param vecClientes recorre estructura clientes.
 * \param tamClientes tamaño de clientes.
 * \return retorna la cantidad de clientes activos.
 */
int clientesActivos(eClientes vecClientes[],int tamClientes);

/** \brief Muestra encabezado de datos del cliente.
 *
 *
 */
void encabezadoInfoClientes();

/** \brief Agrega un cliente.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \return retorna el numero de indice si se pudo agregar correctamente si no retorna -1.
 */
int altaCliente(eClientes vecClientes[],int tamClientes);


/** \brief Obtiene el primer id registrado.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param ultimoId Guarda el valor del ultimo id generado.
 * \return retorna 0 si todo esta bien y -1 si algo salio mal.
 *
 */
int primerIdRegistrado(eClientes vecClientes[],int tamClientes,int* ultimoId);


/** \brief Obtiene el ultimo id registrado.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param ultimoId Guarda el valor del ultimo id generado.
 * \return retorna 0 si todo esta bien y -1 si algo salio mal.
 *
 */
int ultimoIdRegistrado(eClientes vecClientes[],int tamClientes,int* ultimoId);

/** \brief Muestra los datos de un cliente seleccionado.
 *
 * \param unCliente es una variable de la estructura eClientes con todoso los datos almacenados de esa posicion.
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.

 *
 */
void listarCliente(eClientes unCliente,ePrestamos vecPrestamos[],int tamPrestamos);

/** \brief Muestra a todos los clientes activos.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 *
 */
void listarClientes(eClientes vecClientes[],int tamClientes,ePrestamos vecPrestamos[],int tamPrestamos);

/** \brief Elimina un cliente mediante baja logica.
*
* \param vecClientes recorre la estructura de clientes.
* \param tamClientes es el tamaño de clientes.
* \param vecPrestamos recorre la estructura de prestamos.
* \param tamPrestamos es el tamaño de prestamos.

* \return retorna el indice del cliente modificado
*/
int bajaCliente(eClientes vecClientes[],int tamClientes,ePrestamos vecPrestamos[],int tamPrestamos,int* idCliente);

/** \brief Mediante un id trabaja con la posicion en memoria de ese id y modifica los datos que solicite el usuario.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.
 * \param id es el id del cliente a modificar.
 * \return retorna el indice del cliente modificado.
 */
int modCliente(eClientes vecClientes[],int tamClientes,int id,ePrestamos vecPrestamos[],int tamPrestamos);

/** \brief Busca un cliente mediante su id.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param idCliente es el id del cliente a buscar.

 * \return retorna el indicel del cliente buscado.
 */
int buscarClienteId(eClientes vecClientes[],int tamClientes,int* idCliente);

/** \brief Cuenta los clientes activos.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.

 * \return retorna la cantidad de clientes.
 */
int contTotalClientes(eClientes vecClientes[],int tamClientes);

/** \brief Muestra el header de clientes saldados.
 */

void listarClientePrestamosSaldados(eClientes unCliente,ePrestamos vecPrestamos[],int tamPrestamos);
/** \brief Muestra los clientes con la cantidad de prestamos saldados.
 * \param unCliente variable correspondiente a la estructura de clientes.
 * \param vecPrestamos recorre la estructura de prestamos.
 * \param tamPrestamos es el tamaño de prestamos.

 */
void encabezadoInfoClientesSaldados();

/** \brief Busca mediante el id del cliente su cuil para ser mostrado en la descripcion de los prestamos.
 *
 * \param vecClientes recorre la estructura de clientes.
 * \param tamClientes es el tamaño de clientes.
 * \param idCliente es el id del cliente.
 * \param cuilCliente es el cuil del cliente.
 * \return retorna -1 si no salio bien, o 0 si salio todo ok.
 *
 */
int getCuilCliente(eClientes vecClientes[],int tamClientes,int idCliente,char* cuilCliente);

#endif // CLIENTES_H_INCLUDED
