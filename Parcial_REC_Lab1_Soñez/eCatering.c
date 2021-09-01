#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "eCatering.h"
#include "inputDataFunctions.h"


eCatering* Servicio_new()
{

    eCatering *this = malloc(sizeof(eCatering));
    if (this != NULL)
    {

        Servicio_setIdServicio(this,0);
        Servicio_setPrecio(this, 0);
        Servicio_setNombre(this, " ");
        Servicio_setMedida(this, " ");
        Servicio_setRubro(this, 0);
    }

    return this;
}

eCatering* Servicio_add(char *idServicioStr, char *nombreStr, char *medidaStr, char *precioStr,  char *rubroStr)
{

    eCatering *this = Servicio_new();

    if (this == NULL)
        return NULL;

    Servicio_setIdServicio(this, atoi(idServicioStr));
    Servicio_setPrecio(this, atof(precioStr));
    Servicio_setNombre(this, nombreStr);
    Servicio_setMedida(this, medidaStr);
    Servicio_setRubro(this, atoi(rubroStr));


    return this;
}

int Servicio_setIdServicio(eCatering *this,int id_Servicio)
{

    if(this != NULL)
    {
        this->id_Servicio = id_Servicio;
    }
    return 0;
}

int Servicio_getIdServicio(eCatering *this,int *id_Servicio)
{

    if (this != NULL && id_Servicio != NULL)
    {
        *id_Servicio = this->id_Servicio;
    }
    return 0;
}

int Servicio_setPrecio(eCatering *this,float precio)
{

    if (this != NULL && precio >= 0)
    {
        this->precio = precio;
    }
    return 0;
}

int Servicio_getPrecio(eCatering *this, float *precio)
{

    if (this != NULL && precio != NULL)
    {
        *precio = this->precio;
    }
    return 0;
}

int Servicio_setNombre(eCatering *this,char *nombreCatering)
{

    if (this != NULL && nombreCatering != NULL)
    {
        short int cantLetras = countLettersStr(nombreCatering);
        if(cantLetras >= 3)
            strcpy(this->Servicio, nombreCatering);
        else
        {
            return -1;
        }
    }
    return 0;
}

int Servicio_getNombre(eCatering *this,char *nombreCatering)
{

    if (this != NULL && nombreCatering != NULL)
    {
        strcpy(nombreCatering, this->Servicio);
    }
    return 0;
}

int Servicio_setMedida(eCatering *this,char *medida)
{

    if (this != NULL && medida != NULL)
    {
        strcpy(this->medida, medida);
    }
    return 0;
}

int Servicio_getMedida(eCatering *this,char *medida)
{

    if (this != NULL && medida != NULL)
    {
        strcpy(medida, this->medida);
    }
    return 0;
}

int Servicio_setRubro(eCatering *this,short int rubroId)
{

    if (this != NULL && rubroId > 0 && rubroId <= 4)
    {
        this->rubroId = rubroId;
    }
    return 0;
}

int Servicio_getRubro(eCatering *this,short int *rubroId)
{

    if (this != NULL && rubroId != NULL)
    {
        *rubroId = this->rubroId;
    }
    return 0;
}

int Servicio_NameOrder(void *this, void *this2)
{

    int rtrn = -1;
    if (this == NULL || this2 == NULL)
        return rtrn;

    char nombreArt1[120],nombreArt2[120];

    Servicio_getNombre(this,nombreArt1);
    Servicio_getNombre(this2,nombreArt2);

    if(strcmp(nombreArt1, nombreArt2) > 0)
    {
        rtrn = 1;
    }
    else
    {
        rtrn = -1;
    }

    return rtrn;
}


void Servicio_calcDescuento(void *this)
{

    short int rubro;
    float precio;

    Servicio_getRubro(this, &rubro);
    Servicio_getPrecio(this, &precio);

    switch(rubro)
    {

    case 1:
    {
        if(precio >= 150)
        {
            precio -= (precio * 20) / 100;
        }
        Servicio_setPrecio(this, precio);
    }
    break;

    case 2:
    {
        if (precio <= 30)
        {
            precio -= (precio * 10) / 100;
        }
        Servicio_setPrecio(this, precio);
    }
    break;

    default:
        ;
        break;
    }
}

