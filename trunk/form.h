/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Form.h: the header file for the class that draws the main graphics item window
 *
 */

#ifndef FORM_H
#define FORM_H

// include necessary files
#include "ui_form.h"
#include "board.h"
#include "ball.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelFive.h"
#include "spaceship.h"  // Ivan Collazo
#include <QDebug>       // Ivan Collazo
#include <QKeyEvent>    // Ivan Collazo
#include <QtGui/QWidget>

namespace Ui {
    class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(QWidget *parent = 0);
    ~Form();


protected:
    void changeEvent(QEvent *e);
    void keyPressEvent(QKeyEvent *); // Ivan Collazo

private:
    Ui::Form *m_ui;
    void setupSplashScreen();

private slots:
    void on_newGame_clicked();
    void on_exit_clicked();
};

#endif // FORM_H
