#include "suspencion.h"

suspencion::suspencion()
{

}

void suspencion::draw(int mode, int text){
    //Suspencion
    glPushMatrix();
    Pieza.draw(0, mode, text);
    glPopMatrix();
}
