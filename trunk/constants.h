#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "block.h"
#include "spaceship.h"

class Constants
{
    public:
        static int itemsWindowViewWidth;
        static Block *currentBlock;
        static Block *blocks[20][27];
        static QPushButton *cont;
        static int levelNumber;
        static int count;
        static QVector<QPointF> positions;
        static QVector<int> colors;
        static SpaceShip *life1;
        static SpaceShip *life2;
        static SpaceShip *life3;
        static QGraphicsTextItem *levelInfo;
        static QGraphicsTextItem *lives;
        static QGraphicsTextItem *score;
        static int powerup;
        static int scoreCount;
        static QTimer *timer;        
};

#endif // CONSTANTS_H
