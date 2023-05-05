HEADERS += \
  apoyo_db.h \
  asiento.h \
  brazera.h \
  cabezera.h \
  chess_board.h \
  cilindro.h \
  cojin.h \
  colors.h \
  basic_object3d.h \
  cono.h \
  cube.h \
  cuello.h \
  descansa_brazo.h \
  esfera.h \
  espaldar.h \
  file_ply_stl.h \
  object3d.h \
  axis.h \
  pieza.h \
  ply_object.h \
  profil_object.h \
  reposa_cabeza.h \
  reposa_culo.h \
  reposa_espalda.h \
  silla.h \
  silla_base.h \
  stb_image.h \
  suspencion.h \
  suspencion_db.h \
  tetrahedron.h \
  glwidget.h \
  window.h

SOURCES += \
  apoyo_db.cpp \
  asiento.cpp \
  basic_object3d.cc \
  brazera.cpp \
  cabezera.cpp \
  chess_board.cpp \
  cilindro.cpp \
  cojin.cpp \
  cono.cpp \
  cube.cpp \
  cuello.cpp \
  descansa_brazo.cpp \
  esfera.cpp \
  espaldar.cpp \
  file_ply_stl.cc \
  object3d.cc \
  axis.cc \
  pieza.cpp \
  ply_object.cpp \
  profil_object.cpp \
  reposa_cabeza.cpp \
  reposa_culo.cpp \
  reposa_espalda.cpp \
  silla.cpp \
  silla_base.cpp \
  stb_image_implementation.cpp \
  suspencion.cpp \
  suspencion_db.cpp \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc

#INCLUDEPATH += D:\UGR\IG\GL

#LIBS += -lopengl32



CONFIG += c++11
QT += openglwidgets


#DEFINES+=LINUX
DEFINES+=WINDOWS

!linux {
TARGET= Programa

INCLUDEPATH += "D:\UGR\IG\GL"
LIBS += -lopengl32
}

linux {
TARGET= maplab

INCLUDEPATH += /home/dmartin/codigo/funciontecas/glew-2.1.0/include

LIBS += \
    -L/home/dmartin/codigo/funciontecas/glew-2.1.0/lib -lGLEW \
    -lGL
}
