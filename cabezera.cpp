#include "cabezera.h"

cabezera::cabezera()
{

}

void cabezera::draw(int mode, int text){
    glMatrixMode(GL_MODELVIEW);


    Cuello.draw(mode, text);


    glPushMatrix();

    glTranslated(0, 0.375, 0);
    ReposaCabeza.draw(mode, text);
    glPopMatrix();
}
