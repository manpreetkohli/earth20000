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
#include "spaceship.h"


class Ball : public QGraphicsItem
{
    private:
        SpaceShip *playersShip;
        //QPushButton *cont;
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
        void loadStoryLevel4(QGraphicsScene *scene);
        //void loadStoryLevel3(QGraphicsScene *scene);
        //QPushButton *cont;
        bool visibleFound;
        SleeperThread *t;
        //int count;
        //int count;
    public:
        Ball(SpaceShip *ship);
        void moveX(int amount);
        qreal directionX, directionY, positionX, positionY, ballDirection;
        qreal viewWidth, viewHeight, width, height, shipXPosition;
        int score, hasPowerup, multipleBalls;
        long timer;
        double factor;
        ~Ball();
        void setShipPositon (int pos);
        void setXSpeed(int factor);
        void setYSpeed(int factor);
        bool posXDir;
        bool posYDir;
        bool rightEdge;
        bool leftEdge;
        bool topEdge;
        bool spaceshipHit;
};

#endif // BALL_H

