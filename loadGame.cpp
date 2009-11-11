/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * loadGame.cpp: creates the design for the saved game. Reads in the saved file,
 * and based on the input, creates the blocks for the board
 *
 */


#include <QtGui>
#include "loadGame.h"
#include "block.h"
#include "constants.h"

LoadGame::LoadGame(QGraphicsScene *theScene)
{
    xPos = 3;
    yPos = 32;


    QFile file("levels.txt");

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Cannot open file for reading: ";


    }

    QTextStream in(&file);

    QChar c;

    // draw all the transparent blocks for the level editor window
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 27; j++)
        {

            in >> c;

            if (c == 'w')
                Constants::blocks[i][j] = new Block();
            else if (c == 'r')
                Constants::blocks[i][j] = new RedBlock();
            else if (c == 'g')
                Constants::blocks[i][j] = new GreenBlock();
            else if (c == 'b')
                Constants::blocks[i][j] = new BlueBlock();
            else if (c == 'm')
                Constants::blocks[i][j] = new MagentaBlock();
            else if (c == 'y')
                Constants::blocks[i][j] = new YellowBlock();

            else
            {
                xPos+=OUTLINEW;
                continue;
            }


            theScene->addItem(Constants::blocks[i][j]);
            Constants::blocks[i][j]->setPos(xPos, yPos);
            Constants::blocks[i][j]->show();
            xPos+=OUTLINEW;
        }

        in >> c;
        in >> c;
        yPos += OUTLINEH;
        xPos = 3;
    }
}

QRectF LoadGame::boundingRect() const
{
    return QRectF(0, 0, 27 * OUTLINEW, 21 * OUTLINEH);
}

void LoadGame::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


