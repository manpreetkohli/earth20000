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
#include "block.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFive.h"
#include <QtGui>
#include "constants.h"
#include "powerup.h"
#include "form.h"
#include "board.h"

int Constants::scoreCount;

// constructor
Ball::Ball(SpaceShip *ship)
{
    playersShip = ship;
    //count = 3;
    ballImage.load(":soccer.png");          // load an image for the ball
    ballImage.load(":cricketball.png");     // load an image for the ball
    factor = 0.25;
    directionX = 1.0;                         // set the X-axis increment for the movement
    directionY = -1.0;                        // set the Y-axis increment for the movement
    positionX = 0;                          // initial X coordinate of the ball
    positionY = 0;                          // initial Y coordinate of the ball
    posXDir = true;
    posYDir = true;
    rightEdge = false;
    leftEdge = false;
    topEdge = false;
    setPos(positionX, positionY);           // set initial position of the ball
    Constants::scoreCount = 0;
    counter = 0;
    t = new SleeperThread();    
    timer = 0;
    multipleBalls = 0;
}


// destructor
Ball::~Ball() //Ivan
{
    qDebug() << "Destructor";
}


// function that paints the ball below the loaded image
void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
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
    int blockX, blockY;
    if(!phase) return;
    QList<QGraphicsItem *> hits = this->collidingItems(Qt::IntersectsItemBoundingRect);
    
    // Power up i.e. decrease the speed of the ball
    if(Constants::powerup == 1 && timer < 3000)
    {
        factor = 0.125;
        timer = timer + 100;
        //qDebug() << "Timer (slow): " << timer;
    }
    // Power down i.e. increase the speed of the ball
    if(Constants::powerup == 2 && timer < 3000)
    {
        factor = 0.50;
        timer = timer + 100;
        //qDebug() << "Timer (speed): " << timer;
    }

    if(timer == 3000)
    {
        factor = 0.25;
        timer = 0;
    }

    //qDebug() << "Factor: " << factor;

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
                        directionX = -1;//directionX;
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

            /**********************************
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

                blockX = ((Block *)(((Block *)(hits.at(0)))->parentItem()))->getXPos();
                blockY = ((Block *)(((Block *)(hits.at(0)))->parentItem()))->getYPos();
                
                qDebug() << "Score: " << Constants::scoreCount;

                /**********************************
                   BEGIN BLOCK COLLISION RULES
                 ********************************/
                if(((Block *)(hits.at(0)))->getColor2() != 0)
                {
                    ((Block *)(hits.at(0)))->setVisible(false);
                    ((Block *)(hits.at(0)))->setColor1(1);

                    switch(((Block *)(hits.at(0)))->getColor2())
                    {
                    case 6:
                        ((Block *)(hits.at(0)))->setColor2(5);
                        Constants::scoreCount+=5;

                        break;
                    case 5:
                        ((Block *)(hits.at(0)))->setColor2(4);
                        Constants::scoreCount+=6;
                        break;
                    case 4:
                        ((Block *)(hits.at(0)))->setColor2(3);
                        Constants::scoreCount+=7;
                        break;
                    case 3:
                        ((Block *)(hits.at(0)))->setColor2(2);
                        Constants::scoreCount+=8;
                        break;
                    case 2:
                        ((Block *)(hits.at(0)))->setColor2(0);
                        Constants::scoreCount+=9;
                        break;
                    }

                    ((Block *)(hits.at(0)))->show();                    
                }
                else
                {
                    ((Block *)(hits.at(0)))->setVisible(false);
                    Constants::scoreCount+=10;

                    if(((Block *)(((Block *)(hits.at(0)))->parentItem()))->getPowerup() == 1)
                    {
                        qDebug() << "My type is: " << ((Block *)(((Block *)(hits.at(0)))->parentItem()))->getPowerup();
                        Powerup *oneup = new Powerup;
                        oneup->setPosition(blockX, blockY);
                        oneup->setType(1);
                        oneup->setVisible(true);
                        this->scene()->addItem(oneup);
                        qDebug() << "I slow down";
                        timer = 0;
                    }
                    if(((Block *)(((Block *)(hits.at(0)))->parentItem()))->getPowerup() == 2)
                    {
                        qDebug() << "My type is: " << ((Block *)(((Block *)(hits.at(0)))->parentItem()))->getPowerup();
                        Powerup *anotherup = new Powerup;
                        anotherup->setPosition(blockX, blockY);
                        anotherup->setType(2);
                        anotherup->setVisible(true);
                        this->scene()->addItem(anotherup);
                        qDebug() << "I speed up";
                        timer = 0;
                    }

                    counter++;
                }
                                
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
                        //qDebug() << "I entered 1";
                        directionX = directionX;
                        directionY = -directionY;
                        posXDir = true;
                        posYDir = false;
                    }
                    if(posXDir == false && posYDir == true)
                    {
                        //qDebug() << "I entered 2";
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
                        //qDebug() << "I entered 5";
                        directionX = -directionX;
                        directionY = directionY;
                        posXDir = true;
                        posYDir = true;
                    }
                    if(posXDir == false && posYDir == false)
                    {
                        //qDebug() << "I entered 6";
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
                        //qDebug() << "I entered 9";
                        directionX = -directionX;
                        directionY = directionY;
                        posXDir = false;
                        posYDir = true;
                    }
                    if(posXDir == true && posYDir == false)
                    {
                        //qDebug() << "I entered 10";
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
                        //qDebug() << "I entered 13";
                        directionX = directionX;
                        directionY = -directionY;
                        posXDir = true;
                        posYDir = true;
                    }
                    if(posXDir == false && posYDir == false)
                    {
                        //qDebug() << "I entered 14";
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

            if (Constants::levelNumber == 1 && counter == 1)        // should be 84 for level 1
            {                
                this->hide();                       // hide the ball
                loadStoryLevel2(this->scene());     // call function to load the level 2 story screen
                this->scene()->removeItem(this);    // remove the ball from the scene
                playersShip->hide();     // hide the spaceship
                qDebug() << "level one done";
                counter = 0;
            }

            else if (Constants::levelNumber == 2 && counter == 1)       // should be 132 for level 2
            {
                this->hide();                       // hide the ball
                loadStoryLevel3(this->scene());     // call function to load the level 2 story screen
                this->scene()->removeItem(this);    // remove the ball from the scene
                playersShip->hide();     // hide the spaceship
                qDebug() << "level two done";
                counter = 0;
            }


            else if (Constants::levelNumber == 3 && counter == 1)       // should be 262 for level 3
            {
                this->hide();                       // hide the ball
                loadStoryLevel4(this->scene());     // call function to load the level 2 story screen
                this->scene()->removeItem(this);    // remove the ball from the scene
                playersShip->hide();     // hide the spaceship
                qDebug() << "level three done";
                counter = 0;
            }


//            else if (Constants::levelNumber == 5 && counter == 132)       // should be 132 for level 2
//            {
//                this->hide();                       // hide the ball
//                loadStoryLevel3(this->scene());     // call function to load the level 2 story screen
//                this->scene()->removeItem(this);    // remove the ball from the scene
//                playersShip->hide();     // hide the spaceship
//                qDebug() << "level two done";
//                counter = 0;
//            }

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
    positionX+=directionX * factor;
    positionY+=directionY * factor;

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
    if (positionY >= 95)
    {
        if (Constants::count == 3)
        {
            this->scene()->removeItem(Constants::life3);        // remove a spawn from the HUD
            Constants::count--;                                 // decrement no. of lives remaining

            // play respawn music
            QSound *spawnSound = new QSound("start.wav", 0);
            spawnSound->setLoops(1);
            spawnSound->play();

            t->msleep(3000);
        }
        else if (Constants::count == 2)
        {
            this->scene()->removeItem(Constants::life2);        // remove a spawn from the HUD
            Constants::count--;                                 // decrement no. of lives remaining

            // play respawn music
            QSound *spawnSound = new QSound("start.wav", 0);
            spawnSound->setLoops(1);
            spawnSound->play();

            t->msleep(3000);
        }
        else if (Constants::count == 1)
        {
            this->scene()->removeItem(Constants::life1);        // remove a spawn from the HUD
            Constants::count--;                                 // decrement no. of lives remaining

            // play respawn music
            QSound *spawnSound = new QSound("start.wav", 0);
            spawnSound->setLoops(1);
            spawnSound->play();

            t->msleep(3000);
        }
        else if (Constants::count == 0)
        {
            // add game over logic
            QGraphicsView *temp  = this->scene()->views().at(0);

            this->scene()->deleteLater();

            QGraphicsScene *gameOverScene = new QGraphicsScene;

            temp->setScene(gameOverScene);

            gameOverScene->setSceneRect(0, 0, temp->geometry().width() - 5, temp->geometry().height() - 5);       // set dimensions of the scene

            QFont *font = new QFont();
            font->setBold(true);
            font->setPointSize(60);

            // play game over music
            QSound *gameover = new QSound("gameover.wav", 0);
            gameover->setLoops(1);
            gameover->play();

            // display game over message
            QGraphicsTextItem *gameOver = gameOverScene->addText(QString("GAME OVER"), *font);
            gameOver->setDefaultTextColor(Qt::cyan);
            gameOver->setOpacity(0.8);
            gameOver->setPos(150, 200);

            font->setPointSize(13);
            font->setWeight(75);

            QPushButton *exit = new QPushButton(temp->parentWidget());
            exit->setText("EXIT");
            exit->setGeometry(300, 600, 150, 40);
            exit->setFont(*font);
            exit->show();
            exit->setStyleSheet("background-color: rgba(255, 255, 255, 100);");

            QObject::connect(exit, SIGNAL(clicked()), temp->parentWidget(), SLOT(close()));
        }

        positionX = 0;                          // reset X coordinate to 0
        positionY = 0;                          // reset Y coordinate to 0
        setPos(positionX, positionY);           // set the coordinates to initial position
        factor = 0.25;
        directionX = 1.0;                         // set the X-axis increment for the movement
        directionY = -1.0;                        // set the Y-axis increment for the movement
        Constants::powerup = 0;
        posXDir = true;
        posYDir = true;
        rightEdge = false;
        leftEdge = false;
        topEdge = false;
    }

    // set the new position of the ball
    setPos(positionX,positionY);
}


