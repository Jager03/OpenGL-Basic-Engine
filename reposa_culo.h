#ifndef REPOSA_CULO_H
#define REPOSA_CULO_H

#include<object3d.h>
#include<cojin.h>
#include<descansa_brazo.h>

class reposa_culo : public _object3D
{
public:
    reposa_culo();

    void draw(int mode, int text);

private:
    cojin Cojin;
    descansa_brazo DB1;
    descansa_brazo DB2;
};

#endif // REPOSA_CULO_H
