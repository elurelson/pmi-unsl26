#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

typedef struct paciente{
    char nombre[70];
    char apellido[70];
    int dni;
    int osocial; //1: tiene obra social| 2: no tiene obra social
}Paciente;

//INIT//
void init_Paciente(Paciente *p)
{
    strcpy((*p).nombre, "\0");
    strcpy((*p).apellido, "\0");
    (*p).dni= -1;
    (*p).osocial=-1;
}

//SETTERS//

void set_Nombre(Paciente *p, char* pacienteN)
{
    strcpy(p->nombre,pacienteN);
}

void set_Apellido(Paciente *p, char* pacienteN)
{
    strcpy(p->apellido, pacienteN);   
}

void set_Dni(Paciente *p, int dniPaciente)
{
    (*p).dni= dniPaciente;
}

void set_OSocial(Paciente *p, int oSocial)
{
    (*p).osocial= oSocial;
}

//GETTERS//

char* get_Nombre(Paciente p)
{
    char *a;
    a=(char*)malloc(strlen(p.nombre)+1);
    if(a==NULL)
    {
            exit(1);
    }
    else
    {
            strcpy(a,p.nombre);
            return a;
    }
}

char* get_Apellido(Paciente p)
{
    char *a;
    a=(char*)malloc(strlen(p.apellido)+1);
    if(a==NULL)
    {
        exit(1);
    }
    else
    {
        strcpy(a,p.apellido);
        return a;
    }
}


int get_Dni(Paciente p)
{
    return p.dni;
}

int get_OSocial(Paciente p)
{
    return p.osocial;
}

#endif // PACIENTE_H_INCLUDED
