/**
*	\class		MainWindow
*	\brief		Main Window of the GUI
*	\author		Soumik SARKAR
*	\version	SCARA-Simulator_v1
*	\date		09/09/2021
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt Libraries
#include <QMainWindow>
// User Defined Libraries
#include <./BackEnd/SCARA.h>
#include <./UI/ScaraUI.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void StartUpUI(void);
    void Connections(void);
    void PrepareDials(void);
    void PrepareSceneForGraphics(void);
    void InitValues(void);
    void PrepareInfoBoxes(void);
    void UpdateCurrentInfoDisplay(SCARA);
    void DrawStartUpSCARA(void);

public slots:
    void UpdateSCARAGraphics(int);
    void UpdateSCARAGraphics(double);
    void UpdateDialsForChangeInJointLimits(double);
    void DisplayWorkspaceInfo(void);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    SCARA scara;
    SCARA_UI scaraUI;

};
#endif // MAINWINDOW_H
