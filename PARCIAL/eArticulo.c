#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "eArticulo.h"
#include "inputDataFunctions.h"


eArticulo* articulo_new()
{

    eArticulo *this = malloc(sizeof(eArticulo));
    if (this != NULL)
    {

        articulo_setIdArticulo(this,0);
        articulo_setPrecio(this, 0);
        articulo_setNombre(this, " ");
        articulo_setMedida(this, " ");
        articulo_setRubro(this, 0);
    }

    return this;
}

eArticulo* articulo_add(char *idArticuloStr, char *nombreStr, char *medidaStr, char *precioStr,  char *rubroStr)
{

    eArticulo *this = articulo_new();

    if (this == NULL)
        return NULL;

    articulo_setIdArticulo(this, atoi(idArticuloStr));
    articulo_setPrecio(this, atof(precioStr));
    articulo_setNombre(this, nombreStr);
    articulo_setMedida(this, medidaStr);
    articulo_setRubro(this, atoi(rubroStr));


    return this;
}

int articulo_setIdArticulo(eArticulo *this,int id_Articulo)
{

    if(this != NULL)
    {
        this->id_articulo = id_Articulo;
    }
    return 0;
}

int articulo_getIdArticulo(eArticulo *this,int *id_Articulo)
{

    if (this != NULL && id_Articulo != NULL)
    {
        *id_Articulo = this->id_articulo;
    }
    return 0;
}

int articulo_setPrecio(eArticulo *this,float precio)
{

    if (this != NULL && precio >= 0)
    {
        this->precio = precio;
    }
    return 0;
}

int articulo_getPrecio(eArticulo *this, float *precio)
{

    if (this != NULL && precio != NULL)
    {
        *precio = this->precio;
    }
    return 0;
}

int articulo_setNombre(eArticulo *this,char *nombreArticulo)
{

    if (this != NULL && nombreArticulo != NULL)
    {
        short int cantLetras = countLettersStr(nombreArticulo);
        if(cantLetras >= 3)
            strcpy(this->articulo, nombreArticulo);
        else
        {
            return -1;
        }
    }
    return 0;
}

int articulo_getNombre(eArticulo *this,char *nombreArticulo)
{

    if (this != NULL && nombreArticulo != NULL)
    {
        strcpy(nombreArticulo, this->articulo);
    }
    return 0;
}

int articulo_setMedida(eArticulo *this,char *medida)
{

    if (this != NULL && medida != NULL)
    {
        strcpy(this->medida, medida);
    }
    return 0;
}

int articulo_getMedida(eArticulo *this,char *medida)
{

    if (this != NULL && medida != NULL)
    {
        strcpy(medida, this->medida);
    }
    return 0;
}

int articulo_setRubro(eArticulo *this,short int rubroId)
{

    if (this != NULL && rubroId > 0 && rubroId <= 4)
    {
        this->rubroId = rubroId;
    }
    return 0;
}

int articulo_getRubro(eArticulo *this,short int *rubroId)
{

    if (this != NULL && rubroId != NULL)
    {
        *rubroId = this->rubroId;
    }
    return 0;
}

