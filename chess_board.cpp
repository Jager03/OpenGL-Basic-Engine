#include "chess_board.h"

chess_board::chess_board(int s)
{
    int size = s;
    Vertices.resize((size +1)*(size+1));
    texCoord.resize(Vertices.size());
    int cntr = 0;
    float step = 1 / float(size);

    // <= para que llegue de 0.5 a -0.5 y no se quede una iteracion atras 0.5 - step
    // o en caso de las texturas que llegue a 1.0 y no a 0.8
    for(int i = 0; i <= size; i++) {
        for(int j = 0; j <= size; j++){
            Vertices[cntr] = _vertex3f(-0.5+(step*j), -0.5+(step*i), 0);
            texCoord[cntr] = _vertex2f(1 - (step*j), 1 - (step*i));
            cout << "Vertices #" << cntr << ": " << Vertices[cntr].x << " " << Vertices[cntr].y << " " << Vertices[cntr].z << "  \n";
            cout << "texCoord #" << cntr << ": " << texCoord[cntr].x << " " << texCoord[cntr].y << "  \n\n";
            cntr++;
        }
    }

    //cambiar el size a size+1 para que sea equivalente con la generacion de vertices
    size = s+1;

    Triangles.resize(((size-1)*(size-1))*2);
    //Triangles.resize(10);
    cntr = 0;
    int mod = (size * size)-1;

    int x = 0;
    int y = 0;
    int z = 0;

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            x = (1 + (size*j) + i);
            y = (size+1) + (size*j) + i;
            z = (size) + (size*j) + i;

            if(x > mod) x = x%mod;
            if(y > mod) y = y%mod;
            if(z > mod) z = z%mod;

            Triangles[cntr] = _vertex3ui(x, y, z);
            cntr++;

            x = (size) + (size*j) + i;
            y = (0) + (size*j) + i;
            z = (1) + (size*j) + i;

            if(x > mod) x = x%mod;
            if(y > mod) y = y%mod;
            if(z > mod) z = z%mod;

            Triangles[cntr] = _vertex3ui(x, y, z);
            cntr++;
        }
    }

    this->fill_flat_normal();
    this->fill_smooth_normal();


    /*****************************************************************************//**
     *
     *
     *
     *****************************************************************************/


}
/*****************************************************************************//**
 *
 1.  The first argument specifies the texture target; setting this to GL_TEXTURE_2D means this operation will generate a texture on the currently bound texture object at the same target (so any textures bound to targets GL_TEXTURE_1D or GL_TEXTURE_3D will not be affected).
 2.   The second argument specifies the mipmap level for which we want to create a texture for if you want to set each mipmap level manually, but we'll leave it at the base level which is 0.
 3.   The third argument tells OpenGL in what kind of format we want to store the texture. Our image has only RGB values so we'll store the texture with RGB values as well.
 4.   The 4th and 5th argument sets the width and height of the resulting texture. We stored those earlier when loading the image so we'll use the corresponding variables.
 5.   The next argument should always be 0 (some legacy stuff).
 6.   The 7th and 8th argument specify the format and datatype of the source image. We loaded the image with RGB values and stored them as chars (bytes) so we'll pass in the corresponding values.
 7.   The last argument is the actual image data.

 *****************************************************************************/
