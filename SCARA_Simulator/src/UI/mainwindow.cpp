#include "./UI/mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->viewer->setScene(scene);

    connect(ui->q1,SIGNAL(valueChanged(int)), this, SLOT(DrawSCARA(int)));
    connect(ui->q2,SIGNAL(valueChanged(int)), this, SLOT(DrawSCARA(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DrawSCARA(int junk)
{
    
    
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;

    QPen redPen(Qt::red);
    QPen blackPen(Qt::black);

    redPen.setWidth(5);
    blackPen.setWidth(5);

    double l1 = 100;
    double l2 = 100;


    double x0 = 0;
    double y0 = 0;

    double x1,x2,y1,y2;

    double q1 = ui->q1->value();
    double q2 = ui->q2->value();

    x1 = l1 * cos(M_PI*q1/180);
    y1 = l1 * sin(M_PI*q1/180);

    x2 = l1 * cos(M_PI*q1/180) + l2 * cos((M_PI*q1/180) + (M_PI*q2/180));
    y2 = l1 * sin(M_PI*q1/180) + l2 * sin((M_PI*q1/180) + (M_PI*q2/180));

    scene->clear();
    line1 = scene->addLine(x0,y0,x1,y1,redPen);
    line2 = scene->addLine(x1,y1,x2,y2,blackPen);

}

