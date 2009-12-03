/**
 levelFive.cpp

Creates the design for the fifth level. Uses the polymorphism feature
of the block.cpp class and randomly generates blocks of different colors
and places them in a pre-defined layout. Also places the mothership
in the layout as part of the boss battle

Author: Natraj Subramanian

  **/

#include <QtGui>
#include "levelFive.h"

LevelFive::LevelFive(QGraphicsScene *theScene)
{
    xPos = -380 + (BOUNDWIDTH - 25 * OUTLINEW)/4;
    yPos = -630 + (BOUNDHEIGHT)/4;

    // Declare variable to hold seconds in clock
    time_t seconds;
    // Get value from system clock and place in seconds variable
    time(&seconds);
    // Convert seconds to a unsigned integer
    srand((unsigned int) seconds);

    int detColor;

    // Create the layout for the level
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 25; j++)
        {
            if( (i > 1 && i < 8) && ( j > 3 && j < 21) )
            {
                 xPos += BLOCKW + SPACE;
            }
            else
            {
                detColor = generateRandomNumber(0,5);

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

                block[i][j]->setXPos(xPos);
                block[i][j]->setYPos(yPos);
                block[i][j]->scale(1.0, 1.0);
                block[i][j]->setPos(xPos, yPos);
                xPos += BLOCKW + SPACE;
                theScene->addItem(block[i][j]);
            }
        }

        yPos += BLOCKH + SPACE;
        xPos = -380 + (BOUNDWIDTH - 25 * OUTLINEW)/4;
    }
}

QRectF LevelFive::boundingRect() const
{
    return QRectF(375, 625, BOUNDWIDTH, BOUNDHEIGHT);
}

void LevelFive::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

// Given a min and a max, generate a random number between
// this range
int LevelFive::generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
