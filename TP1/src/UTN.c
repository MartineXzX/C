/*
 * UTN.c
 *
 *  Created on: 16 abr. 2020
 *      Author: User
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"

void mostrarMenu(double a, double b)
{
	printf("\n1) Ingresar 1er operador (A=%.2lf)\n", a);
	printf("\n2) Ingresar 2do operador (B=%.2lf)\n", b);
	printf( "\n3) Calcular todas las operaciones.\n  ( suma ; resta ; multiplicacion ; division ; factorial )\n");
    printf( "\n4) Mostrar resultados (Realizar operaciones[opcion 3] cada vez que\nquiera mostrar resultados.\n");
    printf( "\n5) Salir.\n");
}

int GetInt(char texto[], char error[], int minimo, int maximo)
{
    int valida = 0;
    int numero;
    while(valida == 0 )
    {
        printf("%s \n",texto);
        fflush(stdin);
        scanf("%d",&numero);

        if(numero <= minimo || numero >= maximo)
        {
            system("cls");
            printf("%s \n ",error);
            printf("El valor ingresado tiene que ser un numero de las opciones que se muestran:\n ( 1 ; 2 ; 3 ; 4 ; 5 )\n\n");
            printf("Tener en cuenta que si no se ingreso al menos un operador,\n no se podra utilizar la opcion 3,\n por lo que la opcion 4 tampoco se podra utilizar\n hasta que se realicen las operaciones de la opcion 3.\n\n");
            system("pause");
            system("cls");
            return 0;

        }
        else
        {
            valida=1;
        }
    }
    return numero;

}

float getFloat(char texto[], char error[], int minimo, int maximo)
{
    int valida = 0;
    float numero;
    while(valida == 0 )
    {
        printf("%s \n",texto);
        fflush(stdin);
        scanf("%f",&numero);

        if(numero <= minimo || numero >= maximo)
        {
            system("cls");
            printf("%s \n ",error);
            printf("El valor ingresado tiene que ser un numero de las opciones que se muestran:\n ( 1 ; 2 ; 3 ; 4 ; 5 )\n\n");
            system("pause");
            system("cls");
            return 0;

        }
        else
        {
            valida=1;
        }
    }
    return numero;

}

double Suma(double operador1, double operador2)
{
    return operador1+operador2;
}

double Resta(double operador1, double operador2)
{
    return operador1-operador2;
}

double Multiplica(double operador1, double operador2)
{
    return operador1*operador2;
}

int Divide(double * respuesta,double operador1, double operador2)
{
    if (operador2 == 0)
    {
        return 0;
    }
    else
    {
        *respuesta=operador1/operador2;
        return 1;
    }
}

double getOperadorValido(char mensaje[],char mensajeError[])
{
    double operador;
    printf("%s",mensaje);
    fflush(stdin);
    if(scanf("%lf",&operador))
    {
        return operador;
    }
    else
    {
        printf("%s",mensajeError);
        system("pause");
        return 0;
    }


}
double factorial(double operador)
{
    double acumulador = 1;
    double i;
    for(i = operador; i>0; i--)
    {
        acumulador *= i;

    }
    return acumulador;

}


