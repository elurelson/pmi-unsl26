#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "fecha.h"
#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED
typedef struct{
int id_turno; //DEl 1 al 390aprox
int dni_paciente;   //unico
float monto;        //monto solo si no posee obra social, si posee monto=0
int mutual;         //mutual solo acepta 4 mutuales 1:2:3:4: a definir
Fecha fecha;
int estado;         //1:solicitado  2:confirmado  3:atendido  4:cancelado
}Turno;

//INIT//
void init_Turno(Turno *t){
    (*t).id_turno=
    (*t).dni_paciente=
    (*t).monto=
    (*t).mutual=
    (*t) //fecha a definir
    (*t).estado=

}

//SETTERS//


//GETTERS//


#endif // TURNO_H_INCLUDED
