#include "form.h"

#include <QApplication>

int main(int argc, char **argv)
{

    QApplication app(argc, argv);
    Form form;

    form.setGeometry(250, 40, 800, 725);
    form.show();


    return app.exec();

}
