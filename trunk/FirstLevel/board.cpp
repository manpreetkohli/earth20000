#include "board.h"

#include <QTimer>

Board::Board()
{
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    timer = new QTimer();

   // bgImage->load("universe4.jpg");

}

void Board::showBoard()
{


//    view->setBackgroundBrush(QPixmap(":universe4.jpg").);

    view->show();
    view->setGeometry(250, 40, 750, 725);
    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    // set the maximum and minimum dimensions of the window to the dimensions of the current
    // setup so that the window cannot be maximized or minimized during the game
    view->setMaximumSize(750, 725);
    view->setMinimumSize(750, 725);


     QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));

     // Set the timer to trigger every 30 ms.
    timer->start(1);

}


