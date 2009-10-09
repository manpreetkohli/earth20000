#include "spaceship.h"
//#include "MoveBehavior.h"
//#include "ShotBehavior.h"

#include <QPainter>
#include <QGraphicsScene>
#include <QStyleOption>
#include <QGraphicsItem>
#include <iostream>

//MoveBehavior shipMoving;
//ShotBehavior shipShooting;

// constructor
spaceShip::spaceShip()
        : width(100), height(60), left(325), top(620), color(Qt::red)
{

}

// destructor
spaceShip::~spaceShip()
{

}

// the bounding rectangle of the object for collision detection
QRectF spaceShip::boundingRect()
{
    return QRectF(left, top, width, height);
}

// called whenever the spaceShip needs to be drawn
void spaceShip::paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        // For the fun of it, I am going to make the character turn
        // Red when it detects it has collided with something else.
        // listOfCollidingItems returns a QList of items that you
        // can later traverse to examine what collided with the character.
        QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

        // If nothing collided then draw the character in black, otherwise red.
        if (listOfCollidingItems.isEmpty()) painter->setBrush(Qt::black);
        else painter->setBrush(Qt::red);


    painter->setBrush(color);
    painter->drawRect(left, top, width, height);
}


//void spaceShip::performShipMovement()
//{
//    shipMoving.move();

//}

//void spaceShip::performShootingMovement()
//{
//    shipShooting.shot();
//}



