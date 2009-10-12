#include "spaceship.h"
#include "MoveBehavior.h"
//#include "ShotBehavior.h"

#include <QPainter>
//#include <QGraphicsScene>
#include <QStyleOption>
#include <QGraphicsItem>
#include <iostream>
#include <QDebug>
#include <QKeyEvent>

MoveBehavior shipMoving;
//ShotBehavior shipShooting;

using namespace std;

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
    setPos(left, top);
   // setFlag(QGraphicsItem::boundingRect());
}

// destructor
SpaceShip::~SpaceShip()
{
    qDebug() << "Destructor" ;
}

// called whenever the spaceShip needs to be drawn
void SpaceShip::paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        // For the fun of it, I am going to make the character turn
        // Red when it detects it has collided with something else.
        // listOfCollidingItems returns a QList of items that you
        // can later traverse to examine what collided with the character.
        QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

        // If nothing collided then draw the character in black, otherwise red.
        if (listOfCollidingItems.isEmpty()) painter->setBrush(Qt::black);
        else painter->setBrush(Qt::blue);

    painter->setBrush(color);
    painter->drawRect(335, 640, 80, 30);
    painter->drawPixmap(335, 640, 90, 35, shipsImage);
}

// the bounding rectangle of the object for collision detection
QRectF SpaceShip::boundingRect() const
{
    return QRectF(335, 640, 90, 35);
}

    void SpaceShip::performShipMovement()
    {
        //shipMoving.move(QKeyEvent *event);
    }

//void SpaceShip::performShootingMovement()
//{
//    shipShooting.shot();
//}



