#ifndef SILLA_BASE_H
#define SILLA_BASE_H

#include <pieza.h>


class silla_base
{
public:
    silla_base();
    void draw(int mode, int text);
    pieza getPieza();
    void animacion2_i(double rate);
    void animacion2_d(double rate);

private:
    pieza Pieza{};
};

#endif // SILLA_BASE_H
