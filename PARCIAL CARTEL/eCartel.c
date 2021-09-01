#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "eCartel.h"
#include "inputDataFunctions.h"

eCartel* Servicio_New()
{
    eCartel *this = malloc(sizeof(eCartel));
    if(this != NULL)
    {
        Servicio_setId(this,0);
        Servicio_setTipo(this,0);
        Servicio_setDomicilio(this, " ");
        Servicio_setLocalidad(this, " ");
        Servicio_setEstado(this, 0);
        Servicio_setMedida(this, 0);
    }
    return this;
}

eCartel* Servicio_add(char *idStr, char *tipoStr, char *domicilioStr, char *localidadStr, char *estadoIdStr, char *medidaStr)
{
    eCartel *this = Servicio_New();

    if(this == NULL)
    {
        return NULL;

    }

    Servicio_setId(this, atoi(idStr));
    Servicio_setTipo(this, atoi(tipoStr));
    Servicio_setDomicilio(this, domicilioStr);
    Servicio_setLocalidad(this, localidadStr);
    Servicio_setEstado(this, atoi(estadoIdStr));
    Servicio_setMedida(this, atoi(medidaStr));

    return this;

}

int Servicio_setId(eCartel *this,int id)
{

    if(this != NULL)
    {
        this->id = id;
    }
    return 0;
}

int Servicio_getId(eCartel *this,int *id)
{

    if (this != NULL && id != NULL)
    {
        *id = this->id;
    }
    return 0;
}

int Servicio_setTipo(eCartel *this,int tipo)
{

    if (this != NULL && tipo > 0 && tipo <= 2)
    {
        this->tipo = tipo;
    }
    return 0;
}

int Servicio_getTipo(eCartel *this,int *tipo)
{

    if (this != NULL && tipo != NULL)
    {
        *tipo = this->tipo;
    }
    return 0;
}

int Servicio_setDomicilio(eCartel *this, char *domicilio)
{
    int ret=0;

    if (this!=NULL && domicilio!=NULL)
    {
        strcpy(this->domicilio, domicilio);
        ret=1;
    }
    return ret;
}

int Servicio_getDomicilio(eCartel* this,char* domicilio)
{
    int ret=0;

    if (this!=NULL && domicilio!=NULL)
    {
        strcpy(domicilio,this->domicilio);
        ret=1;
    }
    return ret;
}

int Servicio_setLocalidad(eCartel *this, char *localidad)
{
    int ret=0;

    if (this!=NULL && localidad!=NULL)
    {
        strcpy(this->localidad, localidad);
        ret=1;
    }
    return ret;
}

int Servicio_getLocalidad(eCartel* this,char* localidad)
{
    int ret=0;

    if (this!=NULL && localidad!=NULL)
    {
        strcpy(localidad,this->localidad);
        ret=1;
    }
    return ret;
}

int Servicio_setEstado(eCartel *this,int estado)
{

    if (this != NULL && estado > 0 && estado <= 2)
    {
        this->estado = estado;
    }
    return 0;
}

int Servicio_getEstado(eCartel *this,int *estado)
{

    if (this != NULL && estado != NULL)
    {
        *estado = this->estado;
    }
    return 0;
}

int Servicio_setMedida(eCartel *this,int medida)
{

    if(this != NULL)
    {
        this->medida = medida;
    }
    return 0;
}

int Servicio_getMedida(eCartel *this,int *medida)
{

    if (this != NULL && medida != NULL)
    {
        *medida = this->medida;
    }
    return 0;
}

