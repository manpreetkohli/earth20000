#include <QtGui>

#include <iostream>

#include "block.h"

QColor colors[7] = {QColor(Qt::white), QColor(Qt::black), QColor(Qt::red), QColor(Qt::green),
                    QColor(Qt::blue), QColor(Qt::magenta), QColor(Qt::yellow)};
int color1, color2;

SingleBlock::SingleBlock(QGraphicsItem *parent = 0)
        :QGraphicsItem(parent)
{
    if(parent != NULL)
    {
        color1 = ((SingleBlock *)parent)->getColor1();
        color2 = ((SingleBlock *)parent)->getColor2();
    }
}

QRectF SingleBlock::boundingRect() const
{
    return QRectF(0, 0, OUTLINEW, OUTLINEH);
}

void SingleBlock::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    
    painter->setPen(QPen(Qt::black, 0));
    painter->setBrush(Qt::white);
    painter->drawRoundedRect(OUTLINEX, OUTLINEY, OUTLINEW, OUTLINEH, XRADIUS, YRADIUS, Qt::RelativeSize);

    QLinearGradient gradient(0, 20, 0, 4);
    gradient.setSpread(QGradient::ReflectSpread);

    gradient.setColorAt(0, colors[color1]);
    gradient.setColorAt(1, colors[color2]);
    
    /**
      If we decided to change it up later on:
      if(generateRandomNumber(0, 1) == 0)
    {
        gradient.setColorAt(0, colors[generateRandomNumber(0,16)].light(generateRandomNumber(0, 100)));
    }
    else
    {
        gradient.setColorAt(0, colors[generateRandomNumber(0,16)].dark(generateRandomNumber(0, 100)));
    }

    if(generateRandomNumber(0, 1) == 0)
    {
        gradient.setColorAt(1, colors[generateRandomNumber(0,16)].light(generateRandomNumber(0, 100)));
    }
    else
    {
        gradient.setColorAt(1, colors[generateRandomNumber(0,16)].dark(generateRandomNumber(0, 100)));
    }

      **/
    

    painter->setBrush(gradient);
    painter->setPen(QPen(Qt::black, 0));
    painter->drawRoundedRect(BLOCKX, BLOCKY, BLOCKW, BLOCKH, XRADIUS, YRADIUS, Qt::RelativeSize);
}

int SingleBlock::generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int SingleBlock::type() const
{
    return Type;
}

void SingleBlock::setColor1(int theColor)
{
    int *colorPtr;
    colorPtr = &color1;
    *colorPtr= theColor;
}

void SingleBlock::setColor2(int theColor)
{
    int *colorPtr;
    colorPtr = &color2;
    *colorPtr= theColor;

}

int SingleBlock::getColor1()
{
    return color1;
}

int SingleBlock::getColor2()
{
    return color2;
}

Block::Block()
{
    //set default color
    setColor1(0);
    setColor2(1);

    QGraphicsItem *oneBlock = new SingleBlock(this);

}

QRectF Block::boundingRect() const
{
    return QRectF();
}

void Block::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


RedBlock::RedBlock()
{
    //Set color to red
    setColor1(1);
    setColor2(2);

    QGraphicsItem *oneBlock = new SingleBlock(this);

}

QRectF RedBlock::boundingRect() const
{
    return QRectF();
}

void RedBlock::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


GreenBlock::GreenBlock()
{
    //Set color to green
    setColor1(1);
    setColor2(3);

    QGraphicsItem *oneBlock = new SingleBlock(this);

}

QRectF GreenBlock::boundingRect() const
{
    return QRectF();
}

void GreenBlock::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


BlueBlock::BlueBlock()
{
    //Set color to blue
    setColor1(1);
    setColor2(4);

    QGraphicsItem *oneBlock = new SingleBlock(this);

}

QRectF BlueBlock::boundingRect() const
{
    return QRectF();
}

void BlueBlock::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

MagentaBlock::MagentaBlock()
{
    //Set color to magenta
    setColor1(1);
    setColor2(5);

    QGraphicsItem *oneBlock = new SingleBlock(this);

}

QRectF MagentaBlock::boundingRect() const
{
    return QRectF();
}

void MagentaBlock::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

YellowBlock::YellowBlock()
{
    //Set color to yellow
    setColor1(1);
    setColor2(6);

    QGraphicsItem *oneBlock = new SingleBlock(this);

}

QRectF YellowBlock::boundingRect() const
{
    return QRectF();
}

void YellowBlock::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
