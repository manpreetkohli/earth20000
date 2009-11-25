/**
 levelTwo.h

Contains prototypes for the levelTwo.cpp class.

Author: Natraj Subramanian

  **/

#ifndef LEVELTWO_H
#define LEVELTWO_H

#include <QGraphicsItem>
#include <QtGui>
#include "block.h"

class levelTwo: public QGraphicsItem
{
public:
    int xPos, yPos;
    Block *block[9][20];
    levelTwo(QGraphicsScene *theScene);
    QRectF boundingRect() const;
    void levelTwo::paint(QPainter *painter,
                         const QStyleOptionGraphicsItem *option,
                         QWidget *widget = 0);
    int generateRandomNumber(int min, int max);
};


#endif // LEVELTWO_H
