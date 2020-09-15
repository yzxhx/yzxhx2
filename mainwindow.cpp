#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>
#include <QString>
#include <QtMath>
#include <iostream>
#include <math.h>
#include <stack>       //栈
#include <vector>     //容器
#include <cstdlib>    //字符串处理
#include <limits.h>
using namespace std;
bool isnum(char x);  //判断数字
bool isfh(char x);   //判断符号
int  yxj(char x);    //判断优先级
vector<string> hzbds(string s);//后缀表达式
double cv(string s); //转数字
double js(vector<string> V);//计算后缀表达式

#include <QString>
#include <math.h>
int jiecheng(int n){
    int result=1;
    if(n==0)return 0;
    else{
        for(int i=1;i<=n;i++)
            result*=i;
    }
    return result;
}

string bdszh(string s);//表达式转换
QString bf="";
int isbf=0;
int slen;
int yyc=0,yec=0,fbc=0,gbsc=0,gysc=0,zshsc=0;
QString k1,k2,k3,k4;
int len1=0,len2=0,len3=0;
int mod=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1000,800);
    setWindowTitle("Standard");
    ui->inputline->setFont(QFont("黑体",40));  //设置字体
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
    connect(ui->btntg,&QPushButton::clicked,this,&MainWindow::btntgclicked);
    connect(ui->btncl,&QPushButton::clicked,this,&MainWindow::btnclclicked);
    connect(ui->btnbfh,&QPushButton::clicked,this,&MainWindow::btnbfhclicked);
    connect(ui->btnpf,&QPushButton::clicked,this,&MainWindow::btnpfclicked);
    connect(ui->btngh,&QPushButton::clicked,this,&MainWindow::btnghclicked);

    connect(ui->btntime,&QPushButton::clicked,this,&MainWindow::btntimeclicked);
    connect(ui->btnzs,&QPushButton::clicked,this,&MainWindow::btnzsclicked);
    connect(ui->btnjiec,&QPushButton::clicked,this,&MainWindow::btnjiecclicked);
    connect(ui->btnpai,&QPushButton::clicked,this,&MainWindow::btnpaiclicked);
    connect(ui->btne,&QPushButton::clicked,this,&MainWindow::btneclicked);
    connect(ui->btngbs,&QPushButton::clicked,this,&MainWindow::btngbsclicked);
    connect(ui->btngys,&QPushButton::clicked,this,&MainWindow::btngysclicked);
    connect(ui->btnlog,&QPushButton::clicked,this,&MainWindow::btnlgclicked);
    connect(ui->btn10x,&QPushButton::clicked,this,&MainWindow::btn10xclicked);
    connect(ui->btnsin,&QPushButton::clicked,this,&MainWindow::btnsinclicked);
    connect(ui->btncos,&QPushButton::clicked,this,&MainWindow::btncosclicked);
    connect(ui->btntan,&QPushButton::clicked,this,&MainWindow::btntanclicked);
    connect(ui->btnln,&QPushButton::clicked,this,&MainWindow::btnlnclicked);
    connect(ui->btnyy,&QPushButton::clicked,this,&MainWindow::btnyyclicked);
    connect(ui->btnye,&QPushButton::clicked,this,&MainWindow::btnyeclicked);
    connect(ui->btnfb,&QPushButton::clicked,this,&MainWindow::btnfbclicked);
    connect(ui->btnzshs,&QPushButton::clicked,this,&MainWindow::btnzshsclicked);
    connect(ui->btnqh,&QPushButton::clicked,this,&MainWindow::btnmodclicked);
    connect(ui->Programmer,&QAction::triggered,this,&MainWindow::shiftpro);
    connect(&w,&programmer::change,this,&MainWindow::shiftstand);
}
void MainWindow::shiftpro(){
    w.show();hide();
}
void MainWindow::shiftstand(){
    w.hide();show();
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
void MainWindow::btnclclicked(){
    input = '0';bf='0';isbf=0;yyc=0;yec=0;fbc=0;gbsc=0;gysc=0;zshsc=0;
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
        input = input + "%";
        ui->inputline->setText(input);
}
void MainWindow::btnpfclicked(){

        input = input + "^2";
        ui->inputline->setText(input);
}
void MainWindow::btnghclicked(){

        input = input + "^(1/2)";
        ui->inputline->setText(input);
}
void MainWindow::btntgclicked(){
    input = input.left(input.length()-1);
    ui->inputline->setText(input);
}
void MainWindow::btnresultclicked(){                //计算
    if(yyc){
            k2=input.right(input.length()-len2);
            string k1s=k1.toStdString();string k2s=k2.toStdString();
            double k1d=cv(k1s);double k2d=cv(k2s);
            double xd=-k2d/k1d;
            QString x=QString::number(xd);
            input+=" x:"+x;ui->inputline->setText(input);
    }
    else if(yec){
        k3=input.right(input.length()-len3);
        string k1s = k1.toStdString();string k2s = k2.toStdString();
        string k3s = k3.toStdString();
        double k1d = cv(k1s);double k2d = cv(k2s);double k3d = cv(k3s);
        double pbs=k2d*k2d-4*k1d*k3d;
        QString x1,x2;
        if(pbs>=0){
            x1 =QString::number((-k2d-sqrt(pbs))/(2*k1d));
            x2 =QString::number((-k2d+sqrt(pbs))/(2*k1d));
        }
        else{
            x1=QString::number(-k2d/2/k1d)+"-"+QString::number(sqrt(-pbs)/2/k1d)+"i";
            x2=QString::number(-k2d/2/k1d)+"+"+QString::number(sqrt(-pbs)/2/k1d)+"i";

        }
        input+=" x1:"+x1+" x2:"+x2;ui->inputline->setText(input);
    }
    else if(fbc){
        k2=input.right(input.length()-len2);
        string k1s=k1.toStdString();string k2s=k2.toStdString();
        double k1d=cv(k1s);double k2d=cv(k2s);
        double xd=k2d/k1d;
        QString x=QString::number(xd);
        input+=" x:"+x;ui->inputline->setText(input);
    }
    else if(gbsc){
        k2=input.right(input.length()-len2);
        string k1s=k1.toStdString();string k2s=k2.toStdString();
        double k1d=cv(k1s);double k2d=cv(k2s);int k1i=k1d,k2i=k2d;
        if(k1d!=k1i||k2d!=k2i){input+=" 输入错误";ui->inputline->setText(input);}
        else{
             int r,t,m=k1d,n=k2d;//算法
             if(m<n){
                 t=m;m=n;n=t;}
            while(n!=0){
            r=m%n;m=n;n=r;
            }
            int gbs=k1d*k2d/m;
            QString x=QString::number(gbs);
            input+=" 最小公倍数为:"+x;ui->inputline->setText(input);
        }
    }
    else if(gysc){
        k2=input.right(input.length()-len2);
        string k1s=k1.toStdString();string k2s=k2.toStdString();
        double k1d=cv(k1s);double k2d=cv(k2s);int k1i=k1d,k2i=k2d;
        if(k1d!=k1i||k2d!=k2i){input+=" 输入错误";ui->inputline->setText(input);}
        else {
            int r,t,m=k1d,n=k2d;//算法
            if(m<n){
                t=m;m=n;n=t;}
           while(n!=0){
           r=m%n;m=n;n=r;
           }
           QString x=QString::number(m);
           input+=" 最大公约数为:"+x;ui->inputline->setText(input);
        }
    }
    else if(zshsc){
        k2=input.right(input.length()-len2);
        string k1s=k1.toStdString();string k2s=k2.toStdString();
        double k1d=cv(k1s);double k2d=cv(k2s);
        double xd;
        if(mod==0)xd=log(k1d)/log(k2d);
        else  xd = pow(k2d,k1d);
        QString x=QString::number(xd);
        input+=" x:"+x;ui->inputline->setText(input);
    }
    else {
        if(isbf)input=bf+input.right(input.length()-slen);
          ui->inputline->setText(input);
            isbf=0;
            string s = input.toStdString();
            s=bdszh(s);
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
}
void MainWindow::btntimeclicked(){
    input=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");
    ui->inputline->setText(input);

}
void MainWindow::btnzsclicked(){
    if(input=="0")
        input = '^';
        else input = input + '^';
       ui->inputline->setText(input);
}
void MainWindow::btnjiecclicked(){
        input = input + "!";
        ui->inputline->setText(input);
}
void MainWindow::btnpaiclicked(){
    if(input=="0")
        input = "Π";
        else input = input + "Π";
        ui->inputline->setText(input);slen=input.length();
        isbf=1;bf=input.left(input.length()-1)+"3.141592653589";
}
void MainWindow::btneclicked(){
    if(input=="0")
        input = 'e';
        else input = input + 'e';
        ui->inputline->setText(input);slen=input.length();
        isbf=1;bf=input.left(input.length()-1)+"2.718281828459";
}
void MainWindow::btngbsclicked(){
    gbsc++;
    if(gbsc==1){
        input="num1:";ui->inputline->setText(input);
        len1=input.length();
    }
    if(gbsc==2){
        k1=input.right(input.length()-len1);
        input+=" num2:";ui->inputline->setText(input);
        len2=input.length();
    }
}
void MainWindow::btngysclicked(){
    gysc++;
    if(gysc==1){
        input="num1:";ui->inputline->setText(input);
        len1=input.length();
    }
    if(gysc==2){
        k1=input.right(input.length()-len1);
        input+=" num2:";ui->inputline->setText(input);
        len2=input.length();
    }
}
void MainWindow::btnlgclicked(){
    if(input=="0")
        input = "lg";
        else input = input + "lg";
        ui->inputline->setText(input);
}
void MainWindow::btn10xclicked(){
    if(input=="0")
        input = "10^";
        else input = input + "10^";
        ui->inputline->setText(input);
}
void MainWindow::btnlnclicked(){
    if(input=="0")
        input = "ln";
        else input = input + "ln";
        ui->inputline->setText(input);
}
void MainWindow::btnsinclicked(){
    if(mod==0){
        if(input=="0")
            input = "sin";
            else input = input + "sin";
            ui->inputline->setText(input);
    }
    else {
        if(input=="0")
            input = "arcsin";
            else input = input + "arcsin";
            ui->inputline->setText(input);
    }

}
void MainWindow::btncosclicked(){
    if(mod==0){
        if(input=="0")
            input = "cos";
            else input = input + "cos";
            ui->inputline->setText(input);
    }
    else {
        if(input=="0")
            input = "arccos";
            else input = input + "arccos";
            ui->inputline->setText(input);
    }

}
void MainWindow::btntanclicked(){
    if(mod==0){
        if(input=="0")
            input = "tan";
            else input = input + "tan";
            ui->inputline->setText(input);
    }
    else {
        if(input=="0")
            input = "arctan";
            else input = input + "arctan";
            ui->inputline->setText(input);
    }

}
void MainWindow::btnyyclicked(){
    yyc++;
    if(yyc==1){
        input="k:";ui->inputline->setText(input);
        len1=input.length();
    }
    if(yyc==2){
        k1=input.right(input.length()-len1);
        input+=" b:";ui->inputline->setText(input);
        len2=input.length();
    }
}
void MainWindow::btnyeclicked(){
    yec++;
    if(yec==1){
        input="a:";ui->inputline->setText(input);
        len1=input.length();
    }
    if(yec==2){
        k1=input.right(input.length()-len1);
        input+=" b:";ui->inputline->setText(input);
        len2=input.length();
    }
    if(yec==3){
        k2=input.right(input.length()-len2);
        input+=" c:";ui->inputline->setText(input);
        len3=input.length();
    }
}
void MainWindow::btnfbclicked(){
    fbc++;
    if(fbc==1){
        input="y:";ui->inputline->setText(input);
        len1=input.length();
    }
    if(fbc==2){
        k1=input.right(input.length()-len1);
        input+=" k:";ui->inputline->setText(input);
        len2=input.length();
    }
}
void MainWindow::btnzshsclicked(){
    zshsc++;
    if(zshsc==1){
        input="y:";ui->inputline->setText(input);
        len1=input.length();
    }
    if(zshsc==2){
        k1=input.right(input.length()-len1);
        input+=" a:";ui->inputline->setText(input);
        len2=input.length();
    }
}
void MainWindow::btnmodclicked(){
    if(mod==0){
        mod=1;
        ui->btnsin->setText("arcsin");
        ui->btncos->setText("arccos");
        ui->btntan->setText("arctan");
        ui->btnzshs->setText("y=log(a)x");
    }
    else{
        mod=0;
        ui->btnsin->setText("sin");
        ui->btncos->setText("cos");
        ui->btntan->setText("tan");
        ui->btnzshs->setText("y=a^x");
    }
}
bool isnum(char x){                                 //判断是否为数字
    if(x>='0'&&x<='9')return true;
    else return false;
}
bool isfh(char x){                                    //判断是否为符号
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='('||x==')'||x=='^'||x=='s'||x=='S'||x=='c'||x=='C'||x=='t'||x=='T'||x=='g'||x=='n'||x=='!')return true;
    else return false;
}
int yxj(char x){                                       //运算符的优先级
    int fhyxj = 0;
    if(x=='(')fhyxj = 6;
    if(x=='!')fhyxj = 5;
    if(x=='c'||x=='C'||x=='S'||x=='T'||x=='s'||x=='t'||x=='g'||x=='n')fhyxj=4;
    if(x=='*'||x=='/'||x=='^')fhyxj = 3;
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
                      while(yxj(fh.top())!=6&&!fh.empty()){
                          string str = "";
                          str += fh.top();
                          V.push_back(str);
                          fh.pop();
                      }
                      if(fh.top()=='(')fh.pop();i++;
                  }
                  else if(begin==6){          //如果为左括号直接入栈
                      fh.push(s[i]);i++;
                  }
                  else{
                      while(!fh.empty()&&begin<=yxj(fh.top())&&yxj(fh.top())!=6){
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
                case '^':
                   result.push(pow(b,a));
                   break;
                case 's':
                   result.push(sin(a));break;
                case 'S':
                   result.push(asin(a));break;
                case 'c':
                   result.push(cos(a));break;
                case 'C':
                   result.push(acos(a));break;
                case 't':
                   result.push(tan(a));break;
                case 'T':
                   result.push(atan(a));break;
                case 'g':
                   result.push(log10(a));break;
                case 'n':
                   result.push(log(a));break;
                case '!':
                   result.push(jiecheng(b));break;
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
string bdszh(string s){
    int i=0;string re="";
    for(;i<s.length();i++){
        if(s[i]=='s'){
            i=i+2;re+="0s";
        }
        else if(s[i]=='a'&&s[i+3]=='s'){
            i=i+5;re+="0S";
        }
        else if(s[i]=='c'){
            i=i+2;re+="0c";
        }
        else if(s[i]=='a'&&s[i+3]=='c'){
            i=i+5;re+="0C";
        }
        else if(s[i]=='t'){
            i=i+2;re+="0t";
        }
        else if(s[i]=='a'&&s[i+3]=='t'){
            i=i+5;re+="0T";
        }
        else if(s[i]=='l'&&s[i+1]=='g'){
            i=i+1;re+="0g";
        }
        else if(s[i]=='l'&&s[i+1]=='n'){
            i=i+1;re+="0n";
        }
        else if(s[i]=='%'){
            re+="/100";
        }
        else if(s[i]=='!'){
            re+="!0";
        }
        else {
            re+=s[i];
        }
    }
    return re;
}
MainWindow::~MainWindow()
{
    delete ui;
}
