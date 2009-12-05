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

// added by Manpreet Kohli
// initialize all the static variables that are going to be used
int Constants::itemsWindowViewWidth = 238;
Block *Constants::currentBlock;
Block *Constants::blocks[20][27];
int Constants::levelNumber;
QPushButton *Constants::cont;
QPushButton *skipIntro;
QTimer *timer3 = new QTimer();  // Ivan Collazo
QTimer *timer4 = new QTimer();  // Ivan Collazo

/*!
  added by Manpreet Kohli
  constructor sets up the graphics item
  */
Form::Form(QWidget *parent) :  QWidget(parent), m_ui(new Ui::Form)
{
    m_ui->setupUi(this);
    windowWidth = 1000;
    windowHeight = 725;
    mainViewWidth = 762;
    font = new QFont();
    storyText = new QLabel(this);
    t = new SleeperThread();
    timer3 = new QTimer();
    timer4 = new QTimer();
    bgNo = 0;
}

/*!
  destructor to delete the instance
  */
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

/*!
  added by Manpreet Kohli
  exit the program if the exit button is clicked
  */
void Form::on_exit_clicked()
{
    exit(1);
}

/*!
  added by Manpreet Kohli
  hide and deletes all the elements (QButtons and QLabels) of the splash screen
  */
void Form::hideElements(Ui::Form *m_ui)
{
    m_ui->title->hide();
    m_ui->newGame->hide();
    m_ui->levelEditor->hide();
    m_ui->load->hide();
    m_ui->controls->hide();
    m_ui->exit->hide();

    delete m_ui->title;
    delete m_ui->newGame;
    delete m_ui->levelEditor;
    delete m_ui->load;
    delete m_ui->controls;
    delete m_ui->exit;
}

/*!
  added by Manpreet Kohli
  function called when the "New Game" button is clicked on the splash screen
  hides all the elements of the splash screen and displays the first page of the story line
  Storyline slides added by Natraj Subramanian
  */
void Form::on_newGame_clicked()
{
    // call function to hide all the elements (QButtons and QLabels) of the splash screen
    hideElements(m_ui);
    m_ui->view->setStyleSheet("background-image: url(:/Storyline/slide1.jpg)");

    font->setPointSize(13);
    font->setWeight(75);

    Constants::cont = new QPushButton(this);
    Constants::cont->setText("CONTINUE");
    Constants::cont->setGeometry(200, 600, 150, 40);
    Constants::cont->setFont(*font);
    Constants::cont->show();
    Constants::cont->setStyleSheet("background-color: rgba(255, 255, 255, 100);");

    // Added by Natraj Subramanian
    // Skip the intro and head to the starting level straightaway
    skipIntro = new QPushButton(this);
    skipIntro->setText("SKIP INTRO");
    skipIntro->setGeometry(400, 600, 150, 40);
    skipIntro->setFont(*font);
    skipIntro->show();
    skipIntro->setStyleSheet("background-color: rgba(255, 255, 255, 100);");

    // if the continue button is clicked on the screen, load the second screen of the story line
    QObject::connect(Constants::cont, SIGNAL(clicked()), this, SLOT(loadStoryScreen2()));
    // if the skip intro button is clicked, load the ninth screen of the story line
    QObject::connect(skipIntro, SIGNAL(clicked()), this, SLOT(loadStoryScreen9()));
}

/*!
  added by Manpreet Kohli
  function to display the second screen of the story line
  hides first screen of the story line and loads the second screen
  Storyline slides added by Natraj Subramanian
  */
void Form::loadStoryScreen2()
{
    // disconnect previous connection for the continue button
    Constants::cont->disconnect(this, SLOT(loadStoryScreen2()));
    m_ui->view->setStyleSheet("background-image: url(:/Storyline/slide2.jpg)");
    // if the continue button is clicked on the screen, load the third screen of the story line
    QObject::connect(Constants::cont, SIGNAL(clicked()), this, SLOT(loadStoryScreen3()));
}

void Form::loadStoryScreen3()
{
    // disconnect previous connection for the continue button
    Constants::cont->disconnect(this, SLOT(loadStoryScreen3()));
    m_ui->view->setStyleSheet("background-image: url(:/Storyline/slide3.jpg)");
    // if the continue button is clicked on the screen, load the fourth screen of the story line
    QObject::connect(Constants::cont, SIGNAL(clicked()), this, SLOT(loadStoryScreen4()));
}

