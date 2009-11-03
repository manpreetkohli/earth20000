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
        qreal viewWidth, viewHeight, width, height;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QRectF boundingRect() const;
        void setBounceBounds(qreal x, qreal y);
        void advance(int phase);

    public:
        Ball();

        ~Ball();

};

#endif // BALL_H
