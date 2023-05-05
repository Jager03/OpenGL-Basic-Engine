#ifndef CUELLO_H
#define CUELLO_H

#include<object3d.h>
#include<pieza.h>

class cuello : public _object3D
{
public:
    cuello();
    void draw(int mode, int text);

private:
    pieza Pieza;
};

#endif // CUELLO_H