// function to display the level 2 message
// hides ___________________
void Ball::loadStoryLevel2(QGraphicsScene *scene)
{
    // hide the spawns remaining
    if (Constants::life1 != NULL)
        Constants::life1->hide();

    if (Constants::life2 != NULL)
        Constants::life2->hide();

    if (Constants::life3 != NULL)
        Constants::life3->hide();

    Constants::levelInfo->hide();

    QFont *font = new QFont();
    font->setBold(true);
    font->setPointSize(80);

    storyText = scene->addText("    LEVEL 2", *font);
    storyText->setDefaultTextColor(Qt::blue);
    storyText->setPos(40, 70);
    storyText->show();

    // play the start level music
    QSound *intro = new QSound("intro.wav", 0);
    intro->setLoops(1);
    intro->play();

    Constants::lives->hide();

    font->setPointSize(13);
    font->setBold(true);
    font->setWeight(75);

    Constants::cont = new QPushButton(scene->views().at(0)->parentWidget());
    Constants::cont->setText("CONTINUE");
    Constants::cont->setGeometry(300, 600, 150, 40);
    Constants::cont->setFont(*font);
    Constants::cont->show();
    Constants::cont->setStyleSheet("background-color: rgba(255, 255, 255, 100);");

    // if the continue button is clicked on the screen, load the second level
    QObject::connect(Constants::cont, SIGNAL(clicked()), this->scene()->views().at(0)->parentWidget(), SLOT(loadLevel2()));
}


