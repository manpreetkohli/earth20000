#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsItem>
#include <QtGui>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QTimeLine;
QT_END_NAMESPACE


class SingleBlock : public QGraphicsItem
{
public:
    SingleBlock(QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    enum { Type = UserType + 1 };
    int type() const;
};

class Block : public SingleBlock
{
public:
    Block();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

};

#endif

