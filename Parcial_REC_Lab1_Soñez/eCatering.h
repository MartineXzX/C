#ifndef ECATERING_H_
#define ECATERING_H_

struct eCatering
{
    int id_Servicio;
    float precio;
    char medida[60], Servicio[120];
    short int rubroId;


}typedef eCatering;
#include "LinkedList.h"
eCatering* Servicio_new();
eCatering* Servicio_add(char *idServicioStr, char *nombreStr, char *medidaStr, char *precioStr,  char *rubroStr);

int Servicio_setIdServicio(eCatering *this,int id_Servicio);
int Servicio_getIdServicio(eCatering *this,int *id_Servicio);

int Servicio_setPrecio(eCatering *this,float precio);
int Servicio_getPrecio(eCatering *this, float *precio);

int Servicio_setNombre(eCatering *this,char *nombreCatering);
int Servicio_getNombre(eCatering *this,char *nombreCatering);

int Servicio_setMedida(eCatering *this,char *medida);
int Servicio_getMedida(eCatering *this,char *medida);

int Servicio_setRubro(eCatering *this,short int rubroId);
int Servicio_getRubro(eCatering *this,short int *rubroId);

void Servicio_calcDescuento(void *this);
void Servicio_printServicio(void *this, FILE *fp);
void Servicio_calcRubro(short int rubro);
int Servicio_NameOrder(void *this, void *this2);
int Servicio_Listar(eCatering* this, int *idServicio, float *precio, char *nombreStr, char *medidaStr, short int *rubro);
int listarServicios(LinkedList *pArrayListVenta);
int informes( LinkedList* pArrayList);
int ServiciosRubro3 (void* this);
int ServiciosMayores100 (void* this);



#endif /* ECATERING_H_ */

