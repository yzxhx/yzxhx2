#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
class programmer : public QMainWindow
{
    Q_OBJECT
public:
    explicit programmer(QWidget *parent = nullptr);
public:
    void sendsst();
    void sendsc();
    void sjz();
    void sljz();
    void ejz();

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
    void sstand();
    void sscin();

public slots:
private:
    QPushButton *btn0;QPushButton *btn1;QPushButton *btn2;QPushButton *btn3;
    QPushButton *btn4;QPushButton *btn5;QPushButton *btn6;QPushButton *btn7;
    QPushButton *btn8;QPushButton *btn9;QPushButton *btnjia;QPushButton *btnjian;
    QPushButton *btncheng;QPushButton *btnchu;QPushButton *btnA;QPushButton *btnB;
    QPushButton *btnC;QPushButton *btnD;QPushButton *btnE;QPushButton *btnF;
    QPushButton *btnfh;QPushButton *btnCL;QPushButton *btntg;QPushButton *btnresult;
    QPushButton *btnHex;QPushButton *btnDec;QPushButton *btnBin;
    QLineEdit *datahex;QLineEdit *datadec;QLineEdit *databin;QPushButton *btnhex;QPushButton *btnbin;
    QString input = "0";
};

#endif // PROGRAMMER_H
