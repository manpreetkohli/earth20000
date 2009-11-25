/**
 levelThree.cpp

Creates the design for the second level. Uses the polymorphism feature
of the block.cpp class and randomly generates blocks of different colors
and places them in a pre-defined layout.

Author: Natraj Subramanian

  **/

#include <QtGui>
#include <cctype>
#include <cstdlib>
#include <time.h>
#include <QGraphicsItem>
#include "levelThree.h"
#include "block.h"

levelThree::levelThree(QGraphicsScene *theScene)
{
    xPos = -380 + (BOUNDWIDTH - 20 * OUTLINEW)/2;       // 260
    yPos = -630 + (BOUNDHEIGHT)/(8);
    int randomPowerBlock, powerupCounter;
    powerupCounter = 0;

    // Declare variable to hold seconds in clock
    time_t seconds;

    // Get value from system clock and place in seconds variable
    time(&seconds);

    // Convert seconds to a unsigned integer
    srand((unsigned int) seconds);

    int detColor;

    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(((i == 0 || i == 1 || i == 2 || i == 3 || i == 5 || i == 5 || i == 7
                 || i == 9) && (j == 0 || ( j > 6 && j < 13 ) || j == 19) ) ||
                 (i == 3 || i == 4) && (j == 0 || j == 19))
            {
                xPos += BLOCKW + SPACE;
            }
            else
            {
                detColor = generateRandomNumber(0,5);
                randomPowerBlock = generateRandomNumber(0,10);

                if(detColor == 0)
                {
                    block[i][j] = new MonoBlock;
                }
                if(detColor == 1)
                {
                    block[i][j] = new RedBlock;
                }

                if(detColor == 2)
                {
                    block[i][j] = new GreenBlock;
                }
                if(detColor == 3)
                {
                    block[i][j] = new BlueBlock;
                }
                if(detColor == 4)
                {
                    block[i][j] = new MagentaBlock;
                }
                if(detColor == 5)
                {
                    block[i][j] = new YellowBlock;
                }

                if(randomPowerBlock == 1)
                {
                    block[i][j]->setPowerup(1);
                    powerupCounter++;

                    if(powerupCounter % 3 == 0)
                    {
                        block[i][j]->setPowerup(2);
                    }

                }

                block[i][j]->setXPos(xPos);
                block[i][j]->setYPos(yPos);
                block[i][j]->scale(1.0, 1.0);
                block[i][j]->setPos(xPos, yPos);
                xPos += BLOCKW + SPACE;
                theScene->addItem(block[i][j]);
            }
        }

        yPos += BLOCKH + SPACE;
        xPos = -380 + (BOUNDWIDTH - 20 * OUTLINEW)/2;

    }

}

QRectF levelThree::boundingRect() const
{
    return QRectF(375, 625, BOUNDWIDTH, BOUNDHEIGHT);
}

void levelThree::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

int levelThree::generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

