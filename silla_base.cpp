#include "silla_base.h"
#include <GL/gl.h>

silla_base::silla_base()
{

}

pieza silla_base::getPieza(){
    return this->Pieza;
}

void silla_base::draw(int mode, int text){
    glMatrixMode(GL_MODELVIEW);



        //Piso
    glPushMatrix();
    glTranslated(0, -1, 0);
    Pieza.draw(1, mode, text);
    glPopMatrix();

}

void silla_base::animacion2_i(double rate){

}

void silla_base::animacion2_d(double rate){

}
