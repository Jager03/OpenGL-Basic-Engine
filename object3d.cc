/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"
#include "qopenglext.h"

#define pi 3.141592653589793238462643383279502884197169399375105820974944


using namespace _colors_ne;

/*****************************************************************************//**
 *
 * Funcion auxiliar para normalizar un vecotr
 *
 *****************************************************************************/
_vertex3f normalize(_vertex3f v){
    float norm = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);

    float x = v[0]/norm;
    float y = v[1]/norm;
    float z = v[2]/norm;

    return _vertex3f(x, y, z);
}

/*****************************************************************************//**
 *
 *  Funcion auxiliar para calcular la normal entre dos vectores
 *
 *****************************************************************************/

_vertex3f dot_product(_vertex3f &v1, _vertex3f &v2){
    float x = v1[1]*v2[2] - v1[2]*v2[1];
    float y = v1[2]*v2[0] - v1[0]*v2[2];
    float z = v1[0]*v2[1] - v1[1]*v2[0];

    return _vertex3f(x, y, z);
}

/*****************************************************************************//**
 *
 *  Constructor
 *
 *****************************************************************************/

_object3D::_object3D(){
    normal_flat.resize(Triangles.size());
    _vertex3f normal = 0;

    for(unsigned int i = 0; i < Triangles.size(); i++){
        _vertex3f a = Vertices[Triangles[i]._1] - Vertices[Triangles[i]._0];
        _vertex3f b = Vertices[Triangles[i]._2] - Vertices[Triangles[i]._0];

        normal = normalize(dot_product(a, b));

        this->normal_flat[i] = normal;

    }
}

/*****************************************************************************//**
 *
 *  Funciones de dibujado:
 *
 *****************************************************************************/

void _object3D::draw_line()
{
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    glBegin(GL_TRIANGLES);
//    for(unsigned int i = 0; i < Triangles.size(); i++){
//        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
//        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
//        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
//    }
//    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3,GL_FLOAT,0,&Vertices[0]);

    glDrawElements(GL_TRIANGLES,Triangles.size()*3,GL_UNSIGNED_INT,&Triangles[0]);


}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
//    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//    glBegin(GL_TRIANGLES);
//    for(unsigned int i = 0; i < Triangles.size(); i++){
//        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
//        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
//        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
//    }
//    glEnd();
  
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3,GL_FLOAT,0,&Vertices[0]);

    glDrawElements(GL_TRIANGLES,Triangles.size()*3,GL_UNSIGNED_INT,&Triangles[0]);
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    bool colorFlag {false};

    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);
    for(unsigned int i = 0; i < Triangles.size(); i++){
        if(colorFlag){
             glColor3fv((GLfloat *) &BLACK);
        }
        else glColor3fv((GLfloat *) &YEllOW);

        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

        colorFlag = !colorFlag;
    }
    glEnd();

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_revolution(int n, vector<_vertex3f> curve){
    float angle = (2*pi)/n;
    int counterIndex{}, counterStep{};
    float x, y, z{};
    const unsigned int m = curve.size();

    this->Vertices.resize(curve.size()*n);
    for(int i{}; i <= 2*pi; i = angle*counterStep){
        for(unsigned int j{}; j < curve.size(); j++){
            x = cos(i) * curve[j]._0;
            y = curve[j]._1;
            z = -sin(i) * curve[j]._2;

            this->Vertices[counterIndex] = _vertex3f(x, y, z);
            counterIndex++;
        }
        counterStep++;
    }

    _vertex3ui initT0{0, m, 1};
    _vertex3ui initT1{m, m-1, 1};
    counterIndex = 0;
    this->Triangles.resize((m-1)*n*2);
    for(unsigned int i{}; i < m-1; i++){
        for(int j{}; j < n; j++){
            this->Triangles[counterIndex] = _vertex3ui(getCord(initT0._0, m, j, i), getCord(initT0._1, m, j, i), getCord(initT0._2, m, j, i) );
            this->Triangles[counterIndex++] = _vertex3ui(getCord(initT1._0, m, j, i), getCord(initT1._1, m, j, i), getCord(initT1._2, m, j, i) );
            counterIndex++;
        }
    }
}

