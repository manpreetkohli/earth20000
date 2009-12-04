// include necessary files
#include <QPainter>
#include <QDebug>
#include <QtGui>
#include <iostream>
#include "ball.h"
#include "block.h"
#include "board.h"
#include "constants.h"
#include "form.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFive.h"
#include "powerup.h"

int Ball::scoreCount = 0;

/*!
  constructor
 */
Ball::Ball(SpaceShip *ship)
{
    playersShip = ship;
    ballImage.load(":soccer.png");            // load an image for the ball
    ballImage.load(":cricketball.png");       // load an image for the ball
    factor = 0.25;
    directionX = 1.0;                         // set the X-axis increment for the movement
    directionY = -1.0;                        // set the Y-axis increment for the movement
    positionX = 0;                            // initial X coordinate of the ball
    positionY = 0;                            // initial Y coordinate of the ball
    posXDir = true;
    posYDir = true;
    setPos(positionX, positionY);             // set initial position of the ball
    counter = 0;                              // to keep track of the no. of blocks that have been destroyed
    t = new SleeperThread();
    scoreFont = new QFont();
    initializeScore();
    skip = false;
}

/*!
  destructor
  by Ivan
 */
Ball::~Ball()
{
    qDebug() << "Destructor";
    delete this;
}

/*!
  added by Manpreet Kohli.
  displays the score in the HUD
 */
void Ball::initializeScore()
{
    scoreFont ->setFamily("SansSerif");
    scoreFont ->setBold(true);
    scoreFont ->setPointSize(24);
    scoreDisplay = playersShip->scene()->addText(QString::number(scoreCount, 10), *scoreFont);
    scoreDisplay->setDefaultTextColor(Qt::white);
    scoreDisplay->setOpacity(1.0);
    scoreDisplay->setPos(330, -10);
    scoreDisplay->show();
}

/*!
  added by Manpreet Kohli.
  function that paints the ball below the loaded image
 */
void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(375, 622, 20, 20, ballImage);
}

/*!
  added by Manpreet Kohli
  Define the bounding rectangle of the object for collision detection
 */
QRectF Ball::boundingRect() const
{
    return QRectF(375, 622, 20, 20);
}

/*!
  function set the players Ship position to be used in the physics portion in the advance function
 */
void Ball::setShipPositon(int pos)
{
    shipXPosition = pos;
}

/*!
  added by Manpreet Kohli
  generic function to load story screen right before level starts
 */
void Ball::loadStory(int levelNumber)
{
    if (levelNumber == 1)
        loadStoryScreen(this->scene(), 2, "    LEVEL 2");     // call function to load the level 2 story screen
    else if (levelNumber == 2)
        loadStoryScreen(this->scene(), 3, "    LEVEL 3");
    else if (levelNumber == 3)
        loadStoryScreen(this->scene(), 4, "FINAL LEVEL");
    else if (levelNumber == 4)
        loadStoryScreen(this->scene(), 5, "HOW THE FUCK DID YOU BEAT THIS GAME?");

    this->hide();                           // hide the ball
    this->scene()->removeItem(this);        // remove the ball from the scene
    playersShip->hide();                    // hide the spaceship
    counter = 0;
}

/*!
  added by Manpreet Kohli
  calls if the user has pressed period for cheat mode to skip to the next level
 */
void Ball::setSkip(bool value)
{
    skip = value;
}

/*!
  added by Manpreet Kohli
  returns the variable skip
 */
bool Ball::getSkip()
{
    return skip;
}

void Ball::setPositionX(qreal pos)
{
    positionX += pos;
}

/*!
  added by Manpreet Kohli
  function that removes a spawn from the HUD and sleeps for 3 secs to finish playing the respawning music
 */
void Ball::removeSpawn(int currentLives)
{
    if (currentLives == 3)
        this->scene()->removeItem(Constants::life3);        // remove a spawn from the HUD
    else if (currentLives == 2)
        this->scene()->removeItem(Constants::life2);        // remove a spawn from the HUD
    else if (currentLives == 1)
        this->scene()->removeItem(Constants::life1);        // remove a spawn from the HUD

    // play respawn music
    QSound *spawnSound = new QSound("start.wav", 0);
    spawnSound->setLoops(1);
    spawnSound->play();

    Constants::count--;                                     // decrement no. of lives remaining
    t->msleep(3000);                                        // sleep for 3 secs
}

