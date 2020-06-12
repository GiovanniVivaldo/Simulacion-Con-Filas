#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Nodo
{
    char dato[20];
    int edicion;
    struct _Nodo *siguiente;
}
Nodo;

Nodo* crearNodo(char d[20],int e)
{
    Nodo *nuevo;

    nuevo=(Nodo*)malloc(sizeof(Nodo));
    strcpy(nuevo->dato,d);
    nuevo->edicion=e;
    nuevo->siguiente=NULL;

    return nuevo;
}

Nodo* Push(Nodo *top, char d[20],int e)
{

    Nodo *nuevo,*aux;
    nuevo=crearNodo(d,e);

    if(top==NULL)
    {
        return nuevo;
    }
    else
    {
        aux=top;
        while(aux->siguiente!=NULL)
        {
            aux=aux->siguiente;
        }

    }
    aux->siguiente=nuevo;
    return top;

}

Nodo* Pop(Nodo *top)
{
    Nodo *aux;
    aux=top;

    if(aux!=NULL)
        {
            top=top->siguiente;
            free(aux);
        }

    return top;
}

void verCola(Nodo *top)
{
    Nodo *aux;
    aux=top;

    if(aux==NULL)
        {
            printf("\n\tNINGUNA\n");
        }
    else
        {
           // printf("\n\tCARACTERES EN LA COLA");
            while(aux!=NULL)
            {
                printf("%s%d ", aux->dato,aux->edicion);
                aux=aux->siguiente;
            }
            printf("\n");
        }
}

void tamano(Nodo *top)
{
    int contadorTop=0;
    Nodo *aux;
    aux=top;

    if(aux==NULL)
    {
        printf("Cola vacia\n");
    }
    else
    {
        while(aux!=NULL)
        {
            contadorTop++;
            aux=aux->siguiente;
        }
    }

    printf("\nNumero De Caracteres En La Cola: %d \n", contadorTop);
}

#endif // FILAS_H_INCLUDED
