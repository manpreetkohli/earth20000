#include <QPainter>
#include <QStyleOption>
#include "powerup.h"
#include "constants.h"
#include "spaceship.h"
#include "block.h"
#include "board.h"
#include "ball.h"

int Constants::powerup;

Powerup::Powerup()
{
    powerupImage.load(":Powerup.png");          // load an image for the ball
    directionX = 0;                         // set the X-axis increment for the movement
    directionY = -1;                        // set the Y-axis increment for the movement
    xPos = 0;                          // initial X coordinate of the ball
    yPos = 0;                          // initial Y coordinate of the ball
    setPos(xPos, yPos);
}

Powerup::~Powerup()
{
}

void Powerup::setPosition(int x, int y)
{
    xPos = x;
    yPos = y;
}

/*!
  Set the type of the powerup i.e. either slow down
  or speed up
  */
void Powerup::setType(int type)
{
    int *typePtr;
    typePtr = &powerupType;
    *typePtr = type;
}

QRectF Powerup::boundingRect() const
{
    return QRectF(375, 625, 27, 27);
}

void Powerup::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(375, 625, 27, 27, powerupImage);
}

void Powerup::advance(int phase)
{
    if(!phase) return;

    if(yPos < 95)
    {
        QList<QGraphicsItem *> hits = this->collidingItems(Qt::IntersectsItemBoundingRect);

        if(!hits.isEmpty())
        {
            // Checks if the first item that collidingItems has detected
            // has the ID_SPACESHIP as its type and not BLOCKID
            // If it does then the powerup icon is set invisible and then
            // subsequently removed from the scene.
            if(hits.first()->type() == ID_SPACESHIP && hits.first()->type() != BLOCKID)
            {
                powerupAcquired = new QSound("tone2.wav");
                powerupAcquired->setLoops(1);
                powerupAcquired->play();
                this->setVisible(false);
                this->scene()->removeItem(this);

                // Powerup type 1 specifies a slow down of the ball
                // If powerup type is 1, then set the static variable
                // powerup in the constants class to 1, so that it
                // can be read in by the ball during its next clock
                // cycle.
                // Powerup type 2 specifies a speed up of the ball
                if(this->powerupType == 1)
                {
                    if(Constants::powerup != 1)
                    {
                        Constants::powerup = 1;
                    }
                }
                if(this->powerupType == 2)
                {
                    if(Constants::powerup != 2)
                    {
                        Constants::powerup = 2;
                    }
                }
            }
        }

        // Move the ball down the Y Axis by directionY
        yPos-=directionY;
        setPos(xPos, yPos);
    }
    else
    {
        // If the powerup has passed the boundary of the window,
        // then remove it from the scene.
        Constants::powerup = 0;
        this->scene()->removeItem(this);
    }
}
