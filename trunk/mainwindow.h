#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <QDebug>
#include <QGraphicsItem>

using namespace std;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

//private slots:


private:
    Ui::MainWindow *ui;
};

class TestShipScene : public QGraphicsScene
{
    public:

    void keyPressEvent(QKeyEvent *event);


};
#endif // MAINWINDOW_H