// function to display the level 2 message
// hides ___________________
void Ball::loadStoryLevel3(QGraphicsScene *scene)
{
    // hide the spawns remaining
    if (Constants::life1 != NULL)
        Constants::life1->hide();

    if (Constants::life2 != NULL)
        Constants::life2->hide();

    if (Constants::life3 != NULL)
        Constants::life3->hide();

    Constants::levelInfo->hide();

    QFont *font = new QFont();
    font->setBold(true);
    font->setPointSize(80);

    storyText = scene->addText("    LEVEL 3", *font);
    storyText->setDefaultTextColor(Qt::blue);
    storyText->setPos(40, 70);
    storyText->show();

    // play the start level music
    QSound *intro = new QSound("intro.wav", 0);
    intro->setLoops(1);
    intro->play();

    Constants::lives->hide();

    font->setPointSize(13);
    font->setBold(true);
    font->setWeight(75);

    Constants::cont = new QPushButton(scene->views().at(0)->parentWidget());
    Constants::cont->setText("CONTINUE");
    Constants::cont->setGeometry(300, 600, 150, 40);
    Constants::cont->setFont(*font);
    Constants::cont->show();
    Constants::cont->setStyleSheet("background-color: rgba(255, 255, 255, 100);");

    // if the continue button is clicked on the screen, load the third level
     QObject::connect(Constants::cont, SIGNAL(clicked()), this->scene()->views().at(0)->parentWidget(), SLOT(loadLevel3()));
}




// function to display the level 2 message
// hides ___________________
void Ball::loadStoryLevel4(QGraphicsScene *scene)
{
    // hide the spawns remaining
    if (Constants::life1 != NULL)
        Constants::life1->hide();

    if (Constants::life2 != NULL)
        Constants::life2->hide();

    if (Constants::life3 != NULL)
        Constants::life3->hide();

    Constants::levelInfo->hide();

    QFont *font = new QFont();
    font->setBold(true);
    font->setPointSize(80);

    storyText = scene->addText("    FINAL LEVEL", *font);
    storyText->setDefaultTextColor(Qt::blue);
    storyText->setPos(40, 70);
    storyText->show();

    // play the start level music
    QSound *intro = new QSound("intro.wav", 0);
    intro->setLoops(1);
    intro->play();

    Constants::lives->hide();

    font->setPointSize(13);
    font->setBold(true);
    font->setWeight(75);

    Constants::cont = new QPushButton(scene->views().at(0)->parentWidget());
    Constants::cont->setText("CONTINUE");
    Constants::cont->setGeometry(300, 600, 150, 40);
    Constants::cont->setFont(*font);
    Constants::cont->show();
    Constants::cont->setStyleSheet("background-color: rgba(255, 255, 255, 100);");

    // if the continue button is clicked on the screen, load the third level
    QObject::connect(Constants::cont, SIGNAL(clicked()), this->scene()->views().at(0)->parentWidget(), SLOT(loadLevel4()));
}




