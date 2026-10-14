#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "fecha.h"
#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED
typedef struct
{
    int id_turno;       //unico
    int dni_paciente;   //unico
    float monto;        //monto solo si no posee obra social, si posee monto=0
    int mutual;         //0 -> sin mutual || >= 0 -> 4 mutuales 1:2:3:4: a definir
    Fecha fecha;
    int estado;         //1:solicitado  2:confirmado  3:atendido  4:cancelado
} Turno;

//INIT//
void init_Turno(Turno *t)
{
    (*t).id_turno= -1;
    (*t).dni_paciente= -1;
    (*t).monto=-1;
    (*t).mutual=-1;
    init_Fecha(&((*t).fecha));
    (*t).estado=0;
}

//SETTERS//

int set_IdTurno(Turno *t, int id_t)
{
    if((*t).id_turno != -1)
    {
        return 0;
    }   
    
    (*t).id_turno= id_t;
        return 1;
    
}

int set_DniPaciente(Turno *t, int dni_paciente)
{
    if((*t).dni_paciente != -1)
        return 0;
    
    (*t).dni_paciente= dni_paciente;
    return 1;
}

int set_Monto(Turno *t, float monto_paciente)
{
    if((*t).monto != -1)
        return 0;

    if(monto_paciente < -1)
        return 0;
    
    
    (*t).monto= monto_paciente;
        return 1;
    
}

int set_Mutual(Turno *t, int mutual_paciente)
{
    if((*t).mutual != -1)
    {
        return 0;
    }
    if(mutual_paciente < 0 || mutual_paciente > 4)
    {
        return 0;
    }
  
    (*t).mutual= mutual_paciente;
    return 1;
}

int set_FechaTurno(Turno *t, Fecha fecha_turno)
{
    (*t).fecha= fecha_turno;   
}

int set_Estado(Turno *t, int estado)
{
    if(estado < 0 || estado > 4)
    {
        return 0;
    }
    else
    {
        (*t).estado=estado;
    }

}

//GETTERS//

int get_IdTurno(Turno t)
{
    return t.id_turno;   
}

int get_DniPaciente(Turno t)
{
    return t.dni_paciente;    
}

float get_Monto(Turno t)
{
    return t.monto;
}

Fecha get_Fecha(Turno t)
{
    return t.fecha;      //get fecha chequear 
}

int get_Estado(Turno t)
{
    return t.estado;
}

#endif // TURNO_H_INCLUDED
