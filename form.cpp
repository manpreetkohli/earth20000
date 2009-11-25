/************************************************************************************
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Form.cpp: the source file for the main graphics item window
 *
 ************************************************************************************/


// include necessary files
#include "sleeperthread.h"
#include "ui_form.h"
#include "spaceship.h"          // Ivan Collazo
#include <QDebug>               // Ivan Collazo
#include <QKeyEvent>            // Ivan Collazo
#include <QSound>               // Ivan Collazo
#include "constants.h"
#include "form.h"
#include "powerup.h"


// initialize all the static variables that are going to be used
int Constants::itemsWindowViewWidth = 238;
Block *Constants::currentBlock;
Block *Constants::blocks[20][27];
int Constants::levelNumber;
QPushButton *Constants::cont;

// constructor sets up the graphics item
Form::Form(QWidget *parent) :  QWidget(parent), m_ui(new Ui::Form)
{
    m_ui->setupUi(this);
    windowWidth = 1000;
    windowHeight = 725;
    mainViewWidth = 762;

    font = new QFont();
    storyText = new QLabel(this);
    t = new SleeperThread();
}


// destructor to delete the instance
Form::~Form()
{
    delete m_ui;
}


void Form::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
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


// hide and deletes all the elements (QButtons and QLabels) of the splash screen
void Form::hideElements(Ui::Form *m_ui)
{
    m_ui->title->hide();
    m_ui->newGame->hide();
    m_ui->levelEditor->hide();
    m_ui->load->hide();
    m_ui->highScores->hide();
    m_ui->credits->hide();
    m_ui->exit->hide();

    delete m_ui->title;
    delete m_ui->newGame;
    delete m_ui->levelEditor;
    delete m_ui->load;
    delete m_ui->highScores;
    delete m_ui->credits;
    delete m_ui->exit;
}


// function called when the "New Game" button is clicked on the splash screen
// hides all the elements of the splash screen and displays the first page of the story line
void Form::on_newGame_clicked()
{
    // call function to hide all the elements (QButtons and QLabels) of the splash screen
    hideElements(m_ui);

    font->setBold(true);
    font->setPointSize(78);

    storyText->setText("<font color = BLUEVIOLET> IT'S THE YEAR <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 19999 </font>");
    storyText->setFont(*font);
    storyText->setGeometry(0, 0, 762, 500);
    storyText->show();

    font->setPointSize(13);
    font->setWeight(75);

    Constants::cont = new QPushButton(this);
    Constants::cont->setText("CONTINUE");
    Constants::cont->setGeometry(300, 600, 150, 40);
    Constants::cont->setFont(*font);
    Constants::cont->show();
    Constants::cont->setStyleSheet("background-color: rgba(255, 255, 255, 100);");

    // if the continue button is clicked on the screen, call load the second screen of the story line
    QObject::connect(Constants::cont, SIGNAL(clicked()), this, SLOT(loadStoryScreen2()));
}


// function to display the second screen of the story line
// hides first screen of the story line and loads the second screen
void Form::loadStoryScreen2()
{
    // disconnect previous connection for the continue button
    Constants::cont->disconnect(this, SLOT(loadStoryScreen2()));

    font->setBold(true);
    font->setPointSize(73);

    storyText->setText("<font color = BLUEVIOLET> SHIT HAPPENS! </font>");
    storyText->setFont(*font);

    // if the continue button is clicked on the screen, load the third screen of the story line
    QObject::connect(Constants::cont, SIGNAL(clicked()), this, SLOT(loadStoryScreen3()));
}


// function to display the final screen of the story line
// hides second screen of the story line and loads the third and final screen
void Form::loadStoryScreen3()
{
    // disconnect previous connection for the continue button
    Constants::cont->disconnect(this, SLOT(loadStoryScreen3()));

    font->setBold(true);
    font->setPointSize(80);

    storyText->setText("<font color = BLUEVIOLET> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; LEVEL 1 </font>");
    storyText->setFont(*font);

    // play the level start music
    intro = new QSound("intro.wav", 0);
    intro->setLoops(1);
    intro->play();

    // if the continue button is clicked on the screen, load the first level
    QObject::connect(Constants::cont, SIGNAL(clicked()), this, SLOT(loadLevel1()));
}


