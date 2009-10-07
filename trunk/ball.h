#ifndef BALL_H
#define BALL_H


#include <QGraphicsItem>

class Ball : public QGraphicsItem
{

    private:


        QPixmap ballImage;
        qreal bounceBoundsX, bounceBoundsY, directionX, directionY, positionX, positionY;
        qreal viewWidth, viewHeight, width, height;


    public:
        Ball();

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        QRectF boundingRect() const;

        void setBounceBounds(qreal x, qreal y);

        void Ball::advance(int phase);

};

#endif // BALL_H
