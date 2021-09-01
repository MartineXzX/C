#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "utn.h"
#include "prestamos.h"
#include "clientes.h"
#include "informes.h"

void informesClientes(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos)
{
    char seguir='s';

    do
    {
        switch(menuInformesClientes())
        {

        case 1:
            clienteMaxPrestamosActivos(vecClientes,vecPrestamos,tamClientes,tamPrestamos);
            break;

        case 2:
            clienteMaxPrestamosSaldados(vecClientes,vecPrestamos,tamClientes,tamPrestamos);
            break;

        case 3:
            seguir='n';
            break;


        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');
}

int menuInformesClientes()
{
    int opcion;
    printf("\n1-Cliente con mas prestamos activos\n2-Cliente con mas prestamos saldados\n3-Salir\n");
    opcion=inputValidInt("\nIngrese una opcion: \n","\nIngrese una opcion valida: \n",1,3,3);
    return opcion;
}

void informesPrestamos(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos)
{
    char seguir='s';

    do
    {
        switch(menuInformesPrestamos())
        {

        case 1:
            prestamosMayores1000(vecPrestamos,vecClientes,tamPrestamos,tamClientes);
            break;

        case 2:
            seguir='n';
            break;


        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');
}

void clienteMaxPrestamosSaldados(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos)
{
    int cont;
    int maximo=0;
    int idMax=0;
    int contValidacion=0;
    contValidacion=cantidadPrestamosSaldados(vecPrestamos,tamPrestamos);

    if(contValidacion>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            cont=0;
            for(int j=0; j<tamPrestamos; j++)
            {
                if(vecPrestamos[j].clienteId==vecClientes[i].clienteId && vecPrestamos[j].prestamoEstado==SALDADO)
                {
                    cont++;
                }
            }

            if(i==0)
            {
                maximo = cont;
            }
            else if(cont>maximo)
            {
                maximo=cont;
                idMax=i;
            }


        }

        printf("\nEl cliente que tiene mas prestamos saldados es: \n");
        encabezadoInfoClientesSaldados();
        listarClientePrestamosSaldados(vecClientes[idMax],vecPrestamos,tamPrestamos);
        printf("\n con %d prestamos saldados\n",maximo);
    }
    else
    {
        mensaje("\nNo hay prestamos saldados\n");
    }

}

void prestamosMayores1000(ePrestamos vecPrestamos[],eClientes vecClientes[],int tamPrestamos,int tamClientes)
{
    float importe;
    int verifico=-1;
    importe=inputFloat("\nIngrese el importe a buscar: \n");
    while(importe<1000)
    {
        mensaje("\nDebe ingresar un importe mayor a 1000\n");
        importe=inputFloat("\nIngrese el importe a buscar: \n");

    }
    encabezadoInfoPrestamo();
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoImporte==importe && importe>1000 && vecPrestamos[i].prestamoEstado==1 && vecPrestamos[i].isEmpty==0)
        {
            listarPrestamo(vecPrestamos[i],vecClientes,tamClientes);
            verifico=1;
        }
    }

    if(verifico==-1)
    {
        mensaje("\nNo se ha encontrado prestamo alguno con el importe indicado.\n");
    }
}


void clienteMaxPrestamosActivos(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos)
{
    int cont;
    int maximo=0;
    int idMax=0;
    int contValidacion=0;
    contValidacion=cantidadPrestamosActivos(vecPrestamos,tamPrestamos);
    if(contValidacion>0)
    {

        for(int i=0; i<tamClientes; i++)
        {
            cont=0;
            for(int j=0; j<tamPrestamos; j++)
            {
                if(vecPrestamos[j].clienteId==vecClientes[i].clienteId && vecPrestamos[j].prestamoEstado==1)
                {
                    cont++;
                }
            }

            if(i==0)
            {
                maximo = cont;
            }
            else if(cont>maximo)
            {
                maximo=cont;
                idMax=i;
            }
        }

        printf("\nEl cliente que tiene mas prestamos activos es: \n");
        encabezadoInfoClientes();
        listarCliente(vecClientes[idMax],vecPrestamos,tamPrestamos);
    }

    else
    {
        mensaje("\nNo hay prestamos activos.\n");
    }

}

int menuInformesPrestamos()
{
    int opcion;
    printf("\n1-Prestamos mayores a 1000\n2-Salir\n");
    opcion=inputValidInt("\nIngrese una opcion: ","\nIngrese una opcion valida: \n",1,2,3);
    return opcion;
}
