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


namespace Ui {
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
        static int windowWidth;
        static int windowHeight;
        static int mainViewWidth;
        static int shipPos;
        QFont *font;
        QPushButton *cont;
        QLabel *storyText1;
        QLabel *storyText2;
        QLabel *storyText3;


    private slots:
        void loadLevel1();
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

};

#endif // FORM_H
