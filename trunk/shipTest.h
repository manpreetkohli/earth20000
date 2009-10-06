#ifndef SHIPTEST_H
#define SHIPTEST_H
#include <QGraphicsScene>
#include <iostream>
#include <QPixmap>
#include <QGraphicsItem>

using namespace std;
class shipTest : public QGraphicsItem
{
    public:
        shipTest (); // constructor
        ~shipTest();
        QRectF boundingRect() const;
        QPainterPath shipShape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
      //  void setPos(qreal x, qreal y);
        //void explodeShip ();

   // protected:
     //   void moveShip();

    private:
        qreal positionX, positionY, directionRight, directionLeft, rotateAngle;
        qreal bounceBoundsX, bounceBoundsY;
        QColor color;
      //  bool animated;
       // QPixmap playersSpaceShip;
};

#endif // SHIPTEST_H
