#include "spaceship.h"
//#include "MoveBehavior.h"
//#include "ShotBehavior.h"

#include <QPainter>
#include <QGraphicsScene>
#include <QStyleOption>
#include <QGraphicsItem>
//#include <iostream>
#include <QDebug>

//MoveBehavior shipMoving;
//ShotBehavior shipShooting;

//using namespace std;

// constructor
SpaceShip::SpaceShip()
{
    width = 100;
    height = 60;
    left = 325;
    top = 620;
    color = (Qt::red);

    setPos(left, top);
}

// destructor
//SpaceShip::~SpaceShip()
//{

//}

// the bounding rectangle of the object for collision detection
QRectF SpaceShip::boundingRect() const
{
    return QRectF(left, top, width, height);
}

// called whenever the spaceShip needs to be drawn
void SpaceShip::paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        // For the fun of it, I am going to make the character turn
        // Red when it detects it has collided with something else.
        // listOfCollidingItems returns a QList of items that you
        // can later traverse to examine what collided with the character.
      //  QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

        // If nothing collided then draw the character in black, otherwise red.
      //  if (listOfCollidingItems.isEmpty()) painter->setBrush(Qt::black);
      //  else painter->setBrush(Qt::red);


    painter->setBrush(color);
    painter->drawRect(left, top, width, height);
}


//void SpaceShip::performShipMovement()
//{
//    shipMoving.move();

//}

//void SpaceShip::performShootingMovement()
//{
//    shipShooting.shot();
//}



