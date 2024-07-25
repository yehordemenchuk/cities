#include "endgamewindow.h"
#include "ui_endgamewindow.h"
#include "dialog.h"
#include "cities.h"

Endgamewindow::Endgamewindow(QWidget *parent, Dialog* dialog_ptr, cities::game_result result)
    : QDialog(parent)
    , ui(new Ui::Endgamewindow)
    , current_dialog_ptr(dialog_ptr)
    , current_result(result)
{
    ui->setupUi(this);
}

Endgamewindow::~Endgamewindow()
{
    delete ui;
}

void Endgamewindow::set_game_result()
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

void Endgamewindow::close_current_windows()
{
    current_dialog_ptr->close();

    close();
}

void Endgamewindow::on_restart_button_clicked()
{
    close_current_windows();

    cities_game();
}
void Endgamewindow::on_exit_button_clicked()
{
    close_current_windows();
}
