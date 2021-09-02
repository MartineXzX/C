/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"



int main()
{
    int opcion,division;
    double operador1 = 0;
    double operador2 = 0;
    double suma,resta,multiplicacion,resultadoDivision;
    double factorial1 ;
    double factorial2 ;
    int flagValidarOperaciones = 0;
    setbuf(stdout, NULL);

    do
    {
        printf("\n|========>[CALCULADORA]<========|\n");

        mostrarMenu(operador1, operador2);

        opcion=GetInt("\nIngrese una Opcion:", "La opcion ingresada es incorrecta.\n",0,6);

        switch(opcion)
        {
        case 1:
            system("cls");
            operador1 = getOperadorValido("\nIngrese el primer operador: \n","\nEl operador ingresado no es valido.\n\n");
            system("cls");
            break;
        case 2:
            system("cls");
            operador2 = getOperadorValido("\nIngrese el segundo operador: \n","\nEl operador ingresado no es valido.\n\n");
            system("cls");
            break;
        case 3:
            system("cls");

            if(operador1 == 0 && operador2 == 0)
            {
                printf("\nIngrese por lo menos un operador para realizar operaciones.\n\n");
            }
            else
            {
                flagValidarOperaciones = 1;
                suma = Suma(operador1,operador2);
                resta = Resta(operador1,operador2);
                multiplicacion = Multiplica(operador1,operador2);
                division = Divide(&resultadoDivision,operador1,operador2);

                if(operador1 >= 0 && operador1<= 170)
                {
                    factorial1 = factorial(operador1);
                }
                if(operador2 >= 0 && operador2 <= 170)
                {
                    factorial2 = factorial(operador2);
                }
                printf("\nSe realizaron todas las operaciones con exito,\nelija la opcion 4 para ver los resultados\n\n");
            }
            break;
        case 4:
            system("cls");
            if(flagValidarOperaciones == 0)
            {
                printf("\nNo se ha realizado ninguna operacion,\npor lo que no se obtuvieron resultados.\n\n");
            }
            else
            {
                printf("\nEl valor actual de A es: %.2lf y el valor actual de B es: %.2lf\n",operador1,operador2);
                printf("\nEl resultado de A+B es: %.2lf\n",suma);
                printf("\nEl resultado de A-B es: %.2lf\n",resta);
                if(division == 1)
                {
                    printf("\nEl resultado de A/B es: %.2lf\n",resultadoDivision);
                }
                else
                {
                    printf("\nNo se puede dividir por 0\n");
                }

                printf("\nEl resultado de A*B es: %.2lf\n",multiplicacion);

            if(operador1 < 0)
                {
                    printf("\nEl operador A es un numero negativo,\npor lo que no se puede obtener su factorial.\n");
                }
                else if(operador1 > 170)
                {
                    printf("\nEl factorial del operador A se encuentra fuera de rango.\n");
                    printf("\nEn esta calculadora se podra obtener los factoriales\n");
                    printf("\nsiempre y cuando el operador A o B,\n sean positivos y se encuentren entre 0 y 170\n");
                }
                else
                {
                    printf("\nEl factorial de A es: %.2lf  \n",factorial1);
                }
            if(operador2 < 0)
                {
                    printf("\nEl operador B es un numero negativo,\npor lo que no se puede obtener su factorial.\n");
                }
                else if(operador2 > 170)
                {
                    printf("\nEl factorial del operador B se encuentra fuera de rango.\n");
                    printf("\nEn esta calculadora se podra obtener los factoriales\n");
                    printf("\nsiempre y cuando el operador A o B,\n sean positivos y se encuentren entre 0 y 170\n\n");
                }
                else
                {
                    printf("\nEl factorial de B es: %.2lf  \n\n",factorial2);
                }
                flagValidarOperaciones = 0;
                system("pause");
                system("cls");
            }
            break;
        }
    }
    while(opcion != 5);
    return 0;
}


