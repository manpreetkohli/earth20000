/*!
* Author: Ivan Collazo
* File: spaceship.cpp
* Date: 10/05/2009
*   This class is a super class for space ships in earth20000
*/

#include "spaceship.h"
//#include "MoveBehavior.h"
//#include "ShotBehavior.h"
#include <QPainter>
//#include <QGraphicsScene>
#include <QStyleOption>
#include <QDebug>
#include <QKeyEvent>
#include "mothershipbullet.h"
#include "alienshipbullet.h"
#include "constants.h"

//MoveBehavior shipMoving;
//ShotBehavior shipShooting;

//using namespace std;

int static leftDirection = 1;
int static rightDirection = 2;


/*!
* constructor
*/
SpaceShip::SpaceShip()
{
    shipsImage.load(":X-Wing-icon-1.png");
    width = 0; //100
    height = 0; //60
    left = 0;  //325
    top = 0;   //620
    shipHit = 4;
   // color = (Qt::red);
    qDebug() << "Space Ship Constructor" ;
    setPos(0, 0);
}

/*!
* destructor
*/
SpaceShip::~SpaceShip()
{
   // qDebug() << "Space Ship Destructor" ;
}

/*!
* destructor
*/
// called whenever the spaceShip needs to be drawn
void SpaceShip::paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // can later traverse to examine what collided with the character.
    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

    if (!listOfCollidingItems.isEmpty())
    {
        if ((listOfCollidingItems.first()->type() == ID_MOTHERSHIPBULLET) || (listOfCollidingItems.first()->type() == ID_ALIENSHIPBULLET))
        {
          //  qDebug() << "SPACE SHIP GOT HIT BY MOTHER SHIP BULLET";
            shipHit--;
            qDebug() << shipHit;

            if (Constants::count == 3)
            {
                this->scene()->removeItem(Constants::life3);        // remove a spawn from the HUD
                Constants::count--;                                 // decrement no. of lives remaining

                // play respawn music
                QSound *spawnSound = new QSound("start.wav", 0);
                spawnSound->setLoops(1);
                spawnSound->play();

                t->msleep(3000);
            }
            else if (Constants::count == 2)
            {
                this->scene()->removeItem(Constants::life2);        // remove a spawn from the HUD
                Constants::count--;                                 // decrement no. of lives remaining

                // play respawn music
                QSound *spawnSound = new QSound("start.wav", 0);
                spawnSound->setLoops(1);
                spawnSound->play();

                t->msleep(3000);
            }
            else if (Constants::count == 1)
            {
                this->scene()->removeItem(Constants::life1);        // remove a spawn from the HUD
                Constants::count--;                                 // decrement no. of lives remaining

                // play respawn music
                QSound *spawnSound = new QSound("start.wav", 0);
                spawnSound->setLoops(1);
                spawnSound->play();

                t->msleep(3000);
            }
            else if (Constants::count == 0)
            {
                // add game over logic
                QGraphicsView *temp  = this->scene()->views().at(0);

                this->scene()->deleteLater();

                QGraphicsScene *gameOverScene = new QGraphicsScene;

                temp->setScene(gameOverScene);

                gameOverScene->setSceneRect(0, 0, temp->geometry().width() - 5, temp->geometry().height() - 5);       // set dimensions of the scene

                QFont *font = new QFont();
                font->setBold(true);
                font->setPointSize(60);

                // play game over music
                QSound *gameover = new QSound("gameover.wav", 0);
                gameover->setLoops(1);
                gameover->play();

                // display game over message
                QGraphicsTextItem *gameOver = gameOverScene->addText(QString("GAME OVER"), *font);
                gameOver->setDefaultTextColor(Qt::cyan);
                gameOver->setOpacity(0.8);
                gameOver->setPos(150, 200);

                font->setPointSize(13);
                font->setWeight(75);

                QPushButton *exit = new QPushButton(temp->parentWidget());
                exit->setText("EXIT");
                exit->setGeometry(300, 600, 150, 40);
                exit->setFont(*font);
                exit->show();
                exit->setStyleSheet("background-color: rgba(255, 255, 255, 100);");

               // Constants::timer->disconnect(this->scene(), SLOT(advance()));
               // Constants::timer->stop();

                QObject::connect(exit, SIGNAL(clicked()), temp->parentWidget(), SLOT(close()));
            }
        }
    }

    painter->drawPixmap(335, 640, 90, 40, shipsImage);
}

// the bounding rectangle of the object for collision detection
QRectF SpaceShip::boundingRect() const
{
    return QRectF(335, 640, 90, 40);
}

// gets ship's horizontal position
int SpaceShip::getShipPosX()
{
    return left;
}

// gets ship's vertical position
int SpaceShip::getShipPosY()
{
    return top;
}

// sets Ships horizontal position
void SpaceShip::setShipPosX (int xPos)
{
    left += xPos;
}

// sets Ships vertical position
void SpaceShip::setShipPosY (int yPos)
{
    top += yPos;
}

// gets the Ship directions
int SpaceShip::getShipDirection()
{
    return shipDirection;
}

// sets Ship Direction
void SpaceShip::setShipDirection(int direction)
{
    // moving left = 1
    if (direction == leftDirection)
    {
        shipDirection = leftDirection;
    }

    //moving right = 2
    else if (direction == rightDirection)
    {
        shipDirection = rightDirection;
    }
}


int SpaceShip::getShipHit()
{  
       return shipHit;
}
//void SpaceShip::performShipMovement()
//{
    //shipMoving.move(QKeyEvent *event);
//}

//void SpaceShip::performShootingMovement()
//{
//    shipShooting.shot();
//}
