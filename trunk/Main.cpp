/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * Main.cpp: creates an app and an object of type Form
 *
 */


// necessary include files
#include "form.h"
#include <QApplication>

// main()
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Form form;      // create an object of type Form

    // set the dimensions of the graphics window
    form.setGeometry(250, 40, 800, 725);

    form.show();    // now actually display the window

    return app.exec();
}
