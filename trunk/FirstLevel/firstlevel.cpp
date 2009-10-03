#include "firstlevel.h"


FirstLevel::FirstLevel()
{
    board = new Board();

    ball = new Ball(board->view->geometry().width(), board->view->geometry().height());

}



void FirstLevel::setupFirstLevel()
{

    board->showBoard();

    // turn off the scrollbar in graphicsview
    board->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    board->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ball->setBounceBounds(board->view->geometry().width(), board->view->geometry().height());

    board->scene->addItem(ball);
    

//    board->view->setUpdatesEnabled(true);




//            myGraphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    // Create a timer that sends a signal to the "advance()" slot of any
    // characters that are created.



}

