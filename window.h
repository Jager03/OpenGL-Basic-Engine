/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QFileDialog>
#include <QDialog>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QGuiApplication>
#include <QTabBar>
#include <QTabWidget>
#include <QLabel>
#include <QCheckBox>
#include <QGridLayout>
#include <QComboBox>

class _gl_widget;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _window : public QMainWindow
{
    Q_OBJECT    //Esta clase va a manejar eventos

public:
    _window();
    void mode_point(bool Value);
    void mode_line(bool Value);
    void mode_fill(bool Value);
    void mode_chess(bool Value);
    void mode_sweep(bool Value);
    void mode_flat(bool Value);
    void mode_smooth(bool Value);
    void luz0(bool Value);
    void luz1(bool Value);
    void change_cBox(int index);
    void change_cMatBox(int index);
    void mode_texture(bool Value, int key);

public slots:           //Slots es una funcion: interrupt_handler
    void mode_point_slot(int State);
    void mode_line_slot(int State);
    void mode_chess_slot(int State);
    void mode_sweep_slot(int State);
    void mode_fill_slot(int State);
    void mode_flat_slot(int State);
    void mode_smooth_slot(int State);
    void luz0_slot(int State);
    void luz1_slot(int State);
    void comboChanged(int State);
    void comboMatChanged(int State);
    void TextureChanged(int State);
    void TextureFlatChanged(int State);
    void TextureSmoothChanged(int State);

private:
  _gl_widget *GL_widget;
  QCheckBox* Checkbox_puntos = nullptr;
  QCheckBox* Checkbox_lineas = nullptr;
  QCheckBox* Checkbox_ajedrez = nullptr;
  QCheckBox* Checkbox_barrido = nullptr;
  QCheckBox* Checkbox_relleno = nullptr;
  QCheckBox* Checkbox_flat = nullptr;
  QCheckBox* Checkbox_smooth= nullptr;
  QCheckBox* Checkbox_luz0 = nullptr;
  QCheckBox* Checkbox_luz1= nullptr;
  QComboBox* ComboBox = nullptr;
  QComboBox* ComboBoxMat = nullptr;
  QCheckBox* CBoxText = nullptr;
  QCheckBox* CBoxTextF = nullptr;
  QCheckBox* CBoxTextS = nullptr;
};

#endif
