#ifndef ESFERA_H
#define ESFERA_H

#include "object3d.h"

class esfera : public _object3D
{
public:
    esfera(int profundidad=20);

private:
    double pi = 3.141592653589793238462643383279502884197169399375105820974944;
};

#endif // ESFERA_H
