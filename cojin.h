#ifndef COJIN_H
#define COJIN_H

#include<object3d.h>
#include<pieza.h>

class cojin
{
public:
    cojin();
    void draw(int mode, int text);

private:
    pieza Pieza;
};

#endif // COJIN_H
