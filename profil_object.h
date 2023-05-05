#ifndef PROFIL_OBJECT_H
#define PROFIL_OBJECT_H

#include "object3d.h"

class profil_object:public _object3D
{
public:
    profil_object();
    vector<_vertex3f> get_curve();

private:
    vector<_vertex3f> curve;
};

#endif // PROFIL_OBJECT_H
