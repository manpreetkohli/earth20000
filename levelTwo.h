/**
 * levelTwo.cpp
 *
 * Creates the design for the second level. Uses the polymorphism feature
 * of the block.cpp class and randomly generates blocks of different colors
 * and places them in a pre-defined layout.
 *
 * This level contains powerups
 *
 * Author: Natraj Subramanian
 *
 */

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
