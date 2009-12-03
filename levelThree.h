/**
 levelTwo.h

Contains prototypes for the levelThree.cpp class.

Author: Natraj Subramanian

  **/

#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "block.h"

class LevelThree: public QGraphicsItem
{
    private:
        int xPos, yPos;
        Block *block[11][20];
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
        int generateRandomNumber(int min, int max);

    public:
        LevelThree(QGraphicsScene *theScene);
};

#endif // LEVELTHREE_H
