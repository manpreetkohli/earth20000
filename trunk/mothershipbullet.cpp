#include "mothershipbullet.h"
#include <QPainter>
#include <QDebug>
#include <iostream>
#include "constants.h"

// constructor
MotherShipBullet::MotherShipBullet()
{
    qDebug() << "Mother Ship Bullet constructor";
    bulletImage.load(":enemyBullet.png");
    directionX = 0;                         // set the X-axis increment for the movement
    directionY = 2;                        // set the Y-axis increment for the movement
    positionX = 0;                          // initial X coordinate of the ball
    positionY = 0;                          // initial Y coordinate of the ball
    width = 30;
    height = 30;
    setPos(positionX, positionY);           // set initial position of the ball
}

// destructor
MotherShipBullet::~MotherShipBullet()
{
    qDebug() << "Mother Ship Bullet Destructor";
}

// creates the mother ship bullet
void MotherShipBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(325, -110, width, height, bulletImage);
}

// Define the bounding rectangle of the object for collision detection
QRectF MotherShipBullet::boundingRect() const
{
  return QRectF(325,-110, width,height);
}

void MotherShipBullet::setBulletPosition (int posX, int posY)
{
    positionX = posX;
    positionY = posY;
}

// function to add motion to the ball inside the board
void MotherShipBullet::advance(int phase)
{
    if(!phase) return;

    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();//ivan


    if (!listOfCollidingItems.isEmpty())
    {
        if(listOfCollidingItems.first()->type() == ID_SPACESHIP)
        {
            qDebug() << "HITTING SPACE SHIP";
            positionX += 700;
        }
    }

    positionY+=directionY;

    // set the new position of the ball
    setPos(positionX,positionY);
}





