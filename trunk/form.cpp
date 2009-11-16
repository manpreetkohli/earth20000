/*!
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Form.cpp: the source file for the main graphics item window
 *
 */


// include necessary files
#include "ui_form.h"

#include "ball.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelFive.h"
#include "spaceship.h"  // Ivan Collazo
#include <QDebug>       // Ivan Collazo
#include <QKeyEvent>    // Ivan Collazo
#include <QSound>      // Ivan Collazo
#include <QtGui/QWidget>
#include "block.h"
#include "constants.h"
#include "enemyShip.h"

// include the header file for this class
#include "form.h"

// create an instance of the player's space ship
SpaceShip *playersShip; // Ivan Collazo

Ball *ball;        // create an instance of the ball

bool Constants::inLevelEditorMode;
int Constants::levelNumber;

// constructor sets up the graphics item
Form::Form(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Form)
{
    Constants::inLevelEditorMode = false;
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

// hide all the elements (QButtons and QLabels) of the splash screen
void Form::hideElements(Ui::Form *m_ui)
{
    m_ui->title->hide();
    m_ui->newGame->hide();
    m_ui->levelEditor->hide();
    m_ui->load->hide();
    m_ui->highScores->hide();
    m_ui->credits->hide();
    m_ui->exit->hide();

    m_ui->title->close();
    m_ui->newGame->close();
    m_ui->levelEditor->close();
    m_ui->load->close();
    m_ui->highScores->close();
    m_ui->credits->close();
    m_ui->exit->close();
    
    delete m_ui->title;
    delete m_ui->newGame;
    delete m_ui->levelEditor;
    delete m_ui->load;
    delete m_ui->highScores;
    delete m_ui->credits;
    delete m_ui->exit;
}

// function called when the "New Game" button is clicked on the splash screen
void Form::on_newGame_clicked()
{
    // call function to hide all the elements (QButtons and QLabels) of the splash screen
    hideElements(m_ui);

    // set a new background for level 1
    m_ui->view->setBackgroundBrush(QPixmap(":universe4.jpg"));

    m_ui->view->setRenderHint(QPainter::Antialiasing);
    //m_ui->view->setCacheMode(QGraphicsView::CacheBackground);

    Constants::levelNumber = 5;

    board = new Board(m_ui->view);       // add the board to the view

    // create an instance of the player's spaceship
    playersShip = new SpaceShip (); // Ivan Collazo

    //EnemyShip *ship = new EnemyShip();

    //board->scene->addItem(ship);

//     add the player's spaceship to the board
    board->scene->addItem(playersShip); // Ivan Collazo

    //QSound *intro = new QSound("intro.wav", 0);
    //intro->setLoops(1);
    //intro->play();

//    QTimer timer(0);
    //timer.start(10000);

    ball = new Ball();        // create an instance of the ball

//    QTimer timer;

    board->scene->addItem(ball);        // add the ball to the board

//    timer.singleShot(10000, board->scene, SLOT(update()));


}

// initialize all the static variables that are going to be used
int Constants::itemsWindowViewWidth = 238;
Block *Constants::currentBlock;
Block *Constants::blocks[21][27];
int Constants::windowWidth = 1000;
int Constants::windowHeight = 725;
int Constants::mainViewWidth = 762;

// function called when the "Level Editor" button is clicked on the splash screen
void Form::on_levelEditor_clicked()
{
    // call function to hide all the elements (QButtons and QLabels) of the splash screen
    hideElements(m_ui);

    Constants::inLevelEditorMode = true;
    resize(Constants::windowWidth, Constants::windowHeight);      // expand the window size
    setMinimumSize(QSize(Constants::windowWidth, Constants::windowHeight));   // change the minimum size of the window
    setMaximumSize(QSize(Constants::windowWidth, Constants::windowHeight));   // change the maximum size of the window
    move(120, 10);          // relocate the window after it's dimensions change

    m_ui->view->setGeometry(0, 0, Constants::mainViewWidth, Constants::windowHeight);    // change the geometry of the current view

    // create a new view to place all the user option buttons in
    QGraphicsView *itemsWindow = new QGraphicsView(this);

    itemsWindow->setGeometry(763, 0, Constants::itemsWindowViewWidth, Constants::windowHeight);     // set the geometry of the new view

    Constants::levelNumber = 0;

    board = new Board(m_ui->view);

    fflush(0);
    QGraphicsScene *itemsWindowScene = new QGraphicsScene();    // create a new scene for the new view

    QLabel *backgrounds = new QLabel(itemsWindow);

    backgrounds->setText("<font color = RED> Select background: <font color/>");

    QFont *fontForLabels = new QFont();

    fontForLabels->setBold(true);
    fontForLabels->setPointSize(15);



    backgrounds->setFont(*fontForLabels);
    backgrounds->show();

    QFont font;
    font.setPointSize(10);
    font.setBold(true);

    QPushButton *backgroundOneButton = new QPushButton(itemsWindow);
    backgroundOneButton->setText("Background one");
    backgroundOneButton->setGeometry(5, 45, 225, 40);
    backgroundOneButton->setFont(font);

    QPushButton *backgroundTwoButton  = new QPushButton(itemsWindow);
    backgroundTwoButton->setText("Background two");
    backgroundTwoButton->setGeometry(5, 85, 225, 40);
    backgroundTwoButton->setFont(font);

    QPushButton *backgroundThreeButton  = new QPushButton(itemsWindow);
    backgroundThreeButton->setText("Background three");
    backgroundThreeButton->setGeometry(5, 125, 225, 40);
    backgroundThreeButton->setFont(font);

    QPushButton *backgroundFourButton  = new QPushButton(itemsWindow);
    backgroundFourButton->setText("Background four");
    backgroundFourButton->setGeometry(5, 165, 225, 40);
    backgroundFourButton->setFont(font);

    backgroundOneButton->show();
    backgroundTwoButton->show();
    backgroundThreeButton->show();
    backgroundFourButton->show();


    QLabel *selectBlock = new QLabel(itemsWindow);
    selectBlock->setText("<font color = RED> Select block: <font color/>");
    selectBlock->setFont(*fontForLabels);
    selectBlock->show();
    selectBlock->setGeometry(0, 225, 250, 60);

    itemsWindow->setScene(itemsWindowScene);

    Block *emptyBlock = new EmptyBlock();
    itemsWindowScene->addItem(emptyBlock);
    emptyBlock->setPos(-375, -330);

    Block *block = new MonoBlock();
    itemsWindowScene->addItem(block);
    block->setPos(-343, -330);

    Block *redBlock = new RedBlock();
    itemsWindowScene->addItem(redBlock);
    redBlock->setPos(-311, -330);

    Block *greenBlock = new GreenBlock();
    itemsWindowScene->addItem(greenBlock);
    greenBlock->setPos(-279, -330);

    Block *blueBlock = new BlueBlock();
    itemsWindowScene->addItem(blueBlock);
    blueBlock->setPos(-247, -330);

    Block *magentaBlock = new MagentaBlock();
    itemsWindowScene->addItem(magentaBlock);
    magentaBlock->setPos(-215, -330);

    Block *yellowBlock = new YellowBlock();
    itemsWindowScene->addItem(yellowBlock);
    yellowBlock->setPos(-183, -330);

    QLabel *currentBlockLabel = new QLabel(itemsWindow);
    currentBlockLabel->setText("<font color = RED> Current selection: <font color/>");
    currentBlockLabel->setFont(*fontForLabels);
    currentBlockLabel->show();
    currentBlockLabel->setGeometry(0, 360, 250, 60);


    Constants::currentBlock = new EmptyBlock();
    itemsWindowScene->addItem(Constants::currentBlock);
    Constants::currentBlock->setPos(-105, 100);


    connect(backgroundOneButton, SIGNAL(clicked()), this, SLOT(backgroundOne_clicked()));
    connect(backgroundTwoButton, SIGNAL(clicked()), this, SLOT(backgroundTwo_clicked()));
    connect(backgroundThreeButton, SIGNAL(clicked()), this, SLOT(backgroundThree_clicked()));
    connect(backgroundFourButton, SIGNAL(clicked()), this, SLOT(backgroundFour_clicked()));

    QPushButton *save = new QPushButton(itemsWindow);
    save->setText("Save");
    save->setGeometry(65, 500, 100, 25);
    save->setFont(font);

    connect(save, SIGNAL(clicked()), this, SLOT(save_clicked()));

    QPushButton *done = new QPushButton(itemsWindow);
    done->setText("Done");
    done->setGeometry(10, 550, 100, 25);
    done->setFont(font);

    connect(done, SIGNAL(clicked()), this, SLOT(done_clicked()));

    QPushButton *reset = new QPushButton(itemsWindow);
    reset->setText("Reset");
    reset->setGeometry(120, 550, 100, 25);
    reset->setFont(font);

    connect(reset, SIGNAL(clicked()), this, SLOT(reset_clicked()));

    save->show();
    done->show();
    reset->show();

    m_ui->view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    itemsWindow->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    itemsWindow->show();    // display the new view

}

void Form::backgroundOne_clicked()
{
    m_ui->view->setBackgroundBrush(QPixmap(":universe4.jpg"));
}

void Form::backgroundTwo_clicked()
{
    m_ui->view->setBackgroundBrush(QPixmap(":bg2.jpg"));
}

void Form::backgroundThree_clicked()
{
    m_ui->view->setBackgroundBrush(QPixmap(":bg3.jpg"));
}

void Form::backgroundFour_clicked()
{
    m_ui->view->setBackgroundBrush(QPixmap(":bg4.jpg"));
}

//if the done button is clicked
void Form::done_clicked()
{
    qDebug() << "size = " << Constants::colors.size();
    qDebug() << "size = " << Constants::positions.size();


    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            qDebug() << "1 " << Constants::blocks[i][j]->pos();


            if (!Constants::positions.contains(Constants::blocks[i][j]->pos()))
                m_ui->view->scene()->removeItem(Constants::blocks[i][j]);

            else
                Constants::blocks[i][j]->setOpacity(2.0);
        }
    }

    resize(Constants::mainViewWidth, Constants::windowHeight);      // expand the window size
    setMinimumSize(QSize(Constants::mainViewWidth, Constants::windowHeight));   // change the minimum size of the window
    setMaximumSize(QSize(Constants::mainViewWidth, Constants::windowHeight));   // change the maximum size of the window
    move(250, 10);          // relocate the window after it's dimensions change


    //Ball *ball = new Ball();

    ball = new Ball(); // create ball in the level editor

    m_ui->view->scene()->addItem(ball);

    playersShip = new SpaceShip();
    m_ui->view->scene()->addItem(playersShip);

    QTimer *timer = new QTimer();       // create a new QTimer() instance

    QObject::connect(timer, SIGNAL(timeout()), m_ui->view->scene(), SLOT(advance()));

    // Set the timer to trigger every 0 ms.
    timer->start(0);

    Constants::inLevelEditorMode = false;

}


