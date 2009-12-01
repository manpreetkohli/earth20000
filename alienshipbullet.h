#ifndef ALIENSHIPBULLET_H
#define ALIENSHIPBULLET_H

#define ID_ALIENSHIPBULLET    2

#include <QGraphicsItem>

class AlienShipBullet : public QGraphicsItem
{
    private:
        QPixmap bulletImage;
        qreal directionX, directionY, positionX, positionY, ballDirection;
        qreal viewWidth, viewHeight, width, height, shipXPosition;

        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        virtual QRectF boundingRect() const;
        virtual void advance(int phase);

    public:
        AlienShipBullet();

        ~AlienShipBullet();

        void setShipPosition (int pos);

        void setBulletPosition (int posX, int posY);


};

#endif // ALIENSHIPBULLET_H
