/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployees.h"

int main()

	{
	    eEmpleado listaEmpleadosMain[MAX_EMPLEADOS];
	    initEmployees(listaEmpleadosMain,MAX_EMPLEADOS);
	    int opcion;
	    int bandera=0;
	    setbuf(stdout, NULL);
	    do
	    {
	        system("cls");
	        menuPrincipal();
	        fflush(stdin);
	        scanf("%d",&opcion);
	        switch(opcion)
	        {
	            case 1://ALTA
	                if(addEmployees(listaEmpleadosMain,MAX_EMPLEADOS)==0)
	                {
	                    bandera = 1;
	                }
	                break;
	            case 2://MOD
	                if(bandera == 1)
	                {
	                    modificarEmployee(listaEmpleadosMain,MAX_EMPLEADOS);
	                }
	                else
	                {
	                    printf("\nError!! Tiene que haber empleados ingresados primero!\n\n");
	                }
	                break;
	            case 3://BAJA
	                if(bandera == 1)
	                {
	                    removeEmployee(listaEmpleadosMain,MAX_EMPLEADOS);
	                }
	                else
	                {
	                    printf("\nError!! Tiene que haber empleados ingresados primero!\n\n");
	                }
	                break;
	            case 4://INFO
	                if(bandera == 1)
	                {
	                    sortEmployees(listaEmpleadosMain,MAX_EMPLEADOS);
	                    printEmployees(listaEmpleadosMain,MAX_EMPLEADOS);
	                    printSalarios(listaEmpleadosMain,MAX_EMPLEADOS);
	                }
	                else
	                {
	                    printf("\nError!! Tiene que haber empleados ingresados primero!\n\n");
	                }
	                break;
	            case 5:
	                printf("\nSaliendo...\nQue tenga buen dia!!!\n\n");
	                break;
	            default:
	                printf("\nError: opcion no valida.\n");
	                break;
	        }
	        system("pause");
	        system("cls");
	    }
	    while(opcion!=5);
	    return EXIT_SUCCESS;
}