// if the reset button gets clicked
void Form::reset_clicked()
{
    // clear the positions vector so that the previously clicked blocks don't get drawn
    Constants::positions.clear();

    Constants::colors.clear();

    // delete the board pointer and create a fresh instance of the board
    delete board;
    board = new Board(m_ui->view);
}


// if the save button gets clicked
void Form::save_clicked()
{
    QFile file("levels.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Cannot open file for writing: ";
        exit(0);
    }

    QTextStream out(&file);

    qDebug() << "kabaddi " << Constants::positions.size();

    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            bool temp = false;

            for (int k = 0; k < Constants::positions.size(); k++)
            {
                if (Constants::positions.at(k) == Constants::blocks[i][j]->pos())
                {
                    qDebug() << "color is " << Constants::colors.at(k);
                    switch(Constants::colors.at(k))
                    {
                        case 0:
                            out << "w";        // don't know if space is needed
                            break;
                        case 2:
                            out << "r";
                            break;
                        case 3:
                            out << "g";
                            break;
                        case 4:
                            out << "b";
                            break;
                        case 5:
                            out << "m";
                            break;
                        case 6:
                            out << "y";
                            break;
                        case 7:
                            out << "t";
                            break;
                    }

                    temp = true;
                    break;
                }
            }

            if (temp == false)
            {
                out << "t";

            }
        }

        out << endl;

    }
}


