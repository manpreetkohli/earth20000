#include "shipTest.h"
#include <QGraphicsItem>
//#include <iostream>
#include <QPixmap>
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QStyleOption>
#include <QGraphicsScene>

using namespace std;

shipTest::shipTest()
        : positionX(5), positionY(20), directionRight(1),
          directionLeft(1), color(Qt::red)
{  
         //   animated = false;
         //   cout << "Load pixmap" << playersSpaceShip.load(":/soccer.png")<< endl;
}

shipTest::~shipTest()
{
}


QRectF shipTest::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}


/**
QPainterPath shipTest::shipShape() const
{
    QPainterPath path;
    path.addRect(10, 20, 60, 20);
    QPainter painter(path);
    painter.setBrush(Qt::red);
    return path;
}
*/


void shipTest::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setBrush(Qt::red);
    painter->drawRect(10, 20, 60, 20);
    //painter->setBrush(Qt::red);
   //painter->setBrush(color);
}

