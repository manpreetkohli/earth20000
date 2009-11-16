/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Ball.h: header file for the Ball class that creates the ball that bounces around inside the level
 *
 */

#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>


class Ball : public QGraphicsItem
{
    private:
        QPixmap ballImage;
        qreal directionX, directionY, positionX, positionY, ballDirection;
        qreal viewWidth, viewHeight, width, height, shipXPosition;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QRectF boundingRect() const;
        void setBounceBounds(qreal x, qreal y);
        void advance(int phase);


        int count;
    public:
        Ball();

        ~Ball();
        void setShipPositon (int pos);
        bool posXDir;
        bool posYDir;
        bool rightEdge;
        bool leftEdge;
        bool topEdge;
        bool spaceshipHit;
};

#endif // BALL_H
