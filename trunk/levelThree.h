/**
 levelTwo.h

Contains prototypes for the levelThree.cpp class.

Author: Natraj Subramanian

  **/

#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include <QGraphicsItem>
#include <QtGui>
#include "block.h"

class levelThree: public QGraphicsItem
{
public:
    int xPos, yPos;
    Block *block[11][20];
    levelThree(QGraphicsScene *theScene);
    QRectF boundingRect() const;
    void levelThree::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget = 0);
    int generateRandomNumber(int min, int max);
};

#endif // LEVELTHREE_H
