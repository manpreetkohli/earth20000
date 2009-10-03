#ifndef FIRSTLEVEL_H
#define FIRSTLEVEL_H

#include "board.h"
#include "ball.h"
#include <QTimer>

class FirstLevel
{

    private:
        Board *board;
        Ball *ball;

    public:
        FirstLevel();
        void setupFirstLevel();


};


#endif // FIRSTLEVEL_H
