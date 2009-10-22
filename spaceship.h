/**
/ Author: Ivan Collazo
/ File: spaceship.h
/ Date: 10/05/2009
/ This is the hearder file for the class super class spaceship in earth:20000
/
/
*/


#ifndef SPACESHIP_H
#define SPACESHIP_H
//#include "MoveBehavior.h"
//#include "ShotBehavior.h"
#include <QGraphicsItem>

//using namespace std;

class SpaceShip : public QGraphicsItem
{
    private:

        // variables for the position and dimension of ship
        qreal left;
        qreal top;
        qreal width;
        qreal height;

        // Color of the character,
        QColor color;

        // for image of th ship that will be place on the object.
        QPixmap shipsImage;

    public:
        // declare two reference var for behavior interface types
        // MoveBehavior shipMoving;
        //  ShotBehavior shipShooting;

        // constructor
        SpaceShip();

        // destructor
        ~SpaceShip();

        // the bounding rectangle of the object for collision detection
        QRectF boundingRect () const;

        // called whenever the spaceShip needs to be drawn
        void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        void setBounceBounds (qreal x, qreal y);

      //void performShipMovement();
        //  void performShootingMovement();

};

#endif // SPACESHIP_H
