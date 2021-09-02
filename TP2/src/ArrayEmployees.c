/*
 * ArrayEmployees.c
 *
 *  Created on: 15 may. 2020
 *      Author: User
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
void initEmployees(eEmpleado arrayEmpleados[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        arrayEmpleados[i].isEmpty = 1;
    }
}

void menuPrincipal()
{
    printf("\n*********Bienvenido**********\n\n-------------------------\n1.Dar de alta un empleado\n2."
           "Modificar datos de un empleado\n3.Dar de baja un empleado\n4.Mostrar los empleados\n5.Salir"
           "\n-------------------------\n\n"
           "Ingrese una opcion: ");
}

int addEmployees(eEmpleado arrayEmpleados[],int cantidad)//listo
{
    int retorno=0;
        system("cls");
        if(addOneEmployee(arrayEmpleados,buscarLibre(arrayEmpleados,cantidad),cantidad) == -1)
        {

            retorno=-1;
        }
        fflush(stdin);
    return retorno;
}

static int generateNextId ()
{
    static int id=0;

    id ++;

    return id;
}

int addOneEmployee(eEmpleado arrayEmpleados[],int vacio,int cantidad)//listo
{
    int retorno = -1;
    int auxId;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    if(retorno==-1)
    {

        auxId=generateNextId();

        getValidString("\nIngrese nombre:\n", " Error, ingrese nombre nuevamente (solo letras):", auxName);

        getValidString("\nIngrese apellido:\n", " Error, ingrese apellido nuevamente (solo letras):", auxLastName);

        auxSalary=getValidFloat("\nIngrese salario:\n"," Error, ingrese salario nuevamente (solo numero flotante):\n", 0, 1000000);

        auxSector=getValidInt("\nIngrese sector:\n"," Error, ingrese sector nuevamente (solo numero):\n", 1, 10);

        arrayEmpleados[vacio].id=auxId;
        strcpy(arrayEmpleados[vacio].nombre, auxName);
        strcpy(arrayEmpleados[vacio].apellido, auxLastName);
        arrayEmpleados[vacio].salario=auxSalary;
        arrayEmpleados[vacio].sector=auxSector;
        arrayEmpleados[vacio].isEmpty = 0;
        retorno = 0;
    }

    if(retorno==0)
    {
        printf("\nEmpleado cargado con exito!\n");
    }


    return retorno;
}

int buscarLibre(eEmpleado arrayEmpleados[],int cantidad)
{
    int i;
    int retorno = -1;
    for(i=0;i<cantidad;i++)
    {
        if(arrayEmpleados[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}



int removeEmployee(eEmpleado arrayEmpleados[],int cantidad)//listo
{
    system("cls");
    int id;
    int indice;
    int retorno=-1;
    printEmployees(arrayEmpleados,cantidad);
    printf("\n\nIngrese el id del empleado que quiere dar de baja: ");
    fflush(stdin);
    scanf("%d",&id);
    indice = findEmployeeById(arrayEmpleados,cantidad,id);
    if(indice>=0)
    {
        arrayEmpleados[indice].isEmpty = 1;
        printf ("\n El empleado fue dado de baja con exito.\n");
        system ("pause");
        retorno=1;
    }
    else
    {
        printf("Error!. Ese id no existe.\n");
        system ("pause");
    }
    return retorno;
}

int modificarEmployee(eEmpleado arrayEmpleados[],int cantidad)
{
    system("cls");
    int retorno=-1;
    int indice;
    int id;
    int opcion;
    char opcion2;
    char auxNewName[31];
    char auxNewLastName[31];
    float auxNewSalary;
    int auxNewSector;

    printEmployees(arrayEmpleados,cantidad);
    printf("\n\nIngrese el id del empleado a modificar: \n");
    fflush(stdin);
    scanf("%d",&id);

    indice = findEmployeeById(arrayEmpleados,cantidad,id);

    if(arrayEmpleados != NULL)
    {
        if(indice>=0)
        {
            do{
                system("cls");
                printEmployees(arrayEmpleados, cantidad);

                printf("\nQue campo quiere modificar?\n");
                printf("\n1_Nombre: %s\n2_Apellido: %s\n3_Salario: %f\n4_Sector: %d\n\nElija una opcion :",arrayEmpleados[indice].nombre,
                arrayEmpleados[indice].apellido,arrayEmpleados[indice].salario,arrayEmpleados[indice].sector);
                fflush(stdin);
                scanf("%d",&opcion);
                system("cls");

                switch(opcion)
                {
                    case 1:

                        getValidString(" Ingrese nuevo nombre: "," Error, ingrese nuevamente:", auxNewName);
                        strcpy(arrayEmpleados[indice].nombre, auxNewName);
                        break;
                    case 2:

                        getValidString(" Ingrese nuevo apellido: "," Error, ingrese nuevamente:", auxNewLastName);
                        strcpy(arrayEmpleados[indice].apellido, auxNewLastName);
                        break;
                    case 3:

                        auxNewSalary=getValidFloat(" Ingrese nuevo salario: \n"," Error, el salario no es valido.\n", 0, 1000000);
                        arrayEmpleados[indice].salario=auxNewSalary;
                        break;
                    case 4:

                        auxNewSector=getValidInt(" Ingrese nuevo sector: \n"," Error, el sector no es valido.\n", 0, 200);
                        arrayEmpleados[indice].sector=auxNewSector;
                        break;
                    default:
                        printf("\nError: opcion no valida, elija una opcion del 1 al 4.\n");
                        system("pause");
                        system("cls");
                        break;
                }
                printf("Desea continuar? s/n \n :");
                fflush(stdin);
                scanf("%c",&opcion2);
                system("pause");
                system("cls");
            }while(opcion2=='s' || opcion2=='S');
        }
        else if(indice<0)
        {
            printf("No existe ese id");
            system("pause");
        }
        retorno=0;
    }
    return retorno;
}


int idEmployee(eEmpleado arrayEmpleados[],int indice,int cantidad)
{
    int retorno = 0;
    int i;
    int comparacion;
    printf("\nID: ");
    fflush(stdin);
    scanf("%d",&arrayEmpleados[indice].id);
    for(i=0;i<cantidad;i++)
    {
        if(arrayEmpleados[i].isEmpty == 0)
        {
            for(comparacion=i+1;comparacion<cantidad;comparacion++)
            {
                if((arrayEmpleados[comparacion].isEmpty == 0) && (arrayEmpleados[i].id == arrayEmpleados[comparacion].id))
                {
                    retorno = -1;
                }
            }
        }
    }
    return retorno;
}



int printEmployees(eEmpleado arrayEmpleados[],int cantidad)
{
    int i;
    int retorno=-1;
    if(arrayEmpleados!=NULL)
    {
        printf("\n%5s %20s %20s %10s %3s \n", "ID","Nombre","Apellido","Sueldo","Sector");
        for(i=0;i<cantidad;i++)
        {
            if(arrayEmpleados[i].isEmpty == 0)
            {
                printf ("%5d %20s %20s %10.2f %3d\n", arrayEmpleados[i].id, arrayEmpleados[i].nombre, arrayEmpleados[i].apellido, arrayEmpleados[i].salario, arrayEmpleados[i].sector);
                retorno=0;
            }
        }
    }
    return retorno;
}

int sortEmployees(eEmpleado arrayEmpleados[],int cantidad)
{
    int i;
    int comparacion;
    int retorno=-1;
    for(i=0;i<cantidad;i++)
    {
        if(arrayEmpleados[i].isEmpty == 0)
        {
            for(comparacion=i+1;comparacion<cantidad;comparacion++)
            {
                if((arrayEmpleados[comparacion].isEmpty==0) && (strcmp(arrayEmpleados[i].apellido,arrayEmpleados[comparacion].apellido)>0))
                {
                    intercambio(arrayEmpleados,i,comparacion);
                }
                else if((arrayEmpleados[comparacion].isEmpty==0) && (arrayEmpleados[i].sector<=arrayEmpleados[comparacion].sector))
                {
                    intercambio(arrayEmpleados,i,comparacion);
                }
            }
        }
        retorno=0;
    }

    return retorno;
}

void intercambio(eEmpleado arrayEmpleados[],int indice1,int indice2)
{
    eEmpleado aux;
    aux = arrayEmpleados[indice1];
    arrayEmpleados[indice1] = arrayEmpleados[indice2];
    arrayEmpleados[indice2] = aux;
}

int findEmployeeById(eEmpleado arrayEmpleados[],int cantidad,int id)
{
    int i,retorno=-1;
    for(i=0;i<cantidad;i++)
    {
        if(arrayEmpleados[i].isEmpty == 0 && arrayEmpleados[i].id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void printSalarios(eEmpleado arrayEmpleados[], int cantidad)
{
    float promedio=0;
    float total=0;
    int contadorEmpleados=0;
    int contadorSalarios=0;

    for(int i=0; i<cantidad; i++)
    {
        if(arrayEmpleados[i].isEmpty == 0)
        {
            contadorEmpleados++;
            total=total+arrayEmpleados[i].salario;
        }
    }
    promedio= total/contadorEmpleados;

    for(int i=0; i<cantidad; i++)
    {
        if(arrayEmpleados[i].isEmpty == 0)
        {
            if(arrayEmpleados[i].salario>promedio)
            {
                contadorSalarios++;
            }
        }
    }
    printf("\nEl total de los salarios es: %.2f\n", total);
    printf("El promedio de los salarios es: %.2f\n", promedio);
    printf("La cantidad de Empleados que superan el promedio: %d\n", contadorSalarios);
}


