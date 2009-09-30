#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsItem>
#include <QtGui>

#define BOUNDWIDTH 800
#define BOUNDHEIGHT 600

#define BLOCKX 0
#define BLOCKY -30
#define BLOCKW 24
#define BLOCKH 24
#define XRADIUS 100
#define YRADIUS 20
#define OUTLINEX -2
#define OUTLINEY -32
#define OUTLINEW 28
#define OUTLINEH 28
#define SPACE 4

class SingleBlock : public QGraphicsItem
{
public:
    int color1;
    int color2;
    SingleBlock(QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    enum { Type = UserType + 1 };
    int generateRandomNumber(int min, int max);
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

