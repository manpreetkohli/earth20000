/**
  block.h
  
  Header file for block.cpp
  
  Contains the prototypes for the methods used in the block.cpp class.
300
  Author: Natraj Subramanian
      
  **/

#ifndef BLOCK_H
#define BLOCK_H

#include <QtGui>

#define BOUNDWIDTH 800
#define BOUNDHEIGHT 725
#define BLOCKX 377
#define BLOCKY 627
#define BLOCKW 24
#define BLOCKH 24
#define XRADIUS 100
#define YRADIUS 20
#define OUTLINEX 375
#define OUTLINEY 625
#define OUTLINEW 28
#define OUTLINEH 28
#define SPACE 4
#define BLOCKID 128

class SingleBlock : public QGraphicsItem
{
    private:
        static int colorSelected;

    public:
        int color1;
        int color2;
        int xPos, yPos, hasPowerup;
        SingleBlock(QGraphicsItem *parent);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
        void mousePressEvent(QGraphicsSceneMouseEvent* event);
        virtual void setColor1(int theColor);
        virtual void setColor2(int theColor);
        virtual void setXPos(int thePos);
        virtual void setYPos(int thePos);
        virtual void setPowerup(int value);
        virtual int type() const {return BLOCKID; }
        int getColor1();
        int getColor2();
        int getXPos();
        int getYPos();
        int getPowerup();
};

class Block : public SingleBlock
{
    public:
        Block();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

class MonoBlock : public Block
{
    public:
        MonoBlock();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

class EmptyBlock : public Block
{
    public:
        EmptyBlock();
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
