#include "./UI/mainwindow.h"
#include "./UI/ui_mainwindow.h"

/*
//
//
#################################################################################################
#										STARTUP FUNCTIONS										#
#################################################################################################
//
//
*/

void MainWindow::StartUpUI()
{
	Connections();
	PrepareDials();
	PrepareSceneForGraphics();
	PrepareInfoBoxes();
	InitValues();
	DrawStartUpSCARA();
	emit showMaximized();
}

void MainWindow::Connections()
{
	connect(ui->q1, SIGNAL(valueChanged(int)), this, SLOT(UpdateSCARAGraphics(int)));
	connect(ui->q2, SIGNAL(valueChanged(int)), this, SLOT(UpdateSCARAGraphics(int)));
	connect(ui->l1, SIGNAL(valueChanged(double)), this, SLOT(UpdateSCARAGraphics(double)));
	connect(ui->l2, SIGNAL(valueChanged(double)), this, SLOT(UpdateSCARAGraphics(double)));
	connect(ui->q1Max, SIGNAL(valueChanged(double)), this, SLOT(UpdateDialsForChangeInJointLimits(double)));
	connect(ui->q1Min, SIGNAL(valueChanged(double)), this, SLOT(UpdateDialsForChangeInJointLimits(double)));
	connect(ui->q2Max, SIGNAL(valueChanged(double)), this, SLOT(UpdateDialsForChangeInJointLimits(double)));
	connect(ui->q2Min, SIGNAL(valueChanged(double)), this, SLOT(UpdateDialsForChangeInJointLimits(double)));
	connect(ui->showWorkspaceButton, SIGNAL(pressed(void)), this, SLOT(DisplayWorkspaceInfo(void)));

}

void MainWindow::InitValues(void)
{
	ui->q1Max->setValue(90);
	ui->q1Min->setValue(-90);
	ui->q2Max->setValue(60);
	ui->q2Min->setValue(-60);
	ui->l1->setValue(200);
	ui->l2->setValue(150);
	ui->q1->setValue(40);
	ui->q2->setValue(30);
}

void MainWindow::PrepareInfoBoxes()
{
	ui->q1Display->setReadOnly(true);
	ui->q2Display->setReadOnly(true);
	ui->xDisplay->setReadOnly(true);
	ui->yDisplay->setReadOnly(true);
	ui->helpPanel->hide(); // for now!!
}

void MainWindow::DrawStartUpSCARA()
{
	UpdateSCARAGraphics(27102014);
}