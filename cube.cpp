#include "cube.h"

_cube::_cube(float Size)
{
    Vertices.resize(8);

    Vertices[0]=_vertex3f(Size/2,-Size/2,Size/2);
    Vertices[1]=_vertex3f(-Size/2,-Size/2,Size/2);
    Vertices[2]=_vertex3f(-Size/2,Size/2,Size/2);
    Vertices[3]=_vertex3f(Size/2,Size/2,Size/2);
    Vertices[4]=_vertex3f(Size/2,-Size/2,-Size/2);
    Vertices[5]=_vertex3f(-Size/2,-Size/2,-Size/2);
    Vertices[6]=_vertex3f(-Size/2,Size/2,-Size/2);
    Vertices[7]=_vertex3f(Size/2,Size/2,-Size/2);

    Triangles.resize(12);

    //Adelante
    Triangles[0]=_vertex3ui(2,1,0);
    Triangles[1]=_vertex3ui(0,3,2);

    //Atras
    Triangles[2]=_vertex3ui(4,5,6);
    Triangles[3]=_vertex3ui(6,7,4);

    //Lado dereccho
    Triangles[4]=_vertex3ui(6,5,1);
    Triangles[5]=_vertex3ui(1,2,6);

    //Lado izquierdo
    Triangles[6]=_vertex3ui(0,4,7);
    Triangles[7]=_vertex3ui(7,3,0);

    //Arriba
    Triangles[8]=_vertex3ui(6,2,3);
    Triangles[9]=_vertex3ui(3,7,6);

    //Abajo
    Triangles[10]=_vertex3ui(0,1,5);
    Triangles[11]=_vertex3ui(5,4,0);

    texCoord.resize(8);

    texCoord[0] = _vertex2f(0, 1);
    texCoord[1] = _vertex2f(1, 1);
    texCoord[2] = _vertex2f(1, 0);
    texCoord[3] = _vertex2f(0, 0);

    texCoord[4] = _vertex2f(0, 1);
    texCoord[5] = _vertex2f(1, 1);
    texCoord[6] = _vertex2f(1, 0);
    texCoord[7] = _vertex2f(0, 0);

    this->fill_flat_normal();
    this->fill_smooth_normal();
}
