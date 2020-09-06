#include "programmer.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
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
    btncheng = new QPushButton("*");btnchu = new QPushButton("/");btnfh = new QPushButton("+/-");btndian = new QPushButton(".");
    btnA = new QPushButton("A");btnB = new QPushButton("B");btnC = new QPushButton("C");btnD = new QPushButton("D");
    btnE = new QPushButton("E");btnF = new QPushButton("F");btnCL = new QPushButton("C");btnresult = new QPushButton("=");
    btnHex = new QPushButton("Hex"); btnDec = new QPushButton("Dec"); btnBin = new QPushButton("Bin");
    databin->setFixedHeight(30);datadec->setFixedHeight(30);datahex->setFixedHeight(30);
    btnBin->setMinimumHeight(30);btnDec->setMinimumHeight(30);btnHex->setMinimumHeight(30);
    btn0->setMinimumHeight(40);btn1->setMinimumHeight(40);btn2->setMinimumHeight(40);btn3->setMinimumHeight(40);
    btn4->setMinimumHeight(40);btn5->setMinimumHeight(40);btn6->setMinimumHeight(40);btn7->setMinimumHeight(40);
    btn8->setMinimumHeight(40);btn9->setMinimumHeight(40);btnjia->setMinimumHeight(40);btnjian->setMinimumHeight(40);
    btncheng->setMinimumHeight(40);btnchu->setMinimumHeight(40);btnfh->setMinimumHeight(40);btndian->setMinimumHeight(40);
    btnA->setMinimumHeight(40);btnB->setMinimumHeight(40);btnC->setMinimumHeight(40);btnD->setMinimumHeight(40);
    btnE->setMinimumHeight(40);btnF->setMinimumHeight(40);btnCL->setMinimumHeight(40);btnresult->setMinimumHeight(40);
    QGridLayout * layout = new QGridLayout;
    layout->addWidget(btnDec,1,1,Qt::Alignment());layout->addWidget(datadec,1,2,1,4,Qt::Alignment());
    layout->addWidget(btnHex,2,1,Qt::Alignment());layout->addWidget(datahex,2,2,1,4,Qt::Alignment());
    layout->addWidget(btnBin,3,1,Qt::Alignment());layout->addWidget(databin,3,2,1,4,Qt::Alignment());
    layout->addWidget(btnA,4,1,Qt::Alignment());layout->addWidget(btnCL,4,2,Qt::Alignment());layout->addWidget(btnchu,4,3,Qt::Alignment());
    layout->addWidget(btnresult,4,4,Qt::Alignment());layout->addWidget(btnB,5,1,Qt::Alignment());layout->addWidget(btnjia,5,2,Qt::Alignment());
    layout->addWidget(btnjian,5,3,Qt::Alignment());layout->addWidget(btncheng,5,4,Qt::Alignment());layout->addWidget(btnC,6,1,Qt::Alignment());
    layout->addWidget(btn7,6,2,Qt::Alignment());layout->addWidget(btn8,6,3,Qt::Alignment());layout->addWidget(btn9,6,4,Qt::Alignment());
    layout->addWidget(btnD,7,1,Qt::Alignment());layout->addWidget(btn4,7,2,Qt::Alignment());layout->addWidget(btn5,7,3,Qt::Alignment());
    layout->addWidget(btn6,7,4,Qt::Alignment());layout->addWidget(btnE,8,1,Qt::Alignment());layout->addWidget(btn1,8,2,Qt::Alignment());
    layout->addWidget(btn2,8,3,Qt::Alignment());layout->addWidget(btn3,8,4,Qt::Alignment());layout->addWidget(btnF,9,1,Qt::Alignment());
    layout->addWidget(btnfh,9,2,Qt::Alignment());layout->addWidget(btn0,9,3,Qt::Alignment());layout->addWidget(btndian,9,4,Qt::Alignment());
    centerwindow->setLayout(layout);//设置界面

}

void programmer::sendsst(){  //切换至standa信号
    emit sstand();
}
void programmer::sendsc(){  //切换至scienti信号
    emit sscin();
}
