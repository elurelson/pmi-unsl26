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
    
    if(mes < 1 || mes > 12) //comprobacion inicial del parametro actual mes
        return 0;  //0= no cargado, el mes esta mal pasado
    
    //comprobaciones en caso de que haya un dia cargado y se quiera modificar el mes

    if(mes == 2 && (*f).dia > 28)
        return 0; // a febrero se le quiso cargar un dia que no entra en el mes 

    if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (*f).dia > 30)
        return 0; //a los meses con 30 dias se le quiso cargar un dia que no entra en el mes 

    if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (*f).dia > 31)
        return 0; //a los meses con 31 dias se le quiso cargar un dia que no entra en el mes 
    
    //si el dia es 0(sin inicializar) permite pasar a cargar el mes
    (*f).mes= mes;
    return 1; //Return 1= Cargado correctamente
        
}

int set_Hora(Fecha *f, int hora)
{
        if (hora >= 0 && hora <= 23)
        {
            (*f).hora=hora;
                return 1; //Return 1= Cargado correctamente
        }   else{
                return 0; //Return 0= La hora esta mal pasada
        }
}

int set_Minuto(Fecha *f, int minuto)
{
    if(minuto !=0 && minuto != 30)
        return 0;
    
    (*f).minuto= minuto;
    return 1;
}

int set_Disponible(Fecha *f, int disponible)
{   
    if(disponible==1||disponible==0)
    {
        (*f).disponible= disponible;
        return 1; //Return 1= Cargado correctamente
    }

    else
        return 0;  //Return 0= el disponible esta mal pasado
}

void set_FechaCompleta(Fecha *f, int dia, int mes, int hora, int minuto, int disponible) //anio no se pasa ya que es fijo
{
    Fecha aux;
    init_Fecha(&aux);

    if(set_Mes(&aux, mes) == 0) //¿por que entra set mes primero?
        return 0;
    if(set_Dia(&aux, dia) == 0)
        return 0;
    if(set_Hora(&aux, hora) == 0)
        return 0;
    if(set_Minuto(&aux, minuto) == 0)
        return 0;
    if (set_Disponible(&aux, disponible) == 0)
        return 0;
    
    *f=aux;
    return 1;
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

Fecha get_FechaCompleta(Fecha f)
{
    return f;
}
#endif // FECHA_H_INCLUDED
