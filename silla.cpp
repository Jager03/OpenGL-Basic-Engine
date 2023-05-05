#include "silla.h"


Silla::Silla()
{
    animacion = 0;
}

void Silla::draw(int mode, int text){                 //incluir como parametros los angleStep de las animaciones y el rate
    glMatrixMode(GL_MODELVIEW);




    Base.draw(mode, text);

    glPushMatrix();
    glTranslated(0, 2*angleStepAnimation, 0);
    glRotated(angleStepAnimationR, 0, 1, 0);
    Asiento.draw(mode, text);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, angleStepAnimation, 0);
    glScaled(1, 1+angleStepAnimation, 1);
    Suspencion.draw(mode, text);
    glPopMatrix();

}

//double Silla::animacion1_i(double rate){
//    return Asiento.animacionEspaldar_i(rate);
//}

//double Silla::animacion1_d(double rate){
//    return Asiento.animacionEspaldar_d(rate);
//}

//void Silla::animacion2_i(double rate){

//    angleStepAnimation = angleStepAnimation + (0.2 * rate);

//    cout << "ASA: " << angleStepAnimation << endl;
//    cout << "rate: " << rate <<endl;
//}

//void Silla::animacion2_d(double rate){
//    if((angleStepAnimation - (0.2 * rate)) >= 0){
//        angleStepAnimation = angleStepAnimation - (0.2 * rate);

//        cout << "ASA: " << angleStepAnimation << endl;
//        cout << "rate: " << rate <<endl;
//    }
//}

//void Silla::animacion3_i(double rate){
//    angleStepAnimationR = angleStepAnimationR + (10 * rate);
//}

//void Silla::animacion3_d(double rate){
//    angleStepAnimationR = angleStepAnimationR - (10 * rate);
//}
