/**
 * levelOne.cpp
 *
 * Creates the design for the first level. Uses the polymorphism feature
 * of the block.cpp class and randomly generates blocks of different colors
 * and places them in a pre-defined layout.
 *
 * Author: Natraj Subramanian
 *
 */

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
