#include <QtGui>
#include <iostream>

#include "enemyShip.h"

EnemyShipPart::EnemyShipPart(QGraphicsItem *parent)
        :QGraphicsItem(parent)
{
}

EnemyShipBody::EnemyShipBody(QGraphicsItem *parent)
        :EnemyShipPart(parent)
{
}

QRectF EnemyShipBody::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void EnemyShipBody::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPointF vertices[13] = {QPointF(0.0, 2.0),
                                     QPointF(1.0, 1.0),
                                     QPointF(2.0, 0.0),
                                     QPointF(22.0, 0.0),
                                     QPointF(23.0, 1.0),
                                     QPointF(24.0, 2.0),
                                     QPointF(24.0, 40.0),
                                     QPointF(14.0, 48.0),
                                     QPointF(13.0, 49.0),
                                     QPointF(12.0, 50.0),
                                     QPointF(11.0, 49.0),
                                     QPointF(10.0, 48.0),
                                     QPointF(0.0, 40.0)};
    
    painter->setPen(QPen(Qt::black, 0));

    QLinearGradient gradient(12, 0, 23, 0);
    gradient.setSpread(QGradient::ReflectSpread);
    gradient.setColorAt(0, Qt::lightGray);
    gradient.setColorAt(1, Qt::black);

    painter->setBrush(gradient);
    painter->drawPolygon(vertices, 13);
}

EnemyShipTail::EnemyShipTail(QGraphicsItem *parent)
        :EnemyShipPart(parent)
{
}

QRectF EnemyShipTail::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void EnemyShipTail::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPointF vertices[8] = {QPointF(0.0, 0.0),
                                     QPointF(20.0, 0.0),
                                     QPointF(18.0, 5.0),
                                     QPointF(17.0, 6.0),
                                     QPointF(16.0, 7.0),
                                     QPointF(4.0, 7.0),
                                     QPointF(3.0, 6.0),
                                     QPointF(2.0, 5.0)};
    
    painter->setPen(QPen(Qt::black, 0));
    QLinearGradient gradient(10, 0, 21, 0);
    gradient.setSpread(QGradient::ReflectSpread);
    gradient.setColorAt(0, Qt::lightGray);
    gradient.setColorAt(1, Qt::black);
    
    painter->setBrush(gradient);
    painter->drawPolygon(vertices, 8);
}

EnemyShipWing1::EnemyShipWing1(QGraphicsItem *parent)
        :EnemyShipPart(parent)
{
}

QRectF EnemyShipWing1::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void EnemyShipWing1::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPointF vertices[3] = {QPointF(0.0, 0.0),
                                     QPointF(35.0, 0.0),
                                     QPointF(35.0, 30.0)};

    painter->setPen(QPen(Qt::black, 0));
    QLinearGradient gradient(0, 0, -35, 0);
    gradient.setSpread(QGradient::ReflectSpread);
    gradient.setColorAt(0, Qt::lightGray);
    gradient.setColorAt(1, Qt::black);

    painter->setBrush(gradient);
    painter->drawPolygon(vertices, 3);
}

EnemyShipWing2::EnemyShipWing2(QGraphicsItem *parent)
        :EnemyShipPart(parent)
{
}

QRectF EnemyShipWing2::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void EnemyShipWing2::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPointF vertices[3] = {QPointF(0.0, 0.0),
                                     QPointF(35.0, 0.0),
                                     QPointF(0.0, 30.0)};

    painter->setPen(QPen(Qt::black, 0));
    QLinearGradient gradient(30, 0, 0, 0);
    gradient.setSpread(QGradient::ReflectSpread);
    gradient.setColorAt(0, Qt::lightGray);
    gradient.setColorAt(1, Qt::black);

    painter->setBrush(gradient);
    painter->drawPolygon(vertices, 3);
}

EnemyShipWindow::EnemyShipWindow(QGraphicsItem *parent)
        :EnemyShipPart(parent)
{
}

QRectF EnemyShipWindow::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void EnemyShipWindow::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPointF vertices[4] = {QPointF(0.0, 0.0),
                                     QPointF(10.0, 0.0),
                                     QPointF(10.0, 6.0),
                                     QPointF(0.0, 6.0)};

    painter->setPen(QPen(Qt::black, 0));
    QLinearGradient gradient(0, 0, 0, 0);
    gradient.setSpread(QGradient::ReflectSpread);
    gradient.setColorAt(0, Qt::black);
    gradient.setColorAt(1, Qt::black);

    painter->setBrush(gradient);
    painter->drawPolygon(vertices, 4);
}

EnemyShip::EnemyShip()
{
    QGraphicsItem *spaceshipTail = new EnemyShipTail(this);
    QGraphicsItem *oneWing = new EnemyShipWing1(this);
    QGraphicsItem *secondWing = new EnemyShipWing2(this);
    QGraphicsItem *spaceshipBody = new EnemyShipBody(this);
    QGraphicsItem *spaceshipWindow = new EnemyShipWindow(this);

    spaceshipTail->setPos(602, 293);
    oneWing->setPos(565, 310);
    secondWing->setPos(623, 310);
    spaceshipBody->setPos(600, 300);
    spaceshipWindow->setPos(607, 332);

    timeline = new QTimeLine;

    QGraphicsItemAnimation *tailAnim = new QGraphicsItemAnimation;
    tailAnim->setItem(spaceshipTail);
    tailAnim->setTimeLine(timeline);
    tailAnim->setTranslationAt(0, 20, 0);
    tailAnim->setTranslationAt(1, -20, 0);

    QGraphicsItemAnimation *oneWingAnim = new QGraphicsItemAnimation;
    oneWingAnim->setItem(oneWing);
    oneWingAnim->setTimeLine(timeline);
    oneWingAnim->setTranslationAt(0, 20, 0);
    oneWingAnim->setTranslationAt(1, -20, 0);

    QGraphicsItemAnimation *secondWingAnim = new QGraphicsItemAnimation;
    secondWingAnim->setItem(secondWing);
    secondWingAnim->setTimeLine(timeline);
    secondWingAnim->setTranslationAt(0, 20, 0);
    secondWingAnim->setTranslationAt(1, -20, 0);

    QGraphicsItemAnimation *bodyAnim = new QGraphicsItemAnimation;
    bodyAnim->setItem(spaceshipBody);
    bodyAnim->setTimeLine(timeline);
    bodyAnim->setTranslationAt(0, 20, 0);
    bodyAnim->setTranslationAt(1, -20, 0);

    QGraphicsItemAnimation *windowAnim = new QGraphicsItemAnimation;
    windowAnim->setItem(spaceshipWindow);
    windowAnim->setTimeLine(timeline);
    windowAnim->setTranslationAt(0, 20, 0);
    windowAnim->setTranslationAt(1, -20, 0);

    timeline->setUpdateInterval(1000/25);
    timeline->setCurveShape(QTimeLine::SineCurve);
    timeline->setLoopCount(0);
    timeline->setDuration(2000);
    timeline->start();

}


EnemyShip::~EnemyShip()
{
    delete timeline;
}

QRectF EnemyShip::boundingRect() const
{
    return QRectF();
}

void EnemyShip::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
