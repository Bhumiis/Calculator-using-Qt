#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Digits
    void on_pushButton0_clicked();
    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
    void on_pushButton3_clicked();
    void on_pushButton4_clicked();
    void on_pushButton5_clicked();
    void on_pushButton6_clicked();
    void on_pushButton7_clicked();
    void on_pushButton8_clicked();
    void on_pushButton9_clicked();

    // Decimal, clear, equals
    void on_pushButtonDecimal_clicked();
    void on_pushButtonClear_clicked();
    void on_pushButtonEqual_clicked();

    // Operations
    void on_pushButtonPlus_clicked();
    void on_pushButtonMinus_clicked();
    void on_pushButtonMultiply_clicked();
    void on_pushButtonDivide_clicked();

    // Unary ops
    void on_pushButtonPlusMinus_clicked();
    void on_pushButtonPercentage_clicked();

private:
    Ui::MainWindow *ui;
    double firstNum;
    bool userIsTypingSecondNumber;
    QString pendingOperator;
    void appendDigit(QString digit);
    void calculate(double secondNum);
};

#endif // MAINWINDOW_H
