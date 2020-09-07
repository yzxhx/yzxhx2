#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
using namespace std;
#include <stack>
#include <vector>
#include <cstdlib>  //字符串处理

#include <limits.h>


bool isnum(char x);
bool isfh(char x);
int  yxj(char x);
vector<string> hzbds(string s);
double cv(string s);
double js(vector<string> V);
int zq=1;

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

void MainWindow::btn0clicked(){                        //按钮信号链接
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
        input = input + '.';
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
        input = '-';
    else {
    QString::iterator p = input.end();             //遍历至输入端的末尾，如果最后一位是负号，则取消
    p--;
    if(*p == '-')input = input.left(input.length()-1);
    else input = input + '-';
    }
    ui->inputline->setText(input);

}

void MainWindow::btnresultclicked(){                //计算
    string inputTemp = input.toStdString();  //将QString 转化为 string
    vector<string> expression = hzbds(inputTemp);
    double value = js(expression);
    if(zq) {
      input=input+"="+QString::number(value);
      ui->inputline->setText(input);
    }else{
      input="表达式错误";            //语法错误
      ui->inputline->setText(input);
    }
}
bool isnum(char x){                                 //判断是否为数字
    if(x>='0'&&x<='9')return true;
    else return false;
}
bool isfh(char x){                                    //判断是否为符号
    if(x=='('||x==')'||x=='+'||x=='-'||x=='*'||x=='/')return true;
    else return false;
}
int yxj(char x){                                       //运算符的优先级
    int fhyxj = 0;
    if(x=='(')fhyxj = 4;
    if(x=='*'||x=='/')fhyxj = 3;
    if(x=='+'||x=='-')fhyxj = 2;
    if(x==')')fhyxj = 1;
    return fhyxj;
}
double cv(string s){
    bool flag = false;
    for(int i = 0; i < s.length(); i++) {
        if(i == 0 && s[i] == '-') continue;
        else if(s[i] == '.' && !flag) {
            if(i > 0 && isnum(s[i-1])) {
                flag = true;
                continue;
            }
            else {zq=0;return 0;}
        }
        else if(isnum(s[i])) continue;
        else {zq=0;return 0;}
    }

    double result = atof(s.c_str());  //字符串改为浮点数
    return result;
}
vector<string> hzbds(string s){
  stack<char> fh;                                       //存放临时符号
  vector<string> V;                                     //返回后缀表达式
  int i = 0;
  while(i<s.length()){
      if(isnum(s[i])){
          string str = "";
          while(isnum(s[i])||s[i]=='.'){
              str+=s[i];i++;
          }
          V.push_back(str);                              //将数字放入容器
      }

      else{
          if(s[i]=='-'&&(i==0||isfh(s[i-1]))){
              string str = "-";i++;
              while(isnum(s[i])||s[i]=='.'){
                  str+=s[i];i++;
              }
              V.push_back(str);                          //判断为负数的情况
          }
          else{
              if(fh.empty()){
                  fh.push(s[i]);i++;
              }                                   //将第一个符号入栈
              else{
                  int begin = yxj(s[i]);
                  if(begin==1){
                      while(yxj(fh.top())!=4){
                          string str = "";
                          str += fh.top();
                      }
                  }
                  else if(begin==4){
                      fh.push(s[i]);i++;
                  }
                  else{
                      while(begin<=yxj(fh.top())&&yxj(fh.top())!=4){
                          string str = "";
                          str += fh.top();
                          V.push_back(str);
                          fh.pop();
                      }
                      fh.push(s[i]);i++;


                  }

              }
          }

      }

  }
  while(!fh.empty()){
      string str = "";
      str += fh.top();
      fh.pop();
      V.push_back(str);
  }
  return V;
}
double js(vector<string> V){
    stack<double> result;
    int i =0;
    for(;i<V.size();i++){
        if(V[i].length()==1&&isfh(V[i][0])){
            double a=0,b=0;
            if(!result.empty()) {
                a = result.top(); result.pop();
            }else {zq=0;return 0;}
            if(!result.empty()) {
                b = result.top(); result.pop();
            }else { zq=0;return 0;}
            switch(V[i][0]) {
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
                    zq=0;return 0;
            }

        }
        else{
            if(zq==0)return 0;
            else result.push(cv(V[i]));
        }
    }
    if(result.empty()) {zq=0;return 0;}

    double value = result.top();
    result.pop();
    return value;
}

MainWindow::~MainWindow()
{
    delete ui;
}
