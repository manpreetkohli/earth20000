/**
 levelOne.h

Contains prototypes for the levelOne.cpp class.

Author: Natraj Subramanian

  **/

#ifndef LEVELONE_H
#define LEVELONE_H

#include "block.h"

class LevelOne: public QGraphicsItem
{
    private:
        int xPos, yPos;
        Block *block[6][16];
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
        int generateRandomNumber(int min, int max);

    public:
        LevelOne(QGraphicsScene *theScene);
};

#endif // LEVELONE_H