/*****************************************************************************//**
 *
 *  Funcion de ayuda para calcular los trinagulos pertenecientes a un vertice
 *
 *****************************************************************************/




vector<int> neighborhoodTriangle(_vertex3f &Vertice, vector<_vertex3ui>& Triangles, vector<_vertex3f>& Vertices){
    vector<int> vecinos;

    //coger cada triangulo y checkear si uno de sus vertices es el vertice a buscar
    for(unsigned int j = 0; j < Triangles.size()  ; j++){
        //chequear cada vertices del triangulo a ver si es el vertice a investigar
        for(unsigned int k = 0; k < 3; k++){
            //Si el vertice k (k: 0,1,2) del triangulo j es igual al vertice i entonces vertice i pertenece al Triangulo j
            if(Vertices[Triangles[j][k]] == Vertice) vecinos.push_back(j);
        }
    }

    return vecinos;
}

/*****************************************************************************//**
 *
 *  Funcion para dibujar en modo flat
 *
 *****************************************************************************/

void _object3D::draw_flat()
{
    glPolygonMode(GL_FRONT, GL_FILL);   //GL_FRONT solamente para no pintar triangulos que no se ven y ayudar a la velocidad de la aplicacion
    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLES);
    for(unsigned int i = 0; i < Triangles.size(); i++){
        glNormal3f (normal_flat[i]._0, normal_flat[i]._1, normal_flat[i]._2);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();

}

/*****************************************************************************//**
 *
 *  Funcion para dibujar con sombreado de Gouraud
 *
 *****************************************************************************/

void _object3D::draw_smooth()
{
    glPolygonMode(GL_FRONT, GL_FILL);   //GL_FRONT solamente para no pintar triangulos que no se ven y ayudar a la velocidad de la aplicacion
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);


    for(unsigned int i = 0; i < Triangles.size(); i++){
        glNormal3f (normal_smooth[Triangles[i]._0]._0, normal_smooth[Triangles[i]._0]._1, normal_smooth[Triangles[i]._0]._2);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);


        glNormal3f (normal_smooth[Triangles[i]._1]._0, normal_smooth[Triangles[i]._1]._1, normal_smooth[Triangles[i]._1]._2);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);


        glNormal3f (normal_smooth[Triangles[i]._2]._0, normal_smooth[Triangles[i]._2]._1, normal_smooth[Triangles[i]._2]._2);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();

}

/*****************************************************************************//**
 *
 *  Funcion para dibujar la textura
 *
 *****************************************************************************/

void _object3D::draw_text(int textID)
{

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textID);

    glBegin(GL_TRIANGLES);

    for(unsigned int i = 0; i < Triangles.size(); i++){

        glTexCoord2f(texCoord[Triangles[i]._0]._0, texCoord[Triangles[i]._0]._1);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);


        glTexCoord2f(texCoord[Triangles[i]._1]._0, texCoord[Triangles[i]._1]._1);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);


        glTexCoord2f(texCoord[Triangles[i]._2]._0, texCoord[Triangles[i]._2]._1);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

    glEnd();
    glDisable(GL_TEXTURE_2D);

//    glEnableClientState(GL_VERTEX_ARRAY);
//    glEnableClientState(GL_TEXTURE_COORD_ARRAY_EXT);
//    glEnable(GL_TEXTURE_2D);

//    glBindTexture(GL_TEXTURE_2D, textura);

//    glVertexPointer(3,GL_FLOAT,0,&Vertices[0]);
//    glTexCoordPointer(2, GL_FLOAT, 0, &texCoord[0]);

//    glDrawElements(GL_TRIANGLES,Triangles.size()*3,GL_UNSIGNED_INT,&Triangles[0]);

