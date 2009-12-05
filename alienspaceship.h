/*!
*   Author: Ivan Collazo
*   File: alienspaceship.cpp
*   Date: 10/05/2009
*   This class is to creat an alienspaceship in earth:20000
*/

#ifndef ALIENSPACESHIP_H
#define ALIENSPACESHIP_H
#define ID_ALIENSPACESHIP   32

#include <QGraphicsItem>
#include "alienshipbullet.h"
#include "ship.h"

/*!
    This class creates aliemspaceship for earth:20000
*/
class AlienSpaceShip : public Ship
{
    private:
        // for image of the ship that will be place on the object.
        QPixmap shipsImage;

        // variables for the position and dimension of ship
        qreal xPosition;
        qreal yPosition;
        qreal shipWidth;
        qreal shipHeight;
        qreal shipHit;

        // instance of AlienShipBullet for fire method
        AlienShipBullet *alienBullet;

        // this method does the bounding rectangle of the object for collision detection
        QRectF boundingRect () const;

        // this method is called whenever the alienspaceship needs to be drawn
        void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    public:
        // constructor
        AlienSpaceShip();

        // destructor
        virtual ~AlienSpaceShip();

        // this method helps ID the ship for collision detection
        virtual int type() const {return ID_ALIENSPACESHIP; }

        // this method gets the amount of times alienspaceship has been hit
        int getShipHit();

        // this method fires the alienspaceship bullets
        void fire();
};

#endif // ALIENSPACESHIP_H
