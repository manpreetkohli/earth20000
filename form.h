/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Form.h: the header file for the class that draws the main graphics item window
 *
 */

#ifndef FORM_H
#define FORM_H


#include <QtGui>
#include "board.h"
#include "ball.h"
#include "shipbullet.h"         // Ivan Collazo
#include "shipsmissiles.h"      // Ivan Collazo
#include "block.h"
#include "alienmothership.h" // Ivan Collazo
//#include "alienspaceship.h" // Ivan collazo
#include "mothershipbullet.h" // Ivan Collazo


namespace Ui
{
    class Form;
}

class Form : public QWidget
{
    Q_OBJECT

    public:
        Form(QWidget *parent = 0);        
        ~Form();
        void stopTimer();


    protected:
        void changeEvent(QEvent *e);
        void keyPressEvent(QKeyEvent *); // Ivan Collazo
        void soundEffect(); // Ivan Collazo

    private:
        Ui::Form *m_ui;
        Board *board;
        void hideElements(Ui::Form *m_ui);


        QSound *intro;
        SleeperThread *t;
        SpaceShip *playersShip; // Ivan Collazo
        QGraphicsView *itemsWindow;
        QGraphicsScene *itemsWindowScene;
        QLabel *backgrounds;
        QPushButton *backgroundOneButton ;
        QPushButton *backgroundTwoButton ;
        QPushButton *backgroundThreeButton ;
        QPushButton *backgroundFourButton ;
        QLabel *selectBlock;
        Block *emptyBlock;
        Block *monoBlock;
        Block *redBlock;
        Block *greenBlock;
        Block *blueBlock;
        Block *magentaBlock;
        Block *yellowBlock;
        QLabel *currentBlockLabel;
        QPushButton *save;
        QPushButton *done ;
        QPushButton *reset ;


        int windowWidth;
        int windowHeight;
        int mainViewWidth;
        int itemsWindowViewWidth;


        AlienMotherShip *motherShip; // Ivan Collazo
        //AlienSpaceShip *alienShip; // Ivan Collazo
        MotherShipBullet *motherShipBullet; // Ivan Collazo

        static int shipPos;
        QFont *font;
        QLabel *storyText;

        Ball *ball;        // create an instance of the ball
        ShipBullet *bullets; // Ivan Collazo
        ShipsMissiles *missiles; //Ivan Collazo

        QTimer *timer;

    private slots:
        void loadLevel1();
        void loadStoryScreen9();
        void loadStoryScreen8();
        void loadStoryScreen7();
        void loadStoryScreen6();
        void loadStoryScreen5();
        void loadStoryScreen4();
        void loadStoryScreen3();
        void loadStoryScreen2();
        void on_load_clicked();
        void on_levelEditor_clicked();
        void on_newGame_clicked();
        void on_exit_clicked();
        void save_clicked();
        void done_clicked();
        void reset_clicked();
        void backgroundOne_clicked();
        void backgroundTwo_clicked();
        void backgroundThree_clicked();
        void backgroundFour_clicked();
        void motherFire();

        void loadLevel2();
        void loadLevel3();
        void loadLevel4();

};

#endif // FORM_H
