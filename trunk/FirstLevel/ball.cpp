#include "ball.h"

#include <QPainter>

Ball::Ball(qreal width, qreal height)
{


    ballImage.load(":cricketball.jpg");
    directionX = 1;
    directionY = -1;
    bounceBoundsX = 0;
    bounceBoundsY = 0;
//    positionX = rand()%200; positionY=rand()%100;

    positionX = 400;
    positionY = 725;
  //  setPos(positionX, positionY);

 //   setFlag(QGraphicsItem::ItemIsMovable, true);



}


void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{



    painter->drawEllipse(-22, 250, 15, 15);


    painter->drawPixmap(-22, 250, 20, 20, ballImage);

}

// Define the bounding rectangle of the object for collision detection
QRectF Ball::boundingRect() const
{


     return QRectF(-20, 250, 20, 20);


//    return QRectF(-20, 0, 20, 20);
}


void Ball::setBounceBounds(qreal x, qreal y)
{
    bounceBoundsX = x;
    bounceBoundsY = y;

}

void Ball::advance(int phase)
{
        if(!phase) return;
//        if (!animated) return;

        // make ball bounce around in the screen
        positionX+=directionX;
        positionY+=directionY;
        if ((positionX >= bounceBoundsX) || (positionX <= 0))
            directionX = -directionX;

        // comment out the positionY >= bounceBoundsY part to make it not 
        // bounce back on hitting the bottom part of the screen
        if ((positionY >= bounceBoundsY) || (positionY <= 0))
            directionY = -directionY;

        setPos(positionX,positionY);
//        rotateAngle++;

}