// function to start the first level of the game after the story screens
void Form::loadLevel1()
{
    // sleep for 3 secs so that the intro music can finish playing
    t->msleep(3000);

    storyText->hide();

    Constants::cont->hide();
    delete Constants::cont;

    Constants::levelNumber = 1;
    if(Constants::levelNumber == 1)
    {
        m_ui->view->setBackgroundBrush(QPixmap(":universe4.jpg"));
    }
    else
    {
        m_ui->view->setBackgroundBrush(QPixmap(":level3.jpg"));
    }

    m_ui->view->setRenderHint(QPainter::Antialiasing);    
    board = new Board(m_ui->view);       // add the board to the view

    // create an instance of the player's spaceship
    playersShip = new SpaceShip(); // Ivan Collazo

    // add the player's spaceship to the board
    board->scene->addItem(playersShip); // Ivan Collazo

//    motherShip = new AlienMotherShip (); // Ivan Collazo
//    board->scene->addItem(motherShip); // Ivan Collazo

//    alienShip = new AlienSpaceShip (); // Ivan Collazo

//    timer = new QTimer();
//    QTimer *timer = new QTimer();
//    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(motherFire()));
//    timer->start(3000);

    ball = new Ball(playersShip);                  // create an instance of the ball
    board->scene->addItem(ball);        // add the ball to the board
}

void Form::loadLevel2()
{
    Constants::cont->disconnect(this, SLOT(loadLevel2()));
    Constants::cont->hide();

    if (Constants::life1 != NULL)
        Constants::life1->show();

    if (Constants::life2 != NULL)
        Constants::life2->show();

    if (Constants::life3 != NULL)
        Constants::life3->show();

    // sleep for 3 secs so that the intro music can finish playing

    t->msleep(3000);

    Constants::levelNumber = 2;
    if(Constants::levelNumber == 1)
    {
        m_ui->view->setBackgroundBrush(QPixmap(":universe4.jpg"));
    }
    else
    {
        m_ui->view->setBackgroundBrush(QPixmap(":level3.jpg"));
    }

    m_ui->view->setRenderHint(QPainter::Antialiasing);
    board = new Board(m_ui->view);       // add the board to the view

    // create an instance of the player's spaceship
    playersShip = new SpaceShip (); // Ivan Collazo

    // add the player's spaceship to the board
    board->scene->addItem(playersShip); // Ivan Collazo

    ball = new Ball(playersShip);                  // create an instance of the ball
    board->scene->addItem(ball);        // add the ball to the board
}


void Form::loadLevel3()
{
    Constants::cont->disconnect(this, SLOT(loadLevel3()));
    Constants::cont->hide();

    if (Constants::life1 != NULL)
        Constants::life1->show();

    if (Constants::life2 != NULL)
        Constants::life2->show();

    if (Constants::life3 != NULL)
        Constants::life3->show();

    // sleep for 3 secs so that the intro music can finish playing

    t->msleep(3000);

    Constants::levelNumber = 3;
    if(Constants::levelNumber == 1)
    {
        m_ui->view->setBackgroundBrush(QPixmap(":universe4.jpg"));
    }
    else
    {
        m_ui->view->setBackgroundBrush(QPixmap(":level3.jpg"));
    }

    m_ui->view->setRenderHint(QPainter::Antialiasing);
    board = new Board(m_ui->view);       // add the board to the view

    // create an instance of the player's spaceship
    playersShip = new SpaceShip (); // Ivan Collazo

    // add the player's spaceship to the board
    board->scene->addItem(playersShip); // Ivan Collazo

    ball = new Ball(playersShip);                  // create an instance of the ball
    board->scene->addItem(ball);        // add the ball to the board
}




void Form::loadLevel4()
{
    Constants::cont->disconnect(this, SLOT(loadLevel3()));
    Constants::cont->hide();

    if (Constants::life1 != NULL)
        Constants::life1->show();

    if (Constants::life2 != NULL)
        Constants::life2->show();

    if (Constants::life3 != NULL)
        Constants::life3->show();

    // sleep for 3 secs so that the intro music can finish playing

    t->msleep(3000);

    Constants::levelNumber = 5;
    if(Constants::levelNumber == 1)
    {
        m_ui->view->setBackgroundBrush(QPixmap(":universe4.jpg"));
    }
    else
    {
        m_ui->view->setBackgroundBrush(QPixmap(":level3.jpg"));
    }

    m_ui->view->setRenderHint(QPainter::Antialiasing);
    board = new Board(m_ui->view);       // add the board to the view

    // create an instance of the player's spaceship
    playersShip = new SpaceShip (); // Ivan Collazo

    // add the player's spaceship to the board
    board->scene->addItem(playersShip); // Ivan Collazo

    ball = new Ball(playersShip);                  // create an instance of the ball
    board->scene->addItem(ball);        // add the ball to the board
}


