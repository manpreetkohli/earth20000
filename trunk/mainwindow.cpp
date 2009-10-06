#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shipTest.h"
#include <QGraphicsItem>
#include <iostream>
#include <QPixmap>
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

using namespace std;

shipTest *aShip= new shipTest;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("TEST SHIP"));

    qDebug() << "TITLE DONE";

    TestShipScene *theScene = new TestShipScene;

    qDebug() << "CREATE SCENE";
    int width = ui->testView->geometry().width();
    int height = ui->testView->geometry().height();

    theScene->setSceneRect(0, 0, width,height);

    // turn off the scrollbar in graphicsview
    ui->testView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->testView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Tell myGraphicsView that this is my scene
    ui->testView->setScene(theScene);

    // Set this to refresh the full viewport whenever any object moves.
    // There are different modes you can set to reduce how frequently
    // you refresh the screen.
    ui->testView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

   // aShip->setBrush(Qt::red);
    aShip->setPos(200,200);
    theScene->addItem(aShip);

    qDebug() << "Made Ship";

  //  QPixmap playersSpaceShip;
    qDebug() << "Works";
}


void TestShipScene::keyPressEvent(QKeyEvent *event)
{
     switch(event->key())
        {
            case Qt::Key_Left:
            qDebug() << "key pressed Left";

        aShip->moveBy(-10,0);
            break;
            case Qt::Key_Right:
            qDebug() << "key pressed Right";
         aShip->moveBy(10,0);
            break;
            case Qt::Key_Space:
            qDebug() << "key pressed Space";
            break;
            default:
            cout << "key pressed " << event->text().data() << endl << flush;
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}

