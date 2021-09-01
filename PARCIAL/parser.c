#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "eArticulo.h"

int parser_ArticulosFromText(FILE* pFile, LinkedList* pArrayListArticulos)
{
    if (pFile == NULL || pArrayListArticulos == NULL)
    {
        printf("Archivo no encontrado o no se encontro la lista.\n");
        return -1;
    }
    int parsedArticles = 0;
    int nonParsedArticles = 0;

    eArticulo *newFromText = articulo_new();
    if(newFromText == NULL)
    {
        printf("No se pudo encontrar espacio para guardar mas Articulos.\n");
        return -1;
    }
    char dataFromText[5][100];

    int cantArt = ll_len(pArrayListArticulos);
    int lastID;
    if(cantArt > 0)
    {
        eArticulo *lastElem = ll_get(pArrayListArticulos, cantArt);
        articulo_getIdArticulo(lastElem, &lastID);
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
            nonParsedArticles++;
            continue;
        }
        newFromText = articulo_add(dataFromText[0], dataFromText[1], dataFromText[2],dataFromText[3], dataFromText[4]);
        ll_add(pArrayListArticulos, newFromText);
        parsedArticles++;
    }
    if(parsedArticles)
        printf("Datos cargados correctamente. %d Articulos\n", parsedArticles);

    if(nonParsedArticles)
        printf("Se han omitido %d Articulos. Ya habian sido cargados.\n", nonParsedArticles);

    return 1;
}
