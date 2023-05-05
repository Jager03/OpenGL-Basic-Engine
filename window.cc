/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QFrame>

#include "window.h"
#include "glwidget.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_window::_window()
{

  QSizePolicy Q(QSizePolicy::Expanding,QSizePolicy::Expanding);

  QWidget *Central_widget = new QWidget(this);

  QFrame *Framed_widget= new QFrame(Central_widget);
  Framed_widget->setSizePolicy(Q);
  Framed_widget->setFrameStyle(QFrame::Panel);
  Framed_widget->setLineWidth(3);


  GL_widget = new _gl_widget(this);
  GL_widget->setSizePolicy(Q);

  QHBoxLayout *Horizontal_frame = new QHBoxLayout();
  Horizontal_frame->setContentsMargins(1,1,1,1);

  Horizontal_frame->addWidget(GL_widget);
  Framed_widget->setLayout(Horizontal_frame);

  QWidget *Widget_tab1 = new QWidget;
  QWidget *Widget_tab2 = new QWidget;

  QWidget* widget_grid = new QWidget;
  QWidget* widget_grid_luces = new QWidget;

  ComboBox = new QComboBox();
  connect(ComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboChanged(int)));
  QStringList elementos = {"triangulo", "cuadrado", "ply", "cono", "cilindro", "esfera", "modelo", "tablero"};
  ComboBox->insertItems(0, elementos);


  ComboBoxMat = new QComboBox();
  connect(ComboBoxMat, SIGNAL(currentIndexChanged(int)), this, SLOT(comboMatChanged(int)));
  QStringList materiales = {"1", "2", "3"};
  ComboBoxMat->insertItems(0, materiales);


  QGridLayout* GridLayout = new QGridLayout;
  QGridLayout* GridLayoutLuces = new QGridLayout;

  QLabel* Label1 = new QLabel("Puntos");
  QLabel* Label2 = new QLabel("Lineas");
  QLabel* Label3 = new QLabel("Ajedrez");
  QLabel* Label4 = new QLabel("Relleno");
  QLabel* Label5 = new QLabel("Seleccionar Objeto:");
  QLabel* Label6 = new QLabel("Iluminacion Flat");
  QLabel* Label7 = new QLabel("\nLuces:");
  QLabel* Label8 = new QLabel("Luz 1");
  QLabel* Label9 = new QLabel("Luz 2");
  QLabel* Label10 = new QLabel("\nMateriales:");
  QLabel* Label11 = new QLabel("Iluminacion Suave");
  QLabel* Label12 = new QLabel("Textura");
  QLabel* Label13 = new QLabel("Textura Iluminacion Flat");
  QLabel* Label14 = new QLabel("Textura Iluminacion Smooth");

  Checkbox_puntos = new QCheckBox();
  connect(Checkbox_puntos, SIGNAL(stateChanged(int)), this, SLOT(mode_point_slot(int)));

  Checkbox_lineas = new QCheckBox();
  connect(Checkbox_lineas, SIGNAL(stateChanged(int)), this, SLOT(mode_line_slot(int)));
  Checkbox_lineas->setChecked(true);

  Checkbox_ajedrez = new QCheckBox();
  connect(Checkbox_ajedrez, SIGNAL(stateChanged(int)), this, SLOT(mode_chess_slot(int)));

  Checkbox_barrido = new QCheckBox();
  connect(Checkbox_barrido, SIGNAL(stateChanged(int)), this, SLOT(mode_sweep_slot(int)));

  Checkbox_relleno = new QCheckBox();
  connect(Checkbox_relleno, SIGNAL(stateChanged(int)), this, SLOT(mode_fill_slot(int)));

  Checkbox_flat = new QCheckBox();
  connect(Checkbox_flat, SIGNAL(stateChanged(int)), this, SLOT(mode_flat_slot(int)));

  Checkbox_smooth = new QCheckBox();
  connect(Checkbox_smooth, SIGNAL(stateChanged(int)), this, SLOT(mode_smooth_slot(int)));

  Checkbox_luz0 = new QCheckBox();
  connect(Checkbox_luz0, SIGNAL(stateChanged(int)), this, SLOT(luz0_slot(int)));

  Checkbox_luz1 = new QCheckBox();
  connect(Checkbox_luz1, SIGNAL(stateChanged(int)), this, SLOT(luz1_slot(int)));

  CBoxText = new QCheckBox();
  connect(CBoxText, SIGNAL(stateChanged(int)), this, SLOT(TextureChanged(int)));

  CBoxTextF = new QCheckBox();
  connect(CBoxTextF, SIGNAL(stateChanged(int)), this, SLOT(TextureFlatChanged(int)));

  CBoxTextS = new QCheckBox();
  connect(CBoxTextS, SIGNAL(stateChanged(int)), this, SLOT(TextureSmoothChanged(int)));


  GridLayout->addWidget(Label1, 0, 0, Qt::AlignRight);
  GridLayout->addWidget(Checkbox_puntos, 0, 1, Qt::AlignLeft);
  GridLayout->addWidget(Label2, 1, 0, Qt::AlignRight);
  GridLayout->addWidget(Checkbox_lineas, 1, 1, Qt::AlignLeft);
  GridLayout->addWidget(Label3, 2, 0, Qt::AlignRight);
  GridLayout->addWidget(Checkbox_ajedrez, 2, 1, Qt::AlignLeft);
  GridLayout->addWidget(Label4, 3, 0, Qt::AlignRight);
  GridLayout->addWidget(Checkbox_relleno, 3, 1, Qt::AlignLeft);
  GridLayout->addWidget(Label6, 4, 0, Qt::AlignRight);
  GridLayout->addWidget(Checkbox_flat, 4, 1, Qt::AlignLeft);
  GridLayout->addWidget(Label11, 5, 0, Qt::AlignRight);
  GridLayout->addWidget(Checkbox_smooth, 5, 1, Qt::AlignLeft);
  GridLayout->addWidget(Label12, 6, 0, Qt::AlignRight);
  GridLayout->addWidget(CBoxText, 6, 1, Qt::AlignLeft);
  GridLayout->addWidget(Label13, 7, 0, Qt::AlignRight);
  GridLayout->addWidget(CBoxTextF, 7, 1, Qt::AlignLeft);
  GridLayout->addWidget(Label14, 8, 0, Qt::AlignRight);
  GridLayout->addWidget(CBoxTextS, 8, 1, Qt::AlignLeft);

  widget_grid->setLayout(GridLayout);

  /*===== Grid de luces ========*/
  GridLayoutLuces->addWidget(Label8, 0, 0, Qt::AlignRight);
  GridLayoutLuces->addWidget(Checkbox_luz0, 0, 1, Qt::AlignLeft);
  GridLayoutLuces->addWidget(Label9, 1, 0, Qt::AlignRight);
  GridLayoutLuces->addWidget(Checkbox_luz1, 1, 1, Qt::AlignLeft);

  widget_grid_luces->setLayout(GridLayoutLuces);


  QVBoxLayout* VBox_tab1 = new QVBoxLayout();
  VBox_tab1->addWidget(widget_grid);
  VBox_tab1->addWidget(Label5);
  VBox_tab1->addWidget(ComboBox);
  VBox_tab1->addWidget(Label7);
  VBox_tab1->addWidget(widget_grid_luces);
  VBox_tab1->addWidget(Label10);
  VBox_tab1->addWidget(ComboBoxMat);
  VBox_tab1->addStretch();

  Widget_tab1->setLayout(VBox_tab1);


  QTabWidget *TabBar1 = new QTabWidget();
  TabBar1->setMaximumWidth(300);
  TabBar1->addTab(Widget_tab1, "Mode");
  TabBar1->addTab(Widget_tab2, "Objects");

  QHBoxLayout *Horizontal_main = new QHBoxLayout(Central_widget);

  Horizontal_main->addWidget(Framed_widget);
  Horizontal_main->addWidget(TabBar1);

  Central_widget->setLayout(Horizontal_main);   //En el horizontal_main esta e
  setCentralWidget(Central_widget);

  // actions for file menu
  QAction *Exit = new QAction(QIcon("./icons/exit.png"), tr("&Exit..."), this);
  Exit->setShortcut(tr("Ctrl+Q"));
  Exit->setToolTip(tr("Exit the application"));
  connect(Exit, SIGNAL(triggered()), this, SLOT(close()));

  // menus
  QMenu *File_menu=menuBar()->addMenu(tr("&File"));
  File_menu->addAction(Exit);
  File_menu->setAttribute(Qt::WA_AlwaysShowToolTips);

  setWindowTitle(tr("Práctica 1"));

  resize(800,800);
}

