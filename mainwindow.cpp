#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , firstNum(0)
    , userIsTypingSecondNumber(false)
{
    ui->setupUi(this);
    ui->label->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendDigit(QString digit)
{
    QString labelText = ui->label->text();

    if ((labelText == "0") || (userIsTypingSecondNumber)) {
        labelText = digit;
        userIsTypingSecondNumber = false;
    } else {
        labelText += digit;
    }

    ui->label->setText(labelText);
}

// === DIGIT BUTTONS ===
void MainWindow::on_pushButton0_clicked() { appendDigit("0"); }
void MainWindow::on_pushButton1_clicked() { appendDigit("1"); }
void MainWindow::on_pushButton2_clicked() { appendDigit("2"); }
void MainWindow::on_pushButton3_clicked() { appendDigit("3"); }
void MainWindow::on_pushButton4_clicked() { appendDigit("4"); }
void MainWindow::on_pushButton5_clicked() { appendDigit("5"); }
void MainWindow::on_pushButton6_clicked() { appendDigit("6"); }
void MainWindow::on_pushButton7_clicked() { appendDigit("7"); }
void MainWindow::on_pushButton8_clicked() { appendDigit("8"); }
void MainWindow::on_pushButton9_clicked() { appendDigit("9"); }

// === DECIMAL ===
void MainWindow::on_pushButtonDecimal_clicked()
{
    if (!ui->label->text().contains(".")) {
        ui->label->setText(ui->label->text() + ".");
    }
}

// === UNARY OPERATIONS ===
void MainWindow::on_pushButtonPlusMinus_clicked()
{
    double num = ui->label->text().toDouble();
    num *= -1;
    ui->label->setText(QString::number(num, 'g', 15));
}

void MainWindow::on_pushButtonPercentage_clicked()
{
    double num = ui->label->text().toDouble();
    num *= 0.01;
    ui->label->setText(QString::number(num, 'g', 15));
}

// === CLEAR ===
void MainWindow::on_pushButtonClear_clicked()
{
    firstNum = 0;
    pendingOperator.clear();
    userIsTypingSecondNumber = false;
    ui->label->setText("0");
}

// === BINARY OPERATIONS ===
void MainWindow::on_pushButtonPlus_clicked()
{
    firstNum = ui->label->text().toDouble();
    pendingOperator = "+";
    userIsTypingSecondNumber = true;
}

void MainWindow::on_pushButtonMinus_clicked()
{
    firstNum = ui->label->text().toDouble();
    pendingOperator = "-";
    userIsTypingSecondNumber = true;
}

void MainWindow::on_pushButtonMultiply_clicked()
{
    firstNum = ui->label->text().toDouble();
    pendingOperator = "*";
    userIsTypingSecondNumber = true;
}

void MainWindow::on_pushButtonDivide_clicked()
{
    firstNum = ui->label->text().toDouble();
    pendingOperator = "/";
    userIsTypingSecondNumber = true;
}

// === CALCULATE RESULT ===
void MainWindow::calculate(double secondNum)
{
    double result = 0;
    if (pendingOperator == "+")
        result = firstNum + secondNum;
    else if (pendingOperator == "-")
        result = firstNum - secondNum;
    else if (pendingOperator == "*")
        result = firstNum * secondNum;
    else if (pendingOperator == "/") {
        if (secondNum != 0)
            result = firstNum / secondNum;
        else {
            ui->label->setText("Error");
            return;
        }
    }
    ui->label->setText(QString::number(result, 'g', 15));
    pendingOperator.clear();
}

void MainWindow::on_pushButtonEqual_clicked()
{
    double secondNum = ui->label->text().toDouble();
    calculate(secondNum);
    userIsTypingSecondNumber = false;
}
