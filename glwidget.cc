/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);

  rateAnimation1 = 1;
  rateAnimation1Tx = 0.25;
  rateAnimation1Ty = 0.15;
  rateAnimation2 = 0.01;
  rateAnimation3 = 1;
  material = 0;
  w = X_MAX;
  h = Y_MAX;


  a1_counter = 0;

  flagErgirEspaldar = false;
  flagRecostarEspaldar = true;
  flagSubirAsiento = false;
  flagBajarAsiento = false;
  flagRotacion1= false;

  flag_text = true;

  enable_animation = false;

  timer = new QTimer();
  timer->setInterval(0);
  timer->start();
  //timer->callOnTimeout(SLOT(idle_event(int)));
  connect(timer, SIGNAL(timeout()), this, SLOT(idle_event()));

  //chesboard = new chess_board(4, 4);
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:Object=OBJECT_TETRAHEDRON; Window->change_cBox(0);break;
  case Qt::Key_2:Object=OBJECT_CUBE;Window->change_cBox(1);break;
  case Qt::Key_3:Object=OBJECT_PLY; Window->change_cBox(2);break;
  case Qt::Key_4:Object=OBJECT_CONO; Window->change_cBox(3);break;
  case Qt::Key_5:Object=OBJECT_CILINDRO; Window->change_cBox(4);break;
  case Qt::Key_6:Object=OBJECT_ESFERA; Window->change_cBox(5);break;
  case Qt::Key_7:Object=OBJECT_MODEL; Window->change_cBox(6);break;
  case Qt::Key_8:Object=OBJECT_CHESSBOARD; Window->change_cBox(7); break; //Arreglar window

  case Qt::Key_J:
      light0 = !light0;
      Window->luz0(light0);
      break;

  case Qt::Key_K:
      light1 = !light1;
      Window->luz1(light1);
      break;

  case Qt::Key_M:
      material++;
      if(material > 2) material = 0;
      Window->change_cMatBox(material);
      cout << "Material: " << material << endl;
      break;

  case Qt::Key_F3:
      Draw_flat = !Draw_flat;
      Window->mode_flat(Draw_flat);
      break;

  case Qt::Key_F4:
      Draw_smooth = !Draw_smooth;
      Window->mode_smooth(Draw_flat);
      break;

  case Qt::Key_F5:
      Draw_texture = !Draw_texture;
      Window->mode_texture(Draw_texture, 0);
      break;

  case Qt::Key_F6:
      Draw_texture_flat = !Draw_texture_flat;
      Window->mode_texture(Draw_texture_flat, 1);
      break;

  case Qt::Key_F7:
      Draw_texture_smooth = !Draw_texture_smooth;
      Window->mode_texture(Draw_texture_smooth, 2);
      break;

  case Qt::Key_P:
      Draw_point=!Draw_point;
      Window->mode_point(Draw_point);
      break;


  case Qt::Key_L:
      Draw_line=!Draw_line;
      Window->mode_line(Draw_line);
      break;

  case Qt::Key_F:
      Draw_fill=!Draw_fill;
      Window->mode_fill(Draw_fill);
      break;

  case Qt::Key_C:
      Draw_chess=!Draw_chess;
      Window->mode_chess(Draw_chess);
      break;

  case Qt::Key_Q:
      angle = silla.Asiento.angleStepAnimationR;
      //If else para que el angulo nunca se pase de 45. En caso tal es reseteado a 45
      if((angle += rateAnimation1) <= 45){
          silla.Asiento.angleStepAnimationR += rateAnimation1;
          silla.Asiento.angleStepAnimationTx += rateAnimation1*0.01;
          //silla.Asiento.angleStepAnimationTy += rateAnimation1*0.001;
          cout << silla.Asiento.angleStepAnimationR <<endl;
          break;
      }
      else{
          silla.Asiento.angleStepAnimationR = 45;
          cout << silla.Asiento.angleStepAnimationR <<endl;
          break;
      }

  case Qt::Key_W:
      angle = silla.Asiento.angleStepAnimationR;
      //If else para que el angulo nunca pueda ser menor a 0. En caso tal es reseteado a  0
      if((angle -= rateAnimation1) >= 0){
          silla.Asiento.angleStepAnimationR -= rateAnimation1;
          silla.Asiento.angleStepAnimationTx -= rateAnimation1*0.01;
          //silla.Asiento.angleStepAnimationTy -= rateAnimation1*0.001;
          cout << silla.Asiento.angleStepAnimationR <<endl;
          break;
      }
      else{
          silla.Asiento.angleStepAnimationR = 0;
          cout << silla.Asiento.angleStepAnimationR <<endl;
          break;
      }


  case Qt::Key_E:
      rateAnimation1 += 1;
      rateAnimation1Tx += 0.0825; //33% de 0.25
      rateAnimation1Ty += 0.04;
      break;

  case Qt::Key_R:
      rateAnimation1 -= 1;
      rateAnimation1Tx -= 0.0825; //33% de 0.25
      rateAnimation1Ty -= 0.04;
      if(rateAnimation1 <= 0) rateAnimation1 = 1;
      break;

  case Qt::Key_S:
      //If else para poner limites a que tanto se puede escalar
      if(silla.angleStepAnimation < 0.5){
          silla.angleStepAnimation += rateAnimation2;
          cout << silla.angleStepAnimation << endl;
          break;
      }
      else{
          silla.angleStepAnimation = 0.5;
          break;
      }

  case Qt::Key_D:
      //If else para limites
      if(silla.angleStepAnimation > -0.5){
          silla.angleStepAnimation -= rateAnimation2;
          cout << silla.angleStepAnimation << endl;
          break;
      }
      else{
          silla.angleStepAnimation = -0.5;
          break;
      }


  case Qt::Key_T:
      rateAnimation2 += 0.05;
      break;

  case Qt::Key_Y:
      rateAnimation2 -= 0.05;
      if(rateAnimation2 <= 0) rateAnimation2 = 0.1;
      break;

  case Qt::Key_Z:
      silla.angleStepAnimationR += rateAnimation3;
      break;

  case Qt::Key_X:
      silla.angleStepAnimationR -= rateAnimation3;
      break;

  case Qt::Key_U:
      rateAnimation3 += 1;
      break;

  case Qt::Key_I:
      rateAnimation3 -= 1;
      if(rateAnimation3 <= 0) rateAnimation3 = 1;
      break;

  case Qt::Key_A:
      enable_animation = !enable_animation;
      break;


  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_PageUp:Observer_distance*=1.2;break;
  case Qt::Key_PageDown:Observer_distance/=1.2;break;
  }

  update();
}


