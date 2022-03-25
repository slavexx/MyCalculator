#include <QGridLayout>
#include <qlist.h>

#include "Calculator.h"

Calculator::Calculator(QWidget* parent)
    : QWidget(parent) {

    QVBoxLayout* vecticalBox = new QVBoxLayout(this);
    vecticalBox->setSpacing(2);
    
    display = new QLabel(this);
    display->setMinimumSize(100, 30);
    display->setText("0");
    display->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QFont* fontLabel = new QFont();
    fontLabel->setPointSizeF(18);
    display->setFont(*fontLabel);

    vecticalBox->addWidget(display);

    QList<QString> NameBtns =
    {
        "C", "<", "%", "/",
        "7", "8", "9", "*",
        "4", "5", "6", "-",
        "1", "2", "3", "+",
        "+/-", "0", ".", "="
    };

    QFont* fontBtn = new QFont();
    fontLabel->setPointSizeF(9);

    for (size_t i = 0; i < 20; ++i) {
        button[i].setText(NameBtns[i]);
        button[i].setFont(*fontLabel);
    }

    connect(button + 4,   &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(button + 5,   &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(button + 6,   &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(button + 8,   &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(button + 9,   &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(button + 10, &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(button + 12, &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(button + 13, &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(button + 14, &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(button + 17, &QPushButton::clicked, this,  &Calculator::digitClicked);

    QHBoxLayout* horizontalBox1 = new QHBoxLayout(this);
    for (int i = 0; i < 4; ++i) horizontalBox1->addWidget(button + i);

    QHBoxLayout* horizontalBox2 = new QHBoxLayout(this);
    for (int i = 4; i < 8; ++i) horizontalBox2->addWidget(button + i);

    QHBoxLayout* horizontalBox3 = new QHBoxLayout(this);
    for (int i = 8; i < 12; ++i) horizontalBox3->addWidget(button + i);

    QHBoxLayout* horizontalBox4 = new QHBoxLayout(this);
    for (int i = 12; i < 16; ++i) horizontalBox4->addWidget(button + i);

    QHBoxLayout* horizontalBox5 = new QHBoxLayout(this);
    for (int i = 16; i < 20; ++i) horizontalBox5->addWidget(button + i);

    horizontalBox1->setSpacing(2);
    horizontalBox2->setSpacing(2);
    horizontalBox3->setSpacing(2);
    horizontalBox4->setSpacing(2);
    horizontalBox5->setSpacing(2);

    vecticalBox->addLayout(horizontalBox1);
    vecticalBox->addLayout(horizontalBox2);
    vecticalBox->addLayout(horizontalBox3);
    vecticalBox->addLayout(horizontalBox4);
    vecticalBox->addLayout(horizontalBox5);

    setLayout(vecticalBox);
}

void Calculator::digitClicked() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    int digitValue = clickedButton->text().toInt();

    if (!pressedOperation) {
        leftOperand = leftOperand * 10 + digitValue;
    }
    else
    {
        rightOperand = rightOperand * 10 + digitValue;
    }

    if (display->text() == "0") display->setText("");
    display->setText(display->text() + QString::number(digitValue));
}
