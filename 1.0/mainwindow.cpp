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


MainWindow::~MainWindow()
{
    delete ui;
}