void Form::loadStoryScreen4()
{
    // disconnect previous connection for the continue button
    Constants::cont->disconnect(this, SLOT(loadStoryScreen4()));
    m_ui->view->setStyleSheet("background-image: url(:/Storyline/slide4.jpg)");
    // if the continue button is clicked on the screen, load the fifth screen of the story line
    QObject::connect(Constants::cont, SIGNAL(clicked()), this, SLOT(loadStoryScreen5()));
}

void Form::loadStoryScreen5()
{
    // disconnect previous connection for the continue button
    Constants::cont->disconnect(this, SLOT(loadStoryScreen5()));
    m_ui->view->setStyleSheet("background-image: url(:/Storyline/slide5.jpg)");
    // if the continue button is clicked on the screen, load the sixth screen of the story line
    QObject::connect(Constants::cont, SIGNAL(clicked()), this, SLOT(loadStoryScreen6()));
}

void Form::loadStoryScreen6()
{
    // disconnect previous connection for the continue button
    Constants::cont->disconnect(this, SLOT(loadStoryScreen6()));
    m_ui->view->setStyleSheet("background-image: url(:/Storyline/slide6.jpg)");
    // if the continue button is clicked on the screen, load the seventh screen of the story line
    QObject::connect(Constants::cont, SIGNAL(clicked()), this, SLOT(loadStoryScreen7()));
}

void Form::loadStoryScreen7()
{
    // disconnect previous connection for the continue button
    Constants::cont->disconnect(this, SLOT(loadStoryScreen7()));
    m_ui->view->setStyleSheet("background-image: url(:/Storyline/slide7.jpg)");
    // if the continue button is clicked on the screen, load the eighth screen of the story line
    QObject::connect(Constants::cont, SIGNAL(clicked()), this, SLOT(loadStoryScreen8()));
}

void Form::loadStoryScreen8()
{
    // disconnect previous connection for the continue button
    Constants::cont->disconnect(this, SLOT(loadStoryScreen8()));
    m_ui->view->setStyleSheet("background-image: url(:/Storyline/slide8.jpg)");
    // if the continue button is clicked on the screen, load the ninth screen of the story line
    QObject::connect(Constants::cont, SIGNAL(clicked()), this, SLOT(loadStoryScreen9()));
}

void Form::loadStoryScreen9()
{
    Constants::cont->setGeometry(300, 600, 150, 40);

    // disconnect previous connection for the continue button
    Constants::cont->disconnect(this, SLOT(loadStoryScreen9()));

    skipIntro->hide();
    delete skipIntro;
    
    // play the start level music
    QSound *intro = new QSound("intro.wav", 0);
    intro->setLoops(1);
    intro->play();

    m_ui->view->setStyleSheet("background-image: url(:/Storyline/level1.jpg)");
    // if the continue button is clicked on the screen, load level one
    QObject::connect(Constants::cont, SIGNAL(clicked()), this, SLOT(loadLevel1()));
}

/*!
  added by Manpreet Kohli, modified by Ivan Collazo
  sets up the level including board, ship, and ball
  */
void Form::setupLevel(int levelNumber)
{
    if (levelNumber == 1)
    {
        storyText->hide();
        Constants::cont->hide();
        delete Constants::cont;
        Constants::levelNumber = 1;
        m_ui->view->setBackgroundBrush(QPixmap(":universe4.jpg"));
    }
    if (levelNumber == 2)
    {
        Constants::cont->disconnect(this, SLOT(loadLevel2()));
        Constants::levelNumber = 2;
    }
    if (levelNumber == 3)
    {
        Constants::cont->disconnect(this, SLOT(loadLevel3()));
        Constants::levelNumber = 3;
    }
    if (levelNumber == 4)
    {
        Constants::cont->disconnect(this, SLOT(loadLevel4()));
        Constants::levelNumber = 4;
    }

    if (levelNumber == 2 || levelNumber == 3 || levelNumber == 4)
    {
        Constants::cont->hide();
        if (Constants::life1 != NULL)
            Constants::life1->show();
        if (Constants::life2 != NULL)
            Constants::life2->show();
        if (Constants::life3 != NULL)
            Constants::life3->show();
        m_ui->view->setBackgroundBrush(QPixmap(":level3.jpg"));
    }

    // sleep for 3 secs so that the intro music can finish playing
    t->msleep(3000);

    m_ui->view->setRenderHint(QPainter::Antialiasing);
    board = new Board(m_ui->view);                      // add the board to the view

    // create an instance of the player's spaceship
    playersShip = new SpaceShip();          // Ivan Collazo

    // add the player's spaceship to the board
    board->scene->addItem(playersShip);     // Ivan Collazo

    // Ivan Collazo
    if (levelNumber == 3)
    {
        alienShip = new AlienSpaceShip ();  // Ivan Collazo
        board->scene->addItem(alienShip);   // Ivan Collazo     
        QObject::connect(timer3, SIGNAL(timeout()), this, SLOT(alienFire()));   // connect to start alien firing
        timer3->start(2000);
    }

    // Ivan Collazo
    if (levelNumber == 4)
    {
        timer3->disconnect(board->scene, SLOT(alienFire()));
        timer3->stop();
        motherShip = new AlienMotherShip ();    // Ivan Collazo
        board->scene->addItem(motherShip);      // Ivan Collazo
        QObject::connect(timer4, SIGNAL(timeout()), this, SLOT(motherFire()));  // connect to start mother ship firing
        timer4->start(3000);
    }

    ball = new Ball(playersShip);                  // create an instance of the ball
    board->scene->addItem(ball);                   // add the ball to the board
}

