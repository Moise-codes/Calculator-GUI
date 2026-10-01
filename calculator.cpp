#include <QRegularExpression>
#include "calculator.h"
#include "./ui_calculator.h"
#include <cmath>
#include <iostream>
#include <QKeyEvent>

using namespace std;

double calcValue = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool subTrigger = false;
bool addTrigger = false;
bool powTrigger = false;
double memoryValue = 0.0;
QRegularExpression regChangeSign("[-]?[0-9.]*");
QRegularExpression regIsNumber("^[-]?[0-9]*\\.?[0-9]*$");

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->ResultDisp->setText(QString::number(calcValue));

    QPushButton *numButtons[10];
    for(int i = 0; i < 10; i++) {
        QString buttonName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(buttonName);
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed()));
    }

    QPushButton *simpleMathButtons[5];
    for(int i = 0; i < 5; i++) {
        QString buttonName = "SMath" + QString::number(i + 1);
        simpleMathButtons[i] = Calculator::findChild<QPushButton *>(buttonName);
        connect(simpleMathButtons[i], SIGNAL(released()), this,
                SLOT(SimpleMathButton()));
    }

    connect(ui->Point, SIGNAL(released()), this,
            SLOT(PointPressed()));
    connect(ui->Root, SIGNAL(released()), this,
            SLOT(RootButton()));
    connect(ui->PrimeCheck, SIGNAL(released()), this,
            SLOT(PrimeButton()));
    connect(ui->Equals, SIGNAL(released()), this,
            SLOT(EqualButton()));
    connect(ui->Sign, SIGNAL(released()), this,
            SLOT(ChangeSign()));
    connect(ui->Clear, SIGNAL(released()), this,
            SLOT(ClearButton()));
    connect(ui->Backspace, SIGNAL(released()), this,
            SLOT(BackspaceButton()));

    connect(ui->SinBtn, SIGNAL(released()), this,
            SLOT(SinButton()));
    connect(ui->CosBtn, SIGNAL(released()), this,
            SLOT(CosButton()));
    connect(ui->TanBtn, SIGNAL(released()), this,
            SLOT(TanButton()));
    connect(ui->LogBtn, SIGNAL(released()), this,
            SLOT(LogButton()));
    connect(ui->LnBtn, SIGNAL(released()), this,
            SLOT(LnButton()));
    connect(ui->FactorialBtn, SIGNAL(released()), this,
            SLOT(FactorialButton()));
    connect(ui->ExpBtn, SIGNAL(released()), this,
            SLOT(ExpButton()));
    connect(ui->PercentBtn, SIGNAL(released()), this,
            SLOT(PercentButton()));
    connect(ui->PiBtn, SIGNAL(released()), this,
            SLOT(PiButton()));
    connect(ui->EBtn, SIGNAL(released()), this,
            SLOT(EButton()));
    connect(ui->OpenParenBtn, SIGNAL(released()), this,
            SLOT(OpenParen()));
    connect(ui->CloseParenBtn, SIGNAL(released()), this,
            SLOT(CloseParen()));
    connect(ui->MC, SIGNAL(released()), this,
            SLOT(MemoryClear()));
    connect(ui->MR, SIGNAL(released()), this,
            SLOT(MemoryRecall()));
    connect(ui->MPlus, SIGNAL(released()), this,
            SLOT(MemoryAdd()));
    connect(ui->MMinus, SIGNAL(released()), this,
            SLOT(MemorySubtract()));
}

void Calculator::SinButton() {
    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        calcValue = displayValue.toDouble();
    }
    double result = sin(calcValue * M_PI / 180.0);
    ui->ResultDisp->setText(QString::number(result, 'g', 16));
}

void Calculator::CosButton() {
    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        calcValue = displayValue.toDouble();
    }
    double result = cos(calcValue * M_PI / 180.0);
    ui->ResultDisp->setText(QString::number(result, 'g', 16));
}

void Calculator::TanButton() {
    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        calcValue = displayValue.toDouble();
    }
    double result = tan(calcValue * M_PI / 180.0);
    ui->ResultDisp->setText(QString::number(result, 'g', 16));
}

