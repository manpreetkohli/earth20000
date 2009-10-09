#ifndef SPACESHIP_H
#define SPACESHIP_H
//#include "MoveBehavior.h"
//#include "ShotBehavior.h"
#include <QGraphicsItem>

using namespace std;

class spaceShip : QGraphicsItem
{
    public:

        // declare two reference var for behavior interface types
       // MoveBehavior shipMoving;
      //  ShotBehavior shipShooting;

        // constructor
        spaceShip();
        virtual ~spaceShip();

        // the bounding rectangle of the object for collision detection
        virtual QRectF boundingRect ();

        // called whenever the spaceShip needs to be drawn
        void paint (QPainter *painter, const QStyleOPtionGraphicItem *option, QWidget *widget);

      //  void performShipMovement();
      //  void performShootingMovement();

    private:

        // Color of the spaceShip
        QColor color;

        qreal left, top, width, height;

};

#endif // SPACESHIP_H