/*!
  added by Manpreet Kohli
  function to start the first level of the game after the story screens
  */
void Form::loadLevel1()
{
    setupLevel(1);
}

/*!
  added by Manpreet Kohli
  function to start the second level of the game after the story screens
  */
void Form::loadLevel2()
{
    setupLevel(2);
}

/*!
  added by Manpreet Kohli
  function to start the third level of the game after the story screens
  */
void Form::loadLevel3()
{
   setupLevel(3);
}

/*!
  added by Manpreet Kohli
  function to start the final level of the game after the story screens
  */
void Form::loadLevel4()
{
    setupLevel(4);
}

/*!
  added by Manpreet Kohli
  function called when the "Level Editor" button is clicked on the splash screen
  */
void Form::on_levelEditor_clicked()
{
    // call function to hide all the elements (QButtons and QLabels) of the splash screen
    hideElements(m_ui);

    resize(windowWidth, windowHeight);          // expand the window size
    setMinimumSize(QSize(windowWidth, windowHeight));
    setMaximumSize(QSize(windowWidth, windowHeight));
    move(120, 10);                              // relocate the window after it's dimensions change

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
    itemsWindow->show();            // display the new view
}

/*!
  added by Manpreet Kohli
  saves the background selected by the user to a file
  */
void Form::saveBackground(QString bg)
{
    // open file for writing
    QFile file("bgs.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Cannot open file for writing ";
        exit(-1);
    }

    if (!file.exists())
    {
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("<font size= \"15\"> ERROR!!! File not found! No saved games exist!</font>");
        err->show();
    }

    QTextStream out(&file);
    out << bg;
}

/*!
  added by Manpreet Kohli
  slot to load background 1 for the level editor
  */
void Form::backgroundOne_clicked()
{
    m_ui->view->setBackgroundBrush(QPixmap(":universe4.jpg"));
    bgNo = 1;
    }

/*!
  added by Manpreet Kohli
  slot to load background 2 for the level editor
  */
void Form::backgroundTwo_clicked()
{
    m_ui->view->setBackgroundBrush(QPixmap(":bg2.jpg"));
    bgNo = 2;
    }

/*!
  added by Manpreet Kohli
  slot to load background 3 for the level editor
  */
void Form::backgroundThree_clicked()
{
    m_ui->view->setBackgroundBrush(QPixmap(":bg3.jpg"));
    bgNo = 3;
}

/*!
  added by Manpreet Kohli
  slot to load background 4 for the level editor
  */
void Form::backgroundFour_clicked()
{
    m_ui->view->setBackgroundBrush(QPixmap(":bg4.jpg"));
    bgNo = 4;
    saveBackground(":bg4.jpg");
}

/*!
  added by Manpreet Kohli
  if the done button is clicked in the level editor
  */
void Form::done_clicked()
{
    // play the level start music
    QSound *intro = new QSound("intro.wav", 0);
    intro->setLoops(1);
    intro->play();

    // sleep for 5 secs so that the intro music can finish playing
    t->msleep(5000);

    // remove the transparent "unselected" blocks from the level editor and double
    // the transparency for the selected blocks
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            if (!Constants::positions.contains(Constants::blocks[i][j]->pos()))
            {
                m_ui->view->scene()->removeItem(Constants::blocks[i][j]);
                delete Constants::blocks[i][j];
            }
            else
            {
                Constants::blocks[i][j]->setOpacity(2.0);
            }
        }
    }

    itemsWindow->deleteLater();

    resize(mainViewWidth, windowHeight);      // expand the window size
    setMinimumSize(QSize(mainViewWidth, windowHeight));   // change the minimum size of the window
    setMaximumSize(QSize(mainViewWidth, windowHeight));   // change the maximum size of the window
    move(250, 10);                            // relocate the window after it's dimensions change

    m_ui->view->scene()->setSceneRect(0, 0, mainViewWidth - 5, windowHeight - 5);       // set dimensions of the scene

    playersShip = new SpaceShip();            // create spaceship in the level editor
    m_ui->view->scene()->addItem(playersShip);

    ball = new Ball(playersShip);             // create ball in the level editor
    m_ui->view->scene()->addItem(ball);
}

