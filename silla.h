#ifndef SILLA_H
#define SILLA_H

#include<object3d.h>
#include<silla_base.h>
#include<asiento.h>
#include<suspencion.h>

class Silla : public _object3D
{
public:
    Silla();
    void draw(int mode, int texture);
    double animacion1_i(double rate);
    double animacion1_d(double rate);
    void animacion2_i(double rate);
    void animacion2_d(double rate);
    void animacion3_i(double rate);
    void animacion3_d(double rate);
    double animacion;
    silla_base Base;
    asiento Asiento;
    suspencion Suspencion;
    double angleStepAnimation;
    double angleStepAnimationR;


};

#endif // SILLA_H
