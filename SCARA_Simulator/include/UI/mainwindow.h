#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt Libraries
#include <QMainWindow>
#include <QGraphicsScene>
#include <QtMath>
// C++ libraries
#include <iostream>
// User Defined Libraries
#include <./BackEnd/SCARA.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void DrawSCARA(int);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Scara scara;

};
#endif // MAINWINDOW_H
