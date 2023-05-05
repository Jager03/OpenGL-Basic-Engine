#ifndef CILINDRO_H
#define CILINDRO_H

#include "object3d.h"


class cilindro : public _object3D
{
public:
    cilindro();

private:
    double pi = 3.141592653589793238462643383279502884197169399375105820974944;
};

#endif // CILINDRO_H
