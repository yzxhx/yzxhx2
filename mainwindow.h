#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <programmer.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    void btnresultclicked();

    void btnzfclicked();
    void btndianclicked();
    void btntgclicked();
    void btnclclicked();
    void btnpfclicked();
    void btnghclicked();
    void btnbfhclicked();
    void btntimeclicked();

    void btnzsclicked();
    void btnklclicked();
    void btnkrclicked();
    void btnlnclicked();
    void btnjiecclicked();
    void btn10xclicked();

    void btnyyclicked();
    void btnyeclicked();
    void btnfbclicked();
    void btngbsclicked();
    void btngysclicked();
    void btnzshsclicked();

    void btnsinclicked();
    void btncosclicked();
    void btntanclicked();

    void btnpaiclicked();
    void btneclicked();
    void btnlgclicked();
    void btnmodclicked();
    void shiftpro();
    void shiftstand();


private:
    Ui::MainWindow *ui;
    programmer w;
    QString input = "0";
};

#endif // MAINWINDOW_H
