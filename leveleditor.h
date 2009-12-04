/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * leveleditor.cpp: creates the design for the level editor
 * by creating 20 * 27 semi-transparent blocks
 *
 */

#ifndef LEVELEDITOR_H
#define LEVELEDITOR_H

class LevelEditor
{
    private:
        int xPos, yPos;
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    public:
        LevelEditor(QGraphicsScene *theScene);    
};

#endif // LEVELEDITOR_H
