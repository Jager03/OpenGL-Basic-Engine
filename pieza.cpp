#include "pieza.h"
using namespace _colors_ne;

pieza::pieza()
{

}

void pieza::draw(int type, int mode, int text){

    glMatrixMode(GL_MODELVIEW);

    if(mode == 0){
        switch(type){
        //suspencion
        case 0:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 1, 0.25);
            Cilindro.draw_point();
            glPopMatrix();
            break;

        //base
        case 1:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(1.5, 0.125, 1.5);
            Cilindro.draw_point();
            glPopMatrix();
            break;

        //cojin
        case 2:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(2.5, 0.25, 2.5);
            cube.draw_point();
            glPopMatrix();
            break;

        //reposa espalda
        case 3:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 2.5, 2.5);
            cube.draw_point();
            glPopMatrix();
            break;

        //cuello
        case 4:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 0.25, 0.5);
            cube.draw_point();
            glPopMatrix();
            break;

        //reposa cabeza
        case 5:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 0.5, 1.25);
            cube.draw_point();
            glPopMatrix();
            break;

        //apoyo descansa brazo
        case 6:
            glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.5f);
            glScaled(0.25, 0.125, 0.25);
            cube.draw_point();
            glPopMatrix();
            break;

        //suspencion DB
        case 7:
            glPushMatrix();
            glColor3f(0.5f, 0.5f, 0.5f);
            glScaled(0.125, 0.2, 0.125);
            Cilindro.draw_point();
            glPopMatrix();
            break;

        //brazera
        case 8:
            glPushMatrix();
            glColor3f(2.0f, 0.5f, 1.0f);
            glScaled(1.5, 0.1, 0.25);
            cube.draw_point();
            glPopMatrix();
            break;
        }

    }
    else if (mode == 1){
        switch(type){
        //suspencion
        case 0:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 1, 0.25);
            Cilindro.draw_line();
            glPopMatrix();
            break;

        //base
        case 1:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(1.5, 0.125, 1.5);
            Cilindro.draw_line();
            glPopMatrix();
            break;

        //cojin
        case 2:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(2.5, 0.25, 2.5);
            cube.draw_line();
            glPopMatrix();
            break;

        //reposa espalda
        case 3:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 2.5, 2.5);
            cube.draw_line();
            glPopMatrix();
            break;

        //cuello
        case 4:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 0.25, 0.5);
            cube.draw_line();
            glPopMatrix();
            break;

        //reposa cabeza
        case 5:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 0.5, 1.25);
            cube.draw_line();
            glPopMatrix();
            break;

        //apoyo descansa brazo
        case 6:
            glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.5f);
            glScaled(0.25, 0.125, 0.25);
            cube.draw_line();
            glPopMatrix();
            break;

        //suspencion DB
        case 7:
            glPushMatrix();
            glColor3f(0.5f, 0.5f, 0.5f);
            glScaled(0.125, 0.2, 0.125);
            Cilindro.draw_line();
            glPopMatrix();
            break;

        //brazera
        case 8:
            glPushMatrix();
            glColor3f(2.0f, 0.5f, 1.0f);
            glScaled(1.5, 0.1, 0.25);
            cube.draw_line();
            glPopMatrix();
            break;


        }

    }

    else if (mode == 2){
        switch(type){
        //suspencion
        case 0:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 1, 0.25);
            Cilindro.draw_fill();
            glPopMatrix();
            break;

        //base
        case 1:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(1.5, 0.125, 1.5);
            Cilindro.draw_fill();
            glPopMatrix();
            break;

        //cojin
        case 2:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(2.5, 0.25, 2.5);
            cube.draw_fill();
            glPopMatrix();
            break;

        //reposa espalda
        case 3:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 2.5, 2.5);
            cube.draw_fill();
            glPopMatrix();
            break;

        //cuello
        case 4:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 0.25, 0.5);
            cube.draw_fill();
            glPopMatrix();
            break;

        //reposa cabeza
        case 5:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 0.5, 1.25);
            cube.draw_fill();
            glPopMatrix();
            break;

        //apoyo descansa brazo
        case 6:
            glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.5f);
            glScaled(0.25, 0.125, 0.25);
            cube.draw_fill();
            glPopMatrix();
            break;

        //suspencion DB
        case 7:
            glPushMatrix();
            glColor3f(0.5f, 0.5f, 0.5f);
            glScaled(0.125, 0.2, 0.125);
            Cilindro.draw_fill();
            glPopMatrix();
            break;

        //brazera
        case 8:
            glPushMatrix();
            glColor3f(2.0f, 0.5f, 1.0f);
            glScaled(1.5, 0.1, 0.25);
            cube.draw_fill();
            glPopMatrix();
            break;


        }

    }
    else if (mode == 3){
        switch(type){
        //suspencion
        case 0:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 1, 0.25);
            Cilindro.draw_chess();
            glPopMatrix();
            break;

        //base
        case 1:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(1.5, 0.125, 1.5);
            Cilindro.draw_chess();
            glPopMatrix();
            break;

        //cojin
        case 2:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(2.5, 0.25, 2.5);
            cube.draw_chess();
            glPopMatrix();
            break;

        //reposa espalda
        case 3:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 2.5, 2.5);
            cube.draw_chess();
            glPopMatrix();
            break;

        //cuello
        case 4:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 0.25, 0.5);
            cube.draw_chess();
            glPopMatrix();
            break;

        //reposa cabeza
        case 5:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 0.5, 1.25);
            cube.draw_chess();
            glPopMatrix();
            break;

        //apoyo descansa brazo
        case 6:
            glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.5f);
            glScaled(0.25, 0.125, 0.25);
            cube.draw_chess();
            glPopMatrix();
            break;

        //suspencion DB
        case 7:
            glPushMatrix();
            glColor3f(0.5f, 0.5f, 0.5f);
            glScaled(0.125, 0.2, 0.125);
            Cilindro.draw_chess();
            glPopMatrix();
            break;

        //brazera
        case 8:
            glPushMatrix();
            glColor3f(2.0f, 0.5f, 1.0f);
            glScaled(1.5, 0.1, 0.25);
            cube.draw_chess();
            glPopMatrix();
            break;


        }

    }

    else if (mode == 4){
        switch(type){
        //suspencion
        case 0:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 1, 0.25);
            Cilindro.draw_flat();
            glPopMatrix();
            break;

        //base
        case 1:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(1.5, 0.125, 1.5);
            Cilindro.draw_flat();
            glPopMatrix();
            break;

        //cojin
        case 2:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(2.5, 0.25, 2.5);
            cube.draw_flat();
            glPopMatrix();
            break;

        //reposa espalda
        case 3:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 2.5, 2.5);
            cube.draw_flat();
            glPopMatrix();
            break;

        //cuello
        case 4:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 0.25, 0.5);
            cube.draw_flat();
            glPopMatrix();
            break;

        //reposa cabeza
        case 5:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 0.5, 1.25);
            cube.draw_flat();
            glPopMatrix();
            break;

        //apoyo descansa brazo
        case 6:
            glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.5f);
            glScaled(0.25, 0.125, 0.25);
            cube.draw_flat();
            glPopMatrix();
            break;

        //suspencion DB
        case 7:
            glPushMatrix();
            glColor3f(0.5f, 0.5f, 0.5f);
            glScaled(0.125, 0.2, 0.125);
            Cilindro.draw_flat();
            glPopMatrix();
            break;

        //brazera
        case 8:
            glPushMatrix();
            glColor3f(2.0f, 0.5f, 1.0f);
            glScaled(1.5, 0.1, 0.25);
            cube.draw_flat();
            glPopMatrix();
            break;


        }

    }

    else if (mode == 5){
        switch(type){
        //suspencion
        case 0:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 1, 0.25);
            Cilindro.draw_smooth();
            glPopMatrix();
            break;

        //base
        case 1:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(1.5, 0.125, 1.5);
            Cilindro.draw_smooth();
            glPopMatrix();
            break;

        //cojin
        case 2:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(2.5, 0.25, 2.5);
            cube.draw_smooth();
            glPopMatrix();
            break;

        //reposa espalda
        case 3:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 2.5, 2.5);
            cube.draw_smooth();
            glPopMatrix();
            break;

        //cuello
        case 4:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 0.25, 0.5);
            cube.draw_smooth();
            glPopMatrix();
            break;

        //reposa cabeza
        case 5:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 0.5, 1.25);
            cube.draw_flat();
            glPopMatrix();
            break;

        //apoyo descansa brazo
        case 6:
            glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.5f);
            glScaled(0.25, 0.125, 0.25);
            cube.draw_smooth();
            glPopMatrix();
            break;

        //suspencion DB
        case 7:
            glPushMatrix();
            glColor3f(0.5f, 0.5f, 0.5f);
            glScaled(0.125, 0.2, 0.125);
            Cilindro.draw_smooth();
            glPopMatrix();
            break;

        //brazera
        case 8:
            glPushMatrix();
            glColor3f(2.0f, 0.5f, 1.0f);
            glScaled(1.5, 0.1, 0.25);
            cube.draw_smooth();
            glPopMatrix();
            break;


        }

    }

    else if (mode == 6){
        switch(type){
        //suspencion
        case 0:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 1, 0.25);
            Cilindro.draw_fill();
            glPopMatrix();
            break;

        //base
        case 1:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(1.5, 0.125, 1.5);
            Cilindro.draw_fill();
            glPopMatrix();
            break;

        //cojin
        case 2:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(2.5, 0.25, 2.5);
            cube.draw_text_flat(text);
            glPopMatrix();
            break;

        //reposa espalda
        case 3:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 2.5, 2.5);
            cube.draw_text_flat(text);
            glPopMatrix();
            break;

        //cuello
        case 4:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 0.25, 0.5);
            cube.draw_text_flat(text);
            glPopMatrix();
            break;

        //reposa cabeza
        case 5:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 0.5, 1.25);
            cube.draw_text_flat(text);
            glPopMatrix();
            break;

        //apoyo descansa brazo
        case 6:
            glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.5f);
            glScaled(0.25, 0.125, 0.25);
            cube.draw_text_flat(text);
            glPopMatrix();
            break;

        //suspencion DB
        case 7:
            glPushMatrix();
            glColor3f(0.5f, 0.5f, 0.5f);
            glScaled(0.125, 0.2, 0.125);
            Cilindro.draw_fill();
            glPopMatrix();
            break;

        //brazera
        case 8:
            glPushMatrix();
            glColor3f(2.0f, 0.5f, 1.0f);
            glScaled(1.5, 0.1, 0.25);
            cube.draw_text_flat(text);
            glPopMatrix();
            break;


        }

    }

    else if (mode == 7){
        switch(type){
        //suspencion
        case 0:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 1, 0.25);
            Cilindro.draw_fill();
            glPopMatrix();
            break;

        //base
        case 1:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(1.5, 0.125, 1.5);
            Cilindro.draw_fill();
            glPopMatrix();
            break;

        //cojin
        case 2:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(2.5, 0.25, 2.5);
            cube.draw_text_smooth(text);
            glPopMatrix();
            break;

        //reposa espalda
        case 3:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 2.5, 2.5);
            cube.draw_text_smooth(text);
            glPopMatrix();
            break;

        //cuello
        case 4:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLACK);
            glScaled(0.25, 0.25, 0.5);
            cube.draw_text_smooth(text);
            glPopMatrix();
            break;

        //reposa cabeza
        case 5:
            glPushMatrix();
            glColor3fv((GLfloat *) &BLUE);
            glScaled(0.25, 0.5, 1.25);
            cube.draw_text_smooth(text);
            glPopMatrix();
            break;

        //apoyo descansa brazo
        case 6:
            glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.5f);
            glScaled(0.25, 0.125, 0.25);
            cube.draw_text_smooth(text);
            glPopMatrix();
            break;

        //suspencion DB
        case 7:
            glPushMatrix();
            glColor3f(0.5f, 0.5f, 0.5f);
            glScaled(0.125, 0.2, 0.125);
            Cilindro.draw_fill();
            glPopMatrix();
            break;

        //brazera
        case 8:
            glPushMatrix();
            glColor3f(2.0f, 0.5f, 1.0f);
            glScaled(1.5, 0.1, 0.25);
            cube.draw_text_smooth(text);
            glPopMatrix();
            break;


        }

    }


}
