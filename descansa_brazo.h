#ifndef APOYA_BRAZO_H
#define APOYA_BRAZO_H

#include<object3d.h>
#include<pieza.h>
#include<apoyo_db.h>
#include<suspencion_db.h>
#include<brazera.h>


class descansa_brazo
{
public:
    descansa_brazo();
    void draw(int mode, int text);

private:
    apoyo_db ApoyoDB;
    suspencion_db SuspencionDB;
    brazera Brazera;


};

#endif // APOYA_BRAZO_H
