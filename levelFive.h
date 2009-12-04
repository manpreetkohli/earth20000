/**
 * levelFive.cpp
 *
 * Creates the design for the fifth level. Uses the polymorphism feature
 * of the block.cpp class and randomly generates blocks of different colors
 * and places them in a pre-defined layout. Also places the mothership
 * in the layout as part of the boss battle
 *
 * Author: Natraj Subramanian
 *
 */

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
