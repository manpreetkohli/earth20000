#include "board.h"
#include "block.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelFive.h"

#include <QTimer>

Board::Board(QGraphicsView *view)
{
    scene = new QGraphicsScene();
    int width = view->geometry().width();
    int height = view->geometry().height();
    scene->setSceneRect(0, 0, width, height);

    //levelOne *theFirstLevel = new levelOne(scene);
    //levelTwo *theSecondLevel = new levelTwo(scene);
    levelFive *theFifthLevel = new levelFive(scene);

    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setScene(scene);

    timer = new QTimer();
}

void Board::showBoard()
{

     QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));

     // Set the timer to trigger every 3 ms.
    timer->start(1000 / 170);

}


