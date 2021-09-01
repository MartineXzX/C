#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "inputDataFunctions.h"
#include "LinkedList.h"
#include "eArticulo.h"
#include "Menu.h"


int main(void)
{

    int option = 0;
    LinkedList *listaArticulos = ll_newLinkedList();
    int rtrn = -1;
    setbuf(stdout, NULL);
    doMenu();
    do
    {

        if (getNumberBetweenTwo(&option, "Ingrese una Opcion.", 1, 6, 3) < 0)
        {
            rtrn = -1;
            break;
        }
        switch (option)
        {

        case 1:
        {
            char archiveName[1024];
            printf("Ingrese el nombre del archivo. (Exceptuando su extension).\n");
            fflush(stdin);
            fgets(archiveName, sizeof(archiveName), stdin);
            archiveName[strlen(archiveName) - 1] = '\0';
            strcat(archiveName, ".csv");
            FILE *fp = fopen (archiveName, "r");
            parser_ArticulosFromText(fp,listaArticulos);
            fclose(fp);
        }
        break;

        case 2:
        {
            if(!ll_sort(listaArticulos, articulo_NameOrder, 1))
            {
                printf("Los articulos se han ordenado alfabeticamente!.\n");
            }
        }
        break;
        case 3:
        {
            listarArticulos(listaArticulos);
        }
        break;
        case 4:
        {
            if(!ll_map(listaArticulos,articulo_calcDescuento))
            {
                printf("Se han modificado los precios.\n");
            }
        }
        break;
        case 5:
        {
            FILE *fp;
            if ((fp = fopen("mapeado.csv", "w")) == NULL)
                break;
            if(!ll_printElementInText(listaArticulos, articulo_printArticulo, fp))
            {
                printf("Datos guardados en mapeado.csv correctamente en Texto\n");
            }
            fclose(fp);

        }
        break;
        case 6:
            informes(listaArticulos);
            break;

        case 7:
        {
            ll_deleteLinkedList(listaArticulos);
        }
        break;
        default:
        {
        } break;
        }
    }
    while (option != 7);

    rtrn = 0;
    return rtrn;
}

