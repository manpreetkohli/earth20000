/**
/ Author: Ivan Collazo
/ File: shipmissiles.cpp
/ Date: 10/20/2009
/
*/

#include "shipsmissiles.h"
#include <QPainter>
#include <QDebug>
#include <iostream>
#include <QStyleOption>

ShipsMissiles::ShipsMissiles()
{   
    missileImage.load(":missiles.png");
    directionX = 0;                         // set the X-axis increment for the movement
    directionY = -4;                        // set the Y-axis increment for the movement
    positionX = -625;                          // initial X coordinate of the ball
    positionY = 0;                          // initial Y coordinate of the ball
    width = 10;
    height = 10;
    setPos(positionX, positionY);           // set initial position of the ball
}


ShipsMissiles::~ShipsMissiles()
{
    qDebug() << "Destructor";
    //delete this->ShipBullet::~ShipBullet();
}

void ShipsMissiles::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  // painter->drawRect(40, 625, 20, 120);
   painter->drawPixmap(-10, 625, 120, 120, missileImage);
}

// Define the bounding rectangle of the object for collision detection
QRectF ShipsMissiles::boundingRect() const
{
    return QRectF(40, 625, 20, 120);
}

// function set the players Ship position to be used in the physics portion in the advance function
void ShipsMissiles::setShipPosition (int pos)
{
    shipXPosition = pos;
    positionX = shipXPosition;
}

// function to add motion to the ball inside the board
void ShipsMissiles::advance(int phase)
{
    if(!phase) return;

    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();//ivan

    positionY+=directionY;

    // comment out the positionY >= 85 part to make it not
    // bounce back on hitting the bottom part of the screen
    if (!listOfCollidingItems.isEmpty() && positionY <= -100)
    {
        qDebug() << "Clear this up when missed or hit object";
       // positionY+= 100;
        //this->ShipBullet::~ShipBullet();
        // delete;
        positionX += 700;
    }

    // set the new position of the ball
    setPos(positionX+330, positionY-80);
}
