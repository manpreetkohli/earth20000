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
#include "loadGame.h"
#include <QTimer>
#include <QGraphicsView>
#include <QtGui>

#include "spaceship.h"



void Board::displayHUDLevel(QGraphicsScene *scene, QString levelNumber, QFont *font)
{
    QGraphicsTextItem *levelInfo = scene->addText(levelNumber, *font);
    levelInfo->setDefaultTextColor(Qt::cyan);
    levelInfo->setOpacity(0.6);
    levelInfo->setPos(15, 0);
}


SpaceShip *Constants::life1;
SpaceShip *Constants::life2;
SpaceShip *Constants::life3;

// constructor
Board::Board(QGraphicsView *view)
{
    scene = new QGraphicsScene();           // create a new scene
    int width = view->geometry().width() - 5;
    int height = view->geometry().height() - 5;
    scene->setSceneRect(0, 0, width, height);       // set dimensions of the scene

    QFont *font = new QFont();

    font->setBold(true);
    font->setPointSize(15);

    if (Constants::levelNumber == 0)
    {
        LevelEditor *theLevelEditor = new LevelEditor(scene);
        QGraphicsTextItem *levelNumber = scene->addText(QString("LEVEL EDITOR MODE"), *font);
        levelNumber->setDefaultTextColor(Qt::cyan);
        levelNumber->setOpacity(0.6);
        levelNumber->setPos(15, 0);
    }
    else if (Constants::levelNumber == 1)
    {
        levelOne *theFirstLevel = new levelOne(scene);
        displayHUDLevel(scene, "LEVEL 1", font);
    }

    else if (Constants::levelNumber == 2)
    {
        levelTwo *theSecondLevel = new levelTwo(scene);
        displayHUDLevel(scene, "LEVEL 2", font);
   }
    else if (Constants::levelNumber == 5)
    {
        levelFive *theFifthLevel = new levelFive(scene);
        displayHUDLevel(scene, "LEVEL 5", font);
    }
    else if (Constants::levelNumber == 6)
    {
        LoadGame *theSavedGame = new LoadGame(scene);
        displayHUDLevel(scene, "SAVED GAME", font);
    }

    QGraphicsTextItem *lives = scene->addText(QString("SPAWNS: "), *font);
    lives->setDefaultTextColor(Qt::cyan);
    lives->setOpacity(0.6);
    lives->setPos(485, 0);

    Constants::life1 = new SpaceShip();
    scene->addItem(Constants::life1);
    Constants::life1->setPos(435, -310);
    Constants::life1->scale(0.5, 0.5);
    Constants::life1->setOpacity(0.5);

    Constants::life2 = new SpaceShip();
    scene->addItem(Constants::life2);
    Constants::life2->setPos(485, -310);
    Constants::life2->scale(0.5, 0.5);
    Constants::life2->setOpacity(0.5);

    Constants::life3 = new SpaceShip();
    scene->addItem(Constants::life3);
    Constants::life3->setPos(535, -310);
    Constants::life3->scale(0.5, 0.5);
    Constants::life3->setOpacity(0.5);

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
    timer->start(10);
}

