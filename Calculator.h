#pragma once

#include <QWidget>
#include <qlabel.h>
#include <qpushbutton.h>

class Calculator : public QWidget {
    Q_OBJECT
public:
    Calculator(QWidget* parent = 0);
private:
    QLabel* label;
    QPushButton btn[20];
    bool pressedOperation = false;
    double rightOperand = 0.0;
    double leftOperand = 0.0;
private slots:
    void digitClicked();
};
