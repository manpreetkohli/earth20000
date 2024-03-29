#include <QtGui>
#include "levelTwo.h"

LevelTwo::LevelTwo(QGraphicsScene *theScene)
{
    xPos = -380 + (BOUNDWIDTH - 20 * OUTLINEW)/2;       // 260
    yPos = -630 + (BOUNDHEIGHT)/(5);
    int randomPowerBlock, powerupCounter;
    powerupCounter = 0;

    // Declare variable to hold seconds in clock
    time_t seconds;

    // Get value from system clock and place in seconds variable
    time(&seconds);

    // Convert seconds to a unsigned integer
    srand((unsigned int) seconds);

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
                randomPowerBlock = generateRandomNumber(0,1);

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

                // Randomly set the powerup value for the current block
                // to either 1 or 2.
                if(randomPowerBlock == 1 && powerupCounter < 7)
                {
                    block[i][j]->setPowerup(1);
                    powerupCounter++;

                    if(powerupCounter % 3 == 0)
                    {
                        block[i][j]->setPowerup(2);
                    }
                }

                // setXPos and setYPos are used to assist the ball with its block
                // collision detection
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

QRectF LevelTwo::boundingRect() const
{
    return QRectF(375, 625, BOUNDWIDTH, BOUNDHEIGHT);
}

void LevelTwo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

/*!
  Given a min and a max, generate a random number between
  this range
  */
int LevelTwo::generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
