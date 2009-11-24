#include "alienmothership.h"
#include <QPainter>
#include <QStyleOption>
#include <QDebug>
#include <QGraphicsView>
#include <QTimer>
#include <QtGui>
#include "mothershipbullet.h"

MotherShipBullet *shipBullet;

QTimer *timer = new QTimer();

AlienMotherShip::AlienMotherShip()
{
    shipsImage.load(":alienSpaceship.png");
    width = 390; //100
    height = 240; //60
    left = 170;  //325
    top = 260;   //620
    alienMotherShipHit = 0;
    //color = (Qt::red);
    qDebug() << "Constructor" ;
  //  setPos(0, 0);
    timer = new QTimer();       // create a new QTimer() instance
}

// destructor
AlienMotherShip::~AlienMotherShip()
{
    qDebug() << "Destructor" ;
}

// called whenever the AlienMotherShip needs to be drawn
void AlienMotherShip::paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // can later traverse to examine what collided with the character.
    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

    // connect the timer to the advance method inside the Ball class
//    QObject::connect(timer, SIGNAL(timeout()), this->scene(), SLOT(fire()));
        // painter->setBrush(color);
        //painter->drawEllipse(178,330,378,90);
       // painter->drawRect(178, 320, 378, 96);
        //painter->drawRect(304, 320, 126, 108);
        painter->drawPixmap(left, top, width, height, shipsImage);

    if (!listOfCollidingItems.isEmpty()) // checks to see if mothership has been hit and increments alienMotherShip hit.
    {
      //qDebug() << "MY ALIEN SHIP GOT HIT";
      ++alienMotherShipHit;
    }
    if (alienMotherShipHit == 5) // if alienMotherShipHit is 5 ship destoryed and game WON!!!!
    {
        qDebug() << "MY ALIEN SHIP GOT Destroyed";
       // shipsImage.load(":fire.png");
       // painter->drawPixmap(left, top, width, height, shipsImage);
       // update();
    }
}

// the bounding rectangle of the object for collision detection
QRectF AlienMotherShip::boundingRect() const
{
    return QRectF(178, 320, 378, 96);
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
    shipBullet->setBulletPosition(25, 480);
    this->scene()->addItem(shipBullet);
    qDebug() << " MOTHER SHIP FIRING ";
     // Set the timer to trigger every 3 ms.
    //timer->start(700);
}



