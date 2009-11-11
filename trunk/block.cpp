/**
 block.cpp

Creates an instance of a single block. Involves polymorphism for creating blocks
of different colors.

Author: Natraj Subramanian

  **/


#include <QtGui>
#include "block.h"
#include "constants.h"

QColor colors[8] = {QColor(Qt::white), QColor(Qt::black), QColor(Qt::red), QColor(Qt::green),
                    QColor(Qt::blue), QColor(Qt::magenta), QColor(Qt::yellow), QColor(Qt::transparent)};
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
    return QRectF(OUTLINEX, OUTLINEY, OUTLINEW, OUTLINEH);
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


// Added by Manpreet Kohli
QVector<QPointF> Constants::positions;
QVector<int> Constants::colors;
int SingleBlock::colorSelected = 7;

// Added by Manpreet Kohli
void SingleBlock::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    qDebug() << "selected " << colorSelected;
    if (Constants::inLevelEditorMode == true)
    {
        if (this->scene()->width() < Constants::itemsWindowViewWidth)
        {
            colorSelected = this->color2;
            qDebug() << "ole ole" << this->color2;


            this->scene()->removeItem(Constants::currentBlock);

            delete Constants::currentBlock;

            switch(colorSelected)
            {
                case 0:
                    qDebug() << "color set to 0";
                    Constants::currentBlock = new Block();
                    break;

                case 2:
                    qDebug() << "color set to 2";
                    Constants::currentBlock = new RedBlock();
                    break;

                case 3:
                    qDebug() << "color set to 3";
                    Constants::currentBlock = new GreenBlock();
                    break;

                case 4:
                    qDebug() << "color set to 4";
                    Constants::currentBlock = new BlueBlock();
                    break;

                case 5:
                    qDebug() << "color set to 5";
                    Constants::currentBlock = new MagentaBlock();
                    break;

                case 6:
                    qDebug() << "color set to 6";
                    Constants::currentBlock = new YellowBlock();
                    break;

                case 7:
                    qDebug() << "color set to 7";
                    Constants::currentBlock = new EmptyBlock();
                    break;
            }

            qDebug() << "geez " << Constants::currentBlock->color1 << "  " << Constants::currentBlock->color2;

            this->scene()->addItem(Constants::currentBlock);

            Constants::currentBlock->setPos(-105, 100);
        }

        else //if (this->scene()->width() > Constants::itemsWindowViewWidth)
        {
            this->setColor2(colorSelected);

            if (colorSelected == 7)
            {
//                this->setOpacity(0.4);
                this->setColor1(7);
            }
            else
            {
                this->setColor1(1);

                this->setOpacity(2.0);

                qDebug() << "wha " << this->getColor2();

                Constants::positions.push_back(this->scenePos());
                Constants::colors.push_back(this->getColor2());

            }

            qDebug() << "okgat " << this->pos();
            qDebug() << "this is me yo " << this->scenePos();

            update(this->boundingRect());
            update(this->sceneBoundingRect());

        }
    }
//    Constants::currentBlock->update(Constants::currentBlock->boundingRect());
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
    setColor1(1);
    setColor2(0);

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

// Added by Manpreet Kohli
EmptyBlock::EmptyBlock()
{
    //Set color to red
    setColor1(7);
    setColor2(7);

    QGraphicsItem *oneBlock = new SingleBlock(this);
}

// Added by Manpreet Kohli
QRectF EmptyBlock::boundingRect() const
{
    return QRectF();
}

// Added by Manpreet Kohli
void EmptyBlock::paint(QPainter *painter,
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
