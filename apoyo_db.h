#ifndef APOYO_DB_H
#define APOYO_DB_H

#include<object3d.h>
#include<pieza.h>

class apoyo_db : public _object3D
{
public:
    apoyo_db();
    void draw(int mode, int text);

private:
    pieza Pieza;
};

#endif // APOYO_DB_H
