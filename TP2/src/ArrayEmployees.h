/*
 * ArrayEmployees.h
 *
 *  Created on: 15 may. 2020
 *      Author: User
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define MAX_EMPLEADOS 1000

typedef struct{
int id;
char nombre[51];
char apellido[51];
float salario;
int sector;
int isEmpty;
}eEmpleado;

/** \brief Inicializa el array de empleados poniendolos como vacios
 *
 * \param arrayEmpleados[] eEmpleado   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void initEmployees(eEmpleado arrayEmpleados[],int cantidad);

/** \brief una funcion que muestra el menú principal
 *
 * \return void
 *
 */


void menuPrincipal();

/** \brief Da de alta un empleado si encuentra espacio
 *
 * \param arrayEmpleados[] eEmpleado   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return int  -1 en caso de error y 0 en caso de exito
 *
 */
int addEmployees(eEmpleado arrayEmpleados[],int cantidad);

/** \brief Toma los datos de un empleado para darlo de alta
 *
 * \param arrayEmpleados[] eEmpleado   Array de empleados
 * \param vacio int Indice del primer espacio vacio del array
 * \param cantidad int  Cantidad de empleados del array
 * \return int  Devuelve -1 en caso de error y 0 si se logra completar
 *
 */
int addOneEmployee(eEmpleado arrayEmpleados[],int vacio,int cantidad);

/** \brief Busca el primer espacio vacio en el array
 *
 * \param arrayEmpleados[] eEmpleado   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return int Devuelve el indice del espacio vacio
 *
 */
int buscarLibre(eEmpleado arrayEmpleados[],int cantidad);

/** \brief  Toma el array de empleados y lo imprime por pantalla
 *
 * \param arrayEmpleados[] eEmpleado   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
int printEmployees(eEmpleado arrayEmpleados[],int cantidad);

/** \brief Imprime una lista ordenada por apellido y sector
 *
 * \param arrayEmpleados eEmpleado Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
int sortEmployees(eEmpleado arrayEmpleados[],int cantidad);

/** \brief  Muestra la lista de empleados y mediande el id se permite la baja
 *
 * \param arrayEmpleados[] eEmpleado   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return int
 *
 */
int removeEmployee(eEmpleado arrayEmpleados[],int cantidad);

/** \brief  Busca empleados por id y permite modificar el resto de los parametros de la estructura
 *
 * \param arrayEmpleados[] eEmpleado   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
int modificarEmployee(eEmpleado arrayEmpleados[],int cantidad);

/** \brief  Modifica el nombre del empleado mediante su indice
 *
 * \param arrayEmpleados[] eEmpleado   el array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void modificarNombre(eEmpleado arrayEmpleados[],int indice);

/** \brief  Modifica el apellido del empleado mediante su indice
 *
 * \param arrayEmpleados[] eEmpleado   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void modificarApellido(eEmpleado arrayEmpleados[],int indice);

/** \brief  Modifica el sector del empleado mediante su indice
 *
 * \param arrayEmpleados[] eEmpleado   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void modificarSector(eEmpleado arrayEmpleados[],int indice);

/** \brief  Modifica el salario del empleado mediante su indice
 *
 * \param arrayEmpleados[] eEmpleado   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void modificarSalario(eEmpleado arrayEmpleados[],int indice);


/** \brief  Da de alta la id del empleado con la condicion de que no se repita
 *
 * \param arrayEmpleados[] eEmpleado   Array de empleados
 * \param indice int    Indice del empleado a dar de alta
 * \param cantidad int  Cantidad de empleados del array
 * \return int Retorna 0 si no hay problemas y -1 si la id ya se encuentra en uso
 *
 */
int idEmployee(eEmpleado arrayEmpleados[],int indice,int cantidad);

/** \brief  Intercambia el indice de dos empleados dentro del array
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param indice1 int   Indice del primer empleado
 * \param indice2 int   Indice del Segundo empleado
 * \return void
 *
 */
void intercambio(eEmpleado arrayEmpleados[],int indice1,int indice2);



/** \brief  Busca el indice de un empleado mediante su id
 *
 * \param arrayEmpleados[] eEmpleado   Array de empleados
 * \param cantidad int  Cantiadad de empleados del array
 * \param id int    Id del empleado a buscar
 * \return int  Retorna -1 en caso de error y el indice correspondiente al id en caso exitoso
 *
 */
int findEmployeeById(eEmpleado arrayEmpleados[],int cantidad,int id);



/** \brief Imprime la suma de los salarios y el promedio
 *
 * \param arrayEmpleados[] eEmpleado Array de empleados
 * \param cantidad int  Cantidad de empleados
 * \return void
 *
 */
void printSalarios(eEmpleado arrayEmpleados[], int cantidad);

#endif /* ARRAYEMPLOYEES_H_ */
