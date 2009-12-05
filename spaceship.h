/*!
*   Author: Ivan Collazo
*   File: spaceship.cpp
*   Date: 10/05/2009
*   This class is to create spaceship in earth:20000
*/

#ifndef SPACESHIP_H
#define SPACESHIP_H
#define ID_SPACESHIP    256 // Added by Natraj

#include <QGraphicsItem>
#include "sleeperthread.h"
#include "ship.h"

/*!
   This class creates players spaceship for earth:20000
*/
class SpaceShip : public Ship
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

        // this if for timer
        SleeperThread *t;

        // this method does the bounding rectangle of the object for collision detection
        QRectF boundingRect () const;

        // this method is called whenever the spaceShip needs to be drawn
        void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    public:        
        // constructor
        SpaceShip();

        // destructor
        virtual ~SpaceShip();

        // Added by Natraj this method helps ID the ship for collision detection
        virtual int type() const {return ID_SPACESHIP; }

        // this method make the sound for ships bullets
        void fireBullets();

        // this method make the sound for ships missiles
        void fireMissiles();
};

#endif // SPACESHIP_H
