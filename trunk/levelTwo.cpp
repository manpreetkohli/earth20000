#include <QtGui>
#include <cctype>
#include <cstdlib>
#include <time.h>

#include "levelTwo.h"
#include "block.h"

levelTwo::levelTwo(QGraphicsScene *theScene)
{
    xPos = (BOUNDWIDTH - 20 * OUTLINEW)/2;
    yPos = (BOUNDHEIGHT)/(5);

    // Declare variable to hold seconds in clock
    time_t seconds;

    // Get value from system clock and place in seconds variable
    time(&seconds);

    // Convert seconds to a unsigned integer
    srand((unsigned int) seconds);

    Block *block[9][20];
    int detColor;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if( (i == 0) && ( j > 6 && j < 13 )||
                (i == 1) && ( j == 0 || ( j > 7 && j < 12 )|| j == 19) ||
                (i == 2) && ( j == 0 || j == 1 || j == 9 || j == 10 || j == 18 || j == 19) ||
                (i == 3) && ( j < 3 || j > 16 ) ||
                (i > 4 && i < 9) && (j == 0 || j == 1 || j == 9 || j == 10 || j == 18 || j == 19))
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
        xPos = (BOUNDWIDTH - 20 * OUTLINEW)/2;

    }

}

QRectF levelTwo::boundingRect() const
{
    return QRectF(300, 20, 20 * OUTLINEW, 9 * OUTLINEH);
}

void levelTwo::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

int levelTwo::generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
