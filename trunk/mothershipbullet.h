#ifndef MOTHERSHIPBULLET_H
#define MOTHERSHIPBULLET_H

#include <QGraphicsItem>

class MotherShipBullet : public QGraphicsItem
{
    private:
        QPixmap bulletImage;
        qreal directionX, directionY, positionX, positionY, ballDirection;
        qreal viewWidth, viewHeight, width, height, shipXPosition;

        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        virtual QRectF boundingRect() const;
        virtual void advance(int phase);

    public:
        MotherShipBullet();

        ~MotherShipBullet();

        void setShipPosition (int pos);

        void setBulletYPosition (int pos);

        void setBulletXPosition (int pos);


};

#endif // MOTHERSHIPBULLET_H
