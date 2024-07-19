#include <string>
#include "dialog.h"
#include "ui_dialog.h"
#include "cities.h"
#include "winnerwindow.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , cities_list(cities::cities_list_length)
{
    ui->setupUi(this);

    load_cities(cities_list);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::start_game()
{
    show();

    ui->game_output->setText(generate_first_city(cities_list).c_str());
}

void show_winnerwindow(Dialog* dialog_ptr, cities::game_result result)
{
    Winnerwindow win_window(nullptr, dialog_ptr, result);

    win_window.set_game_result();

    win_window.show();

    win_window.exec();
}

void cities_game()
{
    Dialog dialog;

    dialog.start_game();

    dialog.exec();
}

void Dialog::on_enter_button_clicked()
{
    string user_city = str_to_lower(ui->user_input->text().toStdString());
    string game_city = ui->game_output->text().toStdString();
    cities::city_validity validity = validate_city(user_city, cities_list);

    if (validity == cities::VALID && user_city[0] == game_city[game_city.length() - cities::shift])
    {
        ui->game_output->clear();
        ui->error_label->clear();

        string new_city = generate_city(user_city, cities_list);

        if (new_city == cities::no_city)
            show_winnerwindow(this, cities::USER_WON);

        else
        {
            ui->user_input->clear();

            ui->game_output->setText(new_city.c_str());
        }
    }

    else if (validity == cities::ABSENT_CITY_FIRST_LETTER)
        show_winnerwindow(this, cities::USER_LOOSE);

    else
        ui->error_label->setText("Invalid city name");
}

void Dialog::on_exit_button_clicked()
{
    close();
}
