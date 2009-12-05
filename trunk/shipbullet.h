/*!
*   Author: Ivan Collazo
*   File: shipbullet.cpp
*   Date: 10/20/2009
*   This class is to create a space ship bullet in earth:20000
*/

#ifndef SHIPBULLET_H
#define SHIPBULLET_H
#define ID_SPACESHIPBULLET    8

#include "ammo.h"

/*!
   This class creates bullets and advances the bullet for earth:20000
*/
class ShipBullet : public Ammo
{
    private:
        // for image of the bullet that will be place on the object.
        QPixmap bulletImage;

        // variables for the position and dimension of bullet
        qreal directionX, directionY, positionX, positionY;
        qreal width, height, shipXPosition;

        // this method is called whenever the shipbullet needs to be drawn
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        // this method does the bounding rectangle of the object for collision detection
        QRectF boundingRect() const;

        // this method adds motion to the shipbullet
        void advance(int phase);

    public:
        // constructor
        ShipBullet();

        // destructor
        virtual ~ShipBullet();

        // this method sets space ships bullet x position
        void setShipBulletXPosition (int pos);

        // this method helps Id the space ships bullet for collision detection
        virtual int type() const {return ID_SPACESHIPBULLET; }
    };

#endif // SHIPBULLET_H
