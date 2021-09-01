#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "utn.h"
#include "prestamos.h"
#include "clientes.h"

void iniciarPrestamos(ePrestamos vecPrestamos[],int tamPrestamos)
{
    for(int i=0; i<tamPrestamos; i++)
    {
        vecPrestamos[i].clienteId=0;
        vecPrestamos[i].prestamoCuotas=0;
        vecPrestamos[i].prestamoEstado=INACTIVO;
        vecPrestamos[i].prestamoId=0;
        vecPrestamos[i].prestamoImporte=0;
        vecPrestamos[i].isEmpty=1;
    }
}

ePrestamos nuevoPrestamo(int clienteId,float prestamoImporte,int prestamoCuotas,int prestamoId)
{
    ePrestamos Prestamo;

    Prestamo.clienteId=clienteId;
    Prestamo.prestamoCuotas=prestamoCuotas;
    Prestamo.prestamoImporte=prestamoImporte;
    Prestamo.prestamoId=prestamoId;
    Prestamo.isEmpty=0;
    Prestamo.prestamoEstado=ACTIVO;

    return Prestamo;
}

int autoIdPrestamos()
{
    static int prestamoId=100;
    return prestamoId++;
}

int prestamosActivos(ePrestamos vecPrestamos[],int tamPrestamos)
{
    int cont=0;
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoEstado==ACTIVO)
        {
            cont++;
        }
    }
    return cont;
}

int buscarLibrePrestamos(ePrestamos vecPrestamos[],int tamPrestamos)
{
    int indice=-1;
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int altaPrestamo(ePrestamos vecPrestamos[],int tamPrestamos,eClientes vecClientes[],int tamClientes)
{
    int emptySpace=-1;
    int idPrestamo;
    int idCliente;
    int idClienteMaximo;
    int idClienteMinimo;
    int prestamoCuotas;
    float prestamoImporte;
    idPrestamo=autoIdPrestamos();
    emptySpace=buscarLibrePrestamos(vecPrestamos,tamPrestamos);
    ultimoIdRegistrado(vecClientes,tamClientes,&idClienteMaximo);
    primerIdRegistrado(vecClientes,tamClientes,&idClienteMinimo);

    if(emptySpace!=-1)
    {
        listarClientes(vecClientes,tamClientes,vecPrestamos,tamPrestamos);
        idCliente=inputValidInt("\nIngrese un ID de un cliente: \n","\nNo ha ingresado un ID valido. Intente nuevamente: \n",idClienteMinimo,idClienteMaximo,3);
        prestamoImporte=inputValidFloat("\nIngrese el importe del prestamo: \n",1000000);
        prestamoCuotas=inputValidInt("\nIngrese la cantidad de cuotas: \n","\nPor favor, ingrese un tipo de dato valido. \n",1,48,3);
        vecPrestamos[emptySpace]=nuevoPrestamo(idCliente,prestamoImporte,prestamoCuotas,idPrestamo);
        printf("\nPrestamo registrado con exito\n");
        encabezadoInfoPrestamo();
        listarPrestamo(vecPrestamos[emptySpace],vecClientes,tamClientes);
    }

    else
    {
        printf("\nNo se pueden agregar mas prestamos\n");
    }

    return emptySpace;
}

int saldarPrestamo(ePrestamos vecPrestamos[],int tamPrestamos,int prestamoId,eClientes vecClientes[],int tamClientes)
{
    int idPrestamo;
    int contActivos;
    int indice;
    char confirm='n';
    contActivos=cantidadPrestamosActivos(vecPrestamos,tamPrestamos);
    if(contActivos>0)
    {
        listarPrestamos(vecPrestamos,tamPrestamos,vecClientes,tamClientes);
        indice=buscarPrestamoActivoId(vecPrestamos,tamPrestamos,&idPrestamo,vecClientes,tamClientes);


        if(indice!=-1)
        {
            confirm=confirma("\nQuiere confirmar el prestamo saldado? s/n: \n");
            if(confirm=='s')
            {
                vecPrestamos[indice].prestamoEstado=SALDADO;
                mensaje("\nPrestamo saldado con exito\n");
            }
            else
            {
                mensaje("\nEl prestamo seguira activo.\n");
            }
        }
    }
    else
    {
        mensaje("No hay prestamos para saldar");
    }
    return indice;
}

int reanudarPrestamo(ePrestamos vecPrestamos[],int tamPrestamos,int prestamoId,eClientes vecClientes[],int tamClientes)
{
    int idPrestamo;
    int indice;
    char confirm='n';
    int contSaldados=0;
    contSaldados=cantidadPrestamosSaldados(vecPrestamos,tamPrestamos);
    if(contSaldados>0)
    {
        encabezadoInfoPrestamo();
        listarPrestamosSaldados(vecPrestamos,tamPrestamos,vecClientes,tamClientes);
        indice=buscarPrestamoSaldadoId(vecPrestamos,tamPrestamos,&idPrestamo,vecClientes,tamClientes);


        if(indice!=-1 && indice!=-2)
        {
            confirm=confirma("\nQuiere confirmar la reactivacion del prestamo? s/n: \n");
            if(confirm=='s')
            {
                vecPrestamos[indice].prestamoEstado=ACTIVO;
                mensaje("\nPrestamo nuevamente activo\n");
            }
            else
            {
                mensaje("\nEl prestamo seguira saldado.\n");
            }
        }
    }
    else
    {
        mensaje("\nNo hay prestamos para reactivar");
    }
    return indice;
}



void listarPrestamo (ePrestamos Prestamo,eClientes vecClientes[],int tamClientes)
{
    char cuil[14];
    getCuilCliente(vecClientes,tamClientes,Prestamo.clienteId,cuil);
    printf("\n%6d %15d %20s %13.2f %5d\n",Prestamo.prestamoId,Prestamo.clienteId,cuil,Prestamo.prestamoImporte,Prestamo.prestamoCuotas);
}

void listarPrestamos(ePrestamos vecPrestamos[],int tamPrestamos,eClientes vecClientes[],int tamClientes)
{
    encabezadoInfoPrestamo();
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoEstado==ACTIVO && vecPrestamos[i].isEmpty==0)
        {
            listarPrestamo(vecPrestamos[i],vecClientes,tamClientes);
        }
    }
}

