#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <iostream>
using namespace std;
#include <stack>       //栈
#include <vector>     //容器
#include <cstdlib>    //字符串处理
#include <limits.h>
bool isnum(char x);  //判断数字
bool isfh(char x);   //判断符号
int  yxj(char x);    //判断优先级
vector<string> hzbds(string s);//后缀表达式
double cv(string s); //转数字
double js(vector<string> V);//计算后缀表达式

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
    ui->inputline->setFont(QFont("黑体",20));  //设置字体
    ui->inputline->setText(input);
    connect(ui->btn0,&QPushButton::clicked,this,&MainWindow::btn0clicked);//信号连接
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
    connect(ui->btnbfh,&QPushButton::clicked,this,&MainWindow::btnbfhclicked);
    connect(ui->btnpf,&QPushButton::clicked,this,&MainWindow::btnpfclicked);
    connect(ui->btngh,&QPushButton::clicked,this,&MainWindow::btnghclicked);
    connect(ui->btntg,&QPushButton::clicked,this,&MainWindow::btntgclicked);//信号连接
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
void MainWindow::btnbfhclicked(){
    string s = input.toStdString();  //将QString 转化为 string
    vector<string> V = hzbds(s);     //计算后缀表达式
    double value = js(V);
    if(value !=INT_MAX) {
      value /=100;
      input=input+"%="+QString::number(value);
      ui->inputline->setText(input);
    }else{
      input="表达式错误";                //语法错误
      ui->inputline->setText(input);   //输出结果
    }
}
void MainWindow::btnpfclicked(){
    string s = input.toStdString();  //将QString 转化为 string
    vector<string> V = hzbds(s);     //计算后缀表达式
    double value = js(V);
    if(value !=INT_MAX) {
      value *=value;
      input=QString::number(value);
      ui->inputline->setText(input);
    }else{
      input="表达式错误";                //语法错误
      ui->inputline->setText(input);   //输出结果
    }
}
void MainWindow::btnghclicked(){
    string s = input.toStdString();
    vector<string> V = hzbds(s);
    double value = js(V);
    if(value !=INT_MAX&&value>=0) {
        value = sqrt(value);   //开方
      input=QString::number(value);
      ui->inputline->setText(input);
    }else{
      input="表达式错误";
      ui->inputline->setText(input);
    }
}
void MainWindow::btntgclicked(){
    input = input.left(input.length()-1);
    ui->inputline->setText(input);
}
void MainWindow::btnresultclicked(){                //计算
    string s = input.toStdString();
    vector<string> V = hzbds(s);
    double value = js(V);
    if(value !=INT_MAX) {
      input=QString::number(value);

      ui->inputline->setText(input);
    }else{
      input="表达式错误";
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
    bool gs = true;                          //判断格式是否正确
    for(int i = 0; i < s.length(); i++) {
        if(i == 0 && s[i] == '-') continue; //负数仅有一个负号
        else if(s[i] == '.' && gs) {        //记录小数点，超过1个则表达式错误
            if(i > 0 && isnum(s[i-1])) {
                gs = false;continue;
            }
            else return INT_MAX;
        }
        else if(isnum(s[i])) continue;
        else return INT_MAX;
    }
    double result = atof(s.c_str());  //字符串改为浮点数
    return result;                    //返回数值
}
vector<string> hzbds(string s){
  stack<char> fh;                                       //存放临时符号的栈
  vector<string> V;                                     //返回后缀表达式
  int i = 0;
  while(i<s.length()){
      if(isnum(s[i])){
          string str = "";
          while(isnum(s[i])||s[i]=='.'){
              str +=s[i];i++;
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
                  int begin = yxj(s[i]);        //记录第一个运算符的优先级
                  if(begin==1){                 //如果为右括号，则将对应左括号内的运算符放入容器
                      while(yxj(fh.top())!=4&&!fh.empty()){
                          string str = "";
                          str += fh.top();
                          V.push_back(str);
                          fh.pop();
                      }
                      if(fh.top()=='(')fh.pop();i++;
                  }
                  else if(begin==4){          //如果为左括号直接入栈
                      fh.push(s[i]);i++;
                  }
                  else{
                      while(!fh.empty()&&begin<=yxj(fh.top())&&yxj(fh.top())!=4){
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

  }
  while(!fh.empty()){  //将栈中剩余运算符放入容器
      string str = "";
      str += fh.top();
      fh.pop();
      V.push_back(str);
  }
  return V;
}

double js(vector<string> V){
    stack<double> result;   //存放临时结果
    int i =0;
    for(;i<V.size();i++){
        if(V[i].length()==1&&isfh(V[i][0])){ //判断是否为符号
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
            if(cv(V[i])==INT_MAX)return INT_MAX;
            else result.push(cv(V[i]));//将容器内数值入栈
        }
    }
    if(result.empty()) return INT_MAX;

    double value = result.top();
    result.pop();
    return value;
}

MainWindow::~MainWindow()
{
    delete ui;
}
