/*!
*   Author: Ivan Collazo
*   File: alienmothership.cpp
*   Date: 10/05/2009
*   This class  is to create an alienmothership in earth:20000
*/

#ifndef ALIENMOTHERSHIP_H
#define ALIENMOTHERSHIP_H
#define ID_MOTHERSHIP    4

#include <QGraphicsItem>
#include "mothershipbullet.h"
#include "ship.h"

/*!
    This class creates alienmothership for earth:20000
*/
class AlienMotherShip : public Ship
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

        // instance of mothershipbullet for fire method
        MotherShipBullet *shipBullet;

        // this method does the bounding rectangle of the object for collision detection
        QRectF boundingRect () const;

        // this method is called whenever the alienmothership needs to be drawn
        void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    public:
        // constructor
        AlienMotherShip();

        // destructor
        virtual ~AlienMotherShip();

        // this method helps ID the ship for collision detection
        virtual int type() const {return ID_MOTHERSHIP; }

        // this method fires the alienmothership bullets
        void fire();
};

#endif // ALIENMOTHERSHIP_H
