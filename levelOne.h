/**
 levelOne.h

Contains prototypes for the levelOne.cpp class.

Author: Natraj Subramanian

  **/

#ifndef LEVELONE_H
#define LEVELONE_H

#include <QGraphicsItem>
#include <QtGui>
#include "block.h"

#include "block.h"

#define LEVELW 600
#define LEVELH 300
class levelOne: public QGraphicsItem
{
public:
    int xPos, yPos;
    Block *block[6][16];
    levelOne(QGraphicsScene *theScene);
    QRectF boundingRect() const;
    void levelOne::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget = 0);
    int generateRandomNumber(int min, int max);




//    Block *block[6][16];

};

#endif // LEVELONE_H
