#include "firstlevel.h"

#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    FirstLevel *firstLevel = new FirstLevel();
    firstLevel->setupFirstLevel();

    return app.exec();

}
