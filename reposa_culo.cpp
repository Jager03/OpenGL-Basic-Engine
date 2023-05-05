#include "reposa_culo.h"

reposa_culo::reposa_culo()
{

}

void reposa_culo::draw(int mode, int text){
    glMatrixMode(GL_MODELVIEW);


    Cojin.draw(mode, text);


    glPushMatrix();
    glTranslated(0, 0, 1.375);
    DB1.draw(mode, text);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 0, -1.375);
    DB2.draw(mode, text);
    glPopMatrix();
}
