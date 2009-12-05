/*!
*   Author: Ivan Collazo
*   File: spaceship.cpp
*   Date: 10/05/2009
*   This is .cpp file for spaceships in earth20000
*/

#include "spaceship.h"
#include "mothershipbullet.h"
#include "alienshipbullet.h"
#include "constants.h"
#include <QSound>

/*!
  constructor
 */
SpaceShip::SpaceShip()
{
    shipsImage.load(":X-Wing-icon-1.png");
    xPosition = 0;
    yPosition = 0;
    shipWidth = 0;
    shipHeight = 0;
    shipHit = 4;
}

/*!
  destructor
 */
SpaceShip::~SpaceShip()
{
}

/*!
   this method is called whenever the spaceShip needs to be drawn
*/
void SpaceShip::paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // can later traverse to examine what collided with the character.
    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

    // checks to see if collisions occurs
    if (!listOfCollidingItems.isEmpty())
    {
        // if collision occurs with mothershipbullet or alienshipbullet decrements shipHit
        if ((listOfCollidingItems.first()->type() == ID_MOTHERSHIPBULLET) || (listOfCollidingItems.first()->type() == ID_ALIENSHIPBULLET))
        {
            shipHit--;

            // added by Manpreet Kohli
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
        }
    }
    painter->drawPixmap(335, 640, 90, 40, shipsImage); // paints the space shipImage
}


/*!
   this method does the bounding rectangle of the object for collision detection
*/
QRectF SpaceShip::boundingRect() const
{
    return QRectF(335, 640, 90, 40);
}

/*!
    this method make the sound for ships bullets
*/
void SpaceShip::fireBullets()
 {
    QSound *gunFireFX = new QSound("44magnum.wav", 0);
    gunFireFX->setLoops(1);
    gunFireFX->play();
}

/*!
    this method make the sound for ships missiles
*/
void SpaceShip::fireMissiles()
{
    QSound *missileFireFX = new QSound("missile.wav", 0);
    missileFireFX->setLoops(1);
    missileFireFX->play();
}
