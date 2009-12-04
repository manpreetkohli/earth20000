/**
 * Constants.h: entails all the static variables that get used in the whole program.
 * These were implemented because without them, the coding becomes a lot more harder
 * and tedious as the variables are needed back and forth in a bunch of classes.
 * If need be, they can be changed so that they get passed as arguments to functions
 * in various classes; however, doing so would make life more miserable than it already
 * is.
 */

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
        static int powerup;
        static QTimer *timer;        
};

#endif // CONSTANTS_H
