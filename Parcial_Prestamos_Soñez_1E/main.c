#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "utn.h"
#include "prestamos.h"
#include "informes.h"
#include "clientes.h"
int main()
{
    setbuf(stdout,NULL);
    eClientes vecClientes[CLIENTESTAM];
    iniciarClientes(vecClientes,CLIENTESTAM);
    ePrestamos vecPrestamos[PRESTAMOSTAM];
    iniciarPrestamos(vecPrestamos,PRESTAMOSTAM);
    char salir;
    int id=0;

    do
    {
        switch(menu())
        {
        case 1:
            altaCliente(vecClientes,CLIENTESTAM);
            break;

        case 2:
            if(clientesActivos(vecClientes,CLIENTESTAM)>0)
                modCliente(vecClientes,CLIENTESTAM,id,vecPrestamos,PRESTAMOSTAM);
            else
                mensaje("\nNo hay clientes activos, por lo que no se puede realizar una modificacion.\n");

            break;

        case 3:
            if(clientesActivos(vecClientes,CLIENTESTAM)>0)
                bajaCliente(vecClientes,CLIENTESTAM,vecPrestamos,PRESTAMOSTAM,&id);
            else

                mensaje("\nNo hay clientes activos, por lo que no se puede realizar una baja de cliente.\n");

            break;
        case 4:
            if(clientesActivos(vecClientes,CLIENTESTAM)>0)
                altaPrestamo(vecPrestamos,PRESTAMOSTAM,vecClientes,CLIENTESTAM);

            else

                mensaje("\nNo hay cliente alguno para asignarle un prestamo.\n");

            break;
        case 5:
            if(prestamosActivos(vecPrestamos,PRESTAMOSTAM)>0)
                saldarPrestamo(vecPrestamos,PRESTAMOSTAM,id,vecClientes,CLIENTESTAM);

            else
                mensaje("No hay prestamos para saldar");
            break;
        case 6:
            if(clientesActivos(vecClientes,CLIENTESTAM)>0)
                reanudarPrestamo(vecPrestamos,PRESTAMOSTAM,id,vecClientes,CLIENTESTAM);
            else
                mensaje("No hay prestamos para reanudar");
            break;
        case 7:
            if(clientesActivos(vecClientes,CLIENTESTAM)>0)
                listarClientes(vecClientes,CLIENTESTAM,vecPrestamos,PRESTAMOSTAM);
            else

                mensaje("\nNo hay clientes que imprimir.\n");

            break;

        case 8:

            if(prestamosActivos(vecPrestamos,PRESTAMOSTAM)>0)
                listarPrestamos(vecPrestamos,PRESTAMOSTAM,vecClientes,CLIENTESTAM);

            else

                mensaje("No hay prestamos que imprimir\n");

            break;


        case 9:
            if(clientesActivos(vecClientes,CLIENTESTAM)>0 && prestamosActivos(vecPrestamos,PRESTAMOSTAM)>0)
                informesClientes(vecClientes,vecPrestamos,CLIENTESTAM,PRESTAMOSTAM);

            else
                mensaje("\nNo se puede realizar informe alguno.(No hay clientes!!)\n");


            break;
        case 10:
            if(clientesActivos(vecClientes,CLIENTESTAM)>0 && prestamosActivos(vecPrestamos,PRESTAMOSTAM)>0)
                informesPrestamos(vecClientes,vecPrestamos,CLIENTESTAM,PRESTAMOSTAM);
            else
                mensaje("\nNo se puede realizar informe alguno.(No hay clientes!!)\n");

            break;

        case 11:
            salir=confirma("\nEsta seguro que desea salir? s/n: \n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(salir!='s');

    return 0;
}
