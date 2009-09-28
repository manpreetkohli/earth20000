#include<QApplication>
//#include<QGraphicsScene>
#include<QGraphicsView>


int main(int argc, char** argv)
{
    QApplication app(argc, argv);


  //  QGraphicsScene *scene = new QGraphicsScene();

    QGraphicsView *view = new QGraphicsView();

    view->show();

    view->setGeometry(250, 40, 750, 725);






    return app.exec();


}


