#ifndef ECARTEL_H_
#define ECARTEL_H_

struct eCartel
{
    int id;
    int tipo;
    char domicilio[120];
    char localidad[120];
    int estado;
    int medida;

} typedef eCartel;
#include "LinkedList.h"

eCartel* Servicio_New();
eCartel* Servicio_add(char *idStr, char *tipoStr, char *domicilioStr, char *localidad, char *estadoIdStr, char *medidaStr);

int Servicio_setId(eCartel *this, int id);
int Servicio_getId(eCartel *this, int *id);

int Servicio_setTipo(eCartel *this, int tipo);
int Servicio_getTipo(eCartel *this, int *tipo);

int Servicio_setDomicilio(eCartel *this, char *domicilio);
int Servicio_getDomicilio(eCartel *this, char *domicilio);

int Servicio_setLocalidad(eCartel *this, char *localidad);
int Servicio_getLocalidad(eCartel *this, char *localidad);

int Servicio_setEstado(eCartel *this, int estadoId);
int Servicio_getEstado(eCartel *this, int *estadoId);

int Servicio_setMedida(eCartel *this, int medida);
int Servicio_getMedida(eCartel *this, int *medida);

int Servicio_NameOrder(void *this, void *this2);

void Servicio_calcTipo(int tipo);
void Servicio_calcEstado(int estado);

void Servicio_calcMedida(void *this);

int Servicio_Listar(eCartel* this, int *id, int *tipo, char *domicilio, char *localidad, int *estado, int *medida);
void Servicio_printServicio(void *this, FILE *fp);
int listarServicios(LinkedList *pArrayListVenta);

int ServiciosMayores100(void* this);
int ServiciosEstado(void* this);

int informes(LinkedList* pArrayList);





#endif /* ECARTEL_H_ */
