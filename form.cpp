#include "form.h"
#include "ui_form.h"
#include "board.h"
#include "ball.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelFive.h"
#include "spaceship.h"

using namespace std;

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

    SpaceShip *playersShip = new SpaceShip ();

    board->scene->addItem(ball);

    board->scene->addItem(playersShip);
}
