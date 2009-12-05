/*!
*   Author: Ivan Collazo
*   File: alienspaceship.cpp
*   Date: 10/05/2009
*   This is .cpp file for alienspaceship in earth20000
*/

#include "alienspaceship.h"
#include "shipbullet.h"
#include <QPainter>
#include <QSound>
#include <QGraphicsView>

/*!
    constructor
*/
AlienSpaceShip::AlienSpaceShip()
{
    shipsImage.load(":TieFighter-icon.png");
    xPosition = 0;
    yPosition = 0;
    shipWidth = 80;
    shipHeight = 40;
    shipHit = 5;
}

/*!
    destructor
*/
AlienSpaceShip::~AlienSpaceShip()
{
}

/*!
    this method is called whenever the alienspaceship needs to be drawn
*/
void AlienSpaceShip::paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // can traverse to examine what collided with alienspaceship
    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

    // paints the alienspaceship image
    painter->drawPixmap(355, 100, shipWidth, shipHeight, shipsImage);

    // checks to see if collisions occurs
    if (!listOfCollidingItems.isEmpty())
    {
        // if collision occurs with spaceshipbullet then decrements alienShipHit
        if(listOfCollidingItems.first()->type() == ID_SPACESHIPBULLET)
        {
            if (shipHit > 0)
            {
               --shipHit;
            }
        }
    }

    // if alienShipHit is 0 ship destoryed then changes alien motherships image and has ship explosion FX
    if (shipHit == 0)
    {
       shipsImage.load(":fire.png");
       painter->drawPixmap(355, 100, shipWidth, shipHeight, shipsImage);

       QSound *shipExplosionFX = new QSound("explosion_2.wav", 0);
       shipExplosionFX->setLoops(1);
       shipExplosionFX->play();

       update(); 
    }
}

/*!
    this method does the bounding rectangle of the object for collision detection
*/
QRectF AlienSpaceShip::boundingRect() const
{
    return QRectF(355, 100, 80, 40);
}

/*!
    this method gets the amount of times alien ship has been hit
*/
int AlienSpaceShip::getShipHit()
{
    return shipHit;
}

/*!
    this method fires the alien space ship bullets
*/
void AlienSpaceShip::fire()
{
    alienBullet = new AlienShipBullet ();
    alienBullet->setBulletPosition(25, 480);
    this->scene()->addItem(alienBullet);

    QSound *alienShipFireFX = new QSound("bomb.wav", 0);
    alienShipFireFX->setLoops(1);
    alienShipFireFX->play();
}

