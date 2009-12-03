/**
 levelFive.h

Contains prototypes for the levelFive.cpp class.

Author: Natraj Subramanian

  **/

#ifndef LEVELFIVE_H
#define LEVELFIVE_H

#include "block.h"

class LevelFive: public QGraphicsItem
{
    private:
        int xPos, yPos;
        Block *block[10][25];
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
        int generateRandomNumber(int min, int max);

    public:
        LevelFive(QGraphicsScene *theScene);
};

#endif // LEVELFIVE_H
