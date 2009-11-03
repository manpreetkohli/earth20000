/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * board.cpp: sets up the board for the game- adds a scene to a view, and then adds the various
 * QGraphicsItems to the board
 *
 */

// include the header file for this class
#include "board.h"
#include "constants.h"
#include "block.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelFive.h"
#include "leveleditor.h"
#include <QTimer>
#include <QGraphicsView>




// constructor
Board::Board(QGraphicsView *view)
{
    scene = new QGraphicsScene();           // create a new scene
    int width = view->geometry().width() - 5;
    int height = view->geometry().height() - 5;
    scene->setSceneRect(0, 0, width, height);       // set dimensions of the scene

//    levelOne *theFirstLevel = new levelOne(scene);
//    levelTwo *theSecondLevel = new levelTwo(scene);


    if (Constants::levelNumber == 0)
        LevelEditor *theLevelEditor = new LevelEditor(scene);
    else if (Constants::levelNumber == 1)
        levelOne *theFirstLevel = new levelOne(scene);
    else if (Constants::levelNumber == 2)
        levelTwo *theSecondLevel = new levelTwo(scene);
    else if (Constants::levelNumber == 5)
        levelFive *theFifthLevel = new levelFive(scene);


    // levelFive *theFifthLevel = new levelFive(scene);

    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setScene(scene);          // set the created scene inside the view
    timer = new QTimer();       // create a new QTimer() instance
}

// method to connect the timer to the ball inside the board
void Board::connectTimerToBall()
{
    // connect the timer to the advance method inside the Ball class
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));

     // Set the timer to trigger every 3 ms.
    timer->start(3);
}


