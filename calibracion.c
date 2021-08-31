// offset[0] = offx
// offset[1] = offy
// offset[2] = offz
#include "calibracion.h"

signed int offset[3] = {0, 0, 0};
float scale[3] = {1, 1, 1};
signed int Min[3] = {0,0,0};
signed int Max[3] = {0,0,0};


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
}

void AccCalcularOffset(void)
{
    unsigned char i = 0;
    for(i=0; i<3; i++)
    {
        offset[i] = (Max[i]+Min[i])/2;
    }
}

void CalularEscala(void)
{
    unsigned char i = 0;
    for(i=0; i<3; i++)
    {
        scale[i] = GRAVEDAD/(Max[i]-offset[i]);
    }
}