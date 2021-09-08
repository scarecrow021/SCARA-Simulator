#include "./UI/mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->viewer->setScene(scene);

    connect(ui->q1, SIGNAL(valueChanged(int)), this, SLOT(DrawSCARA(int)));
    connect(ui->q2, SIGNAL(valueChanged(int)), this, SLOT(DrawSCARA(int)));
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

    scara.SetLength(100, 50);
    scara.SetCurrentAngles(ui->q1->value(), ui->q2->value());
    scara.CalculateFK();

    scene->clear(); // Clear display area each time
    
    line1 = scene->addLine(scara.x0, scara.y0, scara.x1, scara.y1,redPen);
    line2 = scene->addLine(scara.x1, scara.y1, scara.x2, scara.y2,blackPen);
}

