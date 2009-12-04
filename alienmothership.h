#ifndef ALIENMOTHERSHIP_H
#define ALIENMOTHERSHIP_H

#include <QGraphicsItem>

#define ID_MOTHERSHIP    4

class AlienMotherShip : public QGraphicsItem
{
    private:
        // variables for the position and dimension of ship
        qreal left;
        qreal top;
        qreal width;
        qreal height;
        qreal alienMotherShipHit;

        QTimer *timer;

        // Color of the character,
        QColor color;

        // for image of th ship that will be place on the object.
        QPixmap shipsImage;

    public:
        AlienMotherShip();

        ~AlienMotherShip();

        // the bounding rectangle of the object for collision detection
        QRectF boundingRect () const;

        // called whenever the spaceShip needs to be drawn
        void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        // gets Alien MotherShip X Position
        int getShipPosX();

        // gets Alien MotherShip Y Position
        int getShipPosY();

        virtual int type() const {return ID_MOTHERSHIP; }

        // public slots:
        void fire();

        int getShipHit();

};

#endif // ALIENMOTHERSHIP_H
