/*!
*   Author: Ivan Collazo
*   File: alienmothership.cpp
*   Date: 10/05/2009
*   This is .cpp file for alienmothership in earth20000
*/

#include "alienmothership.h"
#include "shipsmissiles.h"
#include <QPainter>
#include <QSound>
#include <QGraphicsView>
#include <QDebug>
#include "constants.h"

/*!
    constructor
*/
AlienMotherShip::AlienMotherShip()
{
    shipsImage.load(":alienSpaceship.png");
//    width = 390;
//    height = 240;
//    left = 170;
//    top = 200;
//    alienMotherShipHit = 20;

    shipWidth = 390;
    shipHeight = 240;
    xPosition = 170;
    yPosition = 200;
    shipHit = 5;
}

/*!
    destructor
*/

AlienMotherShip::~AlienMotherShip()
{
}

/*!
    this method is called whenever the alienmothership needs to be drawn
*/
void AlienMotherShip::paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // can traverse to examine what collided with alienmothership
    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

    // paints the alienmothership image
    painter->drawPixmap(xPosition, yPosition, shipWidth, shipHeight, shipsImage);

    // checks to see if collisions occurs
    if (!listOfCollidingItems.isEmpty())
    {
        // if collision occurs with spaceshipmissile then decrements aliemMotherShipHit
        if(listOfCollidingItems.first()->type() == ID_SPACESHIPMISSILE)
        {
            shipHit--;
        }
    }

    // if alienMotherShipHit is 0 ship destoryed then changes alien motherships image and has ship explosion FX
    if (shipHit == 0)
    {
        shipsImage.load(":fire.png");
        painter->drawPixmap(xPosition, yPosition, shipWidth, shipHeight, shipsImage);

        QSound *shipExplosionFX = new QSound("explosion_2.wav", 0);
        shipExplosionFX->setLoops(1);
        shipExplosionFX->play();

        update();
    }
}

/*!
    this method does the bounding rectangle of the object for collision detection
*/
QRectF AlienMotherShip::boundingRect() const
{
    return QRectF(178, 260, 378, 96);
}

/*!
    this method fires the alienmothership bullets
*/
void AlienMotherShip::fire()
{
    shipBullet = new MotherShipBullet ();
    shipBullet->setBulletPosition(xPosition - 145, yPosition + 280);
    this->scene()->addItem(shipBullet);

    QSound *alienShipFireFX = new QSound("laser_1.wav", 0);
    alienShipFireFX->setLoops(1);
    alienShipFireFX->play();
}
