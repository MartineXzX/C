#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "eCatering.h"

int parser_ServiciosFromText(FILE* pFile, LinkedList* pArrayListServicios)
{
    if (pFile == NULL || pArrayListServicios == NULL)
    {
        printf("Archivo no encontrado o no se encontro la lista.\n");
        return -1;
    }
    int parsedServices = 0;
    int nonParsedServices = 0;

    eCatering *newFromText = Servicio_new();
    if(newFromText == NULL)
    {
        printf("No se pudo encontrar espacio para guardar mas Servicios.\n");
        return -1;
    }
    char dataFromText[5][100];

    int cantArt = ll_len(pArrayListServicios);
    int lastID;
    if(cantArt > 0)
    {
        eCatering *lastElem = ll_get(pArrayListServicios, cantArt);
        Servicio_getIdServicio(lastElem, &lastID);
    }

    while (!feof(pFile))
    {

        int cantParams = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",dataFromText[0], dataFromText[1], dataFromText[2], dataFromText[3], dataFromText[4]);
        if (cantParams != 5)
        {
            printf("Hubo un problema en la carga de un dato.\n");
            break;
        }
        if(!isdigit(dataFromText[0][0]))
            continue;

        if(cantArt > 0 && atoi(dataFromText[0]) < lastID)
        {
            nonParsedServices++;
            continue;
        }
        newFromText = Servicio_add(dataFromText[0], dataFromText[1], dataFromText[2],dataFromText[3], dataFromText[4]);
        ll_add(pArrayListServicios, newFromText);
        parsedServices++;
    }
    if(parsedServices)
        printf("Datos cargados correctamente. %d Servicios\n", parsedServices);

    if(nonParsedServices)
        printf("Se han omitido %d Servicios. Ya habian sido cargados.\n", nonParsedServices);

    return 1;
}
