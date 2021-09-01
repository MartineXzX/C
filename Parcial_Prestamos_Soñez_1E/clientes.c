#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "utn.h"
#include "prestamos.h"
#include "clientes.h"

void iniciarClientes(eClientes vecClientes[],int tamClientes)
{
    for(int i=0; i<tamClientes; i++)
    {
        vecClientes[i].isEmpty=1;
        vecClientes[i].clienteId=0;
        strcpy(vecClientes[i].nombre," ");
        strcpy(vecClientes[i].apellido," ");
        strcpy(vecClientes[i].cuil," ");
    }
}


eClientes nuevoCliente(int clienteId,char nombre[],char apellido[],char cuil[])
{

    eClientes cliente;
    cliente.clienteId = clienteId;
    strcpy(cliente.nombre,nombre);
    strcpy(cliente.apellido,apellido);
    strcpy(cliente.cuil,cuil);
    cliente.isEmpty = 0;

    return cliente;
}

int buscarLibre(eClientes vecClientes[],int tamClientes)
{
    int emptySpace=-1;
    for(int i=0; i<tamClientes; i++)
    {
        if(vecClientes[i].isEmpty==1)
        {
            emptySpace=i;
            break;
        }
    }

    return emptySpace;
}

int autoIdClientes()
{
    static int clienteId=1;
    return clienteId++;
}

int altaCliente(eClientes vecClientes[],int tamClientes)
{
    char name[NOMBRETAM],lastName[APELLIDOTAM];
    int emptySpace;
    int clienteId=autoIdClientes();
    char cuil[CUIL];

    emptySpace=buscarLibre(vecClientes,tamClientes);

    if(emptySpace==-1)
    {
        printf("\nNo se pueden agregar mas clientes.\n");
    }
    else
    {
        utnGetString(name,NOMBRETAM,3,"\nIngrese nombre del cliente: \n","\nIngrese un nombre valido\n");
        utnGetString(lastName,APELLIDOTAM,3,"\nIngrese apellido del cliente: \n","\nIngrese un apellido valido\n");
        cuilValido(cuil,"\nIngrese numero de cuil del cliente.(Ejemplo 00-11111111-22): \n","\nIngrese un cuil valido por favor: \n",5);
        vecClientes[emptySpace]=nuevoCliente(clienteId,name,lastName,cuil);

        printf("\nEl cliente ha sido registrado con exito.\n");

    }
    return emptySpace;
}

int clientesActivos(eClientes vecClientes[],int tamClientes)
{
    int activeCounter=0;
    for(int i=0; i<tamClientes; i++)
    {
        if(vecClientes[i].isEmpty==0)
        {
            activeCounter++;
        }
    }
    return activeCounter;
}


void encabezadoInfoClientes()
{
    mensaje("    ID      NOMBRE      APELLIDO      CUIL          CANTIDAD PRESTAMOS ACTIVOS ");

}

void encabezadoInfoClientesSaldados()
{
    mensaje("    ID      NOMBRE    APELLIDO       CUIL          CANTIDAD PRESTAMOS SALDADOS");

}

int getCuilCliente(eClientes vecClientes[],int tamClientes,int idCliente,char* cuilCliente)
{
    int retorno=-1;

    for(int i=0; i<tamClientes; i++)
    {
        if(vecClientes[i].clienteId==idCliente)
        {
            strcpy(cuilCliente,vecClientes[i].cuil);
            retorno=0;
            break;
        }
    }
    return retorno;
}

int ultimoIdRegistrado(eClientes vecClientes[],int tamClientes,int* ultimoId)
{
    int retorno=-1;

    for(int i=0; i<tamClientes; i++)
    {
        if(vecClientes[i].isEmpty==0)
        {
            *ultimoId=vecClientes[i].clienteId;
            retorno=0;
        }
    }

    return retorno;
}

void listarCliente(eClientes unCliente,ePrestamos vecPrestamos[],int tamPrestamos)
{
    int cantidadPrestamosUnCliente=0;
    cantidadPrestamosUnCliente=cantidadPrestamosCliente(vecPrestamos,tamPrestamos,unCliente.clienteId);
    printf("\n %5d %10s %15s %15s %10d\n",unCliente.clienteId,unCliente.nombre,unCliente.apellido,unCliente.cuil,cantidadPrestamosUnCliente);
}

void listarClientePrestamosSaldados(eClientes unCliente,ePrestamos vecPrestamos[],int tamPrestamos)
{
    int cantidadPrestamosSaldadosUnCliente=0;
    cantidadPrestamosSaldadosUnCliente=cantidadPrestamosSaldadosCliente(vecPrestamos,tamPrestamos,unCliente.clienteId);
    printf("\n %5d %10s %15s %10s %10d\n",unCliente.clienteId,unCliente.nombre,unCliente.apellido,unCliente.cuil,cantidadPrestamosSaldadosUnCliente);
}

void listarClientes(eClientes vecClientes[],int tamClientes,ePrestamos vecPrestamos[],int tamPrestamos)
{
    encabezadoInfoClientes();
    for(int i=0; i<tamClientes; i++)
    {
        if(vecClientes[i].isEmpty==0)
        {
            listarCliente(vecClientes[i],vecPrestamos,tamPrestamos);
        }
    }
}

