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
    factor = 0.25;
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
            if(hits.first()->type() == ID_SPACESHIP && hits.first()->type() != BLOCKID)
            {
                this->setVisible(false);

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

        yPos-=directionY;
        qDebug() << "yPos: " << yPos;

        setPos(xPos, yPos);
    }
    else
    {
        Constants::powerup = 0;
    }

}





