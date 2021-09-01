#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this=(LinkedList*) malloc(sizeof(LinkedList));
    if(this==NULL)
    {
        printf("error");
    }
    else
    {
        this->size=0;
        this->pFirstNode=NULL;
    }


    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=this->size;
    }


    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nodo=NULL;
    int len=ll_len(this);

    if(this!=NULL && nodeIndex>=0 && nodeIndex<len)
    {

        nodo=this->pFirstNode;

        while(nodeIndex>0)
        {
            nodo=nodo->pNextNode;
            nodeIndex--;
        }
        //

    }

    return nodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{


    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);
    Node* anterior=NULL;
    Node* siguiente=NULL;
    Node* nodo;
    int contador=1;

    if(this!=NULL && nodeIndex>=0 &&  nodeIndex<=len)
    {
        nodo=(Node*) malloc(sizeof(Node));

        if(nodo!=NULL)
        {
            //NODO SOLO CON EL PELMENNT.
            nodo->pElement= pElement;
            nodo->pNextNode=NULL;



            if(nodeIndex==0)
            {
                nodo->pNextNode=this->pFirstNode;
                this->pFirstNode=nodo;
                //indice pedido
            }
            else
            {
                anterior=this->pFirstNode;
                siguiente=anterior->pNextNode;
                while(nodeIndex>contador)
                {
                    anterior=siguiente;
                    siguiente=anterior->pNextNode;
                    contador++;
                }
                anterior->pNextNode=nodo;
                nodo->pNextNode=siguiente;


            }
            this->size++;
            returnAux=0;

        }


    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);

    if(this!=NULL)
    {
        if(addNode(this,len,pElement)==0)
        {
            returnAux=0;
        }
    }



    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len=ll_len(this);
    Node* nodo=NULL;
    if(this!=NULL && index>=0 && index<=len)
    {
        nodo=getNode(this,index);//obtenemos un nodo.

        if(nodo!=NULL)
        {
            return nodo->pElement;
        }

    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodo=NULL;


    int len=ll_len(this);



    if(this!=NULL && index>=0 && index<=len)
    {
        nodo=getNode(this,index);

        if(nodo!=NULL)
        {
            nodo->pElement=pElement;
            returnAux=0;

        }

    }

    return returnAux;
}


/** \brief Elimina un nodo y/o un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len=ll_len(this);
    Node* nodo=NULL; //nodo a eliminar
    Node* nodoAnterior=NULL;
    Node* nodoSiguiente=NULL;

    if(this!=NULL && index>=0 && index<=len)
    {
        nodo=getNode(this,index);

        if(nodo!=NULL)
        {
            if(index==0)
            {
                this->pFirstNode=nodo->pNextNode;
                free(nodo);
                this->size--;
                returnAux=0;

            }
            else
            {
                nodoAnterior=getNode(this,index-1);//queremos el anterior
                nodoSiguiente=getNode(this,index+1);//queremos el siguiente

                nodoAnterior->pNextNode=nodoSiguiente;
                free(nodo);
                (this->size)--;

                returnAux=0;

            }

        }
    }



    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* eliminaNodos;
    Node* auxNodos;

    if(this!=NULL && this->size>0)
    {
		for(int i=0;i<ll_len(this);i++)
		{
			eliminaNodos=getNode(this,i);
			if(eliminaNodos!=NULL)
			{
				auxNodos = eliminaNodos->pNextNode;
				this->size--;
				free(eliminaNodos);
			}

			free(auxNodos);
		}
			this->pFirstNode=NULL;

			if(this->size==0)
	    	{
	    		returnAux = 0;
	    	}
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        free(this);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* nodo=NULL;
    int len=ll_len(this);

    if(this!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            nodo=getNode(this,i);

            if(nodo->pElement==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(this->size==0)
        {
            returnAux=1;
        }
        if(this->size>0)
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);

    if(this!=NULL && index>=0 && index<=len)
    {
        returnAux=addNode(this,index,pElement);

    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    //Node* nodoRetorno=NULL;

    int len;

    if(this!=NULL)
    {
        len=ll_len(this);
        if(index>=0 && index<=len)
        {
            returnAux=ll_get(this,index);
            ll_remove(this,index);


        }




    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(ll_indexOf(this,pElement)!=-1)
        {
            returnAux=1;

        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len1=ll_len(this);
    int len2=ll_len(this2);
    Node* auxNode=NULL;

    if(this !=NULL && this2!=NULL)
    {
        returnAux=0;
        if(len1>=len2)
        {
            for(int i=0; i<len2; i++)
            {
                auxNode=getNode(this,i);

                if(ll_contains(this2,auxNode->pElement)==1)
                {
                    returnAux=1;
                }

            }

        }
        //returnAux=0;

    }



    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* auxNode=NULL;

    int len=ll_len(this);

    if(this!=NULL && (from>=0 && from<=len) && (to>=from && to<=len) )
    {
        cloneArray=ll_newLinkedList();

        if(cloneArray!=NULL)
        {
            for(int i=0; i<len; i++)
            {
                auxNode=getNode(this,i);

                if(auxNode!=NULL)
                {
                    addNode(cloneArray,i,auxNode->pElement);
                }
            }

        }

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    int len=ll_len(this);


    if(this!=NULL)
    {
        cloneArray=ll_subList(this,0,len);

    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int len=ll_len(this);
    void* aux;//auxiliar para swapeo.


    if(this!=NULL && pFunc!=NULL)
    {

        for(int i=0; i<len-1; i++)
        {

            for(int j=i+1; j<len; j++)
            {

                if(pFunc(ll_get(this,i),ll_get(this,j))<0 && order ==0)
                {
                    aux=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,aux);// swapeo.
                    returnAux=0;

                }
                else if(pFunc(ll_get(this,i),ll_get(this,j))>0 && order ==1)
                {
                    aux=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,aux);// swapeo.
                    returnAux=0;

                }
            }
        }
    }

    return returnAux;

}

int ll_map(LinkedList* this, void (*fn)(void* element))
{

    int rtrn = -1;
    if(this == NULL)
        return rtrn;

    int cantVentas = ll_len(this);
    if (cantVentas <= 0)
    {
        printf("No se encontraron Elementos dados de alta.\n");
        return rtrn;
    }

    for(int i = 0; i < ll_len(this); i++)
    {
        fn(ll_get(this, i));

    }
    rtrn = 0;
    return rtrn;
}

int ll_count(LinkedList* this, int (*fn)(void* element))
{

    if(this == NULL)
        return -1;

    int contador = 0;
    int cantVentas = ll_len(this);
    if (cantVentas <= 0)
    {
        printf("No se encontraron Elementos dados de alta.\n");
        return -1;
    }

    for(int i = 0; i < ll_len(this); i++)
    {

        contador += fn(ll_get(this, i));

    }

    return contador;
}

int ll_printElementInText(LinkedList* this, void (*print)(void* element, FILE *fp), FILE *fp)
{

    int rtrn = -1;
    if(this == NULL || fp == NULL)
        return rtrn;

    int cantVentas = ll_len(this);
    if (cantVentas <= 0)
    {
        printf("No se encontraron Elementos dados de alta.\n");
        return rtrn;
    }

    for(int i = 0; i < ll_len(this); i++)
    {
        print(ll_get(this, i), fp);
    }
    rtrn = 0;
    return rtrn;
}



