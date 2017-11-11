#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNumber;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digitPressed()));

    connect(ui->pushButton_plusMinus,SIGNAL(released()),this,SLOT(unaryOperationPressed()));
    connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(unaryOperationPressed()));

    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(binaryOperationPressed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binaryOperationPressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binaryOperationPressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binaryOperationPressed()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);

    ui->pushButton_equal->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitPressed()
{
    QPushButton *button = (QPushButton*)sender();

    QString newLabel;

    double labelNumber;

    if (!ui->pushButton_equal->isChecked())
    {
        labelNumber = (ui->label->text() + button->text()).toDouble();
    }
    else
    {
        labelNumber = button->text().toDouble();
        ui->pushButton_equal->setChecked(false);
    }

    newLabel = QString::number(labelNumber,'g',15);

    ui->label->setText(newLabel);

}

void MainWindow::on_pushButton_dot_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unaryOperationPressed()
{
    QPushButton *button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if ( button->text() == "+/-" )
    {
        labelNumber = (ui->label->text()).toDouble();
        labelNumber *= -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
    else if (button->text() == "%")
    {
        labelNumber = (ui->label->text()).toDouble();
        labelNumber *= 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pushButton_clear_released()
{
    ui->label->setText("0");
}

void MainWindow::on_pushButton_equal_released()
{
    double secondNumber = (ui->label->text()).toDouble();
    QString newLabel;

    if (ui->pushButton_plus->isChecked())
    {
        firstNumber += secondNumber;
        ui->pushButton_plus->setChecked(false);
    }
    else if (ui->pushButton_minus->isChecked())
    {
        firstNumber -= secondNumber;
        ui->pushButton_minus->setChecked(false);
    }
    else if (ui->pushButton_multiply->isChecked())
    {
        firstNumber *= secondNumber;
        ui->pushButton_multiply->setChecked(false);
    }
    else if (ui->pushButton_divide->isChecked())
    {
        firstNumber /= secondNumber;
        ui->pushButton_divide->setChecked(false);
    }

    newLabel = QString::number(firstNumber,'g',15);
    ui->label->setText(newLabel);
    firstNumber = 0.0;
    ui->pushButton_equal->setChecked(true);
}

void MainWindow::binaryOperationPressed()
{
    QPushButton *button = (QPushButton*)sender();

    firstNumber = (ui->label->text()).toDouble();

    button->setChecked(true);

    ui->label->setText("");

}
