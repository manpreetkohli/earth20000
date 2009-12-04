#include <QtGui>
#include "leveleditor.h"
#include "block.h"
#include "constants.h"

LevelEditor::LevelEditor(QGraphicsScene *theScene)
{
    xPos = -375;
    yPos = -590;

    // draw all the transparent blocks for the level editor window
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            Constants::blocks[i][j] = new EmptyBlock();
            theScene->addItem(Constants::blocks[i][j]);
            Constants::blocks[i][j]->setXPos(xPos);
            Constants::blocks[i][j]->setYPos(yPos);
            Constants::blocks[i][j]->setPos(xPos, yPos);
            Constants::blocks[i][j]->setOpacity(0.4);
            Constants::blocks[i][j]->show();
            xPos+=OUTLINEW;
        }
        yPos += OUTLINEH;
        xPos = -375;
    }
}

QRectF LevelEditor::boundingRect() const
{
    return QRectF(0, 0, 27 * OUTLINEW, 20 * OUTLINEH);
}

void LevelEditor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
