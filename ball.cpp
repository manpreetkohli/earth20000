/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Ball.cpp: creates the ball that bounces around inside the level
 *
 */

// include necessary files
#include "ball.h"
#include <QPainter>
#include <QDebug>

#include <iostream>
#include "levelOne.h"
#include "levelTwo.h"

// constructor
Ball::Ball()
{

    ballImage.load(":soccer.png");       // load an image for the ball
    ballImage.load(":cricketball.png");     // load an image for the ball

    directionX = 1;                         // set the X-axis increment for the movement
    directionY = -1;                        // set the Y-axis increment for the movement
    positionX = 0;                          // initial X coordinate of the ball
    positionY = 0;                          // initial Y coordinate of the ball
    setPos(positionX, positionY);           // set initial position of the ball
}

// destructor
Ball::~Ball() //Ivan
{
    qDebug() << "Destructor";
}

// function that paints the ball below the loaded image
void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->drawEllipse(375, 625, 15, 15);
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

        QList<QGraphicsItem*> listOfCollidingItems = collidingItems();//ivan


      //  qDebug() << directionX;

       // qDebug() << "x direction";

       // qDebug() << directionY;

        //qDebug() << "Y direction";

 //   qDebug() << positionX;

 //      qDebug() << "x position";

   //   qDebug() << positionY;

    //    qDebug() << "Y position";


        // direction of ball (NE)
        if ( (directionX > 0) && (directionY < 0) )
        {
            ballDirection = 1;
        }

        // direction of ball (NW)
        else if ( (directionX < 0) && (directionY < 0) )
        {
            ballDirection = 2;
        }

        // direction of ball (SW)
        else if ((directionX < 0) && (directionY > 0))
        {
            ballDirection = 3;
        }

        // direction of ball (SE)
        else if ((directionX > 0) && (directionY > 0))
        {
            ballDirection = 4;
        }



        // make ball bounce around in the screen
       // directionX = 1;
        positionX+=directionX;
        positionY+=directionY;

        if ((positionX >= 360) || (positionX <= -380))
        {
            directionX = -directionX;
        }


     //   if ((!listOfCollidingItems.isEmpty()))//(positionY == -100)) //&& (listOfCollidingItems.isEmpty()) )
       // {
         //   qDebug() << "Should be easy ";
        //}

        // comment out the positionY >= 85 part to make it not
        // bounce back on hitting the bottom part of the screen
        if (positionY <= -630)
            directionY = -directionY;

        // if the ball went beyond the bottom of the screen
        if (positionY >= 85)
        {
            positionX = 0;                          // reset X coordinate to 0
            positionY = 0;                          // reset Y coordinate to 0
            setPos(positionX, positionY);           // set the coordinates to initial position
            directionX = rand()% 2 + 1;             // set the X-axis increment for the movement
            directionY = -1;                        // set the Y-axis increment for the movement
           // qDebug() << directionX;
        }


/**

    ball_tempX = ball_x;
    ball_tempY = ball_y;

    if (dir == 1 && ball_x > 5 && ball_y > 5)
    {
        if( ball_x == p1_x + 15 && ball_y >= p1_y && ball_y <= p1_y + 60)
        {
                  dir = rand()% 2 + 3;
         }

        else

         {
                 --ball_x;
                 --ball_y;
         }

    }

    else if (dir == 2 && ball_x > 5 && ball_y < 475)
    {

         if( ball_x == p1_x + 15 && ball_y >= p1_y && ball_y <= p1_y + 60)
        {
                  dir = rand()% 2 + 3;
         }
         else
         {
                 --ball_x;
                 ++ball_y;
         }

    }

    else if (dir == 3 && ball_x < 635 && ball_y > 5)
    {

         if( ball_x + 5 == p2_x && ball_y >= p2_y && ball_y <= p2_y + 60)
        {
                  dir = rand()% 2 + 1;
         }else
         {
                 ++ball_x;
                 --ball_y;
         }

    }

    else if (dir == 4 && ball_x < 635 && ball_y < 475)
    {

         if( ball_x + 5 == p2_x && ball_y >= p2_y && ball_y <= p2_y + 60)
        {
                  dir = rand()% 2 + 1;
         }
         else
         {
                 ++ball_x;
                 ++ball_y;
         }

    }

    else
    {

        if (dir == 1 || dir == 3)    ++dir;
        else if (dir == 2 || dir == 4)    --dir;

    }

*/


        // Ivan
        // If ball collides with Ship then ball bounces
        if ((!listOfCollidingItems.isEmpty() && ((positionY <= 15) && (positionY >= 0))) || (!listOfCollidingItems.isEmpty() && ((positionY <= -100) && (positionY >= -600))) )
        {
            if (ballDirection == 4) //Ball traveling SE
            {

                //switch (

                directionX = directionX;
                directionY = -directionY;
                qDebug() << ballDirection;
                qDebug() << "Ball hit ship traveling SE";

            }

            else if (ballDirection == 3) //Ball traveling SW
            {
                directionX = directionX;
                directionY = -directionY;
                qDebug() << ballDirection;
                qDebug() << "Ball hit ship traveling SW";
            }

            else if (ballDirection == 2) //Ball traveling NW
            {

                //switch (

                directionX = directionX;
                directionY = -directionY;
                qDebug() << ballDirection;
                qDebug() << "Ball hit ship traveling NW";

            }

            else if (ballDirection == 1) //Ball traveling NE
            {

                //switch (

                directionX = directionX;
                directionY = -directionY;
                qDebug() << ballDirection;
                qDebug() << "Ball hit ship traveling NE";

            }



             //directionX = -directionX;
             //directionY = -directionY;
            // qDebug() << "Ball hit ship";
        }

      //  else if ((!listOfCollidingItems.isEmpty()) && (positionY < 18))
     //   {
     //       directionX = -directionX;
    //    }


        // set the new position of the ball
        setPos(positionX,positionY);
}


