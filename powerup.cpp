#include "powerup.h"
#include "constants.h"

PowerupDesign::PowerupDesign(QGraphicsItem *parent = 0)
        :QGraphicsItem(parent)
{
}

QRectF PowerupDesign::boundingRect() const
{
    return QRectF(OUTLINEX, OUTLINEY, OUTLINEW, OUTLINEH);
}

void PowerupDesign::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(Qt::cyan, 0));
    painter->setBrush(Qt::white);
    painter->drawRoundedRect(OUTLINEX, OUTLINEY, OUTLINEW, OUTLINEH, XRADIUS, YRADIUS, Qt::RelativeSize);

    QLinearGradient gradient(0, 20, 0, 4);
    gradient.setSpread(QGradient::ReflectSpread);

    gradient.setColorAt(0, Qt::red);
    gradient.setColorAt(1, Qt::blue);

    painter->setBrush(gradient);
    painter->setPen(QPen(Qt::black, 0));
    painter->drawRoundedRect(BLOCKX, BLOCKY, BLOCKW, BLOCKH, XRADIUS, YRADIUS, Qt::RelativeSize);
}

Powerup::Powerup()
{
    PowerupDesign *temp = new PowerupDesign(this);
    xPos = 0;
    yPos = 0;
    directionX = 0;
    directionY = -2;
    setPos(xPos, yPos);    
}

Powerup::~Powerup()
{
}

void Powerup::setPosition(int x, int y)
{
    xPos = x;
    yPos = y;
}

QRectF Powerup::boundingRect() const
{
    return QRectF();
}

void Powerup::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Powerup::advance(int phase)
{
    if(!phase) return;

    yPos-=directionY;

    setPos(xPos, yPos);
}





