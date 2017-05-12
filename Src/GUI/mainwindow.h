#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "../PhilosopherModel/canteen.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void sendForkStatus(uint,bool);
    void sendStartAllPhilosophers();
    void sendStopAllPhilosophers();
private slots:
    void on_fork_1_clicked(bool checked);
    void on_fork_2_clicked(bool checked);
    void on_fork_3_clicked(bool checked);
    void on_fork_4_clicked(bool checked);
    void on_fork_5_clicked(bool checked);

    void on_startButton_clicked();
    void on_stopButton_clicked();

    void forkStatusChanged  (uint id, bool status);
    void philosopherEating  (uint id);
    void philosopherThinking(uint id);

private:
    Ui::MainWindow *ui;
    Canteen* mainCanteen;
};

#endif // MAINWINDOW_H
