#ifndef CONSTANTS_H
#define CONSTANTS_H


#include "block.h"




class Constants
{



    public:



        static int itemsWindowViewWidth;
        static int windowWidth;
        static int windowHeight;
        static int mainViewWidth;
        static Block *currentBlock;
        static Block *blocks[21][27];
        static bool inLevelEditorMode;
        static QVector<QPointF> positions;      // change name later on

        static QVector<int> colors;      // change name later on

        static int levelNumber;

};

#endif // CONSTANTS_H
