#include "programmer.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <iostream>
#include <stack>       //栈
#include <vector>     //容器
#include <cstdlib>    //字符串处理
#include <limits.h>
using namespace std;
int jzzh = 1;
int bc = 0;
string hextodec(string s);
string bintodec(string s);
bool isnum2(char x);  //判断数字
bool isfh2(char x);   //判断符号
int  yxj2(char x);    //判断优先级
vector<string> hzbds2(string s);//后缀表达式
double cv2(string s); //转数字
double js2(vector<string> V);//计算后缀表达式

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
    jzzh = 1;input = "0";bc=0;
    datadec->setText(input);databin->setText(input);datahex->setText(input);

}
void programmer::sljz(){
    jzzh = 2;input = "0";bc=0;
    datadec->setText(input);databin->setText(input);datahex->setText(input);

}
void programmer::ejz(){
    jzzh = 3;input = "0";bc=0;
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
    if(jzzh==3)bc=1;
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
    if(jzzh==3)bc=1;
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
    if(jzzh==3)bc=1;
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
    if(jzzh==3)bc=1;
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
    if(jzzh==3)bc=1;
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
    if(jzzh==3)bc=1;
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
    if(jzzh==3)bc=1;
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
    if(jzzh==3)bc=1;
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
    input = "0";bc=0;
    datadec->setText(input);databin->setText(input);datahex->setText(input);
}
void programmer::btnAclicked(){
    if(jzzh!=2)bc=1;
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
    if(jzzh!=2)bc=1;
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
    if(jzzh!=2)bc=1;
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
    if(jzzh!=2)bc=1;
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
    if(jzzh!=2)bc=1;
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
    if(jzzh!=2)bc=1;
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
    if(jzzh!=1&&input=="0")bc=1;
    if(input=="0")
        input = '-';
    else {
    QString::iterator p = input.end();             //遍历至输入端的末尾，如果最后一位是负号，则取消
    p--;
    if(*p == '-')input = input.left(input.length()-1);
    else input = input + '-';
    }
    switch (jzzh) {
       case 1:datadec->setText(input);break;
       case 2:datahex->setText(input);break;
       case 3:databin->setText(input);break;
       default:break;
    }

}
void programmer::btnresultclicked(){
    if(bc){
        input="输入表达式错误";
        datadec->setText(input);databin->setText(input);datahex->setText(input);
    }
    else{
        if(jzzh==1){
            string s = input.toStdString();
            vector<string> V = hzbds2(s);
            double value = js2(V);
            int value2 = value;
            if(value !=INT_MAX) {
              input=QString::number(value);
              QString t1 = QString::number(value2, 16);
              QString t2 = QString::number(value2, 2);
              databin->setText(t2);
              datahex->setText(t1);
              datadec->setText(input);
            }else{
              input="表达式错误";
              datadec->setText(input);databin->setText(input);datahex->setText(input);
            }

        }
        if(jzzh==2){
            string ss = input.toStdString();
            string s=hextodec(ss);
            vector<string> V = hzbds2(s);
            double value = js2(V);
            int value2 = value;
            if(value !=INT_MAX) {
              input=QString::number(value);
              QString t1 = QString::number(value2, 16);
              QString t2 = QString::number(value2, 2);
              databin->setText(t2);
              datahex->setText(t1);
              datadec->setText(input);
            }else{
              input="表达式错误";
              datadec->setText(input);databin->setText(input);datahex->setText(input);
            }

        }
        if(jzzh==3){
            string ss = input.toStdString();
            string s=bintodec(ss);
            vector<string> V = hzbds2(s);
            double value = js2(V);
            int value2 = value;
            if(value !=INT_MAX) {
              input=QString::number(value);
              QString t1 = QString::number(value2, 16);
              QString t2 = QString::number(value2, 2);
              databin->setText(t2);
              datahex->setText(t1);
              datadec->setText(input);
            }else{
              input="表达式错误";
              datadec->setText(input);databin->setText(input);datahex->setText(input);
            }
        }




    }
}
string hextodec(string s){
    string jg="";string ls;int i,j=0,f=0,len=0;
    for(i=0;i<s.length();i++){
        if(!isfh2(s[i])&&i<s.length()-1){len++;continue;}
        if(i==s.length()-1&&!isfh2(s[i]))len++;
        ls=s.substr(f,len);
        bool ok;
        QString ls2 = QString::fromStdString(ls);
        int data10 = ls2.toInt(&ok,16);
        QString temp = QString::number(data10,10);
        string temp2 = temp.toStdString();
        jg+=temp2;if(isfh2(s[i])){jg+=s[i];f=i+1;len=0;}
    }

    return jg;
}
string bintodec(string s){
    string jg="";string ls;int i,j=0,f=0,len=0;
    for(i=0;i<s.length();i++){
        if(!isfh2(s[i])&&i<s.length()-1){len++;continue;}
        if(i==s.length()-1&&!isfh2(s[i]))len++;
        ls=s.substr(f,len);
        bool ok;
        QString ls2 = QString::fromStdString(ls);
        int data10 = ls2.toInt(&ok,2);
        QString temp = QString::number(data10,10);
        string temp2 = temp.toStdString();
        jg+=temp2;if(isfh2(s[i])){jg+=s[i];f=i+1;len=0;}
    }

    return jg;
}
bool isnum2(char x){
    if(x>='0'&&x<='9'||x>='A'&&x<='F')return true;
    else return false;
}
bool isfh2(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')return true;
    else return false;
}
int yxj2(char x){
    int fhyxj = 0;
    if(x=='*'||x=='/')fhyxj = 3;
    if(x=='+'||x=='-')fhyxj = 2;
    return fhyxj;
}
double cv2(string s){
    bool gs = true;                          //判断格式是否正确
    for(int i = 0; i < s.length(); i++) {
        if(i == 0 && s[i] == '-') continue; //负数仅有一个负号
        else if(isnum2(s[i])) continue;
        else return INT_MAX;
    }
    double result = atof(s.c_str());  //字符串改为浮点型
    return result;                    //返回数值
}
vector<string> hzbds2(string s){
  stack<char> fh;                                       //存放临时符号的栈
  vector<string> V;                                     //返回后缀表达式
  int i = 0;
  while(i<s.length()){
      if(isnum2(s[i])){
          string str = "";
          while(isnum2(s[i])||s[i]=='.'){
              str +=s[i];i++;
          }
          V.push_back(str);                              //将数字放入容器
      }

      else{
          if(s[i]=='-'&&(i==0||isfh2(s[i-1]))){
              string str = "-";i++;
              while(isnum2(s[i])||s[i]=='.'){
                  str+=s[i];i++;
              }
              V.push_back(str);                          //判断为负数的情况
          }
          else{
              if(fh.empty()){
                  fh.push(s[i]);i++;
              }                                   //将第一个符号入栈
              else{
                  int begin = yxj2(s[i]);        //记录第一个运算符的优先级
                      while(!fh.empty()&&begin<=yxj2(fh.top())&&yxj2(fh.top())!=4){
                          string str = "";   //如果为一般运算符，当其优先级大于栈顶优先级是入栈，否则将栈顶放入容器
                          str += fh.top();
                          V.push_back(str);
                          fh.pop();
                      }
                      fh.push(s[i]);i++;
              }
          }

      }

  }
  while(!fh.empty()){  //将栈中剩余运算符放入容器
      string str = "";
      str += fh.top();
      fh.pop();
      V.push_back(str);
  }
  return V;
}
double js2(vector<string> V){
    stack<double> result;   //存放临时结果
    int i =0;
    for(;i<V.size();i++){
        if(V[i].length()==1&&isfh2(V[i][0])){ //判断是否为符号
            double a=0,b=0;
            if(!result.empty()) {
                a = result.top(); result.pop();
            }else return INT_MAX; //判断表达式是否异常
            if(!result.empty()) {
                b = result.top(); result.pop();
            }else return INT_MAX;
            switch(V[i][0]) {    //计算表达式，将结果入栈
                case '+':
                    result.push(b+a);
                    break;
                case '-':
                    result.push(b-a);
                    break;
                case '*':
                    result.push(b*a);
                    break;
                case '/':
                    result.push(b/a);
                    break;
                default:
                  return INT_MAX;
            }

        }
        else{
            if(cv2(V[i])==INT_MAX)return INT_MAX;
            else result.push(cv2(V[i]));//将容器内数值入栈
        }
    }
    if(result.empty()) return INT_MAX;

    double value = result.top();
    result.pop();
    return value;
}