int articulo_NameOrder(void *this, void *this2)
{

    int rtrn = -1;
    if (this == NULL || this2 == NULL)
        return rtrn;

    char nombreArt1[120],nombreArt2[120];

    articulo_getNombre(this,nombreArt1);
    articulo_getNombre(this2,nombreArt2);

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


void articulo_calcDescuento(void *this)
{

    short int rubro;
    float precio;

    articulo_getRubro(this, &rubro);
    articulo_getPrecio(this, &precio);

    switch(rubro)
    {

    case 1:
    {
        if(precio >= 120)
        {
            precio -= (precio * 20) / 100;
        }
        articulo_setPrecio(this, precio);
    }
    break;

    case 2:
    {
        if (precio <= 200)
        {
            precio -= (precio * 10) / 100;
        }
        articulo_setPrecio(this, precio);
    }
    break;

    default:
        ;
        break;
    }
}

void articulo_calcRubro(short int rubro)
{

    switch(rubro)
    {
    case 1:
    {
        printf("Cuidado de ropa.");
    }
    break;
    case 2:
    {
        printf("Limpieza y desinfeccion.");
    }
    break;
    case 3:
    {
        printf("Cuidado personal e higiene.");
    }
    break;
    case 4:
    {
        printf("Cuidado del automotor.");
    }
    break;
    default:
    {
        printf("Desconocido");
    }
    }

}

int articulo_Listar(eArticulo* this, int *idArticulo, float *precio, char *nombreStr, char *medidaStr, short int *rubro)
{

    if(this == NULL || idArticulo == NULL || precio == NULL || nombreStr == NULL || medidaStr == NULL || rubro == NULL)
        return -1;


    articulo_getIdArticulo(this, idArticulo);
    articulo_getPrecio(this, precio);
    articulo_getNombre(this, nombreStr);
    articulo_getMedida(this, medidaStr);
    articulo_getRubro(this, rubro);

    printf("Articulo. N-%2d", *idArticulo);
    printf("	   %30s", nombreStr);
    printf("	%4s", medidaStr);
    printf("	    %9.2f     ", *precio);
    articulo_calcRubro(*rubro);
    printf("\n\n");


    return 1;
}

void articulo_printArticulo(void *this, FILE *fp)
{

    if(this == NULL || fp == NULL)
        return;

    int idArticulo;
    float precio;
    char medidaStr[60], nombreStr[120];
    short int rubro;

    articulo_getIdArticulo(this, &idArticulo);
    articulo_getPrecio(this, &precio);
    articulo_getNombre(this, nombreStr);
    articulo_getMedida(this, medidaStr);
    articulo_getRubro(this, &rubro);

    fprintf(fp, "%d,%s,%s,%.2f,%d\n", idArticulo, nombreStr, medidaStr, precio, rubro);
}

int listarArticulos(LinkedList *pArrayListVenta)
{

    int rtrn = -1;
    eArticulo *art = articulo_new();
    if(pArrayListVenta == NULL || art == NULL)
        return rtrn;

    int cantArticulos = ll_len(pArrayListVenta);
    if(cantArticulos <= 0)
    {
        printf("La lista se encuentra vacia!.\n");
        return rtrn;
    }

    int idArticulo;
    float precio;
    char medidaStr[60], nombreStr[120];
    short int rubro;

    printf("	Id     | |         Nombre Articulo          | |  Medida  | |  Precio  | |          Rubro          |\n");
    for(int i = 0; i < cantArticulos; i++)
    {

        art = ll_get(pArrayListVenta, i);
        articulo_Listar(art, &idArticulo, &precio, nombreStr, medidaStr, &rubro);

    }
    rtrn = 1;
    return rtrn;
}


int articulosMayores100 (void* this)
{
    int ret = 0;
    float auxPrecio;

    if(this!= NULL)
    {
        articulo_getPrecio((eArticulo*)this,&auxPrecio);
        if(auxPrecio > 100)
        {
            ret=1;
        }
    }
    return ret;
}

int articulosRubro1 (void* this)
{
    int ret = 0;
    short int auxRubro;

    if(this!= NULL)
    {
        articulo_getRubro((eArticulo*)this, &auxRubro);

        if(auxRubro ==1 )
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
    int cantidadRubro1 ;

    if(pArrayList != NULL)
    {

        cantidadVentasMayores100 = ll_count(pArrayList,articulosMayores100);
        cantidadRubro1 = ll_count(pArrayList,articulosRubro1);

        printf("\n -----------------------------INFORMES---------------------------\n");
        printf("\n|Cantidad de Articulos con precio mayor a $ 100 : %d             |\n",cantidadVentasMayores100);
        printf("\n|Cantidad de articulos del rubro 1 : %d                          |\n",cantidadRubro1);
        printf("\n ----------------------------------------------------------------\n");
        ret= 0 ;
    }
    return ret;
}

