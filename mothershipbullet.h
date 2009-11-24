#ifndef MOTHERSHIPBULLET_H
#define MOTHERSHIPBULLET_H


#define ID_MOTHERSHIPBULLET    64

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

        void setBulletPosition (int posX, int posY);
};

#endif // MOTHERSHIPBULLET_H