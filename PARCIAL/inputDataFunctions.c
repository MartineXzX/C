#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arrayFunctions.h"
#include "inputDataFunctions.h"
/*
 * Los arrays Y punteros no pueden ser null VALDAR
 * Faltan algunas funciones por documentar.
 *
 */

int getInt(int *pResultado)
{

    char buffer[64];
    fflush(stdin);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';

    if (isStringFullOfNumbers(buffer) > 0)
    {
        *pResultado = atoi(buffer);
        return 1;
    }
    else if (buffer[0] == 's')
    {
        return -2;
    }
    else
    {
        return 0;
    }

}

int getFloat(float *pResultado)
{

    char buffer[64];
    fflush(stdin);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';
    if (isStringFullOfNumbers(buffer) > 0)
    {
        *pResultado = atof(buffer);
        return 1;
    }
    else if (buffer[0] == 's')
    {
        return -2;
    }
    else
    {
        return 0;
    }

}

int getNumberBetweenTwo(int *pResultado, char *msg, int minimo, int maximo,int reintentos)
{

    int inputBufferInt = 0;
    int rta = -1;
    int i=0;

    printf("%s\n", msg);
    do
    {

        rta = getInt(&inputBufferInt);
        *pResultado = (int)inputBufferInt;
        if (rta > 0 && (inputBufferInt >= minimo && inputBufferInt <= maximo))
        {
            return 1;
        }
        if(rta == -2 && i > 0)
            return -2;

        i++;
        reintentos--;
        if (reintentos > 0)
        {
            if(reintentos == 1)
            {
                printf("Por favor ingrese un numero comprendido entre %d y el %d. 's' para Salir. Ultimo Intento \n",minimo, maximo);
            }
            else
            {
                printf("Por favor ingrese un numero comprendido entre %d y el %d. 's' para Salir. Intentos [%d] \n",minimo, maximo, reintentos);
            }
        }
    }
    while(reintentos > 0);

    return -1;

}

void getString(char *msg, char *buffer)
{

    printf("%s\n", msg);
    fflush(stdin);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer)] = '\0';

}


int getIntNumber(int *pResultado, char *msg, int reintentos)
{

    int inputBufferInt = 0;
    printf("%s\n", msg);

    do
    {

        if ((getInt(&inputBufferInt) == 1))
        {
            *pResultado = (int) inputBufferInt;
            return 1;
        }

        reintentos--;
        if (reintentos > 0)
        {
            printf("Por favor ingrese solamente numeros.\n");
        }
    }
    while (reintentos > 0);

    return -1;

}

int getFloatNumber(float *pResultado, char *msg, int reintentos)
{

    float inputBufferInt = 0;

    do
    {
        printf("%s\n", msg);

        if ((getFloat(&inputBufferInt) == 1))
        {
            *pResultado = (float) inputBufferInt;
            return 1;
        }

        reintentos--;
        if (reintentos > 0)
        {
            printf("Por favor ingrese un numero. Quedan %d intentos.\n", reintentos);
        }
    }
    while (reintentos > 0);

    return -1;

}

int isStringFullOfNumbers(char *str)
{

    int retrn = -1;
    if (str != NULL)
    {

        int points = 0;
        int i;
        for (i = 0; str[i] != '\0'; i++)
        {
            if (i == 0 && (str[i] == '-' || str[i] == '+'))
            {
                continue;
            } //Si encuentra un menos en la primera posicion, salta un ciclo

            if ((!isdigit(str[i]) && str[i] != '.') || (str[i + 1] == '\0' && str[i] == '.') || points > 1)
            {
                return -1;

            }

            if (str[i] == '.')
            {
                points++;
            }
            else if (isdigit(str[i]))
            {
                retrn = 1;
            }

        }
        if (points == 1)
        {
            retrn = 2;
        }

    }
    return retrn;
}

int countLettersStr(char* buffer)
{

    if (buffer[0] == 0) //Si mando enter Directo (NULL)
        return 0;

    int i;
    for (i = 0; buffer[i] != '\0'; i++) {}


    return i;
}




