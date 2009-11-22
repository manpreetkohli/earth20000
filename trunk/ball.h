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
#include "sleeperthread.h"
#include <QtGui>


class Ball : public QGraphicsItem
{
    private:
        QPixmap ballImage;        
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QRectF boundingRect() const;
        void setBounceBounds(qreal x, qreal y);
        void advance(int phase);

        void disconnectTimerAndBall();

        int counter;


        QGraphicsTextItem *storyText;

        void loadStoryLevel2(QGraphicsScene *scene);
        void loadStoryLevel3(QGraphicsScene *scene);

        QPushButton *cont;

        bool visibleFound;

         SleeperThread *t;
        int count;
    public:
        Ball();
        void moveX(int amount);
        qreal directionX, directionY, positionX, positionY, ballDirection;
        qreal viewWidth, viewHeight, width, height, shipXPosition;
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