int Servicio_NameOrder(void *this, void *this2)
{

    int rtrn = 0;
    if (this == NULL || this2 == NULL)
        return rtrn;

    char nombreArt1[120],nombreArt2[120];

    Servicio_getLocalidad(this,nombreArt1);
    Servicio_getLocalidad(this2,nombreArt2);

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

void Servicio_calcTipo(int tipo)
{

    switch(tipo)
    {
    case 1:
    {
        printf("Venta.   ");
    }
    break;
    case 2:
    {
        printf("Alquiler.");
    }
    break;
    default:
    {
        printf("Desconocido.");
    }
    }

}

void Servicio_calcEstado(int estado)
{

    switch(estado)
    {
    case 1:
    {
        printf("Ofrecido.         ");
    }
    break;
    case 2:
    {
        printf("Alquilado/Vendido.");
    }
    break;
    default:
    {
        printf("Desconocido.      ");
    }
    }

}

void Servicio_calcMedida(void *this)
{

    int estado;
    int medida;

    Servicio_getEstado(this, &estado);
    Servicio_getMedida(this, &medida);

    switch(estado)
    {

    case 1:
    {
        if(medida >= 100)
        {
            medida += 10;
        }
        Servicio_setMedida(this, medida);
    }
    break;

    case 2:
    {
        if (medida < 100)
        {
            medida += 20;
        }
        Servicio_setMedida(this, medida);
    }
    break;

    default:
        ;
        break;
    }
}

int Servicio_Listar(eCartel* this, int *id, int *tipo, char *domicilio, char *localidad, int *estado, int *medida)
{
    if(this == NULL || id == NULL || tipo == NULL || domicilio == NULL || localidad == NULL || estado == NULL || medida == NULL)
        return -1;

    Servicio_getId(this, id);
    Servicio_getTipo(this, tipo);
    Servicio_getDomicilio(this, domicilio);
    Servicio_getLocalidad(this, localidad);
    Servicio_getEstado(this, estado);
    Servicio_getMedida(this, medida);

    printf("   Servicio. N-%2d        ", *id);
    Servicio_calcTipo(*tipo);
    printf("        %-30s", domicilio);
    printf("%-26s", localidad);
    Servicio_calcEstado(*estado);
    printf("           %d cm.", *medida);
    printf("\n\n");

    return 1;
}

void Servicio_printServicio(void *this, FILE *fp)
{
    if(this == NULL || fp == NULL)
        return;

    int id;
    int tipo;
    char domicilio[120];
    char localidad[120];
    int estado;
    int medida;

    Servicio_getId(this, &id);
    Servicio_getTipo(this, &tipo);
    Servicio_getDomicilio(this, domicilio);
    Servicio_getLocalidad(this, localidad);
    Servicio_getEstado(this, &estado);
    Servicio_getMedida(this, &medida);

    fprintf(fp, "%d,%d,%s,%s,%d,%d\n", id, tipo, domicilio, localidad, estado, medida);
}

int listarServicios(LinkedList *pArrayListVenta)
{

    int rtrn = -1;
    eCartel *art = Servicio_New();
    if(pArrayListVenta == NULL || art == NULL)
        return rtrn;

    int cantServicios = ll_len(pArrayListVenta);
    if(cantServicios <=0)
    {
        printf("La lista se encuentra vacia!.\n");
        return rtrn;
    }

    int id;
    int tipo;
    char domicilio[120];
    char localidad[120];
    int estado;
    int medida;

    printf("||       Id         ||   Tipo      ||       Domicilio         ||         Localidad        ||          Estado          ||      Medida     ||\n\n");
    for(int i = 0; i < cantServicios; i++)
    {
        art = ll_get(pArrayListVenta, i);
        Servicio_Listar(art, &id, &tipo, domicilio, localidad, &estado, & medida);

    }
    system("pause");
    system("cls");
    rtrn = 1;
    return rtrn;
}

int ServiciosMayores100(void* this)
{
    int ret = 0;
    int auxMedida;

    if(this != NULL)
    {
        Servicio_getMedida((eCartel*)this, &auxMedida);
        if(auxMedida > 100)
        {
            ret = 1;
        }
    }
    return ret;
}

int ServiciosEstado(void* this)
{
    int ret = 0;
    int auxEstado;

    if(this != NULL)
    {
        Servicio_getEstado((eCartel*)this, &auxEstado);
        if(auxEstado == 1)
        {
            ret = 1;
        }

    }
    return ret;
}

int informes(LinkedList* pArrayList)
{
    int ret = -1;
    int cantidadVentasMayores100;
    int cantidadEstado1 ;

    if(pArrayList != NULL)
    {

        cantidadVentasMayores100 = ll_count(pArrayList,ServiciosMayores100);
        cantidadEstado1 = ll_count(pArrayList,ServiciosEstado);

        printf("\n -----------------------------INFORMES---------------------------\n");
        printf("\n|Cantidad de Servicios con medida mayor a 100cm.: %d              |\n",cantidadVentasMayores100);
        printf("\n|Cantidad de Servicios con estado 1 (Ofrecidos): %d              |\n",cantidadEstado1);
        printf("\n ----------------------------------------------------------------\n");
        ret= 0 ;
    }
    return ret;
}

