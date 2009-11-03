/**
 levelEditor.cpp


  **/

#include <QtGui>
#include "leveleditor.h"
#include "block.h"
#include "constants.h"

LevelEditor::LevelEditor(QGraphicsScene *theScene)
{
    xPos = 3;
    yPos = 32;

    // draw all the transparent blocks for the level editor window
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            Constants::blocks[i][j] = new EmptyBlock();
            theScene->addItem(Constants::blocks[i][j]);
            Constants::blocks[i][j]->setPos(xPos, yPos);
            Constants::blocks[i][j]->setOpacity(0.4);
            Constants::blocks[i][j]->show();
            xPos+=OUTLINEW;
        }
        yPos += OUTLINEH;
        xPos = 3;
    }
}

QRectF LevelEditor::boundingRect() const
{
    return QRectF(0, 0, 27 * OUTLINEW, 21 * OUTLINEH);
}

void LevelEditor::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


