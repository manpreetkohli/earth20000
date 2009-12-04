/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * board.cpp: sets up the board for the game- adds a scene to a view, and then adds the various
 * QGraphicsItems to the board
 *
 * HUD slightly modified by Natraj Subramanian
 *
 */

#ifndef BOARD_H
#define BOARD_H

#include <QtGui>

class Board
{
    private:
        QTimer *scoreTimer;
        void displayHUDLevel(QGraphicsScene *scene, QString levelNumber, QFont *font);

    public:
        Board(QGraphicsView *view);
        QGraphicsScene *scene;
        void connectTimerToBall();

    private slots:
        void advance();
};

#endif // BOARD_H
