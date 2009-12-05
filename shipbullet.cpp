/*!
*   Author: Ivan Collazo
*   File: shipbullet.cpp
*   Date: 10/20/2009
*   This is .cpp file for space ships bullets in earth20000
*/

#include "shipbullet.h"
#include "block.h"
#include "alienspaceship.h"
#include "spaceship.h"
#include "constants.h"

/*!
    constructor
*/
ShipBullet::ShipBullet()
{
    bulletImage.load(":bullet.png");
    directionX = 0;                         // set the X-axis increment for the movement
    directionY = -4;                        // set the Y-axis increment for the movement
    positionX = 0;                          // initial X coordinate of the bullet
    positionY = 0;                          // initial Y coordinate of the bullet
    width = 10;                             // width of the bullet
    height = 10;                            // height of the bullet
}

/*!
    destructor
*/
ShipBullet::~ShipBullet()
{
}

/*!
    this method is called whenever the shipbullet needs to be drawn
*/
void ShipBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-10, 600, width, height, bulletImage);
}

/*!
    this method does the bounding rectangle of the object for collision detection
*/

QRectF ShipBullet::boundingRect() const
{
  return QRectF(-10,600, 20,20);
}

/*!
    this method sets shipbullet x position
*/
void ShipBullet::setShipBulletXPosition (int pos)
{
    shipXPosition = pos;
    positionX = shipXPosition;
}

/*!
    this method adds motion to the shipsbullet
*/
void ShipBullet::advance(int phase)
{
    if(!phase) return;

    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

    // checks if there is a collision
    if (!listOfCollidingItems.isEmpty())
    {
        // if collision occurs with a block then bullet bounces back
        if(listOfCollidingItems.first()->type() == BLOCKID)
        {
            directionY = 4;
        }

        // else if collision occurs with a spaceship then bullet is removed from scene
        else if (listOfCollidingItems.first()->type() == ID_SPACESHIP)
        {
            positionX += 700;
            this->scene()->removeItem(this);
        }

        // else if collision occurs with alienspaceship then bullet is removed from scene
        else if (listOfCollidingItems.first()->type() == ID_ALIENSPACESHIP)
        {
            positionX += 700;
            this->scene()->removeItem(this);
        }
    }
    positionY+=directionY;

    // set the new position of the ships bullet
    setPos(positionX+385,positionY);
}
