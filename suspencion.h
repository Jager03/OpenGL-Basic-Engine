#ifndef SUSPENCION_H
#define SUSPENCION_H

#include <pieza.h>

class suspencion
{
public:
    suspencion();
    void draw(int mode, int text);

private:
    pieza Pieza{};
};

#endif // SUSPENCION_H
