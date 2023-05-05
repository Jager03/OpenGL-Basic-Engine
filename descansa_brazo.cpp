#include "descansa_brazo.h"

descansa_brazo::descansa_brazo()
{

}

void descansa_brazo::draw(int mode, int text){
    glMatrixMode(GL_MODELVIEW);

    ApoyoDB.draw(mode, text);


    glPushMatrix();
    glTranslated(0, 0.225, 0);
    SuspencionDB.draw(mode, text);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 0.475, 0);
    Brazera.draw(mode, text);
    glPopMatrix();
}