void _window::mode_point_slot(int State){
    GL_widget->set_mode_point();
}

void _window::mode_point(bool Value){
    Checkbox_puntos->blockSignals(true);    //Para que cambie el estado pero no provoque una señal
    Checkbox_puntos->setChecked(Value);
    Checkbox_puntos->blockSignals(false);
}

void _window::mode_line_slot(int State){
    GL_widget->set_mode_line();
}

void _window::mode_line(bool Value){
    Checkbox_lineas->blockSignals(true);    //Para que cambie el estado pero no provoque una señal
    Checkbox_lineas->setChecked(Value);
    Checkbox_lineas->blockSignals(false);
}

void _window::mode_chess_slot(int State){
    GL_widget->set_mode_chess();
}

void _window::mode_chess(bool Value){
    Checkbox_ajedrez->blockSignals(true);
    Checkbox_ajedrez->setChecked(Value);
    Checkbox_ajedrez->blockSignals(false);
}

void _window::mode_fill_slot(int State){
    GL_widget->set_mode_fill();
}

void _window::mode_fill(bool Value){
    Checkbox_relleno->blockSignals(true);
    Checkbox_relleno->setChecked(Value);
    Checkbox_relleno->blockSignals(false);
}

void _window::mode_sweep_slot(int State){
    GL_widget->set_mode_sweep();
}

