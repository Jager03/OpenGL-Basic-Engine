#include "profil_object.h"

profil_object::profil_object()
{
    Vertices.resize(4);

    Vertices[0]=_vertex3f(0, 1, 0);
    Vertices[1]=_vertex3f(1, 1, 0);
    Vertices[2]=_vertex3f(1, -1, 0);
    Vertices[3]=_vertex3f(0, -1, 0);

    for(unsigned int i{}; i < Vertices.size(); i++){
        curve.push_back(Vertices[i]);
    }
}

vector<_vertex3f> profil_object::get_curve(){
    return this->curve;
}
