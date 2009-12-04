#include "alienspaceship.h"
#include <QPainter>
#include <QStyleOption>
#include <QDebug>
#include <QGraphicsView>
#include <QTimer>
#include <QtGui>
#include "alienshipbullet.h"
#include "shipbullet.h"

AlienShipBullet *alienBullet;

AlienSpaceShip::AlienSpaceShip()
{
    shipsImage.load(":TieFighter-icon.png");
    width = 0; //100
    height = 0; //60
    left = 0;  //325
    top = 0;   //620
    alienShipHit = 5;
    qDebug() << "Alien Ship Constructor" ;
}

/*!
  destructor
  */
AlienSpaceShip::~AlienSpaceShip()
{
    qDebug() << "Alien Space Ship Destructor" ;
}

/*!
  called whenever the spaceShip needs to be drawn
  */
void AlienSpaceShip::paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // can later traverse to examine what collided with the character.
    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

   // painter->setBrush(color);
   // painter->drawRect(315, 100, 80, 30);
    painter->drawPixmap(355, 100, 80, 40, shipsImage);

    if (!listOfCollidingItems.isEmpty())
    {
        if(listOfCollidingItems.first()->type() == ID_SPACESHIPBULLET)
        {
            if (alienShipHit <= 0)
            {
               // qDebug() << "ALIEN SHIP IS ALREADY BLOWED";
            }
            else
            {
                --alienShipHit;
            }
        }
    }

    if (alienShipHit == 0)
    {
       shipsImage.load(":fire.png");
       painter->drawPixmap(355, 100, 80, 40, shipsImage);

       QSound *shipExplosionFX = new QSound("explosion_2.wav", 0);
       shipExplosionFX->setLoops(1);
       shipExplosionFX->play();
       update();
    }
}

/*!
  the bounding rectangle of the object for collision detection
  */
QRectF AlienSpaceShip::boundingRect() const
{
    return QRectF(355, 100, 80, 40);
}

/*!
  gets Ships horizontal position
  */
qreal AlienSpaceShip::getShipPosX()
{
    return left;
}

/*!
  gets Ships horizontal position
  */
qreal AlienSpaceShip::getShipPosY()
{
    return top;
}

void AlienSpaceShip::fire()
{
    alienBullet = new AlienShipBullet ();
    alienBullet->setBulletPosition(25, 480);
    this->scene()->addItem(alienBullet);

    qDebug() << " Alien SHIP FIRING ";

    QSound *alienShipFireFX = new QSound("bomb.wav", 0);
    alienShipFireFX->setLoops(1);
    alienShipFireFX->play();
}

qreal AlienSpaceShip::getAlienShipHit()
{
    return alienShipHit;
}
