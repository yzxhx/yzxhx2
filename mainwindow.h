#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "programmer.h"
#include "scientific.h"
#include <QString>
#include <QStack>
#include <iterator>
#include <iostream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    void progshow();//窗口切换
    void scinshow();
    void p_st();
    void p_s();
    void s_st();
    void s_p();

    void btn0clicked();
    void btn1clicked();
    void btn2clicked();
    void btn3clicked();
    void btn4clicked();
    void btn5clicked();
    void btn6clicked();
    void btn7clicked();
    void btn8clicked();
    void btn9clicked();
    void btnjiaclicked();
    void btnjianclicked();
    void btnchengclicked();
    void btnchuclicked();
    void btnklclicked();
    void btnkrclicked();
    void btnresultclicked();
    void btnzfclicked();
    void btndianclicked();
    void btnCclicked();
    void btnbfhclicked();
    void btnpfclicked();
    void btnghclicked();
    void btntgclicked();
private:
    Ui::MainWindow *ui;
    programmer prog;
    scientific scin;

    QString input = "0";
};

#endif // MAINWINDOW_H
