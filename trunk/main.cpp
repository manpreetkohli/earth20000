/*
#include "block.h"

#include <QtGui>

#undef main

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QGraphicsScene scene(0, 0 , 1600, 1200);

    Block *singleBlock = new Block(50, 50);
    scene.addItem(singleBlock);

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap(":space1.jpg"));
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "ROFLcopter"));
    view.resize(1200, 800);
    view.show();

    return app.exec();
}*/

#include <QtGui>

#include "block.h"

#include <math.h>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QGraphicsScene scene(-200, -200, 400, 400);

    int yValue = -20;

    for(int i = 0; i < 10; i++)
    {
        Block *robot = new Block;
        robot->scale(1.2, 1.2);
        robot->setPos(0, yValue);
        scene.addItem(robot);
        yValue = yValue +24;
    }

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setBackgroundBrush(QColor(230, 200, 167));
    view.setWindowTitle("Drag and Drop Robot");
    view.show();

    return app.exec();
}