/*!
  created and modified by all 3 of us
  function to add motion to the ball inside the board, check for cheat mode,
  check for collisions, check for powerups, and to check if the ball went
  beyond the bottom of the screen to respawn
 */
void Ball::advance(int phase)
{
    // added by Manpreet Kohli
    // check if cheat mode got activated, and if so, skip to the next level
    if (getSkip())
    {
        setSkip(false);
        if (Constants::levelNumber == 1)
            loadStory(1);
        else if (Constants::levelNumber == 2)
            loadStory(2);
        else if (Constants::levelNumber == 3)
            loadStory(3);
        else if (Constants::levelNumber == 4)
            loadStory(4);
    }

    int blockX, blockY;
    if (!phase) return;
    QList<QGraphicsItem *> hits = this->collidingItems(Qt::IntersectsItemBoundingRect);
    
    // Power up i.e. decrease the speed of the ball
    // Natraj Subramanian
    if(Constants::powerup == 1 && timer != 0)
    {
        Constants::timer->stop();
        Constants::timer->start(3);
        timer = timer + 10;
    }
    // Power down i.e. increase the speed of the ball
    // Natraj Subramanian
    if(Constants::powerup == 2 && timer != 0)
    {
        factor = 0.75;
        timer = timer + 10;
    }

    // Timer for how long each powerup should stay in effect
    // Once that timer value has been exceeded, reset the speed
    // back to normal
    // Natraj Subramanian
    if(Constants::powerup == 1 && timer > 25000)
    {
        factor = 0.25;
        Constants::timer->stop();
        Constants::timer->start(1);
        timer = 0;
    }
    if(Constants::powerup == 2 && timer > 10000)
    {
        factor = 0.25;
        Constants::timer->stop();
        Constants::timer->start(1);
        timer = 0;
    }

    // Ivan Collazo
    // checks to see if ball collides with something then does ball physics
    if (!hits.isEmpty())
    {
        if(hits.first()->type() == ID_SPACESHIP)
        {           
                 /*!******************************
                   BEGIN SPACESHIP COLLISION RULES
                  ********************************/
            // physics when the ball collides with top of Ship
            // Ivan Collazo
            if (positionY == 0)
            {                
                // Manpreet Kohli
                // play ship hit sound effect
                QSound *shipHit = new QSound("paddle.wav", 0);
                shipHit->setLoops(1);
                shipHit->play();

                if (ballDirection == 4)     //Ball traveling SE
                {
                    // physics for when the ball hits left most quarter portion of the ship
                    if ((positionX >= shipXPosition - 60) && (positionX <= shipXPosition - 21))
                    {
                        directionX = 1;     //directionX;
                        directionY = -1;    //-directionY;
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
                        directionX = 1;     //directionX;
                        directionY = -2;    //-directionY;
                    }

                    // physics for when the ball hits right most quarter portion of the ship
                    else if ((positionX >= shipXPosition + 21) && (positionX <= shipXPosition + 60))
                    {
                        directionX = 2;     // directionX + 1;
                        directionY = -1;    //-directionY;
                    }
                }
                else if (ballDirection == 3) //Ball traveling SW
                {
                    // physics for when the ball hits left most quarter portion of the ship
                    if ((positionX >= shipXPosition - 60) && (positionX <= shipXPosition - 21))
                    {
                        directionX = -2;    //directionX;
                        directionY = -1;    //directionY;
                    }

                    // physics for when the ball hits left quarter portion of the ship
                    else if ((positionX >= shipXPosition - 20) && (positionX <= shipXPosition))
                    {
                        directionX = -1;    //directionX;
                        directionY = -2;    //directionY;
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
            // physics when the ball collides portion near the event horizons of the ship
            // Ivan Collazo
            else if ((positionY <= 15) && (positionY >= 1) && ((positionX <= shipXPosition - 40) || (positionX >= shipXPosition - 40)))
            {
                // Manpreet Kohli
                // play ship hit sound effect
                QSound *shipHit = new QSound("paddle.wav", 0);
                shipHit->setLoops(1);
                shipHit->play();

                if (ballDirection == 4)     //Ball traveling SE
                {
                    directionX = -3;        //directionX;
                    directionY = -1;        //-directionY;
                }

                else if (ballDirection == 3) //Ball traveling SW
                {
                    directionX = 3;         //directionX;
                    directionY = -1;        //-directionY;
                }
            }

            // physics when the ball collides with the event horizon of ship
            // Ivan Collazo
            else if ((positionY > 15) && ((positionX == shipXPosition - 40) || (positionX == shipXPosition + 40)))
            {
                // Manpreet Kohli
                // play ship hit sound effect
                QSound *shipHit = new QSound("paddle.wav", 0);
                shipHit->setLoops(1);
                shipHit->play();

                if (ballDirection == 4)     //Ball traveling SE
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

                 /*!********************************
                    END SPACESHIP COLLISION RULES
                  **********************************/
        }
        else
        {
            if(hits.first()->type() == BLOCKID)
            {
                // Manpreet Kohli
                // play block collision sound effect
                QSound *blockHit = new QSound("brick.wav", 0);
                blockHit->setLoops(1);
                blockHit->play();

                // Get the x and y parameters of the block that the ball just
                // collided with and use it for calculating movement after
                // collision
                blockX = ((Block *)(((Block *)(hits.at(0)))->parentItem()))->getXPos();
                blockY = ((Block *)(((Block *)(hits.at(0)))->parentItem()))->getYPos();
                
                /*!******************************
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
                        scoreCount+=5;
                        break;
                    case 5:
                        ((Block *)(hits.at(0)))->setColor2(4);
                        scoreCount+=6;
                        break;
                    case 4:
                        ((Block *)(hits.at(0)))->setColor2(3);
                        scoreCount+=7;
                        break;
                    case 3:
                        ((Block *)(hits.at(0)))->setColor2(2);
                        scoreCount+=8;
                        break;
                    case 2:
                        ((Block *)(hits.at(0)))->setColor2(0);
                        scoreCount+=9;
                        break;
                    }

                    scoreDisplay->setPlainText(QString::number(scoreCount, 10));
                    ((Block *)(hits.at(0)))->show();                    
                }
                else
                {
                    ((Block *)(hits.at(0)))->setVisible(false);
                    scoreCount+=10;
                    scoreDisplay->setPlainText(QString::number(scoreCount, 10));

                    if(((Block *)(((Block *)(hits.at(0)))->parentItem()))->getPowerup() == 1)
                    {                        
                        Powerup *oneup = new Powerup;
                        oneup->setPosition(blockX, blockY);
                        oneup->setType(1);
                        oneup->setVisible(true);
                        this->scene()->addItem(oneup);
                        timer = 10;
                    }
                    if(((Block *)(((Block *)(hits.at(0)))->parentItem()))->getPowerup() == 2)
                    {
                        Powerup *anotherup = new Powerup;
                        anotherup->setPosition(blockX, blockY);
                        anotherup->setType(2);
                        anotherup->setVisible(true);
                        this->scene()->addItem(anotherup);
                        timer = 10;
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
                        directionX = directionX;
                        directionY = -directionY;
                        posXDir = true;
                        posYDir = false;
                    }
                    if(posXDir == false && posYDir == true)
                    {
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
                        directionX = -directionX;
                        directionY = directionY;
                        posXDir = true;
                        posYDir = true;
                    }
                    if(posXDir == false && posYDir == false)
                    {
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
                        directionX = -directionX;
                        directionY = directionY;
                        posXDir = false;
                        posYDir = true;
                    }
                    if(posXDir == true && posYDir == false)
                    {
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
                        directionX = directionX;
                        directionY = -directionY;
                        posXDir = true;
                        posYDir = true;
                    }
                    if(posXDir == false && posYDir == false)
                    {
                        directionX = directionX;
                        directionY = -directionY;
                        posXDir = false;
                        posYDir = true;
                    }
                }

                      /*!********************************
                             END BLOCK COLLISION RULES
                       **********************************/
            }

            // Manpreet Kohli
            // check to see how many blocks have been eliminated in each level,
            // and skip to the next level if all of them are done
            if (Constants::levelNumber == 1 && counter == 84)             // should be 84 for level 1
                loadStory(1);
            else if (Constants::levelNumber == 2 && counter == 132)       // should be 132 for level 2
                loadStory(2);
            else if (Constants::levelNumber == 3 && counter == 162)       // should be 162 for level 3
                loadStory(3);
            else if (Constants::levelNumber == 4 && counter == 148)       // should be 148 for level 4
                loadStory(4);
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
    positionX += directionX * factor;
    positionY += directionY * factor;

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

    // added by Manpreet Kohli
    // if the ball went beyond the bottom of the screen
    if (positionY >= 95)
    {
        // call function to remove a spawn if spawns remain
        if (Constants::count == 3)
            removeSpawn(3);
        else if (Constants::count == 2)
            removeSpawn(2);
        else if (Constants::count == 1)
            removeSpawn(1);

        // otherwise end the game
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

            // display an exit button
            QPushButton *exit = new QPushButton(temp->parentWidget());
            exit->setText("EXIT");
            exit->setGeometry(300, 600, 150, 40);
            exit->setFont(*font);
            exit->show();
            exit->setStyleSheet("background-color: rgba(255, 255, 255, 100);");

            Constants::timer->disconnect(this->scene(), SLOT(advance()));
            Constants::timer->stop();

            QObject::connect(exit, SIGNAL(clicked()), temp->parentWidget(), SLOT(close()));
        }

        // Reset all the values and parameters of the ball and disconnect
        // it from the timer so that it doesn't start moving immediately
        // after respawning
        positionX = playersShip->x();             // reset X coordinate to 0
        positionY = playersShip->y();             // reset Y coordinate to 0
        setPos(positionX, positionY);             // set the coordinates to initial position
        factor = 0.25;
        directionX = 1.0;                         // set the X-axis increment for the movement
        directionY = -1.0;                        // set the Y-axis increment for the movement
        Constants::powerup = 0;                   // Reset the powerup value
        posXDir = true;
        posYDir = true;

        // Manpreet Kohli
        // disconnect the timer with the ball and stop it
        Constants::timer->disconnect(this->scene(), SIGNAL(advance()));
        Constants::timer->stop();
    }

    // set the new position of the ball
    setPos(positionX,positionY);
}

/*!
  added by Manpreet Kohli
  function to hide the HUD and other info and load screen right before the level starts
 */
void Ball::loadStoryScreen(QGraphicsScene *scene, int level, QString levelNumber)
{
    // hide the spawns remaining
    if (Constants::life1 != NULL)
        Constants::life1->hide();
    if (Constants::life2 != NULL)
        Constants::life2->hide();
    if (Constants::life3 != NULL)
        Constants::life3->hide();

    Constants::levelInfo->hide();       // hide the HUD level info

    QFont *font = new QFont();
    font->setBold(true);
    font->setPointSize(80);
    if (level == 5)
        font->setPointSize(23);

    storyText = scene->addText(levelNumber, *font);

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
    if (level == 5)
        Constants::cont->setText("EXIT");
    Constants::cont->setGeometry(300, 600, 150, 40);
    Constants::cont->setFont(*font);
    Constants::cont->show();
    Constants::cont->setStyleSheet("background-color: rgba(255, 255, 255, 100);");

    // if the continue button is clicked on the screen, load the next level
    if (level == 2)
        QObject::connect(Constants::cont, SIGNAL(clicked()), this->scene()->views().at(0)->parentWidget(), SLOT(loadLevel2()));
    else if (level == 3)
        QObject::connect(Constants::cont, SIGNAL(clicked()), this->scene()->views().at(0)->parentWidget(), SLOT(loadLevel3()));
    else if (level == 4)
        QObject::connect(Constants::cont, SIGNAL(clicked()), this->scene()->views().at(0)->parentWidget(), SLOT(loadLevel4()));
    else if (level == 5)
        QObject::connect(Constants::cont, SIGNAL(clicked()), this->scene()->views().at(0)->parentWidget(), SLOT(close()));
}
