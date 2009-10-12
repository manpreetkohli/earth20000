#ifndef FORM_H
#define FORM_H

#include <QtGui/QWidget>
#include <QKeyEvent> // Ivan Collazo

namespace Ui {
    class Form;
}

class Form : public QWidget
{
    Q_OBJECT
public:

    Form(QWidget *parent = 0);
    ~Form();

    void setupSplashScreen();

protected:
    void changeEvent(QEvent *e);
    void keyPressEvent(QKeyEvent *); // Ivan Collazo

private:
    Ui::Form *m_ui;

private slots:
    void on_newGame_clicked();
    void on_exit_clicked();
};

#endif // FORM_H
