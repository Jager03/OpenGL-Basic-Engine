#ifndef CABEZERA_H
#define CABEZERA_H

#include<object3d.h>
#include<pieza.h>
#include<reposa_cabeza.h>
#include<cuello.h>

class cabezera : public _object3D
{
public:
    cabezera();
    void draw(int mode, int text);

private:
    cuello Cuello;
    reposa_cabeza ReposaCabeza;
};

#endif // CABEZERA_H
