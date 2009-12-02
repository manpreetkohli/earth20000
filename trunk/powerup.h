/**
 powerup.h

Contains prototypes for the powerup.cpp class.

Author: Natraj Subramanian

  **/

#ifndef POWERUP_H
#define POWERUP_H

#include <QGraphicsItem>
#include <QtGui>
#include "block.h"
#include "spaceship.h"
#include "constants.h"

class Powerup : public QGraphicsItem
{
public:
    QPixmap powerupImage;
    int powerupType;
    int xPos, yPos, directionX, directionY, timer;
    QSound *powerupAcquired;
    double factor;
    Powerup();
    ~Powerup();
    void setPosition(int x, int y);
    void setType(int type);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    void advance(int phase);
};

#endif // POWERUP_H
