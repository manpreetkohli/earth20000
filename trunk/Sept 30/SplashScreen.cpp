// include files used by this class
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QPalette>
#include <QPixmap>
#include <QGridLayout>


#include <iostream>

#include "FirstLevel.h"


int setupSplashScreen(int argc, char** argv)
{
    QApplication app(argc, argv);

    // create the menu widget
    QWidget *menu = new QWidget();

    // include an image from the Qt directory
    QPalette *palette = new QPalette();
    QPixmap *image = new QPixmap(":spacebattle.jpg");

    // set the background to the image included
    palette->setBrush(QPalette::Background, QBrush(*image));
    menu->setPalette(*palette);

    QLabel *title = new QLabel("<font color= RED> Earth: 20000 </font>", menu, 0);

    // create font to be used for the title
    QFont *font = new QFont();
    font->setBold(true);
    font->setPointSize(50);

    // now set font for the title
    title->setFont(*font);

    title->setFixedSize(500, 70);
    title->setAlignment(Qt::AlignCenter);

    menu->setGeometry(250, 40, 750, 725);

    font->setPointSize(15);

    // create all the buttons for the menu
    QPushButton *newGame = new QPushButton("NEW GAME", menu);
    newGame->setFont(*font);
    newGame->setFixedSize(400, 70);
    newGame->setStyleSheet("background-color: rgba(255, 255, 255, 40%)");

    QPushButton *levelEditor = new QPushButton("LEVEL EDITOR", menu);
    levelEditor->setFont(*font);
    levelEditor->setFixedSize(400, 70);
    levelEditor->setStyleSheet("background-color: rgba(255, 255, 255, 40%)");

    QPushButton *controls = new QPushButton("CONTROLS", menu);
    controls->setFont(*font);
    controls->setFixedSize(400, 70);
    controls->setStyleSheet("background-color: rgba(255, 255, 255, 40%)");

    QPushButton *highScores = new QPushButton("HIGH SCORES", menu);
    highScores->setFont(*font);
    highScores->setFixedSize(400, 70);
    highScores->setStyleSheet("background-color: rgba(255, 255, 255, 40%)");

    QPushButton *credits = new QPushButton("CREDITS", menu);
    credits->setFont(*font);
    credits->setFixedSize(400, 70);
    credits->setStyleSheet("background-color: rgba(255, 255, 255, 40%)");

    QPushButton *exit = new QPushButton("EXIT", menu);
    exit->setFont(*font);
    exit->setFixedSize(400, 70);
    exit->setStyleSheet("background-color: rgba(255, 255, 255, 40%)");

    // set up the main grid
    QGridLayout *layout = new QGridLayout();

    // set up a grid for the title
    QGridLayout *titleLayout = new QGridLayout();
    titleLayout->addWidget(title, 0, 0, Qt::AlignTop);

    // set up a grid for the buttons
    QGridLayout *buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(newGame, 0, 0, Qt::AlignCenter);
    buttonsLayout->addWidget(levelEditor, 20, 0, Qt::AlignCenter);
    buttonsLayout->addWidget(controls, 40, 0, Qt::AlignCenter);
    buttonsLayout->addWidget(highScores, 60, 0, Qt::AlignCenter);
    buttonsLayout->addWidget(credits, 80, 0, Qt::AlignCenter);
    buttonsLayout->addWidget(exit, 100, 0, Qt::AlignCenter);

    // now add the titleLayout and the buttonsLayout into the main layout
    layout->addLayout(titleLayout, 0, 0, Qt::AlignTop);
    layout->addLayout(buttonsLayout, 0, 0, Qt::AlignBottom);

    // add the main layout to the menu widget
    menu->setLayout(layout);

    // set up a maximum size for the window
    menu->setMaximumSize(750, 750);

    // actually display the menu
    menu->show();

    // make exit button quit the game
    QObject::connect(exit, SIGNAL(clicked()),
                     &app, SLOT(quit()));

    std::cout << "hey";
    QObject::connect(newGame, SIGNAL(clicked()),
                     &app, SLOT(SplashScreen::startGame(app)));

    return app.exec();


} /* end setUpSplashScreen() ------------------------------------------- */


void startGame(QApplication app)
{
    app.quit();
    FirstLevel *firstLevel = new FirstLevel();
    firstLevel->setupFirstLevel();

}




