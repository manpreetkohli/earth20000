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
#include <QtGui>
#include "constants.h"


// constructor
Ball::Ball()
{
    count = 3;
    ballImage.load(":soccer.png");          // load an image for the ball
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

// function set the players Ship position to be used in the physics portion in the advance function
void Ball::setShipPositon(int pos)
{
    shipXPosition = pos;
}

// function to add motion to the ball inside the board
void Ball::advance(int phase)
{
    if(!phase) return;

    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();//ivan
    //qDebug() << directionX;
    //qDebug() << "x direction";
    //qDebug() << directionY;
    //qDebug() << "Y direction";
    //qDebug() << positionX;
    //qDebug() << "x position";
    //qDebug() << positionY;
    //qDebug() << "Y position";
    //qDebug() << ballDirection;

    // direction of ball (NE) // Ivan Collazo
    if ((directionX > 0) && (directionY < 0))
    {
        ballDirection = 1;
    }

    // direction of ball (NW) // Ivan Collazo
    else if ((directionX < 0) && (directionY < 0) )
    {
        ballDirection = 2;
    }

    // direction of ball (SW) // Ivan Collazo
    else if ((directionX < 0) && (directionY > 0))
    {
        ballDirection = 3;
    }

    // direction of ball (SE) // Ivan Collazo
    else if ((directionX > 0) && (directionY > 0))
    {
        ballDirection = 4;
    }

    // make ball bounce around in the screen
    positionX+=directionX;
    positionY+=directionY;

    // ball bounces off the left and right side of the screen
    if ((positionX >= 360) || (positionX <= -380))
    {
        directionX = -directionX;
    }

    // ball bounces off the top part of the screen
    if (positionY <= -630)
    {
        directionY = -directionY;
    }

    // if the ball went beyond the bottom of the screen
    if (positionY >= 85)
    {
        if (count == 3)
        {
            this->scene()->removeItem(Constants::life3);
            count--;
            QSound *spawnSound = new QSound("start.wav", 0);
            spawnSound->setLoops(1);
            spawnSound->play();

        }

        else if (count == 2)
        {
            this->scene()->removeItem(Constants::life2);
            count--;
            QSound *spawnSound = new QSound("start.wav", 0);
            spawnSound->setLoops(1);
            spawnSound->play();

        }

        else if (count == 1)
        {
            this->scene()->removeItem(Constants::life1);
            count--;
            QSound *spawnSound = new QSound("start.wav", 0);
            spawnSound->setLoops(1);
            spawnSound->play();
        }


        else if (count == 0)
        {
            // add game over logic
            QFont *font = new QFont();

            font->setBold(true);
            font->setPointSize(25);


            QSound *gameover = new QSound("gameover.wav", 0);
            gameover->setLoops(1);
            gameover->play();


            QGraphicsTextItem *gameOver = this->scene()->addText(QString("GAME OVER"), *font);
            gameOver->setDefaultTextColor(Qt::cyan);
            gameOver->setOpacity(0.8);
            gameOver->setPos(300, 200);

            this->scene()->removeItem(this);
        }

        positionX = 0;                          // reset X coordinate to 0
        positionY = 0;                          // reset Y coordinate to 0
        setPos(positionX, positionY);           // set the coordinates to initial position
        directionX = 1;                         // set the X-axis increment for the movement
        directionY = -1;                        // set the Y-axis increment for the movement
    }

    // Ivan Collazo
    // checks to see if ball collides with something then does ball physics
    if (!listOfCollidingItems.isEmpty())
    {


        // physics when the ball collides with top of Ship // Ivan Collazo
        if (positionY == 0)
        {
            QSound *shipHit = new QSound("paddle.wav", 0);
            shipHit->setLoops(1);
            shipHit->play();

            if (ballDirection == 4) //Ball traveling SE
            {
                // physics for when the ball hits left most quarter portion of the ship
                if ((positionX >= shipXPosition - 60) && (positionX <= shipXPosition - 21))
                {
                    directionX = 1;  //directionX;
                    directionY = -1; //-directionY;
                }

                // physics for when the ball hits left quarter portion of the ship
                else if ((positionX >= shipXPosition - 20) && (positionX <= shipXPosition))
                {
                    directionX = 1;     //directionX;
                    directionY = -2;    //-directionY;
                }

                // physics for when the ball hits right quarter portion of the ship
                else if ((positionX >= shipXPosition) && (positionX <= shipXPosition + 20))
                {
                    directionX = 1; //directionX;
                    directionY = -2;//-directionY;
                }

                // physics for when the ball hits right most quarter portion of the ship
                else if ((positionX >= shipXPosition + 21) && (positionX <= shipXPosition + 60))
                {
                    directionX = 2;// directionX + 1;
                    directionY = -1;//-directionY;
                }
            }

            else if (ballDirection == 3) //Ball traveling SW
            {
                // physics for when the ball hits left most quarter portion of the ship
                if ((positionX >= shipXPosition - 60) && (positionX <= shipXPosition - 21))
                {
                    directionX = -2; //directionX;
                    directionY = -1; //directionY;
                }

                // physics for when the ball hits left quarter portion of the ship
                else if ((positionX >= shipXPosition - 20) && (positionX <= shipXPosition))
                {
                    directionX = -1 ;//directionX;
                    directionY = -2;//directionY;
                }

                // physics for when the ball hits right quarter portion of the ship
                else if ((positionX >= shipXPosition) && (positionX <= shipXPosition + 20))
                {
                    directionX = -1;    //directionX;
                    directionY = -2;    //-directionY;
                }

                // physics for when the ball hits right most quarter portion of the ship
                else if ((positionX >= shipXPosition + 21) && (positionX <= shipXPosition + 60))
                {
                    directionX = -1;    //directionX;
                    directionY = -1;    //-directionY;
                }
            }
        }

        // physics when the ball collides portion near the event horizons of the ship // Ivan Collazo
        else if ((positionY <= 15) && (positionY >= 1) && ((positionX <= shipXPosition - 40) || (positionX >= shipXPosition - 40)))
        {
            QSound *shipHit = new QSound("paddle.wav", 0);
            shipHit->setLoops(1);
            shipHit->play();

            if (ballDirection == 4) //Ball traveling SE
            {
                directionX = -3;  //directionX;
                directionY = -1; //-directionY;
            }

            else if (ballDirection == 3) //Ball traveling SW
            {
                directionX = 3;  //directionX;
                directionY = -1; //-directionY;
            }
        }

        // physics when the ball collides with the event horizon of ship // Ivan Collazo
        else if ((positionY > 15) && ((positionX == shipXPosition - 40) || (positionX == shipXPosition + 40)))
        {
            QSound *shipHit = new QSound("paddle.wav", 0);
            shipHit->setLoops(1);
            shipHit->play();

            if (ballDirection == 4) //Ball traveling SE
            {
                directionX = -6;
                directionY = 6;
            }

            else if (ballDirection == 3) //Ball traveling SW
            {
                directionX = 6;
                directionY = 6;
            }
        }

        /**
            // physics when collides with blocks or any object above the ship
            else if (positionY <= -40)
            {
                if (ballDirection == 1) //Ball traveling NE
                {
                    qDebug() << directionX;
                    qDebug() << directionY;
                    qDebug() << "X and Y Direction BEFORE";
                    qDebug() << "HIT BLOCK GOING NE";
                    directionX = directionX;
                    directionY = -directionY;

                    qDebug() << directionX;
                    qDebug() << directionY;
                    qDebug() << "X and Y Direction AFTER";

                }

                else if (ballDirection == 2) //Ball traveling NW
                {
                   // qDebug() << "HIT BLOCK GOING NW";
                    directionX = directionX;
                     directionY = -directionY;
                }

                else if (ballDirection == 3) //Ball traveling SW
                {
                    qDebug() << "HIT BLOCK GOING SW";
                  //  directionX = directionX;
                  //  directionY = -directionY;
                }

                else if (ballDirection == 4) //Ball traveling SE
                {
                    qDebug() << "HIT BLOCK GOING SE";
                  //  directionX = directionX;d
                   // directionY = -directionY;
                }
             }*/
    }

    // set the new position of the ball
    setPos(positionX,positionY);
}
