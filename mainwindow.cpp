#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myitem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //first step
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-200,-200,300,300);

    QPen mypen = QPen(Qt::red);

    //create 4 lines
    QLineF TopLine(scene->sceneRect().topLeft(),scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(),scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(),scene->sceneRect().bottomRight());
    QLineF BottonLine(scene->sceneRect().bottomLeft(),scene->sceneRect().bottomRight());

    //addLine
    scene->addLine(TopLine, mypen);
    scene->addLine(LeftLine, mypen);
    scene->addLine(RightLine, mypen);
    scene->addLine(BottonLine, mypen);

	//few rectangle created
    int ItemCount = 25;
    for (int i = 0; i<ItemCount ; i++) {
        MyItem *item = new MyItem();
        scene->addItem(item);
    }

    //set timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(100);

}

MainWindow::~MainWindow()
{
    delete ui;
}

