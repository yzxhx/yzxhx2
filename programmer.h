#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <QMainWindow>

namespace Ui {
class programmer;
}

class programmer : public QMainWindow
{
    Q_OBJECT

public:
    explicit programmer(QWidget *parent = nullptr);
    ~programmer();
    void sendslot();
    void jz2();
    void jz8();
    void jz10();
    void jz16();

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
    void btnCLclicked();
    void btntgclicked();
    void btnAclicked();
    void btnBclicked();
    void btnCclicked();
    void btnDclicked();
    void btnEclicked();
    void btnFclicked();
signals:
    void change();
private:
    Ui::programmer *ui;
    QString input = "0";
};

#endif // PROGRAMMER_H
