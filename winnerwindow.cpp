#include "winnerwindow.h"
#include "dialog.h"
#include "ui_winnerwindow.h"

Winnerwindow::Winnerwindow(QWidget *parent, Dialog* dialog_ptr)
    : QDialog(parent)
    , ui(new Ui::Winnerwindow)
    , current_dialog_ptr(dialog_ptr)
{   
    ui->setupUi(this);
}

Winnerwindow::~Winnerwindow()
{
    delete ui;
}

void Winnerwindow::on_restart_button_clicked()
{
    current_dialog_ptr->close();

    Dialog new_dialog;

    new_dialog.start_game();

    close();
}

void Winnerwindow::on_exit_button_clicked()
{
    current_dialog_ptr->close();

    close();
}
