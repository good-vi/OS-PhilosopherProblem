#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#define NUM_OF_PHILOSOPHERS   5
#define DEFAULT_EATING_TIME   10
#define DEFAULT_THINKING_TIME 15

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow),
    mainCanteen(new Canteen(NUM_OF_PHILOSOPHERS, DEFAULT_EATING_TIME,
                            DEFAULT_THINKING_TIME, this))
{
    ui->setupUi(this);

    connect(this, SIGNAL(sendForkStatus(uint,bool)),  mainCanteen, SLOT(setForkStatus(uint,bool)));
    connect(this, SIGNAL(sendStartAllPhilosophers()), mainCanteen, SLOT(startAllPhilosophers()));
    connect(this, SIGNAL(sendStopAllPhilosophers()),  mainCanteen, SLOT(stopAllPhilosophers()));

    connect(mainCanteen, SIGNAL(forkStatusChanged(uint, bool)),
            this, SLOT(forkStatusChanged(uint,bool)));
    connect(mainCanteen, SIGNAL(philosopherEating(uint)),
            this, SLOT(philosopherEating(uint)));
    connect(mainCanteen, SIGNAL(philosopherThinking(uint)),
            this, SLOT(philosopherThinking(uint)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fork_1_clicked(bool checked){
    if (ui->startButton->isEnabled())
        emit sendForkStatus(0, checked);
}

void MainWindow::on_fork_2_clicked(bool checked){
    if (ui->startButton->isEnabled())
        emit sendForkStatus(1, checked);
}

void MainWindow::on_fork_3_clicked(bool checked){
    if (ui->startButton->isEnabled())
        emit sendForkStatus(2, checked);
}

void MainWindow::on_fork_4_clicked(bool checked){
    if (ui->startButton->isEnabled())
        emit sendForkStatus(3, checked);
}

void MainWindow::on_fork_5_clicked(bool checked){
    if (ui->startButton->isEnabled())
        emit sendForkStatus(4, checked);
}

void MainWindow::on_startButton_clicked()
{
    ui->startButton->setEnabled(0);

    ui->fork_1->setEnabled(0);
    ui->fork_2->setEnabled(0);
    ui->fork_3->setEnabled(0);
    ui->fork_4->setEnabled(0);
    ui->fork_5->setEnabled(0);

    emit sendStartAllPhilosophers();
    ui->stopButton->setEnabled(1);
}

void MainWindow::on_stopButton_clicked()
{
    ui->stopButton->setEnabled(0);
    emit sendStopAllPhilosophers();
    delete mainCanteen;
    ui->startButton->setEnabled(1);
}

void MainWindow::forkStatusChanged(uint id, bool status)
{
    switch (id) {
    case 0:
        ui->fork_1->setChecked(status);
        break;
    case 1:
        ui->fork_2->setChecked(status);
        break;
    case 2:
        ui->fork_3->setChecked(status);
        break;
    case 3:
        ui->fork_4->setChecked(status);
        break;
    case 4:
        ui->fork_5->setChecked(status);
        break;
    default:
        break;
    }
}

void MainWindow::philosopherEating(uint id)
{
    switch (id) {
    case 0:
        ui->philosopher_1->setChecked(1);
        break;
    case 1:
        ui->philosopher_2->setChecked(1);
        break;
    case 2:
        ui->philosopher_3->setChecked(1);
        break;
    case 3:
        ui->philosopher_4->setChecked(1);
        break;
    case 4:
        ui->philosopher_5->setChecked(1);
        break;
    default:
        break;
    }
}

void MainWindow::philosopherThinking(uint id)
{
    switch (id) {
    case 0:
        ui->philosopher_1->setChecked(0);
        break;
    case 1:
        ui->philosopher_2->setChecked(0);
        break;
    case 2:
        ui->philosopher_3->setChecked(0);
        break;
    case 3:
        ui->philosopher_4->setChecked(0);
        break;
    case 4:
        ui->philosopher_5->setChecked(0);
        break;
    default:
        break;
    }
}
