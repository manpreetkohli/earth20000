#include "alienshipbullet.h"
#include <QPainter>
#include <QDebug>
#include <iostream>
#include "constants.h"

AlienShipBullet::AlienShipBullet()
{
    bulletImage.load(":motherShipBullet.png");
    directionX = 0;                         // set the X-axis increment for the movement
    directionY = 3;                        // set the Y-axis increment for the movement
    positionX = 0;                          // initial X coordinate of the ball
    positionY = 0;                          // initial Y coordinate of the ball
    width = 20;
    height = 20;
    qDebug() << "Alien bullet Constructor" ;
  //  setPos(positionX, positionY);           // set initial position of the ball
}

AlienShipBullet::~AlienShipBullet()
{
    qDebug() << "Destructor";
}

void AlienShipBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->drawRect(320, -340,20,20);
    painter->drawPixmap(360, -340, width, height, bulletImage);
}

// Define the bounding rectangle of the object for collision detection
QRectF AlienShipBullet::boundingRect() const
{
  return QRectF(360, -340, width, height);
}

void AlienShipBullet::setShipPosition (int pos)
{
    shipXPosition = pos;
    positionX = shipXPosition;
}

void AlienShipBullet::setBulletPosition (int posX, int posY)
{
    positionX = posX;
    positionY = posY;
}

// function to add motion to the ball inside the board
void AlienShipBullet::advance(int phase)
{
    if(!phase) return;

    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();//ivan

    if (!listOfCollidingItems.isEmpty())
    {
        if(listOfCollidingItems.first()->type() == ID_SPACESHIP)
        {
            qDebug() << "HITTING SPACE SHIP";
            this->scene()->removeItem(this);
        }
    }

    positionY+=directionY;

    // set the new position of the ball
    setPos(positionX,positionY);

   if (positionY > 1050)
    {
       qDebug() << " GONE";
        this->scene()->removeItem(this);
    }
}
