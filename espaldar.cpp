#include "espaldar.h"

espaldar::espaldar()
{

}

void espaldar::draw(int mode, int text){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslated(0, 1.375, 0);
    Cabezera.draw(mode, text);
    glPopMatrix();



    ReposaEspalda.draw(mode, text);

}

void espaldar::animacionEspaldar_i(){
    if(angleStepAnimation < 90){
        angleStepAnimation = angleStepAnimation + 15;
        return;
    }
    else return;
}

void espaldar::animacionEspaldar_d(){
    if(angleStepAnimation > 0){
        angleStepAnimation = angleStepAnimation - 15;
        return;
    }
    else return;
}
