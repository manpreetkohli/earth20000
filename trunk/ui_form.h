/********************************************************************************
** Form generated from reading ui file 'form.ui'
**
** Created: Thu Dec 3 16:16:20 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGraphicsView *view;
    QLabel *title;
    QPushButton *newGame;
    QPushButton *levelEditor;
    QPushButton *load;
    QPushButton *controls;
    QPushButton *exit;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(762, 725);
        Form->setMinimumSize(QSize(762, 725));
        Form->setMaximumSize(QSize(762, 725));
        Form->setAutoFillBackground(false);
        view = new QGraphicsView(Form);
        view->setObjectName(QString::fromUtf8("view"));
        view->setGeometry(QRect(0, 0, 762, 725));
        view->setStyleSheet(QString::fromUtf8("background-image: url(:/spacebattle.jpg);"));
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setInteractive(true);
        view->setCacheMode(QGraphicsView::CacheBackground);
        title = new QLabel(Form);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(130, 30, 500, 70));
        QFont font;
        font.setPointSize(50);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        title->setAlignment(Qt::AlignCenter);
        newGame = new QPushButton(Form);
        newGame->setObjectName(QString::fromUtf8("newGame"));
        newGame->setGeometry(QRect(180, 300, 400, 71));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        newGame->setFont(font1);
        levelEditor = new QPushButton(Form);
        levelEditor->setObjectName(QString::fromUtf8("levelEditor"));
        levelEditor->setGeometry(QRect(180, 379, 400, 71));
        levelEditor->setFont(font1);
        load = new QPushButton(Form);
        load->setObjectName(QString::fromUtf8("load"));
        load->setGeometry(QRect(180, 459, 400, 71));
        load->setFont(font1);
        controls = new QPushButton(Form);
        controls->setObjectName(QString::fromUtf8("controls"));
        controls->setGeometry(QRect(180, 540, 400, 71));
        controls->setFont(font1);
        exit = new QPushButton(Form);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(180, 620, 400, 71));
        exit->setFont(font1);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Earth: 20000", 0, QApplication::UnicodeUTF8));
        title->setText(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:50pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">EARTH: 20000 </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        newGame->setStyleSheet(QApplication::translate("Form", "background-color: rgba(255, 255, 255, 100);", 0, QApplication::UnicodeUTF8));
        newGame->setText(QApplication::translate("Form", "NEW GAME", 0, QApplication::UnicodeUTF8));
        levelEditor->setStyleSheet(QApplication::translate("Form", "background-color: rgba(255, 255, 255, 100);", 0, QApplication::UnicodeUTF8));
        levelEditor->setText(QApplication::translate("Form", "LEVEL EDITOR", 0, QApplication::UnicodeUTF8));
        load->setStyleSheet(QApplication::translate("Form", "background-color: rgba(255, 255, 255, 100);", 0, QApplication::UnicodeUTF8));
        load->setText(QApplication::translate("Form", "SAVED GAMES", 0, QApplication::UnicodeUTF8));
        controls->setStyleSheet(QApplication::translate("Form", "background-color: rgba(255, 255, 255, 100);", 0, QApplication::UnicodeUTF8));
        controls->setText(QApplication::translate("Form", "CONTROLS", 0, QApplication::UnicodeUTF8));
        exit->setStyleSheet(QApplication::translate("Form", "background-color: rgba(255, 255, 255, 100);", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("Form", "EXIT", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
