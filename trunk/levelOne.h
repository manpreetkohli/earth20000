/**
 levelOne.h

Contains prototypes for the levelOne.cpp class.

Author: Natraj Subramanian

  **/

#ifndef LEVELONE_H
#define LEVELONE_H



#define LEVELW 600
#define LEVELH 300

extern QList<QGraphicsItem*> listOfCollidingItems;

class levelOne: public QGraphicsItem
{
public:
    int xPos, yPos;
    levelOne(QGraphicsScene *theScene);
    QRectF boundingRect() const;
    void levelOne::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget = 0);
    int generateRandomNumber(int min, int max);

};

#endif // LEVELONE_H
