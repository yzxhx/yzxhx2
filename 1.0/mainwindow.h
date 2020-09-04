#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "programmer.h"
#include "scientific.h"
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

private:
    Ui::MainWindow *ui;
    programmer prog;
    scientific scin;
};

#endif // MAINWINDOW_H
