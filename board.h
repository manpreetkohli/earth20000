#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsView>
#include <QGraphicsScene>


class Board
{

    public:
        QGraphicsScene *scene;
    //    QGraphicsView *view;

        QTimer *timer;
     //   QPalette *palette;
      //  QPixmap *bgImage;

        Board(QGraphicsView *view);
        void showBoard();

};
#endif // BOARD_H
