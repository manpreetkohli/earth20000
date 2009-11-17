/*
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Form.cpp: the source file for the main graphics item window
 *
 */


// include necessary files
#include "sleeperthread.h"
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


// function to start the first level of the game after the story screens
void Form::loadLevel1()
{
    // sleep for 3 secs so that the intro music can finish playing
    SleeperThread *t = new SleeperThread();
    t->msleep(3000);

    storyText3->hide();
    delete storyText3;

    cont->hide();
    delete cont;

    m_ui->view->setBackgroundBrush(QPixmap(":universe4.jpg"));
    m_ui->view->setRenderHint(QPainter::Antialiasing);
    Constants::levelNumber = 1;
    board = new Board(m_ui->view);       // add the board to the view

    // create an instance of the player's spaceship
    playersShip = new SpaceShip (); // Ivan Collazo

    //EnemyShip *ship = new EnemyShip();
    //board->scene->addItem(ship);

    // add the player's spaceship to the board
    board->scene->addItem(playersShip); // Ivan Collazo

    ball = new Ball();                  // create an instance of the ball
    board->scene->addItem(ball);        // add the ball to the board
}


// function to display the final screen of the story line
// hides second screen of the story line and loads the third and final screen
void Form::loadStoryScreen3()
{
    storyText2->hide();
    delete storyText2;

    // disconnect previous connection for the continue button
    cont->disconnect(this, SLOT(loadStoryScreen3()));

    font->setBold(true);
    font->setPointSize(80);

    storyText3 = new QLabel(this);
    storyText3->setText("<font color = BLUEVIOLET> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; LEVEL 1 </font>");
    storyText3->setFont(*font);
    storyText3->setGeometry(0, 0, 762, 500);
    storyText3->show();

    // play the level start music
    QSound *intro = new QSound("intro.wav", 0);
    intro->setLoops(1);
    intro->play();

    // if the continue button is clicked on the screen, load the first level
    QObject::connect(cont, SIGNAL(clicked()), this, SLOT(loadLevel1()));
}


// function to display the second screen of the story line
// hides first screen of the story line and loads the second screen
void Form::loadStoryScreen2()
{
    storyText1->hide();
    delete storyText1;

    // disconnect previous connection for the continue button
    cont->disconnect(this, SLOT(loadStoryScreen2()));

    font->setBold(true);
    font->setPointSize(73);

    storyText2 = new QLabel(this);
    storyText2->setText("<font color = BLUEVIOLET> SHIT HAPPENS! </font>");
    storyText2->setFont(*font);
    storyText2->setGeometry(0, 0, 762, 500);
    storyText2->show();

    // if the continue button is clicked on the screen, load the third screen of the story line
    QObject::connect(cont, SIGNAL(clicked()), this, SLOT(loadStoryScreen3()));
}


// function called when the "New Game" button is clicked on the splash screen
// hides all the elements of the splash screen and displays the first page of the story line
void Form::on_newGame_clicked()
{
    // call function to hide all the elements (QButtons and QLabels) of the splash screen
    hideElements(m_ui);

    font = new QFont();
    font->setBold(true);
    font->setPointSize(78);

    storyText1 = new QLabel(this);
    storyText1->setText("<font color = BLUEVIOLET> IT'S THE YEAR <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 19999 </font>");
    storyText1->setFont(*font);
    storyText1->setGeometry(0, 0, 762, 500);
    storyText1->show();

    font->setPointSize(13);
    font->setBold(true);
    font->setWeight(75);

    cont = new QPushButton(this);
    cont->setText("CONTINUE");
    cont->setGeometry(300, 600, 150, 40);
    cont->setFont(*font);
    cont->show();
    cont->setStyleSheet("background-color: rgba(255, 255, 255, 100);");

    // if the continue button is clicked on the screen, call load the second screen of the story line
    QObject::connect(cont, SIGNAL(clicked()), this, SLOT(loadStoryScreen2()));
}


// initialize all the static variables that are going to be used
int Constants::itemsWindowViewWidth = 238;
Block *Constants::currentBlock;
Block *Constants::blocks[20][27];
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
    setMinimumSize(QSize(Constants::windowWidth, Constants::windowHeight));
    setMaximumSize(QSize(Constants::windowWidth, Constants::windowHeight));
    move(120, 10);          // relocate the window after it's dimensions change

    m_ui->view->setGeometry(0, 0, Constants::mainViewWidth, Constants::windowHeight);    // change the geometry of the current view

    // create a new view to place all the user option buttons in
    QGraphicsView *itemsWindow = new QGraphicsView(this);

    itemsWindow->setGeometry(763, 0, Constants::itemsWindowViewWidth, Constants::windowHeight);     // set the geometry of the new view

    Constants::levelNumber = 0;
    board = new Board(m_ui->view);

    QGraphicsScene *itemsWindowScene = new QGraphicsScene();    // create a new scene for the new view
    itemsWindowScene->setSceneRect(0, 0, Constants::itemsWindowViewWidth - 2, Constants::windowHeight - 2);

    // add various blocks and labels to the itemsWindowScene
    QFont *fontForLabels = new QFont();
    fontForLabels->setBold(true);
    fontForLabels->setPointSize(15);

    QLabel *backgrounds = new QLabel(itemsWindow);
    backgrounds->setText("<font color = RED> Select background: <font color/>");
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
    selectBlock->setGeometry(0, 235, selectBlock->width(), selectBlock->height());

    Block *emptyBlock = new EmptyBlock();
    itemsWindowScene->addItem(emptyBlock);
    emptyBlock->setPos(-370, -340);

    Block *block = new MonoBlock();
    itemsWindowScene->addItem(block);
    block->setPos(-338, -340);

    Block *redBlock = new RedBlock();
    itemsWindowScene->addItem(redBlock);
    redBlock->setPos(-306, -340);

    Block *greenBlock = new GreenBlock();
    itemsWindowScene->addItem(greenBlock);
    greenBlock->setPos(-274, -340);

    Block *blueBlock = new BlueBlock();
    itemsWindowScene->addItem(blueBlock);
    blueBlock->setPos(-242, -340);

    Block *magentaBlock = new MagentaBlock();
    itemsWindowScene->addItem(magentaBlock);
    magentaBlock->setPos(-210, -340);

    Block *yellowBlock = new YellowBlock();
    itemsWindowScene->addItem(yellowBlock);
    yellowBlock->setPos(-178, -340);

    QLabel *currentBlockLabel = new QLabel(itemsWindow);
    currentBlockLabel->setText("<font color = RED> Current selection: <font color/>");
    currentBlockLabel->setFont(*fontForLabels);
    currentBlockLabel->show();
    currentBlockLabel->setGeometry(0, 360, currentBlockLabel->width(), currentBlockLabel->height());

    Constants::currentBlock = new EmptyBlock();
    itemsWindowScene->addItem(Constants::currentBlock);
    Constants::currentBlock->setPos(-274, -225);

    // connect the various background buttons to actual background loading
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
    itemsWindow->setScene(itemsWindowScene);
    itemsWindow->show();    // display the new view
}


