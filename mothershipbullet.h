/*!
*   Author: Ivan Collazo
*   File: mothershipbullet.cpp
*   Date: 10/20/2009
*   This class is to create a motherships bullet in earth:20000
*/

#ifndef MOTHERSHIPBULLET_H
#define MOTHERSHIPBULLET_H
#define ID_MOTHERSHIPBULLET    64

#include "ammo.h"

/*!
*   This class creates mothers ship bullets and advance the bullet for earth:20000
*/
class MotherShipBullet : public Ammo
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
        MotherShipBullet();

        // destructor
        virtual ~MotherShipBullet();

        // this method sets mothershipbullet position
        void setBulletPosition (int posX, int posY);

        // this method helps Id the mothership bullet for collision detection
        virtual int type() const {return ID_MOTHERSHIPBULLET; }
};

#endif // MOTHERSHIPBULLET_H
