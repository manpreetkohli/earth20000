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
    width = 390; //100
    height = 240; //60
    left = 170;  //325
    top = 200;   //620
    alienMotherShipHit = 0;
    qDebug() << "Alien MotherShip Constructor" ;
  //  setPos(0, 0);
    timer = new QTimer();       // create a new QTimer() instance
}

// destructor
AlienMotherShip::~AlienMotherShip()
{
    qDebug() << "Alien MotherShip Destructor" ;
}

// called whenever the AlienMotherShip needs to be drawn
void AlienMotherShip::paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // can later traverse to examine what collided with the character.
    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

        //painter->drawEllipse(178,330,378,90);
       // painter->drawRect(178, 260, 378, 96);
      //  painter->drawRect(304, 320, 126, 108);
        painter->drawPixmap(left, top, width, height, shipsImage);

    if (!listOfCollidingItems.isEmpty()) // checks to see if mothership has been hit and increments alienMotherShip hit.
    {
        if(listOfCollidingItems.first()->type() == ID_SPACESHIPMISSILE)
        {
            qDebug() << "MY ALIEN MOTHER SHIP GOT HIT";
            ++alienMotherShipHit;
            qDebug() << alienMotherShipHit;
            update();
        }
    }
    if (alienMotherShipHit == 20) // if alienMotherShipHit is 5 ship destoryed and game WON!!!!
    {
        qDebug() << "MY ALIEN SHIP GOT Destroyed";
        shipsImage.load(":fire.png");
        painter->drawPixmap(left, top, width, height, shipsImage);

        QSound *shipExplosionFX = new QSound("explosion_2.wav", 0);
        shipExplosionFX->setLoops(1);
        shipExplosionFX->play();

        update();
        //ball->loadEndStory(this->scene());     // call function to load the level 2 story screen
    }
}

// the bounding rectangle of the object for collision detection
QRectF AlienMotherShip::boundingRect() const
{
    return QRectF(178, 260, 378, 96);
}

// gets Ships horizontal position
int AlienMotherShip::getShipPosX()
{
    return left;
}

// gets Ships horizontal position
int AlienMotherShip::getShipPosY()
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
