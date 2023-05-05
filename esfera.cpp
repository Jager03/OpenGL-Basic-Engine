#include "esfera.h"

esfera::esfera(int profundidad)
{
    Vertices.clear();
    Vertices.resize(profundidad + 1);

    double angleStep = (pi)/profundidad;
    double angle = (3*pi)/2;


    for(int i = 0; i < profundidad + 1; i++){
        Vertices[i] = _vertex3f(cos(angle), sin(angle), 0);
        angle += angleStep;
    }

    /*Generar puntos con metodo de revolucion*/

    vector<_vertex3f> curve = Vertices;
    int n = 30;
    angle = (2*pi)/n;
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
    this->fill_flat_normal();
    this->fill_smooth_normal();
}