void _gl_widget::set_mode_point(){
    Draw_point = !Draw_point;
    update();
}

void _gl_widget::set_mode_line(){
    Draw_line = !Draw_line;
    update();
}

void _gl_widget::set_mode_chess(){
    Draw_chess = !Draw_chess;
    update();
}

void _gl_widget::set_mode_fill(){
    Draw_fill = !Draw_fill;
    update();
}

void _gl_widget::set_mode_sweep(){
    Draw_sweep = !Draw_sweep;
    update();
}

void _gl_widget::set_mode_flat(){
    Draw_flat = !Draw_flat;
    update();
}

void _gl_widget::set_mode_smooth(){
    Draw_smooth = !Draw_smooth;
    update();
}

void _gl_widget::set_luz0(){
    light0 = !light0;
    update();
}

void _gl_widget::set_luz1(){
    light1 = !light1;
    update();
}

void _gl_widget::set_textura(int swtch){
    switch(swtch){
    case 0:
        Draw_texture = !Draw_texture;
        update();

    case 1:
        Draw_texture_flat = !Draw_texture_flat;
        update();

    case 2:
        Draw_texture_smooth = !Draw_texture_smooth;
        update();
    }

    update();
}

void _gl_widget::set_object(int key){
    switch(key){
    case 0:
        Object = OBJECT_TETRAHEDRON;update();break;
    case 1:
        Object=OBJECT_CUBE;update();break;
    case 2:
        Object=OBJECT_PLY;update(); break;
    case 3:
        Object=OBJECT_CONO; update();break;
    case 4:
        Object=OBJECT_CILINDRO; update(); break;
    case 5:
        Object=OBJECT_ESFERA; update(); break;
    case 6:
        Object=OBJECT_MODEL; update(); break;
    case 7:
        Object=_gl_widget_ne::OBJECT_CHESSBOARD; update(); break;
    }
}

