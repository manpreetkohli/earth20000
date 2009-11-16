/**
 levelFive.h

Contains prototypes for the levelFive.cpp class.

Author: Natraj Subramanian

  **/

#ifndef LEVELFIVE_H
#define LEVELFIVE_H

#include <QGraphicsItem>
#include <QtGui>
#include "block.h"

#define LEVELW 600
#define LEVELH 300

class levelFive: public QGraphicsItem
{
public:
    int xPos, yPos;
    Block *block[10][25];
    levelFive(QGraphicsScene *theScene);
    QRectF boundingRect() const;
    void levelFive::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget = 0);
    int generateRandomNumber(int min, int max);
};


#endif // LEVELFIVE_H
