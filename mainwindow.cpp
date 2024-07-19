#include <QMessageBox>
#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_play_button_clicked()
{
    close();

    cities_game();
}

void MainWindow::on_exit_button_clicked()
{
    close();
}
