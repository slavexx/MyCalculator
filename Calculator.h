#pragma once
#pragma once

#include <QWidget>
#include <qlabel.h>
#include <qpushbutton.h>

class Calculator : public QWidget {
public:
    Calculator(QWidget* parent = 0);
private:
    QLabel* label;
    QPushButton btn[20];
    bool pressedOperation = false;
private slots:
    void digitClicked();
    double rightOperand = 0.0;
    double leftOperand = 0.0;
};
