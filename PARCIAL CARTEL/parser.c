#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "eCartel.h"

int parser_ServiciosFromText(FILE* pFile, LinkedList* pArrayListServicios)
{
    if (pFile == NULL || pArrayListServicios == NULL)
    {
        printf("\nArchivo no encontrado o no se encontro la lista.\n\n");
        return -1;
    }
    int parsedServices = 0;
    int nonParsedServices = 0;

    eCartel *newFromText = Servicio_New();
    if(newFromText == NULL)
    {
        printf("\nNo se pudo encontrar espacio para guardar mas Servicios.\n\n");
        return -1;
    }
    char dataFromText[6][150];

    int cantArt = ll_len(pArrayListServicios);
    int lastID;
    if(cantArt > 0)
    {
        eCartel *lastElem = ll_get(pArrayListServicios, cantArt);
        Servicio_getId(lastElem, &lastID);
    }

    while (!feof(pFile))
    {

        int cantParams = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",dataFromText[0], dataFromText[1], dataFromText[2], dataFromText[3], dataFromText[4], dataFromText[5]);
        if (cantParams != 6)
        {
            printf("\nHubo un problema en la carga de un dato.\n\n");
            break;
        }
        if(!isdigit(dataFromText[0][0]))
            continue;

        if(cantArt > 0 && atoi(dataFromText[0]) < lastID)
        {
            nonParsedServices++;
            continue;
        }
        newFromText = Servicio_add(dataFromText[0], dataFromText[1], dataFromText[2],dataFromText[3], dataFromText[4], dataFromText[5]);
        ll_add(pArrayListServicios, newFromText);
        parsedServices++;
    }
    if(parsedServices)
        printf("\nDatos cargados correctamente. %d Servicios\n\n", parsedServices);

    if(nonParsedServices)
        printf("\nSe han omitido %d Servicios. Ya habian sido cargados.\n\n", nonParsedServices);

    return 1;
}