int contTotalClientes(eClientes vecClientes[],int tamClientes)
{

    int contTotal=0;

    for(int i=0; i<tamClientes; i++)
    {
        if( (vecClientes[i].isEmpty==0) || (vecClientes[i].isEmpty==1 && vecClientes[i].clienteId==-1))
        {
            contTotal++;
        }
    }
    return contTotal;
}

int primerIdRegistrado(eClientes vecClientes[],int tamClientes,int* primerId)
{
    int retorno=-1;

    for(int i=0; i<tamClientes; i++)
    {
        if(vecClientes[i].isEmpty==0)
        {
            *primerId=vecClientes[i].clienteId;
            retorno=0;
            break;
        }
    }

    return retorno;
}

int modMenu()
{
    int option;
    printf("\n1-Modificar Nombre\n2-Modificar Apellido\n3-Modificar CUIL\n4-Salir");
    option=inputValidInt("\nIngrese opcion: ","Error ingrese un numero valido: ",1,4,4);
    return option;
}

int modCliente(eClientes vecClientes[],int tamClientes,int id,ePrestamos vecPrestamos[],int tamPrestamos)
{
    int verifico=1;
    int idCliente=0;
    int salida=1;
    int modificacion;
    char seguir='s';
    char nuevoNombre[NOMBRETAM];
    char nuevoApellido[APELLIDOTAM];
    char nuevoCuil[CUIL];
    listarClientes(vecClientes,tamClientes,vecPrestamos,tamPrestamos);
    modificacion=buscarClienteId(vecClientes,tamClientes,&idCliente);

    if(modificacion!=-1)
    {


        do
        {
            switch(modMenu())
            {
            case 1:
                utnGetString(nuevoNombre,NOMBRETAM,4,"\nIngrese el nuevo nombre: \n","\nIngrese un nombre valido: \n");
                strcpy(vecClientes[modificacion].nombre,nuevoNombre);
                verifico=1;
                system("cls");
                break;

            case 2:
                utnGetString(nuevoApellido,APELLIDOTAM,4,"\nIngrese el nuevo apellido: ","\nIngrese un apellido valido: \n");
                strcpy(vecClientes[modificacion].apellido,nuevoApellido);
                verifico=1;
                system("cls");
                break;


            case 3:
                cuilValido(nuevoCuil,"\nIngrese el nuevo cuil (00-11111111-22): \n","\nIngrese un cuil valido: \n",5);
                strcpy(vecClientes[modificacion].cuil,nuevoCuil);
                system("cls");
                break;

            case 4:
                salida=0;
                break;

            }
            if(seguir=='n' || seguir=='N')
            {
                salida=0;
            }
        }
        while(salida==1);

    }
    else
    {
        printf("\nIngrese un ID valido.\n");
    }
    return verifico;
}

int bajaCliente(eClientes vecClientes[],int tamClientes,ePrestamos vecPrestamos[],int tamPrestamos,int* idCliente)
{
    int verifico=-1;
    char respuesta;
    int remove;
    listarClientes(vecClientes,tamClientes,vecPrestamos,tamPrestamos);
    remove=buscarClienteId(vecClientes,tamClientes,idCliente);

    if(remove!=-1)
    {
        printf("\nEstos son los prestamos del cliente: %s %s: \n",vecClientes[remove].nombre,vecClientes[remove].apellido);

        listarPrestamosCliente(vecClientes,vecPrestamos,tamClientes,tamPrestamos,idCliente);
        respuesta=getCaracter("\nEsta seguro que desea eliminar este cliente? s/n: \n");

        if(respuesta=='s')
        {
            for(int i=0; i<tamClientes; i++)
            {
                if(vecClientes[i].clienteId==*idCliente)
                {
                    vecClientes[i].isEmpty=1;
                    vecClientes[i].clienteId=-1;
                    strcpy(vecClientes[i].nombre," ");
                    strcpy(vecClientes[i].apellido," ");
                    strcpy(vecClientes[i].cuil," ");
                }


                for(int j=0; j<tamPrestamos; j++)
                {
                    if(vecPrestamos[j].clienteId==*idCliente)
                    {
                        vecPrestamos[j].isEmpty=1;
                        vecPrestamos[j].clienteId=-1;
                        vecPrestamos[j].prestamoCuotas=0;
                        vecPrestamos[j].prestamoEstado=INACTIVO;
                        vecPrestamos[j].prestamoId=0;
                        vecPrestamos[j].prestamoImporte=0;

                    }
                }

            }
            mensaje("\nEl cliente ha sido removido con exito\n");

        }
        else
        {
            printf("\nEl cliente sigue activo.\n");
        }
        verifico=1;

    }

    else
    {
        mensaje("\nIntroduzca un ID valido por favor.(Seleccione uno de los que se muestran)\n");
    }

    return verifico;
}

int buscarClienteId(eClientes vecClientes[],int tamClientes,int* idCliente)
{

    *idCliente=inputInt("\nIngrese el ID del cliente: \n");
    int indice=-1;
    for(int i=0; i<tamClientes; i++)
    {
        if(vecClientes[i].clienteId==*idCliente)
        {
            printf("\nEl cliente seleccionado es: %s %s\n",vecClientes[i].nombre,vecClientes[i].apellido);
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
        mensaje("\nNo se ha encontrado el ID.\n");
    }
    return indice;
}
