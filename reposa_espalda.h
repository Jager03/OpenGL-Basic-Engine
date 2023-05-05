#ifndef REPOSA_ESPALDA_H
#define REPOSA_ESPALDA_H

#include<object3d.h>
#include<pieza.h>
class reposa_espalda : public _object3D
{
public:
    reposa_espalda();
    void draw(int mode, int text);

private:
    pieza Pieza;
};

#endif // REPOSA_ESPALDA_H
