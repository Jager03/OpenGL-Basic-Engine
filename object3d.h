/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"
#include "math.h"
#include "stb_image.h"
#include <GL/gl.h>
#include <QOpenGLWidget>
//#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#define getCord(x, m, j, i) (x)+((m)*(j))+i


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
  public:
    vector<_vertex3ui> Triangles;
    vector<_vertex3f> normal_flat;
    vector<_vertex3f> normal_smooth;
    vector<_vertex2f> texCoord;
    unsigned int textura;
    _object3D();

    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_flat();
    void draw_smooth();
    void draw_revolution(int n, vector<_vertex3f> curve);
    void fill_flat_normal();
    void fill_smooth_normal();
    void draw_text(int textID);
    void draw_text_flat(int textID);
    void draw_text_smooth(int textID);



  //vector<_vertex3ui> neighbourTriangle(_vertex3f Vertice)

};

#endif // OBJECT3D_H
