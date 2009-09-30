#include <QtGui>

#include "levelOne.h"
#include "block.h"

int xPos = 25 * (BLOCKW + SPACE);
int yPos = 10 * (BLOCKH + SPACE);

levelOne::levelOne(QGraphicsScene *theScene)
{
    Block *block[6][16];

    for(int i = 0; i < 6; i++)
    {
        if(i == 0 || i == 5)
        {
            for(int j = 0; j < 10; j++)
            {
                block[i][j] = new Block;
                block[i][j]->scale(1.0, 1.0);
                block[i][j]->setPos(xPos, yPos);
                xPos += BLOCKW + SPACE;
                theScene->addItem(block[i][j]);
            }
        }
        else
        {
            for(int j = 0; j < 16; j++)
            {
                block[i][j] = new Block;
                block[i][j]->scale(1.0, 1.0);
                block[i][j]->setPos(xPos, yPos);
                xPos += BLOCKW + SPACE;
                theScene->addItem(block[i][j]);
            }
        }


        yPos += BLOCKH + SPACE;

        if(i == 4)
        {
            xPos = 25 * (BLOCKW + SPACE);
        }
        else
        {
            xPos = 22 * (BLOCKW + SPACE);
        }

    }
}

QRectF levelOne::boundingRect() const
{
    return QRectF(300, 20, 1024, 768);
}

void levelOne::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
