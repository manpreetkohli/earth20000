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
#include "block.h"
#include "alienspaceship.h"
#include "spaceship.h"
#include "constants.h"

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
    qDebug() << "Ship Bullet Destructor";
}

void ShipBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-10, 600, 10, 10, bulletImage);
}

// Define the bounding rectangle of the object for collision detection
QRectF ShipBullet::boundingRect() const
{
  return QRectF(-10,600, 20,20);
}

// function set the players Ship position to be used in the firing of bullets
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

    if (!listOfCollidingItems.isEmpty())
    {
         if(listOfCollidingItems.first()->type() == BLOCKID)
         {
            qDebug() << "BULLET HIT A BLOCK";
            //directionY = 4;
         }

         else if (listOfCollidingItems.first()->type() == ID_SPACESHIP)
         {
            qDebug() << "BULLET HIT spaceShip";
            this->scene()->removeItem(this);
         }

         else if (listOfCollidingItems.first()->type() == ID_ALIENSPACESHIP)
         {
          qDebug() << "HITTING Alien SHITTT";
          this->scene()->removeItem(this);//   positionX += 700;
         }
    }

    positionY+=directionY;

    // set the new position of the ball
    setPos(positionX+385,positionY);
}