void _window::mode_flat_slot(int State){
    GL_widget->set_mode_flat();
}

void _window::mode_flat(bool Value){
    Checkbox_flat->blockSignals(true);
    Checkbox_flat->setChecked(Value);
    Checkbox_flat->blockSignals(false);
}

void _window::mode_smooth_slot(int State){
    GL_widget->set_mode_smooth();
}

void _window::mode_smooth(bool Value){
    Checkbox_smooth->blockSignals(true);
    Checkbox_smooth->setChecked(Value);
    Checkbox_smooth->blockSignals(false);
}


void _window::comboChanged(int State){
    GL_widget->set_object(ComboBox->currentIndex());
}

void _window::change_cBox(int index){
    ComboBox->setCurrentIndex(index);
}

void _window::luz0_slot(int State){
    GL_widget->set_luz0();
}

void _window::luz1_slot(int State){
    GL_widget->set_luz1();
}

void _window::luz0(bool Value){
    Checkbox_luz0->blockSignals(true);
    Checkbox_luz0->setChecked(Value);
    Checkbox_luz0->blockSignals(false);
}

void _window::luz1(bool Value){
    Checkbox_luz1->blockSignals(true);
    Checkbox_luz1->setChecked(Value);
    Checkbox_luz1->blockSignals(false);
}

void _window::comboMatChanged(int State){
    GL_widget->set_mat(ComboBoxMat->currentIndex());
}

void _window::change_cMatBox(int index){
    ComboBoxMat->setCurrentIndex(index);
}

void _window::TextureChanged(int State){
    GL_widget->set_textura(0);
}

void _window::TextureFlatChanged(int State){
    GL_widget->set_textura(1);
}

void _window::TextureSmoothChanged(int State){
    GL_widget->set_textura(2);
}

void _window::mode_texture(bool Value, int key){
    switch(key){
    case 0:
        CBoxText->blockSignals(true);
        CBoxText->setChecked(Value);
        CBoxText->blockSignals(false);
        break;

    case 1:
        CBoxTextF->blockSignals(true);
        CBoxTextF->setChecked(Value);
        CBoxTextF->blockSignals(false);
        break;

    case 2:
        CBoxTextS->blockSignals(true);
        CBoxTextS->setChecked(Value);
        CBoxTextS->blockSignals(false);
        break;
    }
}


