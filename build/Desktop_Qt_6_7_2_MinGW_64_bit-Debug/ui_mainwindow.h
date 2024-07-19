/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *play_button;
    QPushButton *exit_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/cities_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color: green;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 140, 81, 71));
        play_button = new QPushButton(centralwidget);
        play_button->setObjectName("play_button");
        play_button->setGeometry(QRect(140, 440, 111, 41));
        play_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 85, 0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color:  rgb(0, 102, 0);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color:  rgb(0, 124, 0);\n"
"}"));
        exit_button = new QPushButton(centralwidget);
        exit_button->setObjectName("exit_button");
        exit_button->setGeometry(QRect(520, 440, 111, 41));
        exit_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(0, 85, 0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color:  rgb(0, 102, 0);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color:  rgb(0, 124, 0);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Cities", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700; font-style:italic;\">Cities</span></p></body></html>", nullptr));
        play_button->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        exit_button->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
