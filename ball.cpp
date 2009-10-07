#include "ball.h"

#include <QPainter>

Ball::Ball()
{

    ballImage.load(":soccer.png");
    directionX = 1;
    directionY = -1;

    positionX = 0;
    positionY = 0;
    setPos(positionX, positionY);

}


void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    painter->drawEllipse(375, 625, 15, 15);
    painter->drawPixmap(375, 625, 20, 20, ballImage);

}

// Define the bounding rectangle of the object for collision detection
QRectF Ball::boundingRect() const
{
     return QRectF(375, 625, 20, 20);
}


void Ball::setBounceBounds(qreal x, qreal y)
{
    bounceBoundsX = x;
    bounceBoundsY = y;
}

void Ball::advance(int phase)
{
        if(!phase) return;

        // make ball bounce around in the screen
        positionX+=directionX;
        positionY+=directionY;
        if ((positionX >= 360) || (positionX <= -380))
            directionX = -directionX;

        // comment out the positionY >= 85 part to make it not
        // bounce back on hitting the bottom part of the screen
        if ((positionY >= 85) || (positionY <= -630))
            directionY = -directionY;

        setPos(positionX,positionY);
}
