#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

//////////////////////////

typedef struct fecha{
    int dia; //noviembre tiene 30 | diciembre tiene 31
    int mes; // 11 - noviembre | 12 - diciembre
    int anio; //2026 fijo. no modificable
    int hora; // De 0 a 23hrs
    int minuto;// solo 0 o 30
    int disponible;     // 0:Libre||1:Ocupado|| VALOR POR DEFECTO LIBRE = INIT=0
}Fecha;

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
int set_Dia(Fecha *f, int dia)
{   
    if(dia >= 1 && dia <= 31)
    {
        if(((*f).mes==1||(*f).mes==3||(*f).mes==5||(*f).mes==7||(*f).mes==8||(*f).mes==10||(*f).mes==12) && dia <= 31)
        {
            (*f).dia= dia;
            return 1;  //cargado correctamente
        }
        else if((*f).mes == 2 && dia <= 28)
        {   (*f).dia= dia;
            return 1; //cargado correctamente
        }
        
        else if(((*f).mes==4||(*f).mes==6||(*f).mes==9||(*f).mes==11) && dia <= 30)
        {
            (*f).dia= dia;
            return 1; //cargado correctamente
        }
    }
         
    return 0;   //dia invalido para el mes indicado o mes sin cargar
}
    
    

int set_Mes(Fecha *f, int mes)
{
    
    if(mes < 1 || mes >12)
    {
        return 0;  //Return 0= No cargado, el mes esta mal cargado
    }
    else
    {   
        (*f).mes= mes;
        return 1; //Return 1= Cargado correctamente
    }
    
    
}
void set_Hora(Fecha *f, int hora)
{
    (*f).hora= hora;
}

void set_Minuto(Fecha *f, int minuto)
{
    (*f).minuto= minuto;
}
void set_Disponible(Fecha *f, int disponible)
{
    (*f).disponible= disponible;
}

void set_FechaCompleta(Fecha *f, int dia, int mes, int hora, int minuto, int disponible) //anio no se pasa ya que es fijo
{
   //set_Dia()
}

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
