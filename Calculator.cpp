#include <QGridLayout>
#include <qlabel.h>
#include <qlist.h>

#include "Calculator.h"

Calculator::Calculator(QWidget* parent)
    : QWidget(parent) {

    QVBoxLayout* vb = new QVBoxLayout(this);
    vb->setSpacing(2);
    
    label = new QLabel(this);
    label->setMinimumSize(100, 30);
    label->setText("0");
    label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QFont* fontLabel = new QFont();
    fontLabel->setPointSizeF(18);
    label->setFont(*fontLabel);
    vb->addWidget(label);
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
    for (int i = 0; i < 20; ++i) {
        btn[i].setText(NameBtns[i]);
        btn[i].setFont(*fontLabel);
    }

    connect(btn + 4, &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(btn + 5, &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(btn + 6, &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(btn + 8, &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(btn + 9, &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(btn + 10, &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(btn + 12, &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(btn + 13, &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(btn + 14, &QPushButton::clicked, this,  &Calculator::digitClicked);
    connect(btn + 17, &QPushButton::clicked, this,  &Calculator::digitClicked);

    QHBoxLayout* hb1 = new QHBoxLayout(this);
    for (int i = 0; i < 4; ++i) hb1->addWidget(btn + i);
    QHBoxLayout* hb2 = new QHBoxLayout(this);
    for (int i = 4; i < 8; ++i) hb2->addWidget(btn + i);
    QHBoxLayout* hb3 = new QHBoxLayout(this);
    for (int i = 8; i < 12; ++i) hb3->addWidget(btn + i);
    QHBoxLayout* hb4 = new QHBoxLayout(this);
    for (int i = 12; i < 16; ++i) hb4->addWidget(btn + i);
    QHBoxLayout* hb5 = new QHBoxLayout(this);
    for (int i = 16; i < 20; ++i) hb5->addWidget(btn + i);
    hb1->setSpacing(2);
    hb2->setSpacing(2);
    hb3->setSpacing(2);
    hb4->setSpacing(2);
    hb5->setSpacing(2);
    vb->addLayout(hb1);
    vb->addLayout(hb2);
    vb->addLayout(hb3);
    vb->addLayout(hb4);
    vb->addLayout(hb5);
    setLayout(vb);
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
    if (label->text() == "0") label->setText("");
    label->setText(label->text() + QString::number(digitValue));
}
