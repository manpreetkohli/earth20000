/**
 levelOne.cpp

Creates the design for the first level. Uses the polymorphism feature
of the block.cpp class and randomly generates blocks of different colors
and places them in a pre-defined layout.

Author: Natraj Subramanian

  **/

#include <QtGui>
#include <cctype>
#include <cstdlib>
#include <time.h>
#include <QGraphicsItem>
#include "levelOne.h"
#include "block.h"

//QList<QGraphicsItem*> listOfCollidingItems;

levelOne::levelOne(QGraphicsScene *theScene)
{
    xPos = (BOUNDWIDTH - 16 * OUTLINEW)/2;
    yPos = (BOUNDHEIGHT)/(5/2);

    // Declare variable to hold seconds in clock
    time_t seconds;

    // Get value from system clock and place in seconds variable
    time(&seconds);

    // Convert seconds to a unsigned integer
    srand((unsigned int) seconds);

    Block *block[6][16];
    int detColor;

    for(int i = 0; i < 6; i++)
    {
       for(int j = 0; j < 16; j++)
        {
            if( (i == 0 || i == 5) && ( j < 3 || j > 12))
            {
                 xPos += BLOCKW + SPACE;
             }
            else
            {
                detColor = generateRandomNumber(0,5);

                if(detColor == 0)
                {
                    block[i][j] = new Block;
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

                block[i][j]->scale(1.0, 1.0);
                block[i][j]->setPos(xPos, yPos);
                xPos += BLOCKW + SPACE;
                theScene->addItem(block[i][j]);

            }

        }

        yPos += BLOCKH + SPACE;
        xPos = (BOUNDWIDTH - 16 * OUTLINEW)/2;;

    }
}

QRectF levelOne::boundingRect() const
{
    return QRectF(0, 0, 16 * OUTLINEW, 6 * OUTLINEH);
}

void levelOne::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

int levelOne::generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
