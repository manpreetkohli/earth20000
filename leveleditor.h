/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * header file for the leveleditor: creates the design for the level editor
 * by creating 21 * 27 semi-transparent blocks
 *
 */


#ifndef LEVELEDITOR_H
#define LEVELEDITOR_H

class LevelEditor
{
    public:
        LevelEditor(QGraphicsScene *theScene);

    private:
        int xPos, yPos;
        QRectF boundingRect() const;
        void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
};

#endif // LEVELEDITOR_H
