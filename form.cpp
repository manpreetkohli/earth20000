#include "form.h"
#include "ui_form.h"
#include "board.h"
#include "ball.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelFive.h"
#include "spaceship.h"  // Ivan Collazo
#include <QDebug>       // Ivan Collazo
#include <QKeyEvent>    // Ivan Collazo

//using namespace std;

SpaceShip *playersShip; // Ivan Collazo

Form::Form(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Form)
{
    m_ui->setupUi(this);
}

Form::~Form()
{

    delete m_ui;
}

void Form::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void Form::on_exit_clicked()
{
    exit(1);
}



void Form::on_newGame_clicked()
{
    // TODO:: make separate fn for the next 7 statements as they'll be reused a lot
    m_ui->title->hide();
    m_ui->newGame->hide();
    m_ui->levelEditor->hide();
    m_ui->controls->hide();
    m_ui->highScores->hide();
    m_ui->credits->hide();
    m_ui->exit->hide();

    m_ui->view->setBackgroundBrush(QPixmap(":universe4.jpg"));

    Board *board = new Board(m_ui->view);
    board->showBoard();

    Ball *ball = new Ball();

    playersShip = new SpaceShip (); // Ivan Collazo

    board->scene->addItem(ball);

   // playersShip->performShipMovement(); // Ivan Collazo

    board->scene->addItem(playersShip); // Ivan Collazo
}

void Form::keyPressEvent(QKeyEvent *event)// Ivan Collazo
{
    switch(event->key())
    {
            case Qt::Key_A: //Key_A  _Left
            qDebug() << "key pressed Left";
            playersShip->moveBy(-10,0);
            break;

            case Qt::Key_S: //Key_S _Right
            qDebug() << "key pressed Right";
            playersShip->moveBy(10,0);
            break;

            case Qt::Key_Space:
            qDebug() << "key pressed Space now";
            break;
            default:
            qDebug() << "key pressed " << event->text().data();
    }
}

