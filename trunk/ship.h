/*!
* Author: Ivan Collazo
* File: ship.cpp
* Date: 10/05/2009
* This class is the super class for ships in earth:20000
*/

#ifndef SHIP_H
#define SHIP_H

#include <QtGui>

/*!
    creates a super class of ships
*/
class Ship  : public QGraphicsItem
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

        // this method is the bounding rectangle of the object for collison detection
        virtual QRectF boundingRect() const;

        // this method is called whenever the ship needs to be drawn
        virtual void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    public:
        // constructor
        Ship();

        // destructor
        virtual ~Ship();

        // this method gets ships x position
        int getShipPosX();

        // this method sets ships x position
        void setShipPosX(int xPos);

        // this method gets ships y position
        int getShipPosY();

        // this method sets ships y position
        void setShipPosY(int yPos);

        // this method gets the amount of times ship has been hit
        virtual int getShipHit();
};

#endif // SHIP_H