void _gl_widget::set_mat(int key){
    switch(key){
    case 0:
        material = 0;update();break;
    case 1:
        material = 1;update();break;
    case 2:
        material = 2;update(); break;
    }
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

//  int height = this->Window->height();
//  int width = this->Window->width();

//  float aspectRatio = (float)height / (float)width;

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)

  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  //color
  GLfloat material0_amb_diff[] = {1.0, 0.84, 0.0, 1.0};
  GLfloat material1_amb_diff[] = {0.45, 0.6, 1.0, 1.0};
  GLfloat material2_amb_diff[] = {1, 0.5, 0, 1.0};

//  GLfloat material0_diff[] = {1.0, 1.0, 1.0, 1.0};
//  GLfloat material1_diff[] = {0.6, 0.6, 0.6, 1.0};
//  GLfloat material2_diff[] = {1.0, 1.0, 1.0, 1.0};

  //Refleccion
  GLfloat material0_esp[] = {1, 1, 1, 1.0};
  GLfloat material1_esp[] = {0.2, 0.2, 0.2, 1.0};
  GLfloat material2_esp[] = {0, 0, 0, 1.0};

  GLfloat shininess0[] = {128};
  GLfloat shininess1[] = {64};
  GLfloat shininess2[] = {0};

  /* ========================================= Implementacion de la luz 1 ============================================================== */

  if(light0||light1 == false) glDisable(GL_LIGHTING);
  else glEnable(GL_LIGHTING);

  if(light0){

      //parametro w = 0 para luz direccional (infinitas fuentes de luz)
      GLfloat light_position[] = {0.0, 0.0, 3.0, 0.0};
      GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
      GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
      GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};

      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);

      glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
      glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
      glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
      glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  }
  else{
      glDisable(GL_LIGHT0);
  }

   /* ========================================= Implementacion de la luz 2 ============================================================== */
  if(light1){

      GLfloat light_position[] = {3.0, 3.0, 3.0, 1.0};
      GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
      GLfloat light_diffuse[] = {0.5, 0.8, 1.0, 1.0};
      GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};

      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT1);

      glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
      glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
      glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
      glLightfv(GL_LIGHT1, GL_POSITION, light_position);
  }
  else{
      glDisable(GL_LIGHT1);
  }

   /* ========================================= Implementacion de los distintos materiales ====================================================== */

  switch(material){
    case 0:
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material0_amb_diff);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess0);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material0_esp);
      break;

    case 1:
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material1_amb_diff);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess1);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material1_esp);
      break;

    case 2:
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material2_amb_diff);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess2);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material2_esp);
      break;

  }

  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_PLY:PLY.draw_point(); cout << "trying to draw PLY points: " << PLY.Vertices.size() << endl;break;
    case OBJECT_CILINDRO:Cilindro.draw_point();break;
    case OBJECT_CONO:Cono.draw_point();break;
    case OBJECT_ESFERA:Esfera.draw_point();break;
    case OBJECT_MODEL:silla.draw(0, textureID);break;
    case OBJECT_CHESSBOARD:chesboard.draw_point();break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(3);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_PLY:PLY.draw_line();break;
    case OBJECT_CILINDRO:Cilindro.draw_line();break;
    case OBJECT_CONO:Cono.draw_line();break;
    case OBJECT_ESFERA:Esfera.draw_line();break;
    case OBJECT_MODEL:silla.draw(1, textureID);break;
    case OBJECT_CHESSBOARD:chesboard.draw_line();break;
    default:break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
    case OBJECT_CUBE:Cube.draw_fill();break;
    case OBJECT_PLY:PLY.draw_fill();break;
    case OBJECT_CILINDRO:Cilindro.draw_fill();break;
    case OBJECT_CONO:Cono.draw_fill();break;
    case OBJECT_ESFERA:Esfera.draw_fill();break;
    case OBJECT_MODEL:silla.draw(2, textureID);break;
    case OBJECT_CHESSBOARD:chesboard.draw_fill();break;
    default:break;
    }
  }

  if (Draw_chess){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_PLY:PLY.draw_chess();break;
    case OBJECT_CILINDRO:Cilindro.draw_chess();break;
    case OBJECT_CONO:Cono.draw_chess();break;
    case OBJECT_ESFERA:Esfera.draw_chess();break;
    case OBJECT_MODEL:silla.draw(3, textureID);break;
    case OBJECT_CHESSBOARD:chesboard.draw_chess();break;
    default:break;
    }
  }

  if (Draw_flat){
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_flat();break;
    case OBJECT_CUBE:Cube.draw_flat();break;
    case OBJECT_PLY:PLY.draw_flat();break;
    case OBJECT_CILINDRO:Cilindro.draw_flat();break;
    case OBJECT_CONO:Cono.draw_flat();break;
    case OBJECT_ESFERA:Esfera.draw_flat();break;
    case OBJECT_MODEL:silla.draw(4, textureID);break;
    case OBJECT_CHESSBOARD:chesboard.draw_flat();break;
    default:break;
    }
  }

  if (Draw_smooth){
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_smooth();break;
    case OBJECT_CUBE:Cube.draw_smooth();break;
    case OBJECT_PLY:PLY.draw_smooth();break;
    case OBJECT_CILINDRO:Cilindro.draw_smooth();break;
    case OBJECT_CONO:Cono.draw_smooth();break;
    case OBJECT_ESFERA:Esfera.draw_smooth();break;
    case OBJECT_MODEL:silla.draw(5, textureID);break;
    case OBJECT_CHESSBOARD:chesboard.draw_smooth();break;
    default:break;
    }
  }

  if (Draw_texture){

      if(flag_text){
          makeCurrent();
          unsigned int texture;
          glGenTextures(1, &texture); //Una textura y le pasamos el int como id
          this->textureID = texture;
          glBindTexture(GL_TEXTURE_2D, texture);  //Enlazar textura para que los comandos se apliquen sobre esta
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
          glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

          int width, height, nrChannels;
          unsigned char* data = stbi_load("D:/GR_universidad/IG/skeleton/skeleton/tablero_cordoba_1.jpg", &width, &height, &nrChannels, 0);
          if(data){
              cout<<"Textura cargada exitosamente " << texture << ", " << width << ", " << height <<endl;
              glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);   //mandar datos a la gpu
          }
          else{
              cout << "Fallo al cargar la textura \n";
          }
          stbi_image_free(data);
          flag_text = false;
      }



    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_text(textureID);break;
    case OBJECT_CUBE:Cube.draw_text(textureID);break;
    case OBJECT_PLY:PLY.draw_text(textureID);break;
    case OBJECT_CILINDRO:Cilindro.draw_text(textureID);break;
    case OBJECT_CONO:Cono.draw_text(textureID);break;
    case OBJECT_ESFERA:Esfera.draw_text(textureID);break;
    case OBJECT_MODEL:silla.draw(5, textureID);break;
    case OBJECT_CHESSBOARD:chesboard.draw_text(textureID);break;
    default:break;
    }
  }

  if (Draw_texture_flat){

      if(flag_text){
          makeCurrent();
          unsigned int texture;
          glGenTextures(1, &texture); //Una textura y le pasamos el int como id
          this->textureID = texture;
          glBindTexture(GL_TEXTURE_2D, texture);  //Enlazar textura para que los comandos se apliquen sobre esta
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
          glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

          int width, height, nrChannels;
          unsigned char* data = stbi_load("D:/GR_universidad/IG/skeleton/skeleton/tablero_cordoba_1.jpg", &width, &height, &nrChannels, 0);
          if(data){
              cout<<"Textura cargada exitosamente " << texture << ", " << width << ", " << height <<endl;
              glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);   //mandar datos a la gpu
          }
          else{
              cout << "Fallo al cargar la textura \n";
          }
          stbi_image_free(data);
          flag_text = false;
      }



    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_text_flat(textureID);break;
    case OBJECT_CUBE:Cube.draw_text_flat(textureID);break;
    case OBJECT_PLY:PLY.draw_text_flat(textureID);break;
    case OBJECT_CILINDRO:Cilindro.draw_text_flat(textureID);break;
    case OBJECT_CONO:Cono.draw_text_flat(textureID);break;
    case OBJECT_ESFERA:Esfera.draw_text_flat(textureID);break;
    case OBJECT_MODEL:silla.draw(6, textureID);break;
    case OBJECT_CHESSBOARD:chesboard.draw_text_flat(textureID);break;
    default:break;
    }
  }

  if (Draw_texture_smooth){

      if(flag_text){
          makeCurrent();
          unsigned int texture;
          glGenTextures(1, &texture); //Una textura y le pasamos el int como id
          this->textureID = texture;
          glBindTexture(GL_TEXTURE_2D, texture);  //Enlazar textura para que los comandos se apliquen sobre esta
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
          glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

          int width, height, nrChannels;

          //Camino relativo
          //unsigned char* data = stbi_load("../../skeleton/build-esqueleto_qt-Desktop_Qt_6_4_0_MinGW_64_bit-Debug/tablero_cordoba_1.jpg", &width, &height, &nrChannels, 0);

          unsigned char* data = stbi_load("D:/GR_universidad/IG/skeleton/skeleton/tablero_cordoba_1.jpg", &width, &height, &nrChannels, 0);
          if(data){
              cout<<"Textura cargada exitosamente " << texture << ", " << width << ", " << height <<endl;
              glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);   //mandar datos a la gpu
          }
          else{
              cout << "Fallo al cargar la textura \n";
          }
          stbi_image_free(data);
          flag_text = false;
      }



    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_text_smooth(textureID);break;
    case OBJECT_CUBE:Cube.draw_text_smooth(textureID);break;
    case OBJECT_PLY:PLY.draw_text_smooth(textureID);break;
    case OBJECT_CILINDRO:Cilindro.draw_text_smooth(textureID);break;
    case OBJECT_CONO:Cono.draw_text_smooth(textureID);break;
    case OBJECT_ESFERA:Esfera.draw_text_smooth(textureID);break;
    case OBJECT_MODEL:silla.draw(7, textureID);break;
    case OBJECT_CHESSBOARD:chesboard.draw_text_smooth(textureID);break;
    default:break;
    }
  }
}

