/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *enter_button;
    QPushButton *exit_button;
    QLabel *game_output;
    QLineEdit *user_input;
    QLabel *error_label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(639, 553);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/cities_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	background-color: green;\n"
"}"));
        enter_button = new QPushButton(Dialog);
        enter_button->setObjectName("enter_button");
        enter_button->setGeometry(QRect(60, 468, 131, 51));
        enter_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        exit_button = new QPushButton(Dialog);
        exit_button->setObjectName("exit_button");
        exit_button->setGeometry(QRect(450, 470, 131, 51));
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
        game_output = new QLabel(Dialog);
        game_output->setObjectName("game_output");
        game_output->setGeometry(QRect(220, 140, 171, 31));
        user_input = new QLineEdit(Dialog);
        user_input->setObjectName("user_input");
        user_input->setGeometry(QRect(212, 190, 181, 28));
        error_label = new QLabel(Dialog);
        error_label->setObjectName("error_label");
        error_label->setGeometry(QRect(212, 250, 181, 20));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Cities", nullptr));
        enter_button->setText(QCoreApplication::translate("Dialog", "Enter", nullptr));
        exit_button->setText(QCoreApplication::translate("Dialog", "Exit", nullptr));
        game_output->setText(QString());
        error_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
