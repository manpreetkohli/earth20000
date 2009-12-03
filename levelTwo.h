/**
 levelTwo.h

Contains prototypes for the levelTwo.cpp class.

Author: Natraj Subramanian

  **/

#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "block.h"

class LevelTwo: public QGraphicsItem
{
    private:
        int xPos, yPos;
        Block *block[9][20];
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
        int generateRandomNumber(int min, int max);

    public:
        LevelTwo(QGraphicsScene *theScene);
};

#endif // LEVELTWO_H
