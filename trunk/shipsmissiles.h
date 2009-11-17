/**
/ Author: Ivan Collazo
/ File: shipmissiles.h
/ Date: 10/20/2009
/
*/

#ifndef SHIPSMISSILES_H
#define SHIPSMISSILES_H

#include <QGraphicsItem>

class ShipsMissiles : public QGraphicsItem
{

    private:
        QPixmap missileImage;
        qreal directionX, directionY, positionX, positionY;
        qreal width, height, shipXPosition;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QRectF boundingRect() const;
        void setBounceBounds(qreal x, qreal y);
        void advance(int phase);

    public:
        ShipsMissiles();

        ~ShipsMissiles();

        void setShipPosition (int pos);
};

#endif // SHIPSMISSILES_H
