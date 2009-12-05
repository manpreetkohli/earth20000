/*!
*   Author: Ivan Collazo
*   File: shipsmissiles.cpp
*   Date: 10/20/2009
*   This class is to create ship missiles in earth:20000
*/

#ifndef SHIPSMISSILES_H
#define SHIPSMISSILES_H
#define ID_SPACESHIPMISSILE    16

#include "ammo.h"

/*!
*   This class creates missiles and advances the missiles for earth:20000
*/
class ShipsMissiles :  public Ammo
{
    private:
         // for image of the bullet that will be place on the object.
        QPixmap bulletImage;

        // variables for the position and dimension of missiles
        qreal directionX, directionY, positionX, positionY;
        qreal width, height, shipXPosition;

        // this method is called whenever the shipbsmissiles needs to be drawn
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        // this method does the bounding rectangle of the object for collision detection
        QRectF boundingRect() const;

        // this method adds motion to the shipsmissiles
        void advance(int phase);

    public:
        // constructor
        ShipsMissiles();

        // destructor
        virtual ~ShipsMissiles();

        // this method sets missiles x position
        void setShipMissilesXPosition (int pos);

        // this method helps Id the space ships bullet for collision detection
        virtual int type() const {return ID_SPACESHIPMISSILE; }
};

#endif // SHIPSMISSILES_H
