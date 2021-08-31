#define MIN_X   Min[0]
#define MIN_Y   Min[1]
#define MIN_Z   Min[2]

#define MAX_X   Max[0]
#define MAX_Y   Max[1]
#define MAX_Z   Max[2]

#define GRAVEDAD    1

#define FLAG_XP     ((flags_acc)&0x01)
#define FLAG_YP     ((flags_acc>>1)&0x01)
#define FLAG_ZP     ((flags_acc>>2)&0x01)
#define FLAG_XN     ((flags_acc>>3)&0x01)
#define FLAG_YN     ((flags_acc>>4)&0x01)
#define FLAG_ZN     ((flags_acc>>5)&0x01)

enum{
    EST_CALIB_INICIO,
    EST_CALIB_ESPERA,
    EST_CALIB_XPOS,
    EST_CALIB_XNEG,
    EST_CALIB_YPOS,
    EST_CALIB_YNEG,
    EST_CALIB_ZPOS,
    EST_CALIB_ZNEG,  
    EST_CALIB_EJECUTAR,        
};

void AccValoresCalibracion(signed int * Acc);
void AccCalcularOffset(void);
void CalcularEscala(void);

