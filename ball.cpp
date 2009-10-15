/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Ball.cpp: creates the ball that bounces around inside the level
 *
 */

// include the header file for this class
#include "ball.h"

// constructor
Ball::Ball()
{
    ballImage.load(":cricketball.jpg");     // load an image for the ball
    directionX = 1;                         // set the X-axis increment for the movement
    directionY = -1;                        // set the Y-axis increment for the movement
    positionX = 0;                          // initial X coordinate of the ball
    positionY = 0;                          // initial Y coordinate of the ball
    setPos(positionX, positionY);           // set initial position of the ball
}

// function that paints the ball below the loaded image
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

// function to add motion to the ball inside the board
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

        // set the new position of the ball
        setPos(positionX,positionY);
}
