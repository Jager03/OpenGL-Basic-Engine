#ifndef ASIENTO_H
#define ASIENTO_H

#include<espaldar.h>
#include<reposa_culo.h>
#include<pieza.h>

class asiento
{
public:
    asiento();
    void draw(int mode, int text);
    double animacionEspaldar_i(double rate);
    double animacionEspaldar_d(double rate);
    double angleStepAnimationR;
    double angleStepAnimationTx;
    double angleStepAnimationTy;

private:
    espaldar Espaldar;
    reposa_culo ReposaCulo;
    pieza Pieza;
};

#endif // ASIENTO_H
