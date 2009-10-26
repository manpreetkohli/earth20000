#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include <QGraphicsItem>
#include <QtGui>
#include <QPainter>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QTimeLine;
QT_END_NAMESPACE

class EnemyShipPart: public QGraphicsItem
{
public:
    EnemyShipPart(QGraphicsItem *parent = 0);
};

class EnemyShipBody : public EnemyShipPart
{
public:
    EnemyShipBody(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

class EnemyShipTail : public EnemyShipPart
{
public:
    EnemyShipTail(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

class EnemyShipWing1 : public EnemyShipPart
{
public:
    EnemyShipWing1(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

class EnemyShipWing2 : public EnemyShipPart
{
public:
    EnemyShipWing2(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

class EnemyShipWindow : public EnemyShipPart
{
public:
    EnemyShipWindow(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};


class EnemyShip: public EnemyShipPart
{
public:
    EnemyShip();
    ~EnemyShip();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
private:
    QTimeLine *timeline;
};


#endif // ENEMYSHIP_H
