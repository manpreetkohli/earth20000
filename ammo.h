/*!
* Author: Ivan Collazo
* File: ship.cpp
* Date: 10/05/2009
* This class is a super class for ammo in earth:20000
*/

#ifndef AMMO_H
#define AMMO_H

#include <QtGui>

/*!
    creates a super class of ammo
*/
class Ammo : public QGraphicsItem
{
     private:
        // for image of the ship that will be place on the object.
        QPixmap shipsImage;

        // variables for the position and dimension of bullet
        qreal directionX, directionY, positionX, positionY;
        qreal width, height, shipXPosition;

        // this method is called whenever ammo needs to be drawn
        virtual void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

         // this method is the bounding rectangle of the object for collison detection
        virtual QRectF boundingRect() const;

        // this method adds motion to ammo
        virtual void advance(int phase);

    public:
        // constructor
        Ammo();

        // destructor
        virtual ~Ammo();
};

#endif // AMMO_H
