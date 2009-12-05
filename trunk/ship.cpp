/*!
*   Author: Ivan Collazo
*   File: ship.cpp
*   Date: 10/05/2009
*   This is the .cpp file for the super class for ships in earth20000
*/
#include "ship.h"
#include "constants.h"
#include <QDebug>

/*!
    constructor
*/
Ship::Ship()
{
    xPosition = 0;
    yPosition = 0;
    shipWidth = 0;
    shipHeight = 0;
   // shipHit = 0;
}

/*!
    destructor
*/
Ship::~Ship()
{
}

/*!
    this method is the bounding rectangle of the object for collision detection
*/
QRectF Ship::boundingRect() const
{
    return QRectF(xPosition, yPosition, shipWidth, shipHeight);
}

/*!
    this method is called whenever the ship needs to be drawn
*/
void Ship::paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

/*!
    this method gets ships x position
*/
int Ship::getShipPosX()
{
    return xPosition;
}

/*!
    this method sets ships x position
*/
void Ship::setShipPosX (int xPos)
{
    xPosition += xPos;
}

/*!
*   this method gets ships y position
*/
int Ship::getShipPosY()
{
    return yPosition;
}

/*!
    this method sets ships y position
*/
void Ship::setShipPosY (int yPos)
{
    yPosition += yPos;
}

/*!
    this method gets the amount of times ship has been hit
*/
int Ship::getShipHit()
{
       return shipHit;
}
