#include <string>
#include "dialog.h"
#include "ui_dialog.h"
#include "cities.h"
#include "endgamewindow.h"

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

void show_endgamewindow(Dialog* dialog_ptr, cities::game_result result)
{
    Endgamewindow win_window(nullptr, dialog_ptr, result);

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

void Dialog::update_output_city(string user_city)
{
    ui->game_output->clear();
    ui->error_label->clear();

    string new_city = generate_city(user_city, cities_list);

    if (new_city == cities::no_city)
        show_endgamewindow(this, cities::USER_WON);

    else
    {
        ui->user_input->clear();

        ui->game_output->setText(new_city.c_str());
    }
}

void Dialog::on_enter_button_clicked()
{
    string user_city = str_to_lower(ui->user_input->text().toStdString());
    cities::city_validity validity = validate_city(user_city, ui->game_output->text().toStdString(), cities_list);

    switch(validity)
    {
        case cities::VALID:
            update_output_city(user_city);

            break;

        case cities::ABSENT_CITY_FIRST_LETTER:
            show_endgamewindow(this, cities::USER_LOOSE);

            break;

        case cities::INVALID:
            ui->error_label->setText("Invalid city name");

            break;
    }
}

void Dialog::on_exit_button_clicked()
{
    close();
}
