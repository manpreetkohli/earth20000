/*!
*   Author: Ivan Collazo
*   File: alienshipbullet.cpp
*   Date: 10/20/2009
*   This is .cpp file for alien ships bullets in earth20000
*/

#include "alienshipbullet.h"
#include "spaceship.h"
#include "constants.h"

/*!
    constructor
*/
AlienShipBullet::AlienShipBullet()
{
    bulletImage.load(":motherShipBullet.png");
    directionX = 0;                             // set the X-axis increment for the movement
    directionY = 0.25;                          // set the Y-axis increment for the movement
    positionX = 0;                              // initial X coordinate of the bullet
    positionY = 0;                              // initial Y coordinate of the bullet
    width = 20;                                 // width of the bullet
    height = 20;                                // height of the bullet
}

/*!
    destructor
*/
AlienShipBullet::~AlienShipBullet()
{
}

/*!
    this method is called whenever the alienshipbullet needs to be drawn
*/
void AlienShipBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(360, -340, width, height, bulletImage);
}

/*!
*   this method does the bounding rectangle of the object for collision detection
*/
QRectF AlienShipBullet::boundingRect() const
{
  return QRectF(360, -340, width, height);
}

/*!
*   this method sets alienshipbullet position
*/
void AlienShipBullet::setBulletPosition (int posX, int posY)
{
    positionX = posX;
    positionY = posY;
}

/*!
*   this method adds motion to the alienshipbullet
*/
void AlienShipBullet::advance(int phase)
{
    if(!phase) return;

    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

    // checks if there is a collision
    if (!listOfCollidingItems.isEmpty())
    {
        // if collision occurs with a space ship then alien ship bullet is removed from the scene
        if(listOfCollidingItems.first()->type() == ID_SPACESHIP)
        {
            this->scene()->removeItem(this);
        }
    }

    positionY+=directionY;

    // set the new position of the alien ship bullet
    setPos(positionX,positionY);

    // if position of the alien ship bullet is greater than 800 the mother ship bullet is removed from scene
    if (positionY > 1050)
    {
        this->scene()->removeItem(this);
    }
}
