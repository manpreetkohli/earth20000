/*!
*   Author: Ivan Collazo
*   File: alienshipbullet.cpp
*   Date: 10/20/2009
*   This class is to create an alien ship bullet in earth:20000
*/

#ifndef ALIENSHIPBULLET_H
#define ALIENSHIPBULLET_H
#define ID_ALIENSHIPBULLET    2

#include "ammo.h"

/*!
    This class creates alienshipbullets and advances the bullet for earth:20000
*/
class AlienShipBullet : public Ammo
{
    private:
        // for image of the bullet that will be place on the object.
        QPixmap bulletImage;

        // variables for the position and dimension of alienshipbullet
        qreal directionX, directionY, positionX, positionY;
        qreal width, height, shipXPosition;

        // this method is called whenever the alienshipbullet needs to be drawn
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        // this method does the bounding rectangle of the object for collision detection
        QRectF boundingRect() const;

        // this method adds motion to the alienshipbullet
        void advance(int phase);

    public:
        // constructor
        AlienShipBullet();

        // destructor
        virtual ~AlienShipBullet();

        // this method sets alien ship bullet position
        void setBulletPosition (int posX, int posY);

        // this method helps Id the alien ship bullet for collision detection
        virtual int type() const {return ID_ALIENSHIPBULLET;}
};

#endif // ALIENSHIPBULLET_H