void _gl_widget::idle_event(){
    //cout << "idle" << endl;

    if(enable_animation){
        /** Codigo para automatizar animacion el espaldar**/

        //Primer flag para controlar recostar/ergir espaldar
        if(flagRecostarEspaldar){
            //Reclinar
            if(silla.Asiento.angleStepAnimationR < 45){
                silla.Asiento.angleStepAnimationR += rateAnimation1;
                silla.Asiento.angleStepAnimationTx +=  rateAnimation1*0.01;
                update();
            }
            //Al terminar mandar a bajar el asiento
            else{
              flagRecostarEspaldar = false;
              flagBajarAsiento = true;
            }
        }
        if(flagErgirEspaldar){
            //Ergir
            if(silla.Asiento.angleStepAnimationR > 0){
                silla.Asiento.angleStepAnimationR -= rateAnimation1;
                silla.Asiento.angleStepAnimationTx -=  rateAnimation1*0.01;
                update();
            }
            //Al terminar mandar a que el loop empiece otra vez al recostar el epaldar
            else{
                flagErgirEspaldar = false;
                flagRecostarEspaldar = true;
            }
        }

        //Bajar asiento
        if(flagBajarAsiento){
            if(silla.angleStepAnimation > -0.5){
                silla.angleStepAnimation -= rateAnimation2;
                //cout << silla.angleStepAnimation << endl;
                update();
            }
            //Al terminar mandar a rotar 180
            else{
                flagBajarAsiento = false;
                flagRotacion1 = true;
            }
        }

        //subir asiento
        if(flagSubirAsiento){
            if(silla.angleStepAnimation < 0.5){
                silla.angleStepAnimation += rateAnimation2;
                update();
            }
            //Al terminar mandar a ergir el asiento
            else{
                flagSubirAsiento = false;
                flagErgirEspaldar = true;
            }
        }

        //Rotar 180
        if(flagRotacion1){
            if(silla.angleStepAnimationR <= 360){
                silla.angleStepAnimationR += rateAnimation3;
                update();
            }
            //Al terminar mandar a subir el asiento y poner los grados en 0 para proxima iteracion
            else{
                flagRotacion1 = false;
                //flagRotacion2 = true;
                flagSubirAsiento = true;
                silla.angleStepAnimationR = 0;
            }
        }
    }
}


/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
  w = (float)Width1;
  h = (float)Height1;
  this->aspectRatio = (float)Height1 / (float)Width1;
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;
  Draw_chess=false;
}


