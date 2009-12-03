/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * header file for loadGame.cpp: creates the design for the saved game. Reads in the saved file,
 * and based on the input, creates the blocks for the board
 *
 */


#ifndef LOADGAME_H
#define LOADGAME_H

class LoadGame
{
   private:
        int xPos, yPos;
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    public:
        LoadGame(QGraphicsScene *theScene, QGraphicsView *view);
};



#endif // LOADGAME_H
