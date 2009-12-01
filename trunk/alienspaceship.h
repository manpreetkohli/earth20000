#ifndef ALIENSPACESHIP_H
#define ALIENSPACESHIP_H

#include <QGraphicsItem>

#define ID_ALIENSPACESHIP   32

class AlienSpaceShip : public QGraphicsItem
{
    private:
        // variables for the position and dimension of ship
        qreal left;
        qreal top;
        qreal width;
        qreal height;
        qreal alienShipHit;

      //  QTimer *timer;

        // Color of the character,
        QColor color;

        // for image of th ship that will be place on the object.
        QPixmap shipsImage;

public:
    AlienSpaceShip();

    ~AlienSpaceShip();

    // the bounding rectangle of the object for collision detection
    QRectF boundingRect () const;

    // called whenever the spaceShip needs to be drawn
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getShipPosX();

    int getShipPosY();

    virtual int type() const {return ID_ALIENSPACESHIP; }

    void fire();

};

#endif // ALIENSPACESHIP_H
