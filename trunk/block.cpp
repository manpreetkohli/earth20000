#include <QtGui>

#include "block.h"

SingleBlock::SingleBlock(QGraphicsItem *parent)
    :QGraphicsItem(parent)
{
}

QRectF SingleBlock::boundingRect() const
{
    return QRectF(-15, -50, 100, 100);
}

void SingleBlock::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QLinearGradient gradient(0, -30, 30, 0);
    gradient.setColorAt(1, QColor(Qt::white));
    gradient.setColorAt(0, QColor(Qt::black));

    painter->setBrush(gradient);
    painter->setPen(Qt::NoPen);
    painter->drawRoundedRect(0, -30, 40, 20, 100, 30, Qt::RelativeSize);
    painter->setBrush(Qt::white);

    painter->setPen(QPen(Qt::black, 2));
}

int SingleBlock::type() const
{
    return Type;
}

Block::Block()
{
    QGraphicsItem *headItem = new SingleBlock(this);

    headItem->setPos(0, -18);

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
