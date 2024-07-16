#include <string>
#include "dialog.h"
#include "ui_dialog.h"
#include "cities.h"

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

    ui->game_output->setText(generate_city("a", cities_list).c_str());
}

void Dialog::on_enter_button_clicked()
{
    string user_city = ui->user_input->text().toStdString();
    string game_city = ui->game_output->text().toStdString();

    if (validate_city(user_city, cities_list) && user_city[0] == game_city[game_city.length() - 1])
    {
        ui->game_output->clear();

        ui->game_output->setText(generate_city(user_city, cities_list).c_str());
    }
}

void Dialog::on_exit_button_clicked()
{
    close();
}