// function called when the "Level Editor" button is clicked on the splash screen
void Form::on_levelEditor_clicked()
{
    // call function to hide all the elements (QButtons and QLabels) of the splash screen
    hideElements(m_ui);

    resize(windowWidth, windowHeight);      // expand the window size
    setMinimumSize(QSize(windowWidth, windowHeight));
    setMaximumSize(QSize(windowWidth, windowHeight));
    move(120, 10);          // relocate the window after it's dimensions change

    m_ui->view->setGeometry(0, 0, mainViewWidth, windowHeight);    // change the geometry of the current view

    itemsWindow = new QGraphicsView(this);      // create a new view to place all the user option buttons in
    itemsWindow->setGeometry(763, 0, Constants::itemsWindowViewWidth, windowHeight);     // set the geometry of the new view

    itemsWindowScene = new QGraphicsScene();    // create a new scene for the new view
    itemsWindowScene->setSceneRect(0, 0, Constants::itemsWindowViewWidth - 2, windowHeight - 2);

    Constants::levelNumber = 0;
    board = new Board(m_ui->view);

    font->setBold(true);
    font->setPointSize(15);

    backgrounds = new QLabel(itemsWindow);
    backgrounds->setText("<font color = RED> Select background: <font color/>");
    backgrounds->setFont(*font);
    backgrounds->show();

    font->setPointSize(10);

    backgroundOneButton = new QPushButton(itemsWindow);
    backgroundOneButton->setText("Background one");
    backgroundOneButton->setGeometry(5, 45, 225, 40);
    backgroundOneButton->setFont(*font);

    backgroundTwoButton  = new QPushButton(itemsWindow);
    backgroundTwoButton->setText("Background two");
    backgroundTwoButton->setGeometry(5, 85, 225, 40);
    backgroundTwoButton->setFont(*font);

    backgroundThreeButton  = new QPushButton(itemsWindow);
    backgroundThreeButton->setText("Background three");
    backgroundThreeButton->setGeometry(5, 125, 225, 40);
    backgroundThreeButton->setFont(*font);

    backgroundFourButton  = new QPushButton(itemsWindow);
    backgroundFourButton->setText("Background four");
    backgroundFourButton->setGeometry(5, 165, 225, 40);
    backgroundFourButton->setFont(*font);

    backgroundOneButton->show();
    backgroundTwoButton->show();
    backgroundThreeButton->show();
    backgroundFourButton->show();

    font->setPointSize(15);

    selectBlock = new QLabel(itemsWindow);
    selectBlock->setText("<font color = RED> Select block: <font color/>");
    selectBlock->setFont(*font);
    selectBlock->show();
    selectBlock->setGeometry(0, 235, selectBlock->width(), selectBlock->height());

    emptyBlock = new EmptyBlock();
    itemsWindowScene->addItem(emptyBlock);
    emptyBlock->setPos(-370, -340);

    monoBlock = new MonoBlock();
    itemsWindowScene->addItem(monoBlock);
    monoBlock->setPos(-338, -340);

    redBlock = new RedBlock();
    itemsWindowScene->addItem(redBlock);
    redBlock->setPos(-306, -340);

    greenBlock = new GreenBlock();
    itemsWindowScene->addItem(greenBlock);
    greenBlock->setPos(-274, -340);

    blueBlock = new BlueBlock();
    itemsWindowScene->addItem(blueBlock);
    blueBlock->setPos(-242, -340);

    magentaBlock = new MagentaBlock();
    itemsWindowScene->addItem(magentaBlock);
    magentaBlock->setPos(-210, -340);

    yellowBlock = new YellowBlock();
    itemsWindowScene->addItem(yellowBlock);
    yellowBlock->setPos(-178, -340);

    currentBlockLabel = new QLabel(itemsWindow);
    currentBlockLabel->setText("<font color = RED> Current selection: <font color/>");
    currentBlockLabel->setFont(*font);
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

    font->setPointSize(10);

    save = new QPushButton(itemsWindow);
    save->setText("Save");
    save->setGeometry(65, 500, 100, 25);
    save->setFont(*font);
    connect(save, SIGNAL(clicked()), this, SLOT(save_clicked()));

    done = new QPushButton(itemsWindow);
    done->setText("Done");
    done->setGeometry(10, 550, 100, 25);
    done->setFont(*font);
    connect(done, SIGNAL(clicked()), this, SLOT(done_clicked()));

    reset = new QPushButton(itemsWindow);
    reset->setText("Reset");
    reset->setGeometry(120, 550, 100, 25);
    reset->setFont(*font);
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
    t->msleep(5000);

    // remove the transparent "unselected" blocks from the level editor and double
    // the transparency for the selected blocks
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 27; j++)
        {
//            if (Constants::blocks[i][j]->getColor1() == 7 && Constants::blocks[i][j]->getColor2() == 7)
            if (!Constants::positions.contains(Constants::blocks[i][j]->pos()))
            {

                m_ui->view->scene()->removeItem(Constants::blocks[i][j]);
                delete Constants::blocks[i][j];
            }
            else
            {
                qDebug() << "1st is " << Constants::blocks[i][j]->getColor1();
                qDebug() << "2nd is " << Constants::blocks[i][j]->getColor2();
                Constants::blocks[i][j]->setOpacity(2.0);
            }
        }
    }

    itemsWindow->deleteLater();

    resize(mainViewWidth, windowHeight);      // expand the window size
    setMinimumSize(QSize(mainViewWidth, windowHeight));   // change the minimum size of the window
    setMaximumSize(QSize(mainViewWidth, windowHeight));   // change the maximum size of the window
    move(250, 10);          // relocate the window after it's dimensions change

    ball = new Ball(playersShip);                  // create ball in the level editor
    m_ui->view->scene()->addItem(ball);

    playersShip = new SpaceShip();      // create spaceship in the level editor
    m_ui->view->scene()->addItem(playersShip);
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

    // write each block to the file (the color's initial gets written)
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            bool temp = false;

            for (int k = 0; k < Constants::positions.size(); k++)
            {
                if (Constants::positions.at(k) == Constants::blocks[i][j]->pos())
                {
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

    resize(mainViewWidth, windowHeight);      // expand the window size
    setMinimumSize(QSize(mainViewWidth, windowHeight));   // change the minimum size of the window
    setMaximumSize(QSize(mainViewWidth, windowHeight));   // change the maximum size of the window
    m_ui->view->setGeometry(0, 0, mainViewWidth, windowHeight);

    Constants::levelNumber = 6;
    Board* board = new Board(m_ui->view);

    ball = new Ball(playersShip);
    m_ui->view->scene()->addItem(ball);

    playersShip = new SpaceShip();
    m_ui->view->scene()->addItem(playersShip);

//    timer = new QTimer();
//    QObject::connect(timer, SIGNAL(timeout()), m_ui->view->scene(), SLOT(advance()));

//    Set the timer to trigger every 5 ms.
//    timer->start(5);

//    Constants::inLevelEditorMode = false;
}


// function that gets called when a key is pressed during the game
void Form::keyPressEvent(QKeyEvent *event)// Ivan Collazo
{
    switch(event->key())
    {
        case Qt::Key_A:
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
            if (playersShip->getShipPosX() >= 330)
                playersShip->moveBy(0, 0);
            else
            {
                playersShip->moveBy(30,0);
                playersShip->setShipPosX(30);
                ball->setShipPositon(playersShip->getShipPosX());
            }
            break;

        // Ivan Collazo
        // Case statement when space bar is pressed to fire weapons
        case Qt::Key_Space:
             if ((Constants::levelNumber == 1) || (Constants::levelNumber == 2)) // Levels with no weapons fired
             {
                 qDebug() << "NO WEAPONS";
             }
             else if (Constants::levelNumber == 5) // Level with Missiles Fired
             {
                 ShipsMissiles *missiles = new ShipsMissiles(); // Ivan Collazo
                 missiles->setShipPosition(playersShip->getShipPosX());
                 board->scene->addItem(missiles); // Ivan Collazo
                 qDebug() << "FIRE MISSILES";
             }
             else // Level with Bullets Fired
             {
                 bullets = new ShipBullet(); // Ivan Collazo
                 bullets->setShipPosition(playersShip->getShipPosX());
                 board->scene->addItem(bullets); // Ivan Collazo
                 qDebug() << "FIRE";
             }
             break;

        case Qt::Key_Return:
            if(!board->timer->isActive())
             {
                board->connectTimerToBall();         // connect the timer to the ball
                break;
            }
        case Qt::Key_T:
            board->stopTimer();
            break;
    }
}


void Form::motherFire()
    {
        motherShip->fire();
       // motherShipBullet = new MotherShipBullet();
       // board->scene->addItem(motherShipBullet);
    }