/*!
  added by Manpreet Kohli
  if the reset button gets clicked
  */
void Form::reset_clicked()
{
    // clear the positions and colors vectors so that the previously clicked blocks don't get drawn
    Constants::positions.clear();
    Constants::colors.clear();

    // delete the board pointer and create a fresh instance of the board
    delete board;
    board = new Board(m_ui->view);
}

/*!
  added by Manpreet Kohli
  if the save button gets clicked
  */
void Form::save_clicked()
{
    if (bgNo == 0)
        saveBackground("");         // to make sure a new file always gets created
    else if (bgNo == 1)
        saveBackground(":universe4.jpg");
    else if (bgNo == 2)
        saveBackground(":bg2.jpg");
    else if (bgNo == 3)
        saveBackground(":bg3.jpg");
    else if (bgNo == 4)
        m_ui->view->setBackgroundBrush(QPixmap(":bg4.jpg"));

    // open file for writing
    QFile file("levels.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Cannot open file for writing ";
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

/*!
  added by Manpreet Kohli
  if load game is clicked on the splash screen
  */
void Form::on_load_clicked()
{
    // open the file for reading
    QFile file("levels.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Cannot open file for writing ";
        QErrorMessage *err = new QErrorMessage();
        err->showMessage("<font size= \"15\"> ERROR!!! File not found! </font>");
        err->show();

        QObject::connect(err, SIGNAL(accepted()), err, SLOT(close()));
    }

    else
    {
        hideElements(m_ui);     // hide all the elements on the splash screen

        resize(mainViewWidth, windowHeight);      // expand the window size
        setMinimumSize(QSize(mainViewWidth, windowHeight));   // change the minimum size of the window
        setMaximumSize(QSize(mainViewWidth, windowHeight));   // change the maximum size of the window
        m_ui->view->setGeometry(0, 0, mainViewWidth, windowHeight);

        Constants::levelNumber = 6;
        board = new Board(m_ui->view);

        playersShip = new SpaceShip();
        m_ui->view->scene()->addItem(playersShip);

        ball = new Ball(playersShip);
        m_ui->view->scene()->addItem(ball);
    }
}

/*!
  added by Ivan Collazo, modified by Manpreet Kohli
  function that gets called when a key is pressed during the game
  */
void Form::keyPressEvent(QKeyEvent *event)          // Ivan Collazo
{
    switch(event->key())
    {
        case Qt::Key_A: // move space ship to the left
            if (!Constants::timer->isActive())
            {
                if (playersShip->getShipPosX() <= -330)
                {
                    playersShip->moveBy(0, 0);
                    ball->moveBy(0, 0);
                }
                else
                {
                    playersShip->moveBy(-30, 0);
                    playersShip->setShipPosX(-30);
                    ball->moveBy(-30, 0);
                    ball->setPositionX(-30);
                    ball->setShipPositon(playersShip->getShipPosX());
                }
            }
            else
            {
                if (playersShip->getShipPosX() <= -330)
                    playersShip->moveBy(0, 0);
                else
                {
                    playersShip->moveBy(-30,0);
                    playersShip->setShipPosX(-30);
                    ball->setShipPositon(playersShip->getShipPosX());
                }
            }
            break;

        case Qt::Key_D: // move space ship to the right
            if (!Constants::timer->isActive())
            {
                if (playersShip->getShipPosX() >= 330)
                    playersShip->moveBy(0, 0);

                else
                {
                    playersShip->moveBy(30,0);
                    playersShip->setShipPosX(30);
                    ball->moveBy(30, 0);
                    ball->setPositionX(30);
                    ball->setShipPositon(playersShip->getShipPosX());
                }
            }

            else
            {
                if (playersShip->getShipPosX() >= 330)
                    playersShip->moveBy(0, 0);
                else
                {
                    playersShip->moveBy(30,0);
                    playersShip->setShipPosX(30);
                    ball->setShipPositon(playersShip->getShipPosX());
                }
            }
            break;

        // Ivan Collazo
        // Case statement when space bar is pressed to fire weapons
        case Qt::Key_Space:
             if ((Constants::levelNumber == 1) || (Constants::levelNumber == 2)) // Levels with no weapons fired
             {

             }
             else if (Constants::levelNumber == 4) // Level with Missiles Fired
             {  
                 missiles = new ShipsMissiles(); // Ivan Collazo
                 missiles->setShipMissilesXPosition(playersShip->getShipPosX()); // Ivan Collazo
                 board->scene->addItem(missiles); // Ivan Collazo
                 playersShip->fireMissiles()    ; // Ivan Collazo
             }
             else // Level with Bullets Fired
             {
                 bullets = new ShipBullet(); // Ivan Collazo
                 bullets->setShipBulletXPosition(playersShip->getShipPosX()); // Ivan Collazo
                 board->scene->addItem(bullets); // Ivan Collazo
                 playersShip->fireBullets(); // Ivan Collazo
             }
             break;

         case Qt::Key_Return:
             // added by Natraj Subramanian
             if(!Constants::timer->isActive())
             {
                 board->connectTimerToBall();         // connect the timer to the ball
                 break;
             }

         case Qt::Key_Period:
             // added by Manpreet Kohli
             // if period key is pressed, set cheat mode to on
             ball->setSkip(true);
             break;
    }
}


/*!
  this method creates and stop mothership firing added by Ivan Collazo
  */
void Form::motherFire()
{
    // stops mother ship firing when player loses game
    if (Constants::count == 0)
    {
        timer4->disconnect(board->scene, SLOT(motherFire()));
        timer4->stop();
    }

    // stops mothership firing when game is won
    if (Constants::levelNumber == 5)
    {
        timer4->disconnect(board->scene, SLOT(motherFire()));
        timer4->stop();
    }

    // stops mother ship firing when mother ship is destoryed
    else if (motherShip->getShipHit() == 5)
    {
        timer4->disconnect(board->scene, SLOT(motherFire()));
        timer4->stop();
    }

    // keeps firing mother ship bullets
    else
    {
        motherShip->fire();;
    }
}

/*!
  this method creates and stop alien ship firing added by Ivan Collazo
  */

void Form::alienFire()
{
    // stops alien ship firing when player loses game
    if (Constants::count == 0 )
    {
            timer3->disconnect(board->scene, SLOT(alienFire()));
            timer3->stop();
    }

    // stops alien ship firing when level is won
    else if (Constants::levelNumber == 4)
    {
        timer3->disconnect(board->scene, SLOT(alienFire()));
        timer3->stop();
    }

    // stops alien ship firing when alien ship is destoryed
    else if (alienShip->getShipHit() == 0)
    {
        timer3->disconnect(board->scene, SLOT(alienFire()));
        timer3->stop();
    }

    // keeps firing alien bullets
    else
    {
        alienShip->fire();
    }
}


void Form::on_controls_clicked()
{
    hideElements(m_ui);

    QLabel *a = new QLabel(this);
    a->setText("<font color = RED> A: &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Move Left </font>");
    a->setGeometry(QRect(200, 30, 700, 70));
    a->show();

    QLabel *d = new QLabel(this);
    d->setText("<font color = RED> D: &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Move Right </font>");
    d->show();
    d->setGeometry(QRect(200, 80, 1000, 70));

    QLabel *enter = new QLabel(this);
    enter->setText("<font color = RED> Enter: &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Release ball </font>");
    enter->show();
    enter->setGeometry(QRect(75, 130, 1000, 70));

    QLabel *space = new QLabel(this);
    space->setText("<font color = RED> SPACE BAR: &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Fire bullets or missiles (only activated in level 3 and 4) </font>");
    space->show();
    space->setGeometry(QRect(40, 180, 1000, 70));

    QLabel *period = new QLabel(this);
    period->setText("<font color = RED> Period (.): &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Activate cheat mode (skip to next level) </font>");
    period->show();
    period->setGeometry(QRect(40, 230, 1000, 70));

    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    font.setWeight(75);

    a->setFont(font);
    d->setFont(font);
    enter->setFont(font);
    space->setFont(font);
    period->setFont(font);

    font.setPointSize(13);

    QPushButton *back = new QPushButton(this);
    back->setText("BACK");
    back->setGeometry(340, 550, 100, 50);
    back->setFont(font);
    back->show();
    back->setStyleSheet("background-color: rgba(255, 255, 255, 100);");

}
