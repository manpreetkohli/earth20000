#ifndef CONSTANTS_H
#define CONSTANTS_H


#include "block.h"
#include "spaceship.h"


class Constants
{
    public:
        static int itemsWindowViewWidth;
        static int windowWidth;
        static int windowHeight;
        static int mainViewWidth;
        static Block *currentBlock;
        static Block *blocks[20][27];
        static bool inLevelEditorMode;
        static QVector<QPointF> positions;      // change name later on
        static QVector<int> colors;      // change name later on
        static int levelNumber;
        static SpaceShip *playersShip;
        static SpaceShip *life1;
        static SpaceShip *life2;
        static SpaceShip *life3;
        static QGraphicsTextItem *levelInfo;
        static QGraphicsTextItem *lives;
        static int count;
        static QPushButton *cont;
        static QTimer *timer;
};

#endif // CONSTANTS_H
