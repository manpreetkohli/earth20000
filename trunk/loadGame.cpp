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

LoadGame::LoadGame(QGraphicsScene *theScene, QGraphicsView *view)
{
    xPos = -375;
    yPos = -590;

    QFile file("levels.txt");
    QFile bgFile("bgs.txt");

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Cannot open file for reading ";
    }
    
     if (!bgFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Cannot open file for reading ";
    }

    QTextStream in(&file);
    QTextStream in2(&bgFile);
    QChar c;
    QString bg;
    
    in2 >> bg;    


    view->setBackgroundBrush(QPixmap(bg));

    // draw all the transparent blocks for the level editor window
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            in >> c;

            if (c == 'w')
                Constants::blocks[i][j] = new MonoBlock();
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
            Constants::blocks[i][j]->setXPos(xPos);
            Constants::blocks[i][j]->setYPos(yPos);
            Constants::blocks[i][j]->setPos(xPos, yPos);
            Constants::blocks[i][j]->show();
            xPos+=OUTLINEW;
        }

        in >> c;
        in >> c;
        yPos += OUTLINEH;
        xPos = -375;
    }
}

QRectF LoadGame::boundingRect() const
{
    return QRectF(0, 0, 27 * OUTLINEW, 20 * OUTLINEH);
}

void LoadGame::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


