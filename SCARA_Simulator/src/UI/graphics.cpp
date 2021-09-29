#include "./UI/mainwindow.h"
#include "./UI/ui_mainwindow.h"

/*
//
//
#################################################################################################
#										GRAPHICS FUNCTIONS										#
#################################################################################################
//
//
*/


void MainWindow::PrepareDials()
{
	ui->q1->setWrapping(false);
	ui->q2->setWrapping(false);
}

void MainWindow::PrepareSceneForGraphics()
{
	scene = new QGraphicsScene(this);
	ui->viewer->setScene(scene);
}


void MainWindow::UpdateSCARAGraphics(int junk)
{
    scara.SetLength(ui->l1->value(), ui->l2->value());
    scara.SetCurrentAngles(ui->q1->value(), ui->q2->value());
    scara.SetJointLimits(ui->q1Max->value(), ui->q1Min->value(), ui->q2Max->value(), ui->q2Min->value());
    scara.CalculateFK();
    scaraUI.DrawSCARA(scara, scene);
    UpdateCurrentInfoDisplay(scara);
}

void MainWindow::UpdateSCARAGraphics(double junk)
{
    int _junk = 1;
    UpdateSCARAGraphics(_junk);
}

void MainWindow::UpdateCurrentInfoDisplay(SCARA scara)
{
    ui->xDisplay->setValue(scara.x2);
    ui->yDisplay->setValue(scara.y2);
    ui->q1Display->setValue(ui->q1->value());
    ui->q2Display->setValue(ui->q2->value());
}

void MainWindow::UpdateDialsForChangeInJointLimits(double junk)
{
    ui->q1->setMaximum(ui->q1Max->value());
    ui->q1->setMinimum(ui->q1Min->value());
    ui->q2->setMaximum(ui->q2Max->value());
    ui->q2->setMinimum(ui->q2Min->value());
}

void MainWindow::DisplayWorkspaceInfo(void)
{
    scara.CalculateWorkspace();
    scene->clear();
    scaraUI.GetWorspacePoints(scara, scene);
}