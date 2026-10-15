#include "paciente.h"
#include <stdlib.h>
#ifndef LISTAE_PACIENTE_H_INCLUDED
#define LISTAE_PACIENTE_H_INCLUDED
#define MAX 100

typedef struct
{
    Paciente vipd[MAX];
    int cur;
    int ultimo;
} Lista_Paciente;

// INIT//
void init_ListaPaciente(Lista_Paciente *l)
{
    l->cur = 0;
    l->ultimo = -1;
}

// PREDICADOS//

int isEmpty_ListaPaciente(Lista_Paciente l)
{

    if ((l.ultimo) == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isFull_ListaPaciente(Lista_Paciente l)
{
    if (l.ultimo == MAX - 1)
        return 1;
    else
        return 0;
}

int isOos_ListaPaciente(Lista_Paciente l)
{
    if (l.cur > l.ultimo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// OPERACIONES//

void reset_ListaPaciente(Lista_Paciente *l)
{
    l->cur = 0;
}

int insert_ListaPaciente(Lista_Paciente *l, Paciente nuevopaciente)
{
    int i;
    if (isFull_ListaPaciente(*l))
    {
        return 0;
    }

    for (i = l->ultimo; i >= l->cur; i--)
    {
        l->vipd[i + 1] = l->vipd[i];
    }

    l->vipd[l->cur] = nuevopaciente;
    l->ultimo++;

    return 1;
}

int supress_ListaPaciente(Lista_Paciente *l)
{
    int i;

    if (isOos_ListaPaciente(*l))
        return 0;

    for (i = l->cur; i < l->ultimo; i++)
    {
        l->vipd[i] = l->vipd[i + 1];
    }

    l->ultimo--;
    return 1;
}

int forward(Lista_Paciente *l)
{
    if (isOos_ListaPaciente(*l))
    {
        return 0;
    }
    else
    {
        l->cur++;
        return 1;
    }
}

Paciente copy_ListaPaciente(Lista_Paciente l)
{
    return l.vipd[l.cur];
}

#endif // LISTAE_PACIENTE_H_INCLUDED
