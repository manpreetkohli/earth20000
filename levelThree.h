/**
 * levelThree.cpp
 *
 * Creates the design for the second level. Uses the polymorphism feature
 * of the block.cpp class and randomly generates blocks of different colors
 * and places them in a pre-defined layout.
 *
 * Author: Natraj Subramanian
 *
 */

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