int cantidadPrestamosSaldadosCliente(ePrestamos vecPrestamos[],int tamPrestamos,int clienteId)
{
    int contPrestamos=0;
    for(int i=0; i<tamPrestamos; i++)
    {


        if(vecPrestamos[i].prestamoEstado==SALDADO && vecPrestamos[i].clienteId==clienteId)
        {
            contPrestamos++;
        }

    }
    return contPrestamos;
}

void listarPrestamosSaldados(ePrestamos vecPrestamos[],int tamPrestamos,eClientes vecClientes[],int tamClientes)
{
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoEstado==SALDADO && vecPrestamos[i].isEmpty==0)
        {
            listarPrestamo(vecPrestamos[i],vecClientes,tamClientes);
        }
    }
}

int cantidadPrestamosCliente(ePrestamos vecPrestamos[],int tamPrestamos,int clienteId)
{
    int contPrestamos=0;
    for(int i=0; i<tamPrestamos; i++)
    {


        if(vecPrestamos[i].prestamoEstado==ACTIVO && vecPrestamos[i].clienteId==clienteId)
        {
            contPrestamos++;
        }

    }
    return contPrestamos;
}

void listarPrestamosCliente(eClientes vecClientes[],ePrestamos vecPrestamos[],int tamClientes,int tamPrestamos,int* clienteId)
{
    encabezadoInfoPrestamo();
    for(int i=0; i<tamPrestamos; i++)
    {
        for(int j=0; j<tamClientes; j++)
        {
            if(vecPrestamos[i].clienteId == vecClientes[j].clienteId && vecPrestamos[i].clienteId==*clienteId && vecClientes[j].clienteId==*clienteId)
            {
                listarPrestamo(vecPrestamos[i],vecClientes,tamClientes);
            }
        }
    }
}

int cantidadPrestamosActivos(ePrestamos vecPrestamos[],int tamPrestamos)
{
    int contActivos=0;

    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoEstado==ACTIVO)
        {
            contActivos++;
        }
    }
    return contActivos;
}

int cantidadPrestamosSaldados(ePrestamos vecPrestamos[],int tamPrestamos)
{
    int contSaldados=0;

    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoEstado==SALDADO)
        {
            contSaldados++;
        }
    }
    return contSaldados;
}

int buscarPrestamoId(ePrestamos vecPrestamos[],int tamPrestamos,int* idPrestamo,eClientes vecClientes[],int tamClientes)
{

    *idPrestamo=inputInt("\nIngrese numero de prestamo: ");
    int indice=-1;
    printf("Prestamo:\n");
    encabezadoInfoPrestamo();
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoId==*idPrestamo)
        {
            listarPrestamo(vecPrestamos[i],vecClientes,tamClientes);
            indice=i;
            break;
        }
        else
        {
            continue;
        }
    }
    if(indice==-1)
    {
        mensaje("No se ha encontrado el id!\n");
    }

    return indice;
}

int buscarPrestamoActivoId(ePrestamos vecPrestamos[],int tamPrestamos,int* idPrestamo,eClientes vecClientes[],int tamClientes)
{

    *idPrestamo=inputInt("\nIngrese numero de prestamo: ");
    int indice=-1;
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoId==*idPrestamo && vecPrestamos[i].prestamoEstado==ACTIVO)
        {
            printf("Prestamo:\n");
            encabezadoInfoPrestamo();
            listarPrestamo(vecPrestamos[i],vecClientes,tamClientes);
            indice=i;
            break;
        }
        else if(vecPrestamos[i].prestamoId==*idPrestamo && vecPrestamos[i].prestamoEstado==SALDADO)
        {
            indice=-2;
        }

        else
        {
            continue;
        }
    }
    if(indice==-1)
    {
        mensaje("No se ha encontrado el id!\n");
    }

    if(indice==-2)
    {
        mensaje("Este prestamo ya se encuentra saldado!");
    }

    return indice;
}

int buscarPrestamoSaldadoId(ePrestamos vecPrestamos[],int tamPrestamos,int* idPrestamo,eClientes vecClientes[],int tamClientes)
{

    *idPrestamo=inputInt("\nIngrese numero de prestamo: ");
    int indice=-1;
    for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].prestamoId==*idPrestamo && vecPrestamos[i].prestamoEstado==SALDADO)
        {
            printf("Prestamo:\n");
            encabezadoInfoPrestamo();
            listarPrestamo(vecPrestamos[i],vecClientes,tamClientes);
            indice=i;
            break;
        }
        else if(vecPrestamos[i].prestamoId==*idPrestamo && vecPrestamos[i].prestamoEstado==ACTIVO)
        {
            indice=-2;
        }

        else
        {
            continue;
        }
    }
    if(indice==-1)
    {
        mensaje("No se ha encontrado el id!\n");
    }

    if(indice==-2)
    {
        mensaje("Este prestamo ya se encuentra activo!");
    }

    return indice;
}

void encabezadoInfoPrestamo()
{
    printf("ID PRESTAMO   ID CLIENTE     CUIL CLIENTE      IMPORTE     CUOTAS");
}
