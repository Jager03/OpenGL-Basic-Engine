#ifndef CONO_H
#define CONO_H

#include "object3d.h"

class cono : public _object3D
{
public:
    cono();

private:
    double pi = 3.141592653589793238462643383279502884197169399375105820974944;
};

#endif // CONO_H
