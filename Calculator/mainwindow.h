#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digitPressed();
    void on_pushButton_dot_released();
    void unaryOperationPressed();
    void binaryOperationPressed();

    void on_pushButton_clear_released();
    void on_pushButton_equal_released();
};

#endif // MAINWINDOW_H
