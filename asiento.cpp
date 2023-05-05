#include "asiento.h"

asiento::asiento()
{

}

void asiento::draw(int mode, int text){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslated(-1.375, 2.25, 0);
    glTranslated(-angleStepAnimationTx, -angleStepAnimationTy, 0);
    glRotated(angleStepAnimationR, 0, 0, 1);
    Espaldar.draw(mode, text);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 1.125, 0);
    ReposaCulo.draw(mode, text);
    glPopMatrix();
}

double asiento::animacionEspaldar_i(double rate){
    if((angleStepAnimationR + (15 * rate)) <= 45){
        angleStepAnimationR = angleStepAnimationR + (15 * rate);
        angleStepAnimationTx = angleStepAnimationTx + (0.25 * rate);
        angleStepAnimationTy = angleStepAnimationTy + (0.1 * rate);

        cout << "ASAR: " << angleStepAnimationR << endl;
        cout << "ASATx: " << angleStepAnimationTx << endl;
        cout << "ASATy: " << angleStepAnimationTy << endl;
        cout << "rate: " << rate << endl;

        return angleStepAnimationR;
    }

    else return angleStepAnimationR;
}

double asiento::animacionEspaldar_d(double rate){
    if((angleStepAnimationR - (15 * rate)) >= 0){
        angleStepAnimationR = angleStepAnimationR - (15 * rate);
        angleStepAnimationTx = angleStepAnimationTx - (0.25 * rate);
        angleStepAnimationTy = angleStepAnimationTy - (0.1 * rate);

        cout << "ASAR: " << angleStepAnimationR << endl;
        cout << "ASATx: " << angleStepAnimationTx << endl;
        cout << "ASATy: " << angleStepAnimationTy << endl;
        cout << "rate: " << rate << endl;

        return angleStepAnimationR;
    }

    else return angleStepAnimationR;
}
