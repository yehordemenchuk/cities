#ifndef DIALOG_H
#define DIALOG_H

#include <vector>
#include <string>
#include <QDialog>
#include "cities.h"

using namespace std;

namespace Ui
{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void start_game();

private slots:
    void on_enter_button_clicked();

    void on_exit_button_clicked();

private:
    Ui::Dialog *ui;
    vector<string> cities_list;
};

void show_endgamewindow(Dialog* dialog_ptr, cities::game_result result);
void cities_game();

#endif // DIALOG_H
