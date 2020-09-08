#include "programmer.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <iostream>
using namespace std;
int jzzh = 1;
programmer::programmer(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Programmer");
    resize(500,500);
    QMenuBar *mbar = menuBar();
    QMenu *shift = mbar->addMenu("Shift");
    QAction *a =   shift->addAction("Standard");
    QAction *b =   shift->addAction("Scientific");
    shift->addAction("Programmer");
    connect(a,&QAction::triggered,this,&programmer::sendsst);
    connect(b,&QAction::triggered,this,&programmer::sendsc);

    QWidget *centerwindow = new QWidget;//设置界面
    this->setCentralWidget(centerwindow);
    datadec = new QLineEdit("");
    datahex = new QLineEdit("");
    databin = new QLineEdit("");
    btn0 = new QPushButton("0");btn1 = new QPushButton("1");btn2 = new QPushButton("2");btn3 = new QPushButton("3");
    btn4 = new QPushButton("4");btn5 = new QPushButton("5");btn6 = new QPushButton("6");btn7 = new QPushButton("7");
    btn8 = new QPushButton("8");btn9 = new QPushButton("9");btnjia = new QPushButton("+");btnjian = new QPushButton("-");
    btncheng = new QPushButton("*");btnchu = new QPushButton("/");btnfh = new QPushButton("+/-");btntg = new QPushButton("←");
    btnA = new QPushButton("A");btnB = new QPushButton("B");btnC = new QPushButton("C");btnD = new QPushButton("D");
    btnE = new QPushButton("E");btnF = new QPushButton("F");btnCL = new QPushButton("AC");btnresult = new QPushButton("=");
    btnHex = new QPushButton("Hex"); btnDec = new QPushButton("Dec"); btnBin = new QPushButton("Bin");
    databin->setFixedHeight(30);datadec->setFixedHeight(30);datahex->setFixedHeight(30);
    btnBin->setMinimumHeight(30);btnDec->setMinimumHeight(30);btnHex->setMinimumHeight(30);
    btn0->setMinimumHeight(40);btn1->setMinimumHeight(40);btn2->setMinimumHeight(40);btn3->setMinimumHeight(40);
    btn4->setMinimumHeight(40);btn5->setMinimumHeight(40);btn6->setMinimumHeight(40);btn7->setMinimumHeight(40);
    btn8->setMinimumHeight(40);btn9->setMinimumHeight(40);btnjia->setMinimumHeight(40);btnjian->setMinimumHeight(40);
    btncheng->setMinimumHeight(40);btnchu->setMinimumHeight(40);btnfh->setMinimumHeight(40);btntg->setMinimumHeight(40);
    btnA->setMinimumHeight(40);btnB->setMinimumHeight(40);btnC->setMinimumHeight(40);btnD->setMinimumHeight(40);
    btnE->setMinimumHeight(40);btnF->setMinimumHeight(40);btnCL->setMinimumHeight(40);btnresult->setMinimumHeight(40);
    QGridLayout * layout = new QGridLayout;
    layout->addWidget(btnDec,1,1,Qt::Alignment());layout->addWidget(datadec,1,2,1,4,Qt::Alignment());
    layout->addWidget(btnHex,2,1,Qt::Alignment());layout->addWidget(datahex,2,2,1,4,Qt::Alignment());
    layout->addWidget(btnBin,3,1,Qt::Alignment());layout->addWidget(databin,3,2,1,4,Qt::Alignment());
    layout->addWidget(btnA,4,1,Qt::Alignment());layout->addWidget(btnchu,4,2,Qt::Alignment());layout->addWidget(btnCL,4,3,Qt::Alignment());
    layout->addWidget(btntg,4,4,Qt::Alignment());layout->addWidget(btnB,5,1,Qt::Alignment());layout->addWidget(btnjia,5,2,Qt::Alignment());
    layout->addWidget(btnjian,5,3,Qt::Alignment());layout->addWidget(btncheng,5,4,Qt::Alignment());layout->addWidget(btnC,6,1,Qt::Alignment());
    layout->addWidget(btn7,6,2,Qt::Alignment());layout->addWidget(btn8,6,3,Qt::Alignment());layout->addWidget(btn9,6,4,Qt::Alignment());
    layout->addWidget(btnD,7,1,Qt::Alignment());layout->addWidget(btn4,7,2,Qt::Alignment());layout->addWidget(btn5,7,3,Qt::Alignment());
    layout->addWidget(btn6,7,4,Qt::Alignment());layout->addWidget(btnE,8,1,Qt::Alignment());layout->addWidget(btn1,8,2,Qt::Alignment());
    layout->addWidget(btn2,8,3,Qt::Alignment());layout->addWidget(btn3,8,4,Qt::Alignment());layout->addWidget(btnF,9,1,Qt::Alignment());
    layout->addWidget(btnfh,9,2,Qt::Alignment());layout->addWidget(btn0,9,3,Qt::Alignment());layout->addWidget(btnresult,9,4,Qt::Alignment());
    centerwindow->setLayout(layout);//设置界面
    datadec->setText(input);databin->setText(input);datahex->setText(input);
    connect(btnDec,&QPushButton::clicked,this,&programmer::sjz);
    connect(btnHex,&QPushButton::clicked,this,&programmer::sljz);
    connect(btnBin,&QPushButton::clicked,this,&programmer::ejz);
    connect(btnchu,&QPushButton::clicked,this,&programmer::btnchuclicked);
    connect(btnCL,&QPushButton::clicked,this,&programmer::btnCLclicked);
    connect(btntg,&QPushButton::clicked,this,&programmer::btntgclicked);
    connect(btnjia,&QPushButton::clicked,this,&programmer::btnjiaclicked);
    connect(btnjian,&QPushButton::clicked,this,&programmer::btnjianclicked);
    connect(btncheng,&QPushButton::clicked,this,&programmer::btnchengclicked);
    connect(btn0,&QPushButton::clicked,this,&programmer::btn0clicked);
    connect(btn1,&QPushButton::clicked,this,&programmer::btn1clicked);
    connect(btnresult,&QPushButton::clicked,this,&programmer::btnresultclicked);
    connect(btn2,&QPushButton::clicked,this,&programmer::btn2clicked);
    connect(btn3,&QPushButton::clicked,this,&programmer::btn3clicked);
    connect(btn4,&QPushButton::clicked,this,&programmer::btn4clicked);
    connect(btn5,&QPushButton::clicked,this,&programmer::btn5clicked);
    connect(btn6,&QPushButton::clicked,this,&programmer::btn6clicked);
    connect(btn7,&QPushButton::clicked,this,&programmer::btn7clicked);
    connect(btn8,&QPushButton::clicked,this,&programmer::btn8clicked);
    connect(btn9,&QPushButton::clicked,this,&programmer::btn9clicked);
    connect(btnfh,&QPushButton::clicked,this,&programmer::btnzfclicked);
    connect(btnA,&QPushButton::clicked,this,&programmer::btnAclicked);
    connect(btnB,&QPushButton::clicked,this,&programmer::btnBclicked);
    connect(btnC,&QPushButton::clicked,this,&programmer::btnCclicked);
    connect(btnD,&QPushButton::clicked,this,&programmer::btnDclicked);
    connect(btnE,&QPushButton::clicked,this,&programmer::btnEclicked);
    connect(btnF,&QPushButton::clicked,this,&programmer::btnFclicked);
}

