/*!
*   Author: Ivan Collazo
*   File: shipsmissiles.cpp
*   Date: 10/20/2009
*   This is .cpp file for space ships missiles in earth20000
*/

#include "shipsmissiles.h"
#include "block.h"
#include "constants.h"
#include "alienmothership.h"

/*!
    constructor
*/
ShipsMissiles::ShipsMissiles()
{   
    bulletImage.load(":missiles.png");
    directionX = 0;                         // set the X-axis increment for the movement
    directionY = -4;                        // set the Y-axis increment for the movement
    positionX = -625;                       // initial X coordinate of the missile
    positionY = 0;                          // initial Y coordinate of the missile
    width = 120;                             // width of the missile
    height = 120;                            // height of the missile
    setPos(positionX, positionY);           // set initial position of the missile
}

/*!
    destructor
*/
ShipsMissiles::~ShipsMissiles()
{
}

/*!
    this method is called whenever the shipsmissiles needs to be drawn
*/
void ShipsMissiles::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->drawPixmap(-10, 625, width, height, bulletImage);
}

/*!
    this method does the bounding rectangle of the object for collision detection
*/

QRectF ShipsMissiles::boundingRect() const
{
    return QRectF(40, 625, 20, height);
}

/*!
    this method sets shipmissiles x position
*/
void ShipsMissiles::setShipMissilesXPosition (int pos)
{
    shipXPosition = pos;
    positionX = shipXPosition;
}

/*!
    this method adds motion to the shipsbullet
*/
void ShipsMissiles::advance(int phase)
{
    if(!phase) return;

    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

    // checks if there is a collision
    if (!listOfCollidingItems.isEmpty())
    {
        // if collision occurs with a block then missles is removed from scene
        if (listOfCollidingItems.first()->type() == BLOCKID)
        {
            positionX += 700;
            this->scene()->removeItem(this);
        }

        // else if collision occurs with a mothership then missile is removed from scene
        else if (listOfCollidingItems.first()->type() == ID_MOTHERSHIP)
        {
            positionX += 700;
            this->scene()->removeItem(this);
        }

        // else if collision occurs with a itself then missile is removed from scene
        else if (listOfCollidingItems.first()->type() == ID_SPACESHIPMISSILE)
        {
            positionX += 700;
            this->scene()->removeItem(this);
        }
    }

    positionY+=directionY;

    // set the new position of the shipsmissiles
    setPos(positionX+330, positionY-80);
}
