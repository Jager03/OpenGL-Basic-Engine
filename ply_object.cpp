#include "ply_object.h"
#include "file_ply_stl.h"
#include "math.h"
#define pi 3.141592653589793238462643383279502884197169399375105820974944
#include <filesystem>
namespace fs = std::filesystem;

_ply_object::_ply_object(){
    this->fileName = "beethoven.ply";
    fs::path p = fs::current_path();
    cout << p.string() <<endl;

    _file_ply file_ply{};
    vector<float> coordinates{};
    vector<unsigned int> position{};
    int pos{};

    file_ply.open("D:/GR_universidad/IG/skeleton/skeleton/" + fileName);

    //Camino relativo
    //file_ply.open("../../skeleton/build-esqueleto_qt-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/" +fileName);
    file_ply.read(coordinates, position);

    this->Vertices.resize(coordinates.size()/3);

    for(int i = 0; i < coordinates.size()/3; i++){
        this->Vertices[i] = _vertex3f(coordinates.at(pos), coordinates.at(pos++), coordinates.at(pos++));
        pos++;
    }

    pos = 0;
    this->Triangles.resize(position.size()/3);

    for(int i = 0; i < position.size()/3; i++){
        this->Triangles[i] = _vertex3ui(position.at(pos), position.at(pos++), position.at(pos++));
        pos++;
    }

    this->fill_flat_normal();
    this->fill_smooth_normal();
}

void _ply_object::sweep(int n, vector<_vertex3f> curve){
    /*Generar puntos con metodo de revolucion*/

    double angle = (2*pi)/n;
    int counterIndex = 0;
    int counterStep = 0;
    float x, y, z{};
    const unsigned int m = curve.size();

    Vertices.clear();
    this->Vertices.resize(curve.size()*n);
    for(double i{}; i < 2*pi; i = angle*counterStep){
        for(unsigned int j{}; j < curve.size(); j++){
            x = cos(i) * curve[j]._0;
            y = curve[j]._1;
            z = -sin(i) * curve[j]._0;

            Vertices[counterIndex] = _vertex3f(x, y, z);
            counterIndex++;
        }
        counterStep++;
    }

    /*Generar traingulos con metodo de revolucion*/

    int mod = m*n;
    int trCount = 1;
    Triangles.resize(m*n*2);
    for(unsigned int i = 0; i< m; i++){
        for(unsigned int j=0; j<n; j++){
            if(i != m-2 && i!=0){
                Triangles[trCount]=(_vertex3ui(((j*m)+i)%mod,(((j+1)*m)+i)%mod,((j*m)+i+1)%mod));
                trCount++;
                Triangles[trCount]=(_vertex3ui((((j+1)*m)+i)%mod,(((j+1)*m)+i+1)%mod,((j*m)+i+1)%mod));
                trCount++;
                            }
            else if(i == m-2){
                    Triangles[trCount]=(_vertex3ui(((j*m)+i)%mod,(((j+1)*m)+i)%mod,((j*m)+i+1)%mod));
                    trCount++;
                }
            else if(i == 0){
                    Triangles[trCount]=(_vertex3ui((((j+1)*m)+i)%mod,(((j+1)*m)+i+1)%mod,((j*m)+i+1)%mod));
                    trCount++;
                }
            }
        }
}

