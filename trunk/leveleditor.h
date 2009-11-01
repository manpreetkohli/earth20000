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
