/*!
*   Author: Ivan Collazo
*   File: mothershipbullet.cpp
*   Date: 10/20/2009
*   This is .cpp file for mother ships bullets in earth20000
*/

#include "mothershipbullet.h"
#include "spaceship.h"
#include "constants.h"

/*!
    constructor
*/

MotherShipBullet::MotherShipBullet()
{
    bulletImage.load(":enemyBullet.png");
    directionX = 0;                         // set the X-axis increment for the movement
    directionY = 2;                         // set the Y-axis increment for the movement
    positionX = 0;                          // initial X coordinate of the bullet
    positionY = 0;                          // initial Y coordinate of the bullet
    width = 30;                             // width of the bullet
    height = 30;                            // height of the bullet
    setPos(positionX, positionY);           // set initial position of the bullet
}

/*!
    destructor
*/
MotherShipBullet::~MotherShipBullet()
{
}

/*!
    this method is called whenever the mothershipbullet needs to be drawn
*/
void MotherShipBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(325, -110, width, height, bulletImage);
}

/*!
    this method does the bounding rectangle of the object for collision detection
*/
QRectF MotherShipBullet::boundingRect() const
{
  return QRectF(325,-110, width,height);
}

/*!
    this method sets mothershipbullet position
*/
void MotherShipBullet::setBulletPosition (int posX, int posY)
{
    positionX = posX;
    positionY = posY;
}

/*!
    this method adds motion to the mothershipbullet
*/
void MotherShipBullet::advance(int phase)
{
    if(!phase) return;

    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

    // checks if there is a collision
    if (!listOfCollidingItems.isEmpty())
    {
        // if collision occurs with a space ship then mother ship bullet is removed from the scene
        if(listOfCollidingItems.first()->type() == ID_SPACESHIP)
        {
            this->scene()->removeItem(this);
        }
    }

    positionY+=directionY;

    // set the new position of the mothership bullet
    setPos(positionX,positionY);

    // if position of the mother ship bullet is greater than 800 the mother ship bullet is removed from scene
    if (positionY > 800)
    {
        this->scene()->removeItem(this);
    }
}
