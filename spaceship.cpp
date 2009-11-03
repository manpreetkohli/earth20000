/**
/ Author: Ivan Collazo
/ File: spaceship.cpp
/ Date: 10/05/2009
/   This class is a super class for space ships in earth20000
/
/
*/

#include "spaceship.h"
//#include "MoveBehavior.h"
//#include "ShotBehavior.h"

#include <QPainter>
//#include <QGraphicsScene>
#include <QStyleOption>

#include <QDebug>
#include <QKeyEvent>

//MoveBehavior shipMoving;
//ShotBehavior shipShooting;

using namespace std;

int static leftDirection = 1;
int static rightDirection = 2;


// constructor
SpaceShip::SpaceShip()
{
    shipsImage.load(":playerShip.jpg");
    width = 0; //100
    height = 0; //60
    left = 0;  //325
    top = 0;   //620
    color = (Qt::red);
    qDebug() << "Constructor" ;
    setPos(0, 0);
}

// destructor
SpaceShip::~SpaceShip()
{
    qDebug() << "Destructor" ;
}

// called whenever the spaceShip needs to be drawn
void SpaceShip::paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // can later traverse to examine what collided with the character.
    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

    painter->setBrush(color);
    painter->drawRect(335, 640, 80, 30);
    painter->drawPixmap(335, 640, 90, 35, shipsImage);
}

// the bounding rectangle of the object for collision detection
QRectF SpaceShip::boundingRect() const
{
    return QRectF(335, 640, 90, 35);
}

// gets Ships horizontal position
int SpaceShip::getShipPosX()
{
    return left;
}

// sets Ships horizontal position
void SpaceShip::setShipPosX (int xPos)
{
    left += xPos;
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


//void SpaceShip::performShipMovement()
//{
    //shipMoving.move(QKeyEvent *event);
//}

//void SpaceShip::performShootingMovement()
//{
//    shipShooting.shot();
//}



