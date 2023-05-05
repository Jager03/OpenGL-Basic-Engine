#ifndef PIEZA_H
#define PIEZA_H

#include <cube.h>
#include <cilindro.h>

class pieza
{
public:
    pieza();
    void draw(int type, int mode, int text);

private:
    _cube cube;
    cilindro Cilindro;

};

#endif // PIEZA_H
