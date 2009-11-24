#ifndef ALIENMOTHERSHIP_H
#define ALIENMOTHERSHIP_H

#include <QGraphicsItem>

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

        // the bounding rectangle of the object for collision detection
//         QRectF boundingRectWings () const;

        // called whenever the spaceShip needs to be drawn
        void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        // gets Alien MotherShip X Position
        int getShipPosX();

        // gets Alien MotherShip Y Position
        int getShipPosY();

     // public slots:
        void fire();

};

#endif // ALIENMOTHERSHIP_H
