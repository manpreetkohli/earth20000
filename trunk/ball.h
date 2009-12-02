/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Ball.h: header file for the Ball class that creates the ball that bounces around inside the level
 *
 */

/**
  * Cleaned up December 02, 2009 by Natraj Subramanian
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
        bool skip;
        bool getSkip();

        QPixmap ballImage;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QRectF boundingRect() const;
        void setBounceBounds(qreal x, qreal y);
        void advance(int phase);
        void disconnectTimerAndBall();
        int counter;

        SpaceShip *playersShip;
        void removeSpawn(int currentLives);
        void loadStory(int levelNumber);
        void loadStoryScreen(QGraphicsScene *scene, int level, QString levelNumber);

        QGraphicsTextItem *storyText;
        void loadStoryLevel2(QGraphicsScene *scene);
        void loadStoryLevel3(QGraphicsScene *scene);
        void loadStoryLevel4(QGraphicsScene *scene);
        void loadEndStory(QGraphicsScene *scene);

        bool visibleFound;
        SleeperThread *t;

    public:
        Ball(SpaceShip *ship);
        ~Ball();
        void moveX(int amount);
        void setShipPositon (int pos);
        void setXSpeed(int factor);
        void setYSpeed(int factor);

        void setSkip(bool value);
        qreal directionX, directionY, positionX, positionY, ballDirection;
        qreal viewWidth, viewHeight, width, height, shipXPosition;
        int score, hasPowerup, multipleBalls;
        long timer;
        double factor;
        bool posXDir;
        bool posYDir;

        void setPositionX(qreal pos);

};

#endif // BALL_H

