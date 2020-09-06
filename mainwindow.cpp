#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Standard");
    resize(500,500);
    connect(ui->aProgrammer,&QAction::triggered,this,&MainWindow::progshow);//窗口切换
    connect(ui->aScientific,&QAction::triggered,this,&MainWindow::scinshow);
    connect(&prog,&programmer::sstand,this,&MainWindow::p_st);
    connect(&prog,&programmer::sscin,this,&MainWindow::p_s);
    connect(&scin,&scientific::sst,this,&MainWindow::s_st);
    connect(&scin,&scientific::sp,this,&MainWindow::s_p);//窗口切换

    ui->inputline->setText(input);
    connect(ui->btn0,&QPushButton::clicked,this,&MainWindow::btn0clicked);
    connect(ui->btn1,&QPushButton::clicked,this,&MainWindow::btn1clicked);
    connect(ui->btn2,&QPushButton::clicked,this,&MainWindow::btn2clicked);
    connect(ui->btn3,&QPushButton::clicked,this,&MainWindow::btn3clicked);
    connect(ui->btn4,&QPushButton::clicked,this,&MainWindow::btn4clicked);
    connect(ui->btn5,&QPushButton::clicked,this,&MainWindow::btn5clicked);
    connect(ui->btn6,&QPushButton::clicked,this,&MainWindow::btn6clicked);
    connect(ui->btn7,&QPushButton::clicked,this,&MainWindow::btn7clicked);
    connect(ui->btn8,&QPushButton::clicked,this,&MainWindow::btn8clicked);
    connect(ui->btn9,&QPushButton::clicked,this,&MainWindow::btn9clicked);
    connect(ui->btnjia,&QPushButton::clicked,this,&MainWindow::btnjiaclicked);
    connect(ui->btnjian,&QPushButton::clicked,this,&MainWindow::btnjianclicked);
    connect(ui->btncheng,&QPushButton::clicked,this,&MainWindow::btnchengclicked);
    connect(ui->btnchu,&QPushButton::clicked,this,&MainWindow::btnchuclicked);
    connect(ui->btnresult,&QPushButton::clicked,this,&MainWindow::btnresultclicked);
    connect(ui->btnzf,&QPushButton::clicked,this,&MainWindow::btnzfclicked);
    connect(ui->btndian,&QPushButton::clicked,this,&MainWindow::btndianclicked);
    connect(ui->btnkl,&QPushButton::clicked,this,&MainWindow::btnklclicked);
    connect(ui->btnkr,&QPushButton::clicked,this,&MainWindow::btnkrclicked);
    connect(ui->btnC,&QPushButton::clicked,this,&MainWindow::btnCclicked);

}


void MainWindow::progshow(){                             //窗口切换
    prog.show();
    this->hide();
}
void MainWindow::scinshow(){
    scin.show();
    this->hide();
}
void MainWindow::p_st(){
    prog.hide();
    this->show();
}
void MainWindow::p_s(){
    prog.hide();
    scin.show();
}
void MainWindow::s_p(){
    scin.hide();
    prog.show();
}
void MainWindow::s_st(){                               //窗口切换
    scin.hide();
    this->show();
}

void MainWindow::btn0clicked(){
    if(input=="0")
        input = '0';
        else input = input + '0';
        ui->inputline->setText(input);

}
void MainWindow::btn1clicked(){
    if(input=="0")
        input = '1';
        else input = input + '1';
        ui->inputline->setText(input);

}
void MainWindow::btn2clicked(){
    if(input=="0")
        input = '2';
        else input = input + '2';
        ui->inputline->setText(input);

}
void MainWindow::btn3clicked(){
    if(input=="0")
        input = '3';
        else input = input + '3';
        ui->inputline->setText(input);

}
void MainWindow::btn4clicked(){
    if(input=="0")
        input = '4';
        else input = input + '4';
        ui->inputline->setText(input);

}
void MainWindow::btn5clicked(){
    if(input=="0")
        input = '5';
        else input = input + '5';
        ui->inputline->setText(input);

}
void MainWindow::btn6clicked(){
    if(input=="0")
        input = '6';
        else input = input + '6';
        ui->inputline->setText(input);

}
void MainWindow::btn7clicked(){
    if(input=="0")
        input = '7';
        else input = input + '7';
        ui->inputline->setText(input);

}
void MainWindow::btn8clicked(){
    if(input=="0")
        input = '8';
        else input = input + '8';
        ui->inputline->setText(input);

}
void MainWindow::btn9clicked(){
    if(input=="0")
        input = '9';
        else input = input + '9';
        ui->inputline->setText(input);

}
void MainWindow::btnjiaclicked(){
    if(input=="0")
        input = '+';
        else input = input + '+';
        ui->inputline->setText(input);

}
void MainWindow::btnjianclicked(){
    if(input=="0")
        input = '-';
        else input = input + '-';
        ui->inputline->setText(input);

}
void MainWindow::btnchengclicked(){
    if(input=="0")
        input = '*';
        else input = input + '*';
        ui->inputline->setText(input);

}
void MainWindow::btnchuclicked(){
    if(input=="0")
        input = '/';
        else input = input + '/';
        ui->inputline->setText(input);

}
void MainWindow::btndianclicked(){
    if(input=="0")
        input = '.';
        else input = input + '.';
        ui->inputline->setText(input);

}
void MainWindow::btnklclicked(){
    if(input=="0")
        input = '(';
        else input = input + '(';
        ui->inputline->setText(input);

}
void MainWindow::btnkrclicked(){
    if(input=="0")
        input = ')';
        else input = input + ')';
        ui->inputline->setText(input);

}
void MainWindow::btnCclicked(){
        input = '0';
        ui->inputline->setText(input);

}
void MainWindow::btnzfclicked(){                    //正负号
    if(input=="0")
        input = '1';
        else input = input + "1";
        ui->inputline->setText(input);

}

void MainWindow::btnresultclicked(){                //计算
    if(input=="0")
        input = '1';
        else input = input + "1";
        ui->inputline->setText(input);

}

MainWindow::~MainWindow()
{
    delete ui;
}
