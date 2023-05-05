#ifndef SUSPENCION_DB_H
#define SUSPENCION_DB_H

#include<pieza.h>

class suspencion_db
{
public:
    suspencion_db();
    void draw(int mode, int text);

private:
    pieza Pieza{};
};

#endif // SUSPENCION_DB_H