// slot to load background 1 for the level editor
void Form::backgroundOne_clicked()
{
    m_ui->view->setBackgroundBrush(QPixmap(":universe4.jpg"));
}


// slot to load background 2 for the level editor
void Form::backgroundTwo_clicked()
{
    m_ui->view->setBackgroundBrush(QPixmap(":bg2.jpg"));
}


// slot to load background 3 for the level editor
void Form::backgroundThree_clicked()
{
    m_ui->view->setBackgroundBrush(QPixmap(":bg3.jpg"));
}


// slot to load background 4 for the level editor
void Form::backgroundFour_clicked()
{
    m_ui->view->setBackgroundBrush(QPixmap(":bg4.jpg"));
}


// if the done button is clicked in the level editor
void Form::done_clicked()
{
    // play the level start music
    QSound *intro = new QSound("intro.wav", 0);
    intro->setLoops(1);
    intro->play();

    // sleep for 3 secs so that the intro music can finish playing
    SleeperThread *t = new SleeperThread();
    t->msleep(5000);

    // remove the transparent "unselected" blocks from the level editor and double
    // the transparency for the selected blocks
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 27; j++)
        {
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

    ball = new Ball();                  // create ball in the level editor
    m_ui->view->scene()->addItem(ball);

    playersShip = new SpaceShip();      // create spaceship in the level editor
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
    // clear the positions and colors vectors so that the previously clicked blocks don't get drawn
    Constants::positions.clear();
    Constants::colors.clear();

    // delete the board pointer and create a fresh instance of the board
    delete board;
    board = new Board(m_ui->view);
}


// if the save button gets clicked
void Form::save_clicked()
{
    // open file for writing
    QFile file("levels.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Cannot open file for writing: ";
        exit(-1);
    }

    QTextStream out(&file);

    // write each block to the file (the block's color's initial gets written)
    for (int i = 0; i < 20; i++)
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
                            out << "w";
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
                out << "t";
        }

        out << endl;
    }
}


// function that gets called when a key is pressed during the game
void Form::keyPressEvent(QKeyEvent *event)// Ivan Collazo
{
    switch(event->key())
    {
        case Qt::Key_A:

        qDebug() << playersShip->pos();
            if (playersShip->getShipPosX() <= -330)
                playersShip->moveBy(0, 0);
            else
            {

                playersShip->moveBy(-30,0);
                playersShip->setShipPosX(-30);
                ball->setShipPositon(playersShip->getShipPosX());
            }
            break;

        case Qt::Key_D:
            qDebug() << playersShip->pos();
            if (playersShip->getShipPosX() >= 330)
                playersShip->moveBy(0, 0);
            else
            {
                qDebug() << playersShip->pos();
                playersShip->moveBy(30,0);
                playersShip->setShipPosX(30);
                ball->setShipPositon(playersShip->getShipPosX());
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


// if load game is clicked on the splash screen
void Form::on_load_clicked()
{
    // open the file for reading
    QFile file("levels.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Cannot open file for writing: ";
        exit(-1);
    }

    if (!file.exists())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("<font size= \"15\"> ERROR!!! File not found! </font>");
        err->show();
    }

    hideElements(m_ui);     // hide all the elements on the splash screen

    resize(Constants::mainViewWidth, Constants::windowHeight);      // expand the window size
    setMinimumSize(QSize(Constants::mainViewWidth, Constants::windowHeight));   // change the minimum size of the window
    setMaximumSize(QSize(Constants::mainViewWidth, Constants::windowHeight));   // change the maximum size of the window
    m_ui->view->setGeometry(0, 0, Constants::mainViewWidth, Constants::windowHeight);

    Constants::levelNumber = 6;
    Board* board = new Board(m_ui->view);

    ball = new Ball();
    m_ui->view->scene()->addItem(ball);

    playersShip = new SpaceShip();
    m_ui->view->scene()->addItem(playersShip);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), m_ui->view->scene(), SLOT(advance()));

    // Set the timer to trigger every 5 ms.
    timer->start(5);

    Constants::inLevelEditorMode = false;
}
