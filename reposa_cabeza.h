#ifndef REPOSA_CABEZA_H
#define REPOSA_CABEZA_H

#include<object3d.h>
#include<pieza.h>

class reposa_cabeza
{
public:
    reposa_cabeza();
    void draw(int mode, int text);

private:
    pieza Pieza;
};

#endif // REPOSA_CABEZA_H
