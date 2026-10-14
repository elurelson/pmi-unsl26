#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

//////////////////////////

typedef struct fecha
{
    int dia; //noviembre tiene 30 | diciembre tiene 31
    int mes; // 11 - noviembre | 12 - diciembre
    int anio; //2026 fijo. no modificable
    int hora; // De 0 a 23hrs
    int minuto;// solo 0 o 30
    int disponible;     // 0:Libre||1:Ocupado|| VALOR POR DEFECTO LIBRE = INIT=0
} Fecha;

//INIT//

void init_Fecha(Fecha *f)
{
    (*f).dia=0;
    (*f).mes=0;
    (*f).anio=2026;
    (*f).hora=0;
    (*f).minuto=-1;
    (*f).disponible=0;
}

//SETTERS//
void set_Dia(Fecha *f, int dia)
{   
    (*f).dia = dia;
}
    
void set_Mes(Fecha *f, int mes)
{   
    (*f).mes = mes;
}

void set_Anio(Fecha *f, int anio)
{   
    (*f).anio = anio;
}

void set_Hora(Fecha *f, int hora)
{   
    (*f).hora = hora;
}

void set_Minuto(Fecha *f, int minuto)
{   
    (*f).minuto = minuto;
}

void set_Disponible(Fecha *f, int disponible)
{   
    (*f).disponible = disponible;
}

//set fechacompleta se hace en el main.

//GETTERS//

int get_Dia(Fecha f)
{
    return f.dia;
}
int get_Mes(Fecha f)
{
    return f.mes;
}
int get_Anio(Fecha f)
{
    return f.anio;
}
int get_Hora(Fecha f)
{
    return f.hora;
}
int get_Minuto(Fecha f)
{
    return f.minuto;
}
int get_Disponible(Fecha f)
{
    return f.disponible;
}


#endif // FECHA_H_INCLUDED
