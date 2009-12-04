/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Form.cpp: the source file for the main graphics item window. This
 * class does a lot of stuff including taking care of button presses
 * on the splash screen, level transitions, level editor logic, and
 * key press logic.
 *
 * Storyline graphics and slides created by Natraj Subramanian
 */

#ifndef FORM_H
#define FORM_H

#include <QtGui>
#include "board.h"
#include "ball.h"
#include "shipbullet.h"             // Ivan Collazo
#include "shipsmissiles.h"          // Ivan Collazo
#include "block.h"
#include "alienmothership.h"        // Ivan Collazo
#include "alienspaceship.h"         // Ivan collazo
#include "mothershipbullet.h"       // Ivan Collazo
#include "alienshipbullet.h"        // Ivan Collazo

namespace Ui
{
    class Form;
}

class Form : public QWidget
{
    Q_OBJECT

    private:
        Ui::Form *m_ui;
        Board *board;
        QSound *intro;
        SleeperThread *t;
        SpaceShip *playersShip;                 // Ivan Collazo
        QGraphicsView *itemsWindow;
        QGraphicsScene *itemsWindowScene;
        QLabel *backgrounds;
        QPushButton *backgroundOneButton, *backgroundTwoButton, *backgroundThreeButton, *backgroundFourButton;
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
        QPushButton *done;
        QPushButton *reset;
        int windowWidth;
        int windowHeight;
        int mainViewWidth;
        AlienMotherShip *motherShip;            // Ivan Collazo
        AlienSpaceShip *alienShip;              // Ivan Collazo
        MotherShipBullet *motherShipBullet;     // Ivan Collazo
        AlienShipBullet *alienBullet;           // Ivan collazo
        QFont *font;
        QLabel *storyText;
        Ball *ball;
        ShipBullet *bullets;                    // Ivan Collazo
        ShipsMissiles *missiles;                //Ivan Collazo
        QTimer *timer;
        QTimer *timer3;
        QPushButton *skipIntro;
        QTimer *timer4;

        void hideElements(Ui::Form *m_ui);
        void setupLevel(int levelNumber);
        void saveBackground(QString bg);

    public:
        Form(QWidget *parent = 0);        
        ~Form();

    protected:
        void changeEvent(QEvent *e);
        void keyPressEvent(QKeyEvent *);        // Ivan Collazo

    private slots:
        void on_controls_clicked();
        void on_load_clicked();
        void on_levelEditor_clicked();
        void on_newGame_clicked();
        void on_exit_clicked();
        void loadLevel1();
        void loadLevel2();
        void loadLevel3();
        void loadLevel4();
        void loadStoryScreen9();
        void loadStoryScreen8();
        void loadStoryScreen7();
        void loadStoryScreen6();
        void loadStoryScreen5();
        void loadStoryScreen4();
        void loadStoryScreen3();
        void loadStoryScreen2();
        void save_clicked();
        void done_clicked();
        void reset_clicked();
        void backgroundOne_clicked();
        void backgroundTwo_clicked();
        void backgroundThree_clicked();
        void backgroundFour_clicked();
        void alienFire();
        void motherFire();
};

#endif // FORM_H