void Calculator::LogButton() {
    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        calcValue = displayValue.toDouble();
    }
    double result = log10(calcValue);
    ui->ResultDisp->setText(QString::number(result, 'g', 16));
}

void Calculator::LnButton() {
    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        calcValue = displayValue.toDouble();
    }
    double result = log(calcValue);
    ui->ResultDisp->setText(QString::number(result, 'g', 16));
}

void Calculator::ExpButton() {
    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        calcValue = displayValue.toDouble();
    }
    double result = exp(calcValue);
    ui->ResultDisp->setText(QString::number(result, 'g', 16));
}

void Calculator::FactorialButton() {
    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        calcValue = displayValue.toDouble();
    }
    int n = static_cast<int>(calcValue);
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    ui->ResultDisp->setText(QString::number(result, 'g', 16));
}

void Calculator::PercentButton() {
    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        calcValue = displayValue.toDouble();
    }
    double result = calcValue / 100.0;
    ui->ResultDisp->setText(QString::number(result, 'g', 16));
}

void Calculator::PiButton() {
    ui->ResultDisp->setText(QString::number(M_PI, 'g', 16));
}

void Calculator::EButton() {
    ui->ResultDisp->setText(QString::number(M_E, 'g', 16));
}

void Calculator::OpenParen() {
    QString displayValue = ui->ResultDisp->text();
    ui->ResultDisp->setText(displayValue + "(");
}

void Calculator::CloseParen() {
    QString displayValue = ui->ResultDisp->text();
    ui->ResultDisp->setText(displayValue + ")");
}

void Calculator::MemoryClear() {
    memoryValue = 0.0;
}

void Calculator::MemoryRecall() {
    ui->ResultDisp->setText(QString::number(memoryValue, 'g', 16));
}

void Calculator::MemoryAdd() {
    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        memoryValue += displayValue.toDouble();
    }
}

void Calculator::MemorySubtract() {
    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        memoryValue -= displayValue.toDouble();
    }
}

void Calculator::BackspaceButton() {
    QString displayValue = ui->ResultDisp->text();
    if (displayValue.length() > 1) {
        displayValue.chop(1);
        ui->ResultDisp->setText(displayValue);
    } else {
        ui->ResultDisp->setText("0");
    }
}

Calculator::~Calculator()
{
    delete ui;
}

bool isPrime(const int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void Calculator::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_0 ||
        event->key() == Qt::Key_1 ||
        event->key() == Qt::Key_2 ||
        event->key() == Qt::Key_3 ||
        event->key() == Qt::Key_4 ||
        event->key() == Qt::Key_5 ||
        event->key() == Qt::Key_6 ||
        event->key() == Qt::Key_7 ||
        event->key() == Qt::Key_8 ||
        event->key() == Qt::Key_9) {
        QString numValue = event->text();
        PressNum(numValue);
    } else if (event->key() == Qt::Key_Plus) {
        QString opValue = "1";
        PressMathOp(opValue);
    } else if (event->key() == Qt::Key_Minus) {
        QString opValue = "2";
        PressMathOp(opValue);
    } else if (event->key() == Qt::Key_Slash) {
        QString opValue = "3";
        PressMathOp(opValue);
    } else if (event->key() == Qt::Key_Asterisk) {
        QString opValue = "4";
        PressMathOp(opValue);
    } else if (event->key() == Qt::Key_Delete || event->key() == Qt::Key_C || event->key() == Qt::Key_Escape) {
        ClearButton();
    } else if (event->key() == Qt::Key_Backspace) {
        BackspaceButton();
    } else if (event->key() == Qt::Key_Period) {
        PointPressed();
    } else if (event->key() == Qt::Key_Equal || event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        EqualButton();
    } else if (event->key() == Qt::Key_ParenLeft) {
        OpenParen();
    } else if (event->key() == Qt::Key_ParenRight) {
        CloseParen();
    } else if (event->key() == Qt::Key_Percent) {
        PercentButton();
    }
}

void Calculator::PressNum(QString &buttonValue) {
    QPushButton *button = findChild<QPushButton *>(QString("Button") + buttonValue);
    if (button) {
        button->click();
    }
}

