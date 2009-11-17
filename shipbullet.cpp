/**
/ Author: Ivan Collazo
/ File: shipbullet.cpp
/ Date: 10/20/2009
/
*/

#include "shipbullet.h"
#include <QPainter>
#include <QDebug>
#include <iostream>

ShipBullet::ShipBullet()
{
    bulletImage.load(":bullet.png");
    directionX = 0;                         // set the X-axis increment for the movement
    directionY = -4;                        // set the Y-axis increment for the movement
    positionX = 0;                          // initial X coordinate of the ball
    positionY = 0;                          // initial Y coordinate of the ball
    width = 10;
    height = 10;
  //  setPos(positionX, positionY);           // set initial position of the ball
}

ShipBullet::~ShipBullet()
{
    qDebug() << "Destructor";
    //delete this->ShipBullet::~ShipBullet();
}

void ShipBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-10, 625, 10, 10, bulletImage);
}

// Define the bounding rectangle of the object for collision detection
QRectF ShipBullet::boundingRect() const
{
  return QRectF(-10,625, 20,20);
}

// function set the players Ship position to be used in the physics portion in the advance function
void ShipBullet::setShipPosition (int pos)
{
    shipXPosition = pos;
    positionX = shipXPosition;
}

int ShipBullet::getShipBulletYPosition ()
{
    return positionY;
}

// function to add motion to the ball inside the board
void ShipBullet::advance(int phase)
{
    if(!phase) return;

    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();//ivan


    if (!listOfCollidingItems.isEmpty() && positionY <= -380)
    {
      qDebug() << "HITTING SHITTT";
        positionX += 700;
    }

    positionY+=directionY;

    // comment out the positionY >= 85 part to make it not
    // bounce back on hitting the bottom part of the screen
    if (positionY <= -630)
    {
        //qDebug() << "Clear this up when missed or hit object";
       // positionY+= 100;
        //this->ShipBullet::~ShipBullet();
        // delete this;
    }

    // set the new position of the ball
    setPos(positionX+380,positionY);
}
