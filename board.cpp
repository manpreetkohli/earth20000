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
#include "spaceship.h"
#include "sleeperthread.h"

// added by Manpreet Kohli
// initialize all the statics
QGraphicsTextItem *Constants::levelInfo;
int Constants::count;
QGraphicsTextItem *Constants::lives;
SpaceShip *Constants::life1;
SpaceShip *Constants::life2;
SpaceShip *Constants::life3;
QTimer *Constants::timer;

/*!
  added by Manpreet Kohli
  constructor
  */
Board::Board(QGraphicsView *view)
{
    scene = new QGraphicsScene();                   // create a new scene
    scene->setSceneRect(0, 0, view->geometry().width() - 5,  view->geometry().height() - 5);       // set dimensions of the scene

    QFont *font = new QFont();
    font->setStyleHint(QFont::SansSerif, QFont::PreferAntialias);
    font->setLetterSpacing(QFont::PercentageSpacing, 125);
    font->setBold(true);
    font->setPointSize(14);

    // check which level needs to be displayed and call function to display the corresponding HUD
    if (Constants::levelNumber == 0)
    {
        Constants::count = 3;
        LevelEditor *theLevelEditor = new LevelEditor(scene);
        displayHUDLevel(scene, "LEVEL EDITOR MODE", font);
    }
    else if (Constants::levelNumber == 1)
    {
        Constants::count = 3;
        LevelOne *theFirstLevel = new LevelOne(scene);
        displayHUDLevel(scene, "LEVEL 1", font);
    }
    else if (Constants::levelNumber == 2)
    {
        LevelTwo *theSecondLevel = new LevelTwo(scene);
        displayHUDLevel(scene, "LEVEL 2", font);
    }
    else if (Constants::levelNumber == 3)
    {
        LevelThree *theThirdLevel = new LevelThree(scene);
        displayHUDLevel(scene, "LEVEL 3", font);
    }
    else if (Constants::levelNumber == 4)
    {
        LevelFive *theFifthLevel = new LevelFive(scene);
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

    // display the spawns part of the HUD
    Constants::lives = scene->addText(QString("SPAWNS: "), *font);
    Constants::lives->setDefaultTextColor(Qt::red);
    Constants::lives->setOpacity(0.6);
    Constants::lives->setPos(485, 0);

    // based on the number of spawns remaining, draw the spawns in the HUD
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
    view->setScene(scene);                      // set the created scene inside the view
    Constants::timer = new QTimer();            // create a new QTimer() instance
}

/*!
  added by Manpreet Kohli
  function to display level info in the HUD
  */
void Board::displayHUDLevel(QGraphicsScene *scene, QString levelNumber, QFont *font)
{
    Constants::levelInfo = scene->addText(levelNumber, *font);
    if (Constants::levelNumber == 0 || Constants::levelNumber == 6)
    {
        Constants::levelInfo->setDefaultTextColor(Qt::darkGray);
    }
    else
    {
        Constants::levelInfo->setDefaultTextColor(Qt::white);
    }
    Constants::levelInfo->setOpacity(0.6);
    Constants::levelInfo->setPos(15, 0);
}

/*!
  added by Manpreet Kohli
  method to connect the timer to the ball inside the board
  */
void Board::connectTimerToBall()
{
    // connect the timer to the advance method inside the Ball class
    QObject::connect(Constants::timer, SIGNAL(timeout()), scene, SLOT(advance()));

    // Set the timer to trigger every 1 ms for normal levels, and every  0 ms for the level editor
    if (Constants::levelNumber == 0)
        Constants::timer->start(0);
    else
        Constants::timer->start(1);
}
