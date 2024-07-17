#ifndef WINNERWINDOW_H
#define WINNERWINDOW_H

#include <QDialog>
#include "dialog.h"

namespace Ui {
class Winnerwindow;
}

class Winnerwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Winnerwindow(QWidget *parent = nullptr, Dialog* dialog_ptr = nullptr);
    ~Winnerwindow();

private slots:
    void on_restart_button_clicked();

    void on_exit_button_clicked();

private:
    Ui::Winnerwindow *ui;
    Dialog* current_dialog_ptr;
};

#endif // WINNERWINDOW_H
