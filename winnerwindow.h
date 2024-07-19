#ifndef WINNERWINDOW_H
#define WINNERWINDOW_H

#include <QDialog>
#include "dialog.h"
#include "cities.h"

namespace Ui
{
    class Winnerwindow;
}

class Winnerwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Winnerwindow(QWidget *parent = nullptr, Dialog* dialog_ptr = nullptr,
                          cities::game_result result = cities::USER_WON);
    ~Winnerwindow();

    void set_game_result();

private slots:
    void close_current_window();

    void on_restart_button_clicked();

    void on_exit_button_clicked();

private:
    Ui::Winnerwindow *ui;
    Dialog* current_dialog_ptr;
    cities::game_result current_result;
};

#endif // WINNERWINDOW_H
