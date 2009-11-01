/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * board.h: header file for the Board class that sets up the board for the game- adds a scene to a view,
 * and then adds the various QGraphicsItems to the board
 *
 */


#ifndef BOARD_H
#define BOARD_H

// include necessary files
#include "block.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelFive.h"
#include "leveleditor.h"
#include <QTimer>
#include <QGraphicsView>
#include <QGraphicsScene>

class Board
{
    public:
        QGraphicsScene *scene;
        QTimer *timer;
        Board(QGraphicsView *view);
        void connectTimerToBall();

};
#endif // BOARD_H