void programmer::sendsst(){  //切换至standard信号
    emit sstand();
}
void programmer::sendsc(){  //切换至scientific信号
    emit sscin();
}
void programmer::sjz(){
    jzzh = 1;input = "0";
    datadec->setText(input);databin->setText(input);datahex->setText(input);

}
void programmer::sljz(){
    jzzh = 2;input = "0";
    datadec->setText(input);databin->setText(input);datahex->setText(input);

}
void programmer::ejz(){
    jzzh = 3;input = "0";
    datadec->setText(input);databin->setText(input);datahex->setText(input);
}
void programmer::btn0clicked(){
    if(input=="0")
        input = '0';
        else input = input + '0';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }

}
void programmer::btn1clicked(){
    if(input=="0")
        input = '1';
        else input = input + '1';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btn2clicked(){
    if(input=="0")
        input = '2';
        else input = input + '2';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btn3clicked(){
    if(input=="0")
        input = '3';
        else input = input + '3';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btn4clicked(){
    if(input=="0")
        input = '4';
        else input = input + '4';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btn5clicked(){
    if(input=="0")
        input = '5';
        else input = input + '5';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btn6clicked(){
    if(input=="0")
        input = '6';
        else input = input + '6';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btn7clicked(){
    if(input=="0")
        input = '7';
        else input = input + '7';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btn8clicked(){
    if(input=="0")
        input = '8';
        else input = input + '8';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
    case 3:databin->setText(input);break;
    default:break;
    }
}
void programmer::btn9clicked(){
    if(input=="0")
        input = '9';
        else input = input + '9';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btnjiaclicked(){
    if(input=="0")
        input = '+';
        else input = input + '+';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btnjianclicked(){
    if(input=="0")
        input = '-';
        else input = input + '-';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btnchengclicked(){
    if(input=="0")
        input = '*';
        else input = input + '*';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btnchuclicked(){
    if(input=="0")
        input = '/';
        else input = input + '/';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btntgclicked(){
    input = input.left(input.length()-1);
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btnCLclicked(){
    input = "0";
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btnAclicked(){
    if(input=="0")
        input = 'A';
        else input = input + 'A';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btnBclicked(){
    if(input=="0")
        input = 'B';
        else input = input + 'B';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btnCclicked(){
    if(input=="0")
        input = 'C';
        else input = input + 'C';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btnDclicked(){
    if(input=="0")
        input = 'D';
        else input = input + 'D';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btnEclicked(){
    if(input=="0")
        input = 'E';
        else input = input + 'E';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btnFclicked(){
    if(input=="0")
        input = 'F';
        else input = input + 'F';
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }
}
void programmer::btnzfclicked(){

}
void programmer::btnresultclicked(){}