void Calculator::PressMathOp(QString &buttonValue) {
    QPushButton *button = findChild<QPushButton *>(QString("SMath") + buttonValue);
    if (button) {
        button->click();
    }
}

void Calculator::NumPressed() {
    QPushButton *button = (QPushButton *)sender();
    QString buttonValue = button->text();
    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        if (displayValue == "0") {
            ui->ResultDisp->setText(buttonValue);
        } else {
            QString newValue = displayValue + buttonValue;
            ui->ResultDisp->setText(newValue);
        }
    } else {
        ui->ResultDisp->setText(buttonValue);
    }
}

void Calculator::PointPressed() {
    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        ui->ResultDisp->setText(displayValue + ".");
    }
}

void Calculator::ClearButton() {
    divTrigger = false;
    multTrigger = false;
    subTrigger = false;
    addTrigger = false;
    powTrigger = false;
    calcValue = 0.0;
    ui->ResultDisp->setText(QString::number(calcValue));
}

void Calculator::SimpleMathButton() {
    divTrigger = false;
    multTrigger = false;
    subTrigger = false;
    addTrigger = false;
    powTrigger = false;

    QPushButton *button = (QPushButton *)sender();
    QString buttonOperator = button->text();
    if (QString::compare(buttonOperator, "÷", Qt::CaseInsensitive) == 0) {
        divTrigger = true;
    } else if (QString::compare(buttonOperator, "×", Qt::CaseInsensitive) == 0) {
        multTrigger = true;
    } else if (QString::compare(buttonOperator, "+", Qt::CaseInsensitive) == 0) {
        addTrigger = true;
    } else if (QString::compare(buttonOperator, "-", Qt::CaseInsensitive) == 0) {
        subTrigger = true;
    } else if (QString::compare(buttonOperator, "xⁿ", Qt::CaseInsensitive) == 0) {
        powTrigger = true;
        buttonOperator = "^";
    }

    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        calcValue = displayValue.toDouble();
    }
    ui->ResultDisp->setText(QString::number(calcValue) + buttonOperator);
}

void Calculator::RootButton() {
    QString displayValue = ui->ResultDisp->text();
    if (regIsNumber.match(displayValue).hasMatch()) {
        calcValue = displayValue.toDouble();
    }
    double result = pow(calcValue, 0.5);
    ui->ResultDisp->setText(QString::number(result, 'g', 16));

    divTrigger = false;
    multTrigger = false;
    subTrigger = false;
    addTrigger = false;
    powTrigger = false;
}

void Calculator::PrimeButton() {
    if (isPrime(ui->ResultDisp->text().toInt())) {
        ui->ResultDisp->setText("Yes");
    } else {
        ui->ResultDisp->setText("No");
    }

    divTrigger = false;
    multTrigger = false;
    subTrigger = false;
    addTrigger = false;
    powTrigger = false;
    calcValue = 0.0;
}

void Calculator::EqualButton() {
    double result = 0.0;
    QString displayValue = ui->ResultDisp->text();
    double dblDisplayValue = displayValue.toDouble();
    if (divTrigger || multTrigger || subTrigger || addTrigger || powTrigger) {
        if(divTrigger){
            result = calcValue / dblDisplayValue;
        } else if(multTrigger){
            result = calcValue * dblDisplayValue;
        } else if(subTrigger){
            result = calcValue - dblDisplayValue;
        } else if(addTrigger){
            result = calcValue + dblDisplayValue;
        } else {
            result = pow(calcValue, dblDisplayValue);
        }
    }
    ui->ResultDisp->setText(QString::number(result, 'g', 16));
    divTrigger = false;
    multTrigger = false;
    subTrigger = false;
    addTrigger = false;
    powTrigger = false;
}

void Calculator::ChangeSign() {
    QString displayValue = ui->ResultDisp->text();
    if (regChangeSign.match(displayValue).hasMatch()) {
        double dblDisplayValue = displayValue.toDouble();
        double dblDisplayValueSign = -1 * dblDisplayValue;
        ui->ResultDisp->setText(QString::number(dblDisplayValueSign));
    }
}
