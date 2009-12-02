/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * board.cpp: sets up the board for the game- adds a scene to a view, and then adds the various
 * QGraphicsItems to the board
 *
 */

/**
  HUD slightly modified by Natraj Subramanian
  **/

// include the header file for this class
#include "board.h"
#include "constants.h"
#include "block.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFive.h"
#include "leveleditor.h"
#include "loadGame.h"
#include <QTimer>
#include <QGraphicsView>
#include <QtGui>
#include "spaceship.h"
#include "sleeperthread.h"

QGraphicsTextItem *Constants::levelInfo;
int Constants::count;
QGraphicsTextItem *Constants::lives;
QGraphicsTextItem *Constants::score;
SpaceShip *Constants::life1;
SpaceShip *Constants::life2;
SpaceShip *Constants::life3;
QTimer *Constants::timer;

// constructor
Board::Board(QGraphicsView *view)
{
    scene = new QGraphicsScene();           // create a new scene
    int width = view->geometry().width() - 5;
    int height = view->geometry().height() - 5;
    scene->setSceneRect(0, 0, width, height);       // set dimensions of the scene

    QFont *font = new QFont();
    font->setStyleHint(QFont::SansSerif, QFont::PreferAntialias);
    font->setLetterSpacing(QFont::PercentageSpacing, 125);
    font->setBold(true);
    font->setPointSize(14);

    if (Constants::levelNumber == 0)
    {
        Constants::count = 3;
        LevelEditor *theLevelEditor = new LevelEditor(scene);
        displayHUDLevel(scene, "LEVEL EDITOR MODE", font);
    }
    else if (Constants::levelNumber == 1)
    {
        Constants::count = 3;
        levelOne *theFirstLevel = new levelOne(scene);
        displayHUDLevel(scene, "LEVEL 1", font);
    }

    else if (Constants::levelNumber == 2)
    {
//        Constants::count = 3;
        levelTwo *theSecondLevel = new levelTwo(scene);
        displayHUDLevel(scene, "LEVEL 2", font);
    }
    else if (Constants::levelNumber == 3)
    {
//        Constants::count = 3;
        levelThree *theThirdLevel = new levelThree(scene);
        displayHUDLevel(scene, "LEVEL 3", font);
    }
    else if (Constants::levelNumber == 4)
    {
//        Constants::count = 3;
        levelFive *theFifthLevel = new levelFive(scene);
        displayHUDLevel(scene, "FINAL LEVEL", font);
    }
    else if (Constants::levelNumber == 6)
    {
        Constants::count = 3;
        LoadGame *theSavedGame = new LoadGame(scene, view);
        displayHUDLevel(scene, "SAVED GAME", font);
    }

    font->setFamily("SansSerif");
    font->setBold(true);
    font->setPointSize(15);    

    Constants::lives = scene->addText(QString("SPAWNS: "), *font);
    Constants::lives->setDefaultTextColor(Qt::red);
    Constants::lives->setOpacity(0.6);
    Constants::lives->setPos(485, 0);

    font->setPointSize(24);
    Constants::score = scene->addText(QString::number(Constants::scoreCount, 10), *font);
    Constants::score->setDefaultTextColor(Qt::white);
    Constants::score->setOpacity(1.0);
    Constants::score->setPos(330, 0);

    if (Constants::count >= 1)
    {
        Constants::life1 = new SpaceShip();
        scene->addItem(Constants::life1);
        Constants::life1->setPos(435, -310);
        Constants::life1->scale(0.5, 0.5);
        Constants::life1->setOpacity(0.5);
    }
    if (Constants::count >= 2)
    {
        Constants::life2 = new SpaceShip();
        scene->addItem(Constants::life2);
        Constants::life2->setPos(485, -310);
        Constants::life2->scale(0.5, 0.5);
        Constants::life2->setOpacity(0.5);
    }
    if (Constants::count >= 3)
    {
        Constants::life3 = new SpaceShip();
        scene->addItem(Constants::life3);
        Constants::life3->setPos(535, -310);
        Constants::life3->scale(0.5, 0.5);
        Constants::life3->setOpacity(0.5);
    }

    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setScene(scene);          // set the created scene inside the view
    Constants::timer = new QTimer();       // create a new QTimer() instance
    scoreTimer = new QTimer();
}

// function to display level info in the HUD
void Board::displayHUDLevel(QGraphicsScene *scene, QString levelNumber, QFont *font)
{
    Constants::levelInfo = scene->addText(levelNumber, *font);
    Constants::levelInfo->setDefaultTextColor(Qt::white);
    Constants::levelInfo->setOpacity(0.6);
    Constants::levelInfo->setPos(15, 0);
}

// method to connect the timer to the ball inside the board
void Board::connectTimerToBall()
{
    // connect the timer to the advance method inside the Ball class
    QObject::connect(Constants::timer, SIGNAL(timeout()), scene, SLOT(advance()));

    // Set the timer to trigger every 3 ms.
    if (Constants::levelNumber == 0)
        Constants::timer->start(0);
    else
        Constants::timer->start(1);
}
