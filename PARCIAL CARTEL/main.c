#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "inputDataFunctions.h"
#include "LinkedList.h"
#include "eCartel.h"
#include "Menu.h"


int main(void)
{

    int option = 0;
    LinkedList *listaServicios = ll_newLinkedList();
    int rtrn = -1;
    setbuf(stdout, NULL);

    do
    {
        doMenu();

        if (getNumberBetweenTwo(&option, "\nIngrese una Opcion.", 1, 7, 3) < 0)
        {
            rtrn = -1;
            break;
        }
        switch (option)
        {

        case 1:
        {
            char archiveName[1024];
            printf("\nIngrese el nombre del archivo. (Exceptuando su extension).\n\n");
            fflush(stdin);
            fgets(archiveName, sizeof(archiveName), stdin);
            archiveName[strlen(archiveName) - 1] = '\0';
            strcat(archiveName, ".csv");
            FILE *fp = fopen (archiveName, "r");
            parser_ServiciosFromText(fp,listaServicios);
            fclose(fp);
        }
        break;

        case 2:
        {
            if(!ll_sort(listaServicios, Servicio_NameOrder, 1))
            {
                printf("\nLos Servicios se han ordenado alfabeticamente!.\n\n");
            }
        }
        break;
        case 3:
        {
            listarServicios(listaServicios);
        }
        break;
        case 4:
        {
            if(!ll_map(listaServicios,Servicio_calcMedida))
            {
                printf("\nSe han modificado las medidas.\n\n");
            }
        }
        break;
        case 5:
        {
            FILE *fp;
            if ((fp = fopen("mapeado.csv", "w")) == NULL)
                break;
            if(!ll_printElementInText(listaServicios, Servicio_printServicio, fp))
            {
                printf("\nDatos guardados en mapeado.csv correctamente en Texto\n\n");
            }
            fclose(fp);

        }
        break;
        case 6:
            informes(listaServicios);
            break;

        case 7:
        {
            ll_deleteLinkedList(listaServicios);
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

