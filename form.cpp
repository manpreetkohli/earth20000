/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Form.cpp: the source file for the main graphics item window
 *
 */


// include the header file for this class
#include "form.h"

// create an instance of the player's space ship
SpaceShip *playersShip; // Ivan Collazo

// constructor sets up the graphics item
Form::Form(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Form)
{
    m_ui->setupUi(this);
}

// destructor to delete the instance
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

// exit the program if the exit button is clicked
void Form::on_exit_clicked()
{
    exit(1);
}

// function called when the "New Game" button is clicked on the splash screen
void Form::on_newGame_clicked()
{
    // hide all the elements (QButtons and QLabels) of the splash screen
    m_ui->title->hide();
    m_ui->newGame->hide();
    m_ui->levelEditor->hide();
    m_ui->controls->hide();
    m_ui->highScores->hide();
    m_ui->credits->hide();
    m_ui->exit->hide();

    // set a new background for level 1
    m_ui->view->setBackgroundBrush(QPixmap(":universe4.jpg"));

    //m_ui->view->setRenderHint(QPainter::Antialiasing);
    //m_ui->view->setCacheMode(QGraphicsView::CacheBackground);


    
    Board *board = new Board(m_ui->view);       // add the board to the view
    board->connectTimerToBall();         // connect the timer to the ball
    Ball *ball = new Ball();        // create an instance of the ball

    // create an instance of the player's spaceship
    playersShip = new SpaceShip (); // Ivan Collazo

    board->scene->addItem(ball);        // add the ball to the board

    playersShip->performShipMovement(); // Ivan Collazo

    // add the player's spaceship to the board
    board->scene->addItem(playersShip); // Ivan Collazo
}

// function that gets called when a key is pressed during the game
void Form::keyPressEvent(QKeyEvent *event)// Ivan Collazo
{
    switch(event->key())
    {
            case Qt::Key_A:
            qDebug() << "key pressed Left";
            playersShip->moveBy(-10,0);
            break;

            case Qt::Key_S:
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

