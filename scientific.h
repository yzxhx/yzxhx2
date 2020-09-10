#ifndef SCIENTIFIC_H
#define SCIENTIFIC_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QStack>
#include <iterator>
#include <iostream>

class scientific : public QMainWindow
{
    Q_OBJECT
public:
    explicit scientific(QWidget *parent = nullptr);
public:
    void sendst();
    void sendp();

    void bt0clicked();
    void bt1clicked();
    void bt2clicked();
    void bt3clicked();
    void bt4clicked();
    void bt5clicked();
    void bt6clicked();
    void bt7clicked();
    void bt8clicked();
    void bt9clicked();
    void btjiaclicked();
    void btjianclicked();
    void btchengclicked();
    void btchuclicked();
    void btresultclicked();
    void btzfclicked();
    void btdianclicked();
    void bttgclicked();
    void btACclicked();
    void btzsclicked();
    void btyyclicked();
    void btyeclicked();
    void btfbclicked();
    void btgbsclicked();
    void btgysclicked();
    void btzshsclicked();
    void btsinclicked();
    void btcosclicked();
    void bttanclicked();
    void btklclicked();
    void btkrclicked();
    void btpaiclicked();
    void bteclicked();
    void btlgclicked();
    void btlnclicked();

signals:
   void sst();
   void sp();
private:
   QPushButton *bt0;QPushButton *bt1;QPushButton *bt2;QPushButton *bt3;
   QPushButton *bt4;QPushButton *bt5;QPushButton *bt6;QPushButton *bt7;
   QPushButton *bt8;QPushButton *bt9;QPushButton *btjia;QPushButton *btjian;
   QPushButton *btcheng;QPushButton *btchu;QPushButton *btresult;QPushButton *btzf;
   QPushButton *btdian;QPushButton *bttg;QPushButton *btAC;QPushButton *btzs;

   QPushButton *btyy;QPushButton *btye;QPushButton *btfb;
   QPushButton *btgbs;QPushButton *btgys;   QPushButton *btzshs;
   QPushButton *btsin;QPushButton *btcos;   QPushButton *bttan;

   QPushButton *btkl;QPushButton *btkr;QPushButton *btpai;
   QPushButton *bte; QPushButton *btlg;QPushButton *btln;

   QLineEdit *data;
   QString input = "0";
public slots:
};

#endif // SCIENTIFIC_H
