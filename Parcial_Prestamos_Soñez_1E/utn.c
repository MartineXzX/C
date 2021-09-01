#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "utn.h"

void mensaje(char* cadena)
{
    printf("%s",cadena);
}

char getCaracter(char* mensaje)
{
    char caracter;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&caracter);
    return caracter;
}

char confirma(char* mensaje)
{
    char respuesta;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&respuesta);
    return respuesta;
}

void inputStr(char* mensaje, char* str)
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(str);
}

int esNumerico(char* string)
{
    int i=0;
    int returnValue=1;

    while(string[i]!='\0')
    {
        if(string[i]<'0' || string[i]>'9')
        {
            returnValue=0;
        }
        i++;
    }
    return returnValue;
}

int inputInt(char* string)
{
    int numero;

    printf("%s",string);
    scanf("%d",&numero);
    return numero;
}

int inputValidInt(char* message,char* errorMessage,int minimum,int maximum,int retries)
{
    int numero;
    char auxNum[20];

    if(message!=NULL && errorMessage!=NULL && minimum>0 && maximum>=minimum)
    {
        do
        {
            inputStr(message,auxNum);

            if(esNumerico(auxNum))
            {
                if(maximum==0 || ((atoi(auxNum)<=maximum) && atoi(auxNum)>=minimum))
                {
                    numero=atoi(auxNum);
                    break;
                }
                else
                {
                    printf("Debe introducir una opcion entre %d y %d ",minimum,maximum);
                }
            }
            else
            {
                printf("%s",errorMessage);
                retries--;
            }
        }
        while(retries>0);

    }
    return numero;
}

float inputFloat(char* string)
{
    float numero;

    printf("%s",string);
    scanf("%f",&numero);
    return numero;
}

int validFloat(char str[])
{
    int i=0;
    int validation = 1;
    int contDot = 0;
    int contNum = 0;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9' )
        {
            if( str[i] != '.')
            {
                validation = 0;
            }
            else if( str[i] == '.')
            {
                contDot++;
            }
        }
        else
        {
            contNum++;
        }
        i++;
    }
    if(contDot > 1)
    {
        validation = 0;
    }

    if(contDot == 1 && contNum < 1)
    {
        validation = 0;
    }
    if(str[0] == '.')
    {
        validation = 0;
    }

    return validation;
}

float inputValidFloat(char message[], int max)
{
    float value;
    char input[500] ;
    int length;
    int salida = 1;

    do
    {
        if(max < 0)
        {
            printf("\nPor favor, ingrese un numero positivo.\n");
            break;
        }
        inputStr(message,input);
        length = strlen (input);
        if(length > 0)
        {
            if(validFloat(input))
            {
                if(max == 0 || atoi(input) <= max)
                {
                    value = atof(input);
                    salida = 0;
                }
                else
                {
                    printf("\nPor favor, ingrese un numero entre 0 y %d.\n",max);
                }
            }
            else
            {
                printf("\nPor favor, ingrese solo numeros.\n");
            }
        }
        else
        {
            if(length == 0)
            {
                printf("\nPor favor, complete este campo.\n");
            }
        }

    }
    while(salida);

    return value;
}

void cuilValido(char* cadena,char* mensaje,char* mensajeError,int reintentos)
{
    char cuil[15];
    int i=0;
    int length;
    inputStr(mensaje,cuil);
    length=strlen(cuil);

    if(cuil!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
    {
        while(cuil[i]!='\0')
        {
            if((cuil[2]=='-' && cuil[11]=='-' && length==13) ||(length==11))
            {
                strcpy(cadena,cuil);
                break;
            }
            else
            {
                printf("%s\n",mensajeError);
                inputStr(mensaje,cuil);
                if(cuil[2]=='-' && cuil[11]=='-')
                {
                    strcpy(cadena,cuil);
                    break;
                }
            }
            i++;
        }
        reintentos--;
    }
}

int getString(char* pAux,int limit)
{
    char auxString[100];
    int returnValue =-1;
    if (pAux != NULL && limit >0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);
        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limit)
        {
            strncpy(pAux,auxString,limit);
            returnValue=0;
        }
    }
    return returnValue;
}


int utnGetString(char *pAux,int limit,int retries,char* mensaje,char*mensajeError)
{
    int returnValue=-1;
    char auxString[limit];
    if(pAux!=NULL && limit >0 && retries >=0)
    {
        do
        {
            retries--;
            printf("%s",mensaje);
            if(getString(auxString,limit)==0 && sonLetras(auxString)==0)
            {
                strncpy(pAux,auxString,limit);
                returnValue=0;
                break;
            }
            else
                printf("%s",mensajeError);
        }
        while(retries>=0);
    }
    return returnValue;
}

int sonLetras(char*pAux)
{
    int returnValue=-1;
    int i=0;
    if(pAux!=NULL)
    {
        do
        {
            if(((*(pAux+i)<65 && *(pAux+i)!=32)||*(pAux+i)>90) && (*(pAux+i)<97||*(pAux+i)>122))
            {
                break;
            }
            i++;
        }
        while(i<strlen(pAux));
        if(i==strlen(pAux))
        {
            returnValue=0;
        }
    }
    return returnValue;
}

int menu()
{
    int opcion;

    printf("-------Menu de opciones-------\n\n");
    printf("|1-Alta Cliente               |\n");
    printf("|2-Modificar Cliente          |\n");
    printf("|3-Baja Cliente               |\n");
    printf("|4-Nuevo Prestamo             |\n");
    printf("|5-Saldar Prestamo            |\n");
    printf("|6-Reanudar Prestamo          |\n");
    printf("|7-Imprimir clientes          |\n");
    printf("|8-Imprimir Prestamos         |\n");
    printf("|9-Informes Clientes          |\n");
    printf("|10-Informes Prestamos        |\n");
    printf("|11-Salir                     |\n");
    printf("------------------------------");
    opcion=inputValidInt("\nIngrese una opcion: ","\nIngrese una opcion corecta por favor.\nSolo numeros.\n",1,11,3);

    return opcion;
}
