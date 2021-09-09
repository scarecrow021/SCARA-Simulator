#include "./UI/mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->viewer->setScene(scene);

    connect(ui->q1, SIGNAL(valueChanged(int)), this, SLOT(UpdateSCARAGraphics(int)));
    connect(ui->q2, SIGNAL(valueChanged(int)), this, SLOT(UpdateSCARAGraphics(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateSCARAGraphics(int junk)
{
    scara.SetLength(100, 50);
    scara.SetCurrentAngles(ui->q1->value(), ui->q2->value());
    scara.CalculateFK();
    scaraUI.DrawSCARA(scara, scene);
}

