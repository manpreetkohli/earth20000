#ifndef SPACESHIP_H
#define SPACESHIP_H
//#include "MoveBehavior.h"
//#include "ShotBehavior.h"
#include <QGraphicsItem>

using namespace std;

class SpaceShip : QGraphicsItem
{
    private:

        // variables for the position and dimension of ship
        int left;
        int top;
        int width;
        int height;

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
        //~SpaceShip();

        // the bounding rectangle of the object for collision detection
        QRectF boundingRect () const;

        // called whenever the spaceShip needs to be drawn
        void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
      //  void performShipMovement();
      //  void performShootingMovement();

};

#endif // SPACESHIP_H