void Servicio_calcRubro(short int rubro)
{

    switch(rubro)
    {
    case 1:
    {
        printf("Confiteria.");
    }
    break;
    case 2:
    {
        printf("Lunch.");
    }
    break;
    case 3:
    {
        printf("Picadas.");
    }
    break;
    case 4:
    {
        printf("Bebidas.");
    }
    break;
    default:
    {
        printf("Desconocido");
    }
    }

}

int Servicio_Listar(eCatering* this, int *idServicio, float *precio, char *nombreStr, char *medidaStr, short int *rubro)
{

    if(this == NULL || idServicio == NULL || precio == NULL || nombreStr == NULL || medidaStr == NULL || rubro == NULL)
        return -1;


    Servicio_getIdServicio(this, idServicio);
    Servicio_getPrecio(this, precio);
    Servicio_getNombre(this, nombreStr);
    Servicio_getMedida(this, medidaStr);
    Servicio_getRubro(this, rubro);

    printf("Servicio. N-%2d", *idServicio);
    printf("	   %30s", nombreStr);
    printf("	%4s", medidaStr);
    printf("	    %9.2f     ", *precio);
    Servicio_calcRubro(*rubro);
    printf("\n\n");


    return 1;
}

void Servicio_printServicio(void *this, FILE *fp)
{

    if(this == NULL || fp == NULL)
        return;

    int idServicio;
    float precio;
    char medidaStr[60], nombreStr[120];
    short int rubro;

    Servicio_getIdServicio(this, &idServicio);
    Servicio_getPrecio(this, &precio);
    Servicio_getNombre(this, nombreStr);
    Servicio_getMedida(this, medidaStr);
    Servicio_getRubro(this, &rubro);

    fprintf(fp, "%d,%s,%s,%.2f,%d\n", idServicio, nombreStr, medidaStr, precio, rubro);
}

int listarServicios(LinkedList *pArrayListVenta)
{

    int rtrn = -1;
    eCatering *art = Servicio_new();
    if(pArrayListVenta == NULL || art == NULL)
        return rtrn;

    int cantServicios = ll_len(pArrayListVenta);
    if(cantServicios <= 0)
    {
        printf("La lista se encuentra vacia!.\n");
        return rtrn;
    }

    int idServicio;
    float precio;
    char medidaStr[60], nombreStr[120];
    short int rubro;

    printf("	Id     | |         Nombre Servicio          | |  Medida  | |  Precio  | |          Rubro          |\n");
    for(int i = 0; i < cantServicios; i++)
    {

        art = ll_get(pArrayListVenta, i);
        Servicio_Listar(art, &idServicio, &precio, nombreStr, medidaStr, &rubro);

    }
    rtrn = 1;
    return rtrn;
}


int ServiciosMayores100 (void* this)
{
    int ret = 0;
    float auxPrecio;

    if(this!= NULL)
    {
        Servicio_getPrecio((eCatering*)this,&auxPrecio);
        if(auxPrecio > 100)
        {
            ret=1;
        }
    }
    return ret;
}

int ServiciosRubro3 (void* this)
{
    int ret = 0;
    short int auxRubro;

    if(this!= NULL)
    {
        Servicio_getRubro((eCatering*)this, &auxRubro);

        if(auxRubro ==3 )
        {
            ret=1;
        }
    }
    return ret;
}

int informes( LinkedList* pArrayList)
{
    int ret = -1;
    int cantidadVentasMayores100;
    int cantidadRubro3 ;

    if(pArrayList != NULL)
    {

        cantidadVentasMayores100 = ll_count(pArrayList,ServiciosMayores100);
        cantidadRubro3 = ll_count(pArrayList,ServiciosRubro3);

        printf("\n -----------------------------INFORMES---------------------------\n");
        printf("\n|Cantidad de Servicios con precio mayor a $ 100: %d             |\n",cantidadVentasMayores100);
        printf("\n|Cantidad de Servicios del rubro 3 (Picadas): %d                          |\n",cantidadRubro3);
        printf("\n ----------------------------------------------------------------\n");
        ret= 0 ;
    }
    return ret;
}


