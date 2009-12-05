/*!
*   Author: Ivan Collazo
*   File: ammo.cpp
*   Date: 10/20/2009
*   This is .cpp file for space ships bullets in earth20000
*/

#include "ammo.h"
#include "constants.h"

/*!
    constructor
*/
Ammo::Ammo()
{
    directionX = 0;                         // set the X-axis increment for the movement
    directionY = 0;                        // set the Y-axis increment for the movement
    width = 0;                             // width of the bullet
    height = 0;                            // height of the bullet
}

/*!
    destructor
*/
Ammo::~Ammo()
{
}

/*!
    this method is called whenever the ammo needs to be drawn
*/
void Ammo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(positionX,positionY,width,height);
}

/*!
    this method does the bounding rectangle of the object for collision detection
*/
QRectF Ammo::boundingRect() const
{
  return QRectF(positionX,positionY,width,height);
}

/*!
    this method adds motion to the shipsbullet
*/
void Ammo::advance(int phase)
{
    setPos(positionX,positionY);
}

