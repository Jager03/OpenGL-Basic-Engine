/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "ply_object.h"
#include "profil_object.h"
#include "cono.h"
#include "cilindro.h"
#include "esfera.h"
#include "silla.h"
#include "chess_board.h"
#include <QTimer>

namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=1;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE, OBJECT_PLY, OBJECT_CILINDRO, OBJECT_CONO, OBJECT_ESFERA, OBJECT_MODEL, OBJECT_CHESSBOARD} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();

  void set_mode_point();
  void set_mode_line();
  void set_mode_chess();
  void set_mode_sweep();
  void set_mode_fill();
  void set_mode_flat();
  void set_mode_smooth();
  void set_luz0();
  void set_luz1();
  void set_object(int key);
  void set_mat(int key);
  void set_textura(int swtch);

public slots:
  void idle_event();


protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;


private:
  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;
  _cube Cube;
  _ply_object PLY;
  profil_object PO;
  cono Cono;
  cilindro Cilindro;
  esfera Esfera;
  Silla silla;
  chess_board chesboard = chess_board(4);
  QTimer* timer = nullptr;

  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;
  bool Draw_sweep;
  bool Draw_flat;
  bool Draw_smooth;
  bool Draw_texture;
  bool Draw_texture_flat;
  bool Draw_texture_smooth;

  bool light0;
  bool light1;
  bool enable_animation;
  bool flagRecostarEspaldar;
  bool flagSubirAsiento;
  bool flagRotacion1;
  bool flagErgirEspaldar;
  bool flagBajarAsiento;
  bool flag_text;
  int material;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;

  double rateAnimation1;
  double rateAnimation1Tx;
  double rateAnimation1Ty;
  double rateAnimation2;
  double rateAnimation3;

  int angleStepAnimation1;
  int angleStepAnimation2;
  int angleStepAnimation3;

  int a1_counter;
  int textureID;
  int angle;

  float aspectRatio ,h, w;

};

#endif