// function that gets called when a key is pressed during the game
void Form::keyPressEvent(QKeyEvent *event)// Ivan Collazo
{
    switch(event->key())
    {
        case Qt::Key_A: //Key_Left
            if (playersShip->getShipPosX() <= -340)
                playersShip->moveBy(0, 0);

            else
            {
                playersShip->moveBy(-20,0);
                playersShip->setShipPosX(-20);
                //qDebug() << playersShip->getShipPosX();
                ball->setShipPositon(playersShip->getShipPosX());
                //playersShip->setShipDirection(1);
                //qDebug() << playersShip->getShipDirection();
                //qDebug() << "if 1 works";
            }

            break;

        case Qt::Key_D: //Key_Right

            if (playersShip->getShipPosX() >= 340)
                playersShip->moveBy(0, 0);

            else
            {
                playersShip->moveBy(20,0);
                playersShip->setShipPosX(20);
                //qDebug() << playersShip->getShipPosX();
                ball->setShipPositon(playersShip->getShipPosX());
                //playersShip->setShipDirection(2);
                //qDebug() << playersShip->getShipDirection();
                //qDebug() << "if 2 works";
            }

            break;

        case Qt::Key_Space:
            qDebug() << "FIRE";
            break;

        case Qt::Key_Return:
            board->connectTimerToBall();         // connect the timer to the ball
            break;
    }
}

void Form::soundEffect()
{
      QSound *soundEffect = new QSound("/Users/SkyNet/Desktop//barebear.wav",0);
      soundEffect->setLoops(-1);
      soundEffect->play();
  }


void Form::on_load_clicked()
{

    QFile file("levels.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Cannot open file for writing: ";


    }

    if (!file.exists())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("<font size= \"15\"> ERROR!!! File not found! </font>");
        err->show();
    }


    hideElements(m_ui);

    resize(Constants::mainViewWidth, Constants::windowHeight);      // expand the window size
    setMinimumSize(QSize(Constants::mainViewWidth, Constants::windowHeight));   // change the minimum size of the window
    setMaximumSize(QSize(Constants::mainViewWidth, Constants::windowHeight));   // change the maximum size of the window

    m_ui->view->setGeometry(0, 0, Constants::mainViewWidth, Constants::windowHeight);

    Constants::levelNumber = 6;

    Board* board = new Board(m_ui->view);



    ball = new Ball(); // create ball in the level editor

    m_ui->view->scene()->addItem(ball);

    playersShip = new SpaceShip();
    m_ui->view->scene()->addItem(playersShip);

    QTimer *timer = new QTimer();       // create a new QTimer() instance

    QObject::connect(timer, SIGNAL(timeout()), m_ui->view->scene(), SLOT(advance()));

    // Set the timer to trigger every 0 ms.
    timer->start(5);

    Constants::inLevelEditorMode = false;

}
