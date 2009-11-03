/**
 levelTwo.h

Contains prototypes for the levelTwo.cpp class.

Author: Natraj Subramanian

  **/

#ifndef LEVELTWO_H
#define LEVELTWO_H



#define LEVELW 600
#define LEVELH 300

class levelTwo: public QGraphicsItem
{
public:
    int xPos, yPos;
    levelTwo(QGraphicsScene *theScene);
    QRectF boundingRect() const;
    void levelTwo::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget = 0);
    int generateRandomNumber(int min, int max);
};


#endif // LEVELTWO_H
