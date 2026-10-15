#ifndef LISTOVO_TURNO_H_INCLUDED
#define LISTOVO_TURNO_H_INCLUDED
#include "turno.h"

typedef struct nodo
{
    Turno vipd;
    struct nodo *next;
} Nodo;

typedef struct
{
    Nodo *acc;
    Nodo *cur;
    Nodo *aux;
} Lista_Turno;

// INIT LISTA//
void init_ListaTurno(Lista_Turno *l)
{
    l->acc = NULL;
    l->cur = NULL;
    l->aux = NULL;
}

// PREDICADOS//

int isEmpty_ListaTurno(Lista_Turno l)
{
    if (l.acc == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOos_ListaTurno(Lista_Turno l)
{
    if (l.cur == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull_ListaTurno(Lista_Turno l) // consultar
{
    Nodo *prueba;
    prueba = (Nodo *)malloc(sizeof(Nodo));
    if (prueba == NULL)
    
        return 1;

    free(prueba);
    return 0;
}

// OPERACIONES//
void forwards_ListaTurno(Lista_Turno *l)
{
    l->aux = l->cur;
    l->cur = l->cur->next;
}
void reset_ListaTurno(Lista_Turno *l)
{
    l->aux = NULL;
    l->cur = l->acc;
}

void copy_ListaTurno(Lista_Turno *l, Turno *copiado)
{
    if (!isOos(*l))
        *copiado = l->cur->vipd;
}
void insert_ListaTurno(Lista_Turno *l, Turno nuevoturno)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));

    if (nuevo == NULL)
        return;

    nuevo->vipd = nuevoturno;
    nuevo->next = l->cur;
    if (l->aux == NULL)
    {
        l->acc = nuevo;
    }
    else
    {
        l->aux->next = nuevo;
    }
    l->cur = nuevo;
}

void supress_ListaTurno(Lista_Turno *l)
{
    if (isOos(*l))
        return;

    Nodo *eliminado = l->cur;

    if (l->aux == NULL)
    {
        l->acc = eliminado->next;
    }
    else
    {
        l->aux->next = eliminado->next;
    }
    l->cur = eliminado->next;
    free(eliminado);
}

#endif // LISTOVO_TURNO_H_INCLUDED
