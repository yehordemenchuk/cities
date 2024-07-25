#ifndef ENDGAMEWINDOW_H
#define ENDGAMEWINDOW_H

#include <QDialog>
#include "dialog.h"
#include "cities.h"

namespace Ui {
    class Endgamewindow;
}

class Endgamewindow : public QDialog
{
    Q_OBJECT

public:
    explicit Endgamewindow(QWidget *parent = nullptr, Dialog* dialog_ptr = nullptr,
                           cities::game_result result = cities::USER_WON);
    ~Endgamewindow();

    void set_game_result();

private slots:
    void close_current_windows();

    void on_restart_button_clicked();

    void on_exit_button_clicked();

private:
    Ui::Endgamewindow *ui;
    Dialog* current_dialog_ptr;
    cities::game_result current_result;
};

#endif // ENDGAMEWINDOW_H
