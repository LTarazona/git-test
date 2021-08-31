// offset[0] = offx
// offset[1] = offy
// offset[2] = offz
#include "calibracion.h"

/* Flags */
unsigned char flags_acc;

/* */


/* Ver la posibilidadde grabar los valores de offset y escala en flash */
signed  int offset[3] = {0, 0, 0};
float       scale[3] = {1.0, 1.0, 1.0};
signed  int Min[3] = {0,0,0};
signed  int Max[3] = {0,0,0};
signed  int Acc[3] = {0,0,0};
/*
void AccValoresCalibracion(signed int * Acc)
{
    unsigned char i = 0;
    for(i=0; i<3; i++)
    {
        if (Acc[i] < Min[i])
        {
            Min[i] = Acc[i];
        }
        if (Acc[i] > Max[i])
        {
            Max[i] = Acc[i];
        }
    }
}*/

void ValoresDeCalibracion(unsigned char eje)
{
    if (Acc[eje] < Min[eje])
    {
        Min[eje] = Acc[eje];
    }
    if (Acc[eje] > Max[eje])
    {
        Max[eje] = Acc[eje];
    }
}


void AccCalcularOffset(void)
{
    unsigned char i = 0;
    for(i=0; i<3; i++)
    {
        offset[i] = (Max[i]+Min[i])/2;
    }
        /* Grabar en flash */ 
}

void CalcularEscala(void)
{
    unsigned char i = 0;
    for(i=0; i<3; i++)
    {
        scale[i] = GRAVEDAD/(Max[i]-offset[i]);
    }
        /* Grabar en flash */ 
}

/* Tengo que hacer que se grabe un eje por vez cuando llegue a esa posicion */
unsigned char SecuenciaCalibrado(void)
{
    static unsigned char estadoCalibracion = EST_CALIB_INICIO; 
    unsigned char codEjeActivado = 0; // Codigo del eje que se esta disparando por la gravedad
    unsigned char retval = 0;
    
    switch(estadoCalibracion)
    {
    case EST_CALIB_INICIO:
        /* Paso a la espera por ahora */
        flags_acc = 0;
        estadoCalibracion = EST_CALIB_ESPERA;
        break;
    case EST_CALIB_ESPERA:
        /* Codigo de espera para el siguiente paso en la calibracion */
        codEjeActivado = ObtenerAccDisparada();
        if(flags_acc == CALIBRACION_COMPLETA)
        {
            estadoCalibracion = EST_CALIB_INICIO;
            retval = 1;
            break;
        }
        else
        if(codEjeActivado == INDETERMINADO)
            break;
        else
            estadoCalibracion = EST_CALIB_EJECUTAR;
/*omito el break para saltar al siguiente estado sin usar static en la variable codEjeActivado*/        
    case EST_CALIB_EJECUTAR:
        /* Ver segun que bit estoy recorriendo, segun el codigo que me mando antes */
        break;
        
    default:
        break;
    } 

}