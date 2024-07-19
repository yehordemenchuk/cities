#include "winnerwindow.h"
#include "ui_winnerwindow.h"
#include "dialog.h"
#include "cities.h"

Winnerwindow::Winnerwindow(QWidget *parent, Dialog* dialog_ptr, cities::game_result result)
    : QDialog(parent)
    , ui(new Ui::Winnerwindow)
    , current_dialog_ptr(dialog_ptr)
    , current_result(result)
{   
    ui->setupUi(this);
}

Winnerwindow::~Winnerwindow()
{
    delete ui;
}

void Winnerwindow::set_game_result()
{
    switch(current_result)
    {
        case cities::USER_WON:
            ui->game_result->setText("Congrats! You won!\nDo you want to restart?");

            break;

        case cities::USER_LOOSE:
            ui->game_result->setText(":( Yoy loose\nDo you want to restart?");

            break;
    }
}

void Winnerwindow::close_current_window()
{
    current_dialog_ptr->close();

    close();
}

void Winnerwindow::on_restart_button_clicked()
{
    close_current_window();

    cities_game();
}

void Winnerwindow::on_exit_button_clicked()
{
    close_current_window();
}
