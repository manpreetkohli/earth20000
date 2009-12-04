#include "alienmothership.h"
#include <QPainter>
#include <QStyleOption>
#include <QDebug>
#include <QGraphicsView>
#include <QTimer>
#include <QtGui>
#include "mothershipbullet.h"
#include "shipsmissiles.h"

MotherShipBullet *shipBullet;

QTimer *timer = new QTimer();

AlienMotherShip::AlienMotherShip()
{
    shipsImage.load(":alienSpaceship.png");
    width = 390;
    height = 240;
    left = 170;
    top = 200;
    alienMotherShipHit = 20;
    qDebug() << "Alien MotherShip Constructor" ;
    timer = new QTimer();       // create a new QTimer() instance
}

/*!
  destructor
  */
AlienMotherShip::~AlienMotherShip()
{
    qDebug() << "Alien MotherShip Destructor" ;
}

/*!
  called whenever the AlienMotherShip needs to be drawn
  */
void AlienMotherShip::paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // can later traverse to examine what collided with the character.
    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();
    painter->drawPixmap(left, top, width, height, shipsImage);

    if (!listOfCollidingItems.isEmpty()) // checks to see if mothership has been hit and increments alienMotherShip hit.
    {
        if(listOfCollidingItems.first()->type() == ID_SPACESHIPMISSILE)
        {
            qDebug() << "MY ALIEN MOTHER SHIP GOT HIT";
            alienMotherShipHit--;
            qDebug() << alienMotherShipHit;
            update();
        }
    }
    if (alienMotherShipHit == 0) // if alienMotherShipHit is 5 ship destoryed and game WON!!!!
    {
        qDebug() << "MY ALIEN SHIP GOT Destroyed";
        shipsImage.load(":fire.png");
        painter->drawPixmap(left, top, width, height, shipsImage);

        QSound *shipExplosionFX = new QSound("explosion_2.wav", 0);
        shipExplosionFX->setLoops(1);
        shipExplosionFX->play();

        update();
    }
}

/*!
  the bounding rectangle of the object for collision detection
  */
QRectF AlienMotherShip::boundingRect() const
{
    return QRectF(178, 260, 378, 96);
}

/*!
  gets Ships horizontal position
  */
qreal AlienMotherShip::getShipPosX()
{
    return left;
}

/*!
  gets Ships horizontal position
  */
qreal AlienMotherShip::getShipPosY()
{
    return top;
}

void AlienMotherShip::fire()
{
    shipBullet = new MotherShipBullet ();
    shipBullet->setBulletPosition(left - 145, top + 280);
    this->scene()->addItem(shipBullet);
    qDebug() << " MOTHER SHIP FIRING ";

    QSound *alienShipFireFX = new QSound("laser_1.wav", 0);
    alienShipFireFX->setLoops(1);
    alienShipFireFX->play();
}

qreal AlienMotherShip::getShipHit()
{
    return alienMotherShipHit;
}