//    glDisableClientState(GL_VERTEX_ARRAY);
//    glBindTexture(GL_TEXTURE_2D, 0);
//    glDisable(GL_TEXTURE_2D);


}

void _object3D::draw_text_flat(int textID)
{

    glPolygonMode(GL_FRONT, GL_FILL);
    glShadeModel(GL_FLAT);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textID);

    glBegin(GL_TRIANGLES);

    for(unsigned int i = 0; i < Triangles.size(); i++){
        glNormal3f (normal_flat[i]._0, normal_flat[i]._1, normal_flat[i]._2);
        glTexCoord2f(texCoord[Triangles[i]._0]._0, texCoord[Triangles[i]._0]._1);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);


        glTexCoord2f(texCoord[Triangles[i]._1]._0, texCoord[Triangles[i]._1]._1);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);


        glTexCoord2f(texCoord[Triangles[i]._2]._0, texCoord[Triangles[i]._2]._1);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void _object3D::draw_text_smooth(int textID)
{

    glPolygonMode(GL_FRONT, GL_FILL);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textID);

    glBegin(GL_TRIANGLES);

    for(unsigned int i = 0; i < Triangles.size(); i++){
        glTexCoord2f(texCoord[Triangles[i]._0]._0, texCoord[Triangles[i]._0]._1);
        glTexCoord2f(texCoord[Triangles[i]._0]._0, texCoord[Triangles[i]._0]._1);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

        glTexCoord2f(texCoord[Triangles[i]._1]._0, texCoord[Triangles[i]._1]._1);
        glTexCoord2f(texCoord[Triangles[i]._1]._0, texCoord[Triangles[i]._1]._1);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

        glTexCoord2f(texCoord[Triangles[i]._2]._0, texCoord[Triangles[i]._2]._1);
        glTexCoord2f(texCoord[Triangles[i]._2]._0, texCoord[Triangles[i]._2]._1);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

/*****************************************************************************//**
 *
 *  Funcion para llenar el vector de normales para el modo flat (una normal por triangulo)
 *
 *****************************************************************************/

void _object3D::fill_flat_normal(){
    normal_flat.resize(Triangles.size());
    _vertex3f normal = 0;

    for(unsigned int i = 0; i < Triangles.size(); i++){
        _vertex3f a = Vertices[Triangles[i]._1] - Vertices[Triangles[i]._0];
        _vertex3f b = Vertices[Triangles[i]._2] - Vertices[Triangles[i]._0];

        normal = normalize(dot_product(a, b));

        this->normal_flat[i] = normal;

    }
}

/*****************************************************************************//**
 *
 *  Funcion para llenar el vector de normales de modo smooth (una normal por vertice)
 *
 *****************************************************************************/

void _object3D::fill_smooth_normal(){
    _vertex3f normal = 0;
    normal_smooth.resize(Vertices.size());

    vector<int> vecinos;
    float sumX, sumY, sumZ;
    //por cada vertice checkear a que triangulo pertenece
    for(unsigned int i = 0; i < Vertices.size()  ; i++){
        vecinos = neighborhoodTriangle(Vertices[i], this->Triangles, this->Vertices);
        sumX = 0;
        sumY = 0;
        sumZ = 0;
        //por cada vecino hacer la sumatoria de las componentes x, y, z de sus respectivas normales
        //ya guardadas en el vector normal_flat
        for(unsigned int j = 0; j < vecinos.size(); j++){
            sumX += normal_flat.at(vecinos[j])._0;
            sumY += normal_flat[vecinos[j]]._1;
            sumZ += normal_flat[vecinos[j]]._2;
        }

        //optener la media de las componetes
        normal._0 = sumX/(vecinos.size());
        normal._1 = sumY/vecinos.size();
        normal._2 = sumZ/vecinos.size();

        normal_smooth[i] = normal;
    }
}


