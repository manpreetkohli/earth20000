/**
  block.h

  Header file for block.cpp

  Contains the prototypes for the methods used in the block.cpp class.

  Author: Natraj Subramanian

  **/

#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsItem>
#include <QtGui>

#define BOUNDWIDTH 800
#define BOUNDHEIGHT 725

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
    SingleBlock(QGraphicsItem *parent);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    virtual void setColor1(int theColor);
    virtual void setColor2(int theColor);
    int getColor1();
    int getColor2();

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

class RedBlock : public Block
{
public:
    RedBlock();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

};



class GreenBlock : public Block
{
public:
    GreenBlock();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

};

class BlueBlock : public Block
{
public:
    BlueBlock();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

};


class MagentaBlock : public Block
{
public:
    MagentaBlock();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

};

class YellowBlock : public Block
{
public:
    YellowBlock();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

};

#endif

