/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Ball.cpp: creates the ball that bounces around inside the level
 *
 * Ball motion originally coded by Manpreet Kohli and Ivan Collazo.
 * Later modified by Natraj Subramanian for the use of powerups
 *
 * Block collision detection and reactive movement coded by Natraj
 * Subramanian
 *
 * Powerups by Natraj Subramanian
 *
 */


#ifndef BALL_H
#define BALL_H

#include "sleeperthread.h"
#include "spaceship.h"

class Ball : public QGraphicsItem
{
    private:
        QGraphicsTextItem *scoreDisplay;
        qreal directionX, directionY, positionX, positionY, ballDirection;
        qreal shipXPosition;
        static int scoreCount;
        bool skip;
        bool getSkip();
        QFont *scoreFont;
        QPixmap ballImage;
        int counter;
        SpaceShip *playersShip;
        QGraphicsTextItem *storyText;
        SleeperThread *t;
        long timer;
        double factor;
        bool posXDir;
        bool posYDir;

        void initializeScore();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QRectF boundingRect() const;
        void advance(int phase);
        void removeSpawn(int currentLives);
        void loadStory(int levelNumber);
        void loadStoryScreen(QGraphicsScene *scene, int level, QString levelNumber);

    public:
        Ball(SpaceShip *ship);
        ~Ball();
        void setPositionX(qreal pos);
        void setShipPositon (int pos);
        void setSkip(bool value);
};

#endif // BALL_H

