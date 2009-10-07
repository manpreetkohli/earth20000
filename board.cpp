#include "board.h"

#include <QTimer>

Board::Board(QGraphicsView *view)
{
    scene = new QGraphicsScene();
    int width = view->geometry().width();
    int height = view->geometry().height();
    scene->setSceneRect(0, 0, width, height);
    view->setScene(scene);

    timer = new QTimer();
}

void Board::showBoard()
{

     QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));

     // Set the timer to trigger every 3 ms.
    timer->start(3);

}


