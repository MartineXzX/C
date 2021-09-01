
#ifndef EARTICULO_H_
#define EARTICULO_H_

struct eArticulo
{
    int id_articulo;
    float precio;
    char medida[60], articulo[120];
    short int rubroId;


}typedef eArticulo;
#include "LinkedList.h"
eArticulo* articulo_new();
eArticulo* articulo_add(char *idArticuloStr, char *nombreStr, char *medidaStr, char *precioStr,  char *rubroStr);

int articulo_setIdArticulo(eArticulo *this,int id_Articulo);
int articulo_getIdArticulo(eArticulo *this,int *id_Articulo);

int articulo_setPrecio(eArticulo *this,float precio);
int articulo_getPrecio(eArticulo *this, float *precio);

int articulo_setNombre(eArticulo *this,char *nombreArticulo);
int articulo_getNombre(eArticulo *this,char *nombreArticulo);

int articulo_setMedida(eArticulo *this,char *medida);
int articulo_getMedida(eArticulo *this,char *medida);

int articulo_setRubro(eArticulo *this,short int rubroId);
int articulo_getRubro(eArticulo *this,short int *rubroId);

void articulo_calcDescuento(void *this);
void articulo_printArticulo(void *this, FILE *fp);
void articulo_calcRubro(short int rubro);
int articulo_NameOrder(void *this, void *this2);
int articulo_Listar(eArticulo* this, int *idArticulo, float *precio, char *nombreStr, char *medidaStr, short int *rubro);
int listarArticulos(LinkedList *pArrayListVenta);
int informes( LinkedList* pArrayList);
int articulosRubro1 (void* this);
int articulosMayores100 (void* this);



#endif /* EARTICULO_H_ */
