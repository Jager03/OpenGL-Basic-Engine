#ifndef _PLY_OBJECT_H
#define _PLY_OBJECT_H

#include "object3d.h"


class _ply_object : public _object3D
{
public:
    _ply_object();
    void sweep(int n, vector<_vertex3f> curve);

private:
    string fileName;
};

#endif // _PLY_OBJECT_H
