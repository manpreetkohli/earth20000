/*!
 * Author: Ivan Collazo
 * File: spaceship.cpp
 * Date: 10/05/2009
 *   This class is a super class for space ships in earth20000
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "sleeperthread.h"

// Added by Natraj
#define ID_SPACESHIP    256

#include <QGraphicsItem>

class SpaceShip : public QGraphicsItem
{
    private:
        // variables for the position and dimension of ship
        qreal left;
        qreal top;
        qreal width;
        qreal height;
        qreal shipDirection;
        qreal shipHit;

        SleeperThread *t;

        // Color of the character,
        QColor color;

        // for image of th ship that will be place on the object.
        QPixmap shipsImage;

    public:
        // constructor
        SpaceShip();

        // destructor
        ~SpaceShip();

        // the bounding rectangle of the object for collision detection
        QRectF boundingRect () const;

        // Added by Natraj
        virtual int type() const {return ID_SPACESHIP; }

        // called whenever the spaceShip needs to be drawn
        void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        int getShipPosX();
        int getShipPosY();
        int getShipDirection();
        int getShipHit();
        void setShipPosX(int xPos);
        void setShipPosY(int yPos);
        void setShipDirection(int direction);
};

#endif // SPACESHIP_H
