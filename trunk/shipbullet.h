/**
 * Author: Ivan Collazo
 * File: shipbullet.h
 * Date: 10/20/2009
 *
 */

#ifndef SHIPBULLET_H
#define SHIPBULLET_H

#include <QGraphicsItem>

#define ID_SPACESHIPBULLET    8

class ShipBullet : public QGraphicsItem
{
    private:
        QPixmap bulletImage;
        qreal directionX, directionY, positionX, positionY, ballDirection;
        qreal viewWidth, viewHeight, width, height, shipXPosition;

        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        virtual QRectF boundingRect() const;
        virtual void advance(int phase);

    public:
        ShipBullet();
        ~ShipBullet();
        void setShipPosition (int pos);
        virtual int type() const {return ID_SPACESHIPBULLET; }
        qreal getShipBulletYPosition();
    };

#endif // SHIPBULLET_H
