#ifndef ESPALDAR_H
#define ESPALDAR_H

#include<cabezera.h>
#include<reposa_espalda.h>

class espaldar
{
public:
    espaldar();
    void draw(int mode, int text);
    void animacionEspaldar_i();
    void animacionEspaldar_d();

private:
    cabezera Cabezera;
    reposa_espalda ReposaEspalda;
    double angleStepAnimation;
};

#endif // ESPALDAR_H
