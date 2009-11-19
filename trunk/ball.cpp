/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Ball.cpp: creates the ball that bounces around inside the level
 *
 */

// include necessary files
#include <QPainter>
#include <QDebug>
#include <iostream>
#include <QtGui>
#include "ball.h"
#include "block.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelFive.h"
#include "constants.h"
#include "form.h"
#include "board.h"

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
    posXDir = true;
    posYDir = true;
    rightEdge = false;
    leftEdge = false;
    topEdge = false;
    spaceshipHit = true;
    setPos(positionX, positionY);           // set initial position of the ball


    t = new SleeperThread();

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

void Ball::moveX(int amount)
{
    positionX = positionX + amount;
}

// function set the players Ship position to be used in the physics portion in the advance function
void Ball::setShipPositon(int pos)
{
    shipXPosition = pos;
}

// function to add motion to the ball inside the board
void Ball::advance(int phase)
{
    int blockX, blockY;
    
    if(!phase) return;
    
    QList<QGraphicsItem *> hits = this->collidingItems(Qt::IntersectsItemBoundingRect);
    
    // Ivan Collazo
    // checks to see if ball collides with something then does ball physics    
    if (!hits.isEmpty())
    {
        if(hits.first()->type() == ID_SPACESHIP)
        {
            /** ********************************
                   BEGIN SPACESHIP COLLISION RULES
                  ********************************/
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
                    
                    spaceshipHit = true;
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
                    
                    spaceshipHit = true;
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
            
            /** ********************************
                    END SPACESHIP COLLISION RULES
                  ********************************/
        }
        else
        {
            if(hits.first()->type() == BLOCKID)
            {
                QSound *blockHit = new QSound("brick.wav", 0);
                blockHit->setLoops(1);
                blockHit->play();
                
                // Copyright of Natraj Subramanian
                // I own you

                /** ********************************
                             BEGIN BLOCK COLLISION RULES
                          ********************************/               
                
                if(spaceshipHit == true)
                {
                    if(((Block *)(hits.at(0)))->getColor2() != 0)
                    {
                        ((Block *)(hits.at(0)))->setVisible(false);
                        ((Block *)(hits.at(0)))->setColor1(1);
                        ((Block *)(hits.at(0)))->setColor2(0);
                        ((Block *)(hits.at(0)))->show();
                    }
                    else
                    {
                        ((Block *)(hits.at(0)))->setVisible(false);
                    }

                    spaceshipHit = false;
                }
                else
                {
                    srand(time(NULL));
                    int temp = rand()%2;
                    if(temp == 1)
                    {
                        if(((Block *)(hits.at(0)))->getColor2() != 0)
                        {
                            ((Block *)(hits.at(0)))->setVisible(false);
                            ((Block *)(hits.at(0)))->setColor1(1);
                            ((Block *)(hits.at(0)))->setColor2(0);
                            ((Block *)(hits.at(0)))->show();
                        }
                        else
                        {
                            ((Block *)(hits.at(0)))->setVisible(false);
                        }
                    }
                }
                
                blockX = ((Block *)(((Block *)(hits.at(0)))->parentItem()))->getXPos();
                blockY = ((Block *)(((Block *)(hits.at(0)))->parentItem()))->getYPos();
                
                /*qDebug() << "Ball position X: " << positionX;
                qDebug() << "Ball position Y: " <<  positionY;
                qDebug() << "BlockX : " << blockX;
                qDebug() << "BlockY : " << blockY;
                qDebug() << "BlockX + OUTLINEW/2: " << blockX + OUTLINEW/2;
                qDebug() << "BlockX + OUTLINEW: " << blockX + OUTLINEW;
                qDebug() << "BlockY + OUTLINEH/2: " << blockY + OUTLINEH/2 << "\n";*/
                
                // When the point of impact is on the BOTTOM
                // end of the block. Y > blockY simply because the
                // Y axes is inverted in the scope of the game board
                // and hence, in reality, it is checking if the ball has
                // hit the bottom side of the block.
                if((positionX >= blockX - 19 &&
                    positionX <= blockX + 27) &&
                   positionY >= blockY + 25)
                {
                    if(posXDir == true && posYDir == true)
                    {
                        qDebug() << "I entered 1";
                        directionX = directionX;
                        directionY = -directionY;
                        posXDir = true;
                        posYDir = false;
                    }
                    if(posXDir == false && posYDir == true)
                    {
                        qDebug() << "I entered 2";
                        directionX = directionX;
                        directionY = -directionY;
                        posXDir = false;
                        posYDir = false;
                    }
                    
                }
                // If the ball hit the RIGHT SIDE of the block
                // Ball positionX is at the farther right end
                // and ball positionY is at the lower end of the block
                if(positionX >= blockX + 25 &&
                   (positionY <= blockY + 27 &&
                    positionY >= blockY - 21))
                {
                    if(posXDir == false && posYDir == true)
                    {
                        qDebug() << "I entered 5";
                        directionX = -directionX;
                        directionY = directionY;
                        posXDir = true;
                        posYDir = true;
                    }
                    if(posXDir == false && posYDir == false)
                    {
                        qDebug() << "I entered 6";
                        directionX = -directionX;
                        directionY = directionY;
                        posXDir = true;
                        posYDir = false;
                    }
                }               
                // If the ball hit the LEFT SIDE of the block
                // Ball positionX is at the farther right end
                // and ball positionY is at the lower end of the block
                if((positionX >= blockX - 21 &&
                    positionX <= blockX - 16) &&
                   (positionY <= blockY + 27 &&
                    positionY >= blockY - 21))
                {
                    if(posXDir == true && posYDir == true)
                    {
                        qDebug() << "I entered 9";
                        directionX = -directionX;
                        directionY = directionY;
                        posXDir = false;
                        posYDir = true;
                    }
                    if(posXDir == true && posYDir == false)
                    {
                        qDebug() << "I entered 10";
                        directionX = -directionX;
                        directionY = directionY;
                        posXDir = false;
                        posYDir = false;
                    }
                }               
                // If the ball hits the TOP side of the block
                // PositionY is calculated in such a way that there
                // is a bit of a standard deviation involved with the
                // actual impact point
                if((positionX >= blockX - 19 &&
                    positionX <= blockX + 27) &&
                   (positionY >= blockY - 21 &&
                    positionY <= blockY - 16))
                {
                    if(posXDir == true && posYDir == false)
                    {
                        qDebug() << "I entered 13";
                        directionX = directionX;
                        directionY = -directionY;
                        posXDir = true;
                        posYDir = true;
                    }
                    if(posXDir == false && posYDir == false)
                    {
                        qDebug() << "I entered 14";
                        directionX = directionX;
                        directionY = -directionY;
                        posXDir = false;
                        posYDir = true;
                    }

                }

                
                /** ********************************
                             END BLOCK COLLISION RULES
                      ********************************/
            }
        }
    }
    

    // direction of ball (NE) // Ivan Collazo
    if ((directionX > 0) && (directionY < 0))
    {
        ballDirection = 1;
        posXDir = true;
        posYDir = true;
    }
    // direction of ball (NW) // Ivan Collazo
    else if ((directionX < 0) && (directionY < 0) )
    {
        ballDirection = 2;
        posXDir = false;
        posYDir = true;
    }
    // direction of ball (SW) // Ivan Collazo
    else if ((directionX < 0) && (directionY > 0))
    {
        ballDirection = 3;
        posXDir = false;
        posYDir = false;
    }
    // direction of ball (SE) // Ivan Collazo
    else if ((directionX > 0) && (directionY > 0))
    {
        ballDirection = 4;
        posXDir = true;
        posYDir = false;
    }
    
    // Set the position parameters
    positionX+=directionX;
    positionY+=directionY;

    // ball bounces off the left and right side of the screen
    if ((positionX >= 360) || (positionX <= -380))
    {
        directionX = -directionX;
        posXDir = !(posXDir);
    }

    // ball bounces off the top part of the screen
    if (positionY <= -630)
    {
        directionY = -directionY;
        posYDir = !(posYDir);
    }

    // if the ball went beyond the bottom of the screen
    //    if (positionY >= 85)
    if (positionY >= 95)
    {
        if (count == 3)
        {
            this->scene()->removeItem(Constants::life3);
            count--;

            QSound *spawnSound = new QSound("start.wav", 0);
            spawnSound->setLoops(1);
            spawnSound->play();


            t->msleep(3000);


        }
        else if (count == 2)
        {
            this->scene()->removeItem(Constants::life2);
            count--;
            QSound *spawnSound = new QSound("start.wav", 0);
            spawnSound->setLoops(1);
            spawnSound->play();
            //QSound *spawnSound = new QSound("start.wav", 0);
            //spawnSound->setLoops(1);
            //spawnSound->play();

            t->msleep(3000);

        }
        else if (count == 1)
        {
            this->scene()->removeItem(Constants::life1);
            count--;
            QSound *spawnSound = new QSound("start.wav", 0);
            spawnSound->setLoops(1);
            spawnSound->play();
            //QSound *spawnSound = new QSound("start.wav", 0);
            //spawnSound->setLoops(1);
            //spawnSound->play();

            t->msleep(3000);
        }
        else if (count == 0)
        {
            // add game over logic
            QFont *font = new QFont();

            font->setBold(true);
            font->setPointSize(25);

            //QSound *gameover = new QSound("gameover.wav", 0);
            //gameover->setLoops(1);
            //gameover->play();

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
        posXDir = true;
        posYDir = true;
        rightEdge = false;
        leftEdge = false;
        topEdge = false;
        spaceshipHit = true;
    }

    // Ivan Collazo
    // checks to see if ball collides with something then does ball physics



    // set the new position of the ball
    setPos(positionX,positionY);
    
}
