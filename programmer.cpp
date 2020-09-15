#include "programmer.h"
#include "ui_programmer.h"
#include <QString>
#include <QStack>
#include <iterator>
#include <iostream>
#include <stack>       //栈
#include <vector>     //容器
#include <cstdlib>    //字符串处理
#include <limits.h>
using namespace std;
int jzzh = 1;//判断是否执行进制转换
int bc = 0;//判断输入是否报错
string hextodec(string s);
string bintodec(string s);
string octtodec(string s);
bool isnum2(char x);  //判断数字
bool isfh2(char x);   //判断符号
int  yxj2(char x);    //判断优先级
vector<string> hzbds2(string s);//后缀表达式
double cv2(string s); //转数字
double js2(vector<string> V);//计算后缀表达式
programmer::programmer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::programmer)
{
    ui->setupUi(this);
    setWindowTitle("Programmer");
    resize(1000,1000);
    connect(ui->standard,&QAction::triggered,this,&programmer::sendslot);
    ui->line2->setText(input);ui->line8->setText(input);
    ui->line10->setText(input);ui->line16->setText(input);
    ui->line2->setFont(QFont("黑体",40)); ui->line8->setFont(QFont("黑体",40));
    ui->line10->setFont(QFont("黑体",40)); ui->line16->setFont(QFont("黑体",40));//设置字体
    connect(ui->sjz,&QRadioButton::clicked,this,&programmer::jz10);
    connect(ui->bjz,&QRadioButton::clicked,this,&programmer::jz8);
    connect(ui->sljz,&QRadioButton::clicked,this,&programmer::jz16);
    connect(ui->ejz,&QRadioButton::clicked,this,&programmer::jz2);

    connect(ui->btchu,&QPushButton::clicked,this,&programmer::btnchuclicked);
    connect(ui->btc,&QPushButton::clicked,this,&programmer::btnCLclicked);
    connect(ui->bttg,&QPushButton::clicked,this,&programmer::btntgclicked);
    connect(ui->btjia,&QPushButton::clicked,this,&programmer::btnjiaclicked);
    connect(ui->btjian,&QPushButton::clicked,this,&programmer::btnjianclicked);
    connect(ui->btcheng,&QPushButton::clicked,this,&programmer::btnchengclicked);
    connect(ui->bt0,&QPushButton::clicked,this,&programmer::btn0clicked);
    connect(ui->bt1,&QPushButton::clicked,this,&programmer::btn1clicked);
    connect(ui->btresult,&QPushButton::clicked,this,&programmer::btnresultclicked);
    connect(ui->bt2,&QPushButton::clicked,this,&programmer::btn2clicked);
    connect(ui->bt3,&QPushButton::clicked,this,&programmer::btn3clicked);
    connect(ui->bt4,&QPushButton::clicked,this,&programmer::btn4clicked);
    connect(ui->bt5,&QPushButton::clicked,this,&programmer::btn5clicked);
    connect(ui->bt6,&QPushButton::clicked,this,&programmer::btn6clicked);
    connect(ui->bt7,&QPushButton::clicked,this,&programmer::btn7clicked);
    connect(ui->bt8,&QPushButton::clicked,this,&programmer::btn8clicked);
    connect(ui->bt9,&QPushButton::clicked,this,&programmer::btn9clicked);
    connect(ui->btzf,&QPushButton::clicked,this,&programmer::btnzfclicked);
    connect(ui->btA,&QPushButton::clicked,this,&programmer::btnAclicked);
    connect(ui->btB,&QPushButton::clicked,this,&programmer::btnBclicked);
    connect(ui->btC,&QPushButton::clicked,this,&programmer::btnCclicked);
    connect(ui->btD,&QPushButton::clicked,this,&programmer::btnDclicked);
    connect(ui->btE,&QPushButton::clicked,this,&programmer::btnEclicked);
    connect(ui->btF,&QPushButton::clicked,this,&programmer::btnFclicked);
}
void programmer::sendslot(){
    emit change();
}
void programmer::jz10(){
    jzzh = 1;input = "0";bc=0;
    ui->line10->setText(input);ui->line2->setText(input);ui->line16->setText(input);
    ui->line8->setText(input);

}
void programmer::jz16(){
    jzzh = 2;input = "0";bc=0;
    ui->line10->setText(input);ui->line2->setText(input);ui->line16->setText(input);
    ui->line8->setText(input);
}
void programmer::jz2(){
    jzzh = 3;input = "0";bc=0;
    ui->line10->setText(input);ui->line2->setText(input);ui->line16->setText(input);
    ui->line8->setText(input);
}
void programmer::jz8(){
    jzzh = 4;input = "0";bc=0;
    ui->line10->setText(input);ui->line2->setText(input);ui->line16->setText(input);
    ui->line8->setText(input);
}
void programmer::btn0clicked(){
    if(input=="0")
        input = '0';
        else input = input + '0';
    switch (jzzh) {
       case 1:ui->line10->setText(input);break;
       case 2:ui->line16->setText(input);break;
       case 3:ui->line2->setText(input);break;
       case 4:ui->line8->setText(input);break;
       default:break;
    }

}
void programmer::btn1clicked(){
    if(input=="0")
        input = '1';
        else input = input + '1';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btn2clicked(){
    if(jzzh==3)bc=1;
    if(input=="0")
        input = '2';
        else input = input + '2';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
    default:break;
    }
}
void programmer::btn3clicked(){
    if(jzzh==3)bc=1;
    if(input=="0")
        input = '3';
        else input = input + '3';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btn4clicked(){
    if(jzzh==3)bc=1;
    if(input=="0")
        input = '4';
        else input = input + '4';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btn5clicked(){
    if(jzzh==3)bc=1;
    if(input=="0")
        input = '5';
        else input = input + '5';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btn6clicked(){
    if(jzzh==3)bc=1;
    if(input=="0")
        input = '6';
        else input = input + '6';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btn7clicked(){
    if(jzzh==3)bc=1;
    if(input=="0")
        input = '7';
        else input = input + '7';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btn8clicked(){
    if(jzzh>=3)bc=1;
    if(input=="0")
        input = '8';
        else input = input + '8';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
    default:break;
    }
}
void programmer::btn9clicked(){
    if(jzzh>=3)bc=1;
    if(input=="0")
        input = '9';
        else input = input + '9';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btnjiaclicked(){
    if(input=="0")
        input = '+';
        else input = input + '+';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btnjianclicked(){
    if(input=="0")
        input = '-';
        else input = input + '-';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btnchengclicked(){
    if(input=="0")
        input = '*';
        else input = input + '*';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btnchuclicked(){
    if(input=="0")
        input = '/';
        else input = input + '/';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btntgclicked(){
    input = input.left(input.length()-1);
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btnCLclicked(){
    input = "0";bc=0;
   ui->line10->setText(input);ui->line16->setText(input);ui->line2->setText(input);
   ui->line8->setText(input);
}
void programmer::btnAclicked(){
    if(jzzh!=2)bc=1;
    if(input=="0")
        input = 'A';
        else input = input + 'A';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btnBclicked(){
    if(jzzh!=2)bc=1;
    if(input=="0")
        input = 'B';
        else input = input + 'B';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btnCclicked(){
    if(jzzh!=2)bc=1;
    if(input=="0")
        input = 'C';
        else input = input + 'C';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btnDclicked(){
    if(jzzh!=2)bc=1;
    if(input=="0")
        input = 'D';
        else input = input + 'D';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btnEclicked(){
    if(jzzh!=2)bc=1;
    if(input=="0")
        input = 'E';
        else input = input + 'E';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }
}
void programmer::btnFclicked(){
    if(jzzh!=2)bc=1;
    if(input=="0")
        input = 'F';
        else input = input + 'F';
    switch (jzzh) {
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
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
    case 1:ui->line10->setText(input);break;
    case 2:ui->line16->setText(input);break;
    case 3:ui->line2->setText(input);break;
    case 4:ui->line8->setText(input);break;
       default:break;
    }

}
void programmer::btnresultclicked(){
    if(bc){
        input="输入表达式错误";
        ui->line2->setText(input);ui->line8->setText(input);ui->line10->setText(input);
        ui->line16->setText(input);
    }
    else{
        if(jzzh==1){
            string s = input.toStdString();
            vector<string> V = hzbds2(s);
            int value = js2(V);
            int value2 = value;//强制类型转换
            if(value !=INT_MAX) {
              input=QString::number(value2);
              QString t1 = QString::number(value2, 16);
              t1=t1.toUpper();
              QString t2 = QString::number(value2, 2);
              QString t3 = QString::number(value2,8);
              ui->line2->setText(t2);
              ui->line16->setText(t1);
              ui->line8->setText(t3);
              ui->line10->setText(input);

            }else{
              input="表达式错误";
              ui->line10->setText(input);ui->line8->setText(input);
              ui->line2->setText(input);ui->line16->setText(input);
            }

        }
        if(jzzh==2){
            string ss = input.toStdString();
            string s=hextodec(ss);
            vector<string> V = hzbds2(s);
            double value = js2(V);
            int value2 = value;
            if(value !=INT_MAX) {
              input=QString::number(value2);
              QString t1 = QString::number(value2, 16);
              t1=t1.toUpper();
              QString t2 = QString::number(value2, 2);
              QString t3 = QString::number(value2,8);
              ui->line2->setText(t2);
              ui->line16->setText(t1);
              ui->line8->setText(t3);
              ui->line10->setText(input);
              input = t1;
            }else{
              input="表达式错误";
              ui->line10->setText(input);ui->line8->setText(input);
              ui->line2->setText(input);ui->line16->setText(input);
            }

        }
        if(jzzh==3){
            string ss = input.toStdString();
            string s=bintodec(ss);
            vector<string> V = hzbds2(s);
            double value = js2(V);
            int value2 = value;
            if(value !=INT_MAX) {
              input=QString::number(value2);
              QString t1 = QString::number(value2, 16);
              t1=t1.toUpper();
              QString t2 = QString::number(value2, 2);
              QString t3 = QString::number(value2,8);
              ui->line2->setText(t2);
              ui->line16->setText(t1);
              ui->line8->setText(t3);
              ui->line10->setText(input);
              input = t2;
            }else{
              input="表达式错误";
              ui->line10->setText(input);ui->line8->setText(input);
              ui->line2->setText(input);ui->line16->setText(input);
            }
        }
        if(jzzh==4){
            string ss = input.toStdString();
            string s=octtodec(ss);
            vector<string> V = hzbds2(s);
            double value = js2(V);
            int value2 = value;
            if(value !=INT_MAX) {
              input=QString::number(value2);
              QString t1 = QString::number(value2, 16);
              t1=t1.toUpper();
              QString t2 = QString::number(value2, 2);
              QString t3 = QString::number(value2,8);
              ui->line2->setText(t2);
              ui->line16->setText(t1);
              ui->line8->setText(t3);
              ui->line10->setText(input);
              input = t3;
            }else{
              input="表达式错误";
              ui->line10->setText(input);ui->line8->setText(input);
              ui->line2->setText(input);ui->line16->setText(input);
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
string octtodec(string s){
    string jg="";string ls;int i,j=0,f=0,len=0;
    for(i=0;i<s.length();i++){
        if(!isfh2(s[i])&&i<s.length()-1){len++;continue;}
        if(i==s.length()-1&&!isfh2(s[i]))len++;
        ls=s.substr(f,len);
        bool ok;
        QString ls2 = QString::fromStdString(ls);
        int data10 = ls2.toInt(&ok,8);
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
programmer::~programmer()
{
    delete ui;
}
