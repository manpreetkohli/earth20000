#ifndef LEVELONE_H
#define LEVELONE_H

#include <QGraphicsItem>
#include <QtGui>

#define LEVELW 600
#define LEVELH 300

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QTimeLine;
QT_END_NAMESPACE

class levelOne: public QGraphicsItem
{
public:
    levelOne(QGraphicsScene *theScene);
    QRectF boundingRect() const;
    void levelOne::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget = 0);
    int generateRandomNumber(int min, int max);
};

#endif // LEVELONE_H
