#ifndef POWERUP_H
#define POWERUP_H

#include "block.h"

class PowerupDesign: public QGraphicsItem
{
public:    
    PowerupDesign(QGraphicsItem *parent);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

class Powerup : public PowerupDesign
{
public:
    int powerupType;
    int xPos, yPos, directionX, directionY;
    Powerup();
    ~Powerup();
    void setPosition(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    void advance(int phase);
};

#endif // POWERUP_H
