#include "scientific.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QGridLayout>
#include <QString>
#include <QtDebug>
#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
using namespace std;

string bdszh3(string s);
//string hsbdszh(string s);
bool isnum3(char x);
//bool ishs(char x);
bool isfh(char x);   //判断符号
int  yxj(char x);    //判断优先级
double cv3(string s);
vector<string> hzbds3(string s);
double js3(vector<string> V);
QString bf="";
int isbf=0;
int slen;
int yyc=0,yec=0,fbc=0,gbsc=0,gysc=0,zshsc=0;
QString k1,k2,k3,k4;
int len1=0,len2=0,len3=0;
scientific::scientific(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Scientific");
    resize(500,500);
    QMenuBar *mbar = menuBar();
    QMenu *shift = mbar->addMenu("Shift");
    QAction *a = shift->addAction("Standard");
    shift->addAction("Scientific");
    QAction *b = shift->addAction("Programmer");
    connect(a,&QAction::triggered,this,&scientific::sendst);
    connect(b,&QAction::triggered,this,&scientific::sendp);

    QWidget *centerwindow = new QWidget;//设置界面
    this->setCentralWidget(centerwindow);
    data = new QLineEdit("");
    bt0 = new QPushButton("0");bt1 = new QPushButton("1");bt2 = new QPushButton("2");bt3 = new QPushButton("3");
    bt4 = new QPushButton("4");bt5 = new QPushButton("5");bt6 = new QPushButton("6");bt7 = new QPushButton("7");
    bt8 = new QPushButton("8");bt9 = new QPushButton("9");btjia = new QPushButton("+");btjian = new QPushButton("-");
    btcheng = new QPushButton("*");btchu = new QPushButton("/");btzf = new QPushButton("+/-");bttg = new QPushButton("←");
    btdian = new QPushButton(".");btresult = new QPushButton("=");btAC = new QPushButton("AC");btzs = new QPushButton("^");
    btyy = new QPushButton("y=kx+b");btye = new QPushButton("y=ax²+bx+c");btfb = new QPushButton("y=k/x");
    btgbs = new QPushButton("最小公倍数");btgys = new QPushButton("最大公约数");btzshs = new QPushButton("y=a^x");
    btkl = new QPushButton("(");btkr = new QPushButton(")");btpai = new QPushButton("Π");
    btlg = new QPushButton("lg");btln = new QPushButton("ln");bte = new QPushButton("e");
    btsin = new QPushButton("sin");btcos = new QPushButton("cos");bttan = new QPushButton("tan");
    data->setFont(QFont("黑体",20));
    data->setFixedHeight(60);
    bt0->setMinimumHeight(40);bt1->setMinimumHeight(40);bt2->setMinimumHeight(40);bt3->setMinimumHeight(40);
    bt4->setMinimumHeight(40);bt5->setMinimumHeight(40);bt6->setMinimumHeight(40);bt7->setMinimumHeight(40);
    bt8->setMinimumHeight(40);bt9->setMinimumHeight(40);btjia->setMinimumHeight(40);btjian->setMinimumHeight(40);
    btcheng->setMinimumHeight(40);btchu->setMinimumHeight(40);btzf->setMinimumHeight(40);bttg->setMinimumHeight(40);
    btAC->setMinimumHeight(40);btzs->setMinimumHeight(40);btdian->setMinimumHeight(40);btresult->setMinimumHeight(40);
    btyy->setMinimumHeight(40);btye->setMinimumHeight(40);btfb->setMinimumHeight(40);
    btgbs->setMinimumHeight(40);btgys->setMinimumHeight(40);btzshs->setMinimumHeight(40);
    btkl->setMinimumHeight(40);btkr->setMinimumHeight(40);btpai->setMinimumHeight(40);
    btlg->setMinimumHeight(40);btln->setMinimumHeight(40);bte->setMinimumHeight(40);
    btsin->setMinimumHeight(40);btcos->setMinimumHeight(40);bttan->setMinimumHeight(40);

    QGridLayout * layout = new QGridLayout;
    layout->addWidget(data,1,1,1,7,Qt::Alignment());

    layout->addWidget(btyy,2,1,Qt::Alignment());layout->addWidget(btye,2,2,Qt::Alignment());
    layout->addWidget(btfb,2,3,Qt::Alignment());layout->addWidget(btzs,2,4,Qt::Alignment());
    layout->addWidget(btAC,2,5,Qt::Alignment());layout->addWidget(bttg,2,6,Qt::Alignment());
    layout->addWidget(btjia,2,7,Qt::Alignment());layout->addWidget(btgbs,3,1,Qt::Alignment());
    layout->addWidget(btgys,3,2,Qt::Alignment());layout->addWidget(btzshs,3,3,Qt::Alignment());
    layout->addWidget(bt7,3,4,Qt::Alignment());layout->addWidget(bt8,3,5,Qt::Alignment());
    layout->addWidget(bt9,3,6,Qt::Alignment());layout->addWidget(btjian,3,7,Qt::Alignment());
    layout->addWidget(btkl,4,1,Qt::Alignment());layout->addWidget(btkr,4,2,Qt::Alignment());
    layout->addWidget(btpai,4,3,Qt::Alignment());layout->addWidget(bt4,4,4,Qt::Alignment());
    layout->addWidget(bt5,4,5,Qt::Alignment());layout->addWidget(bt6,4,6,Qt::Alignment());
    layout->addWidget(btcheng,4,7,Qt::Alignment());layout->addWidget(btlg,5,1,Qt::Alignment());
    layout->addWidget(btln,5,2,Qt::Alignment());layout->addWidget(bte,5,3,Qt::Alignment());
    layout->addWidget(bt1,5,4,Qt::Alignment());layout->addWidget(bt2,5,5,Qt::Alignment());
    layout->addWidget(bt3,5,6,Qt::Alignment());layout->addWidget(btchu,5,7,Qt::Alignment());
    layout->addWidget(btsin,6,1,Qt::Alignment());layout->addWidget(btcos,6,2,Qt::Alignment());
    layout->addWidget(bttan,6,3,Qt::Alignment());layout->addWidget(btzf,6,4,Qt::Alignment());
    layout->addWidget(bt0,6,5,Qt::Alignment());layout->addWidget(btdian,6,6,Qt::Alignment());
    layout->addWidget(btresult,6,7,Qt::Alignment());
    centerwindow->setLayout(layout);//设置界面
    data->setText(input);
    connect(bt0,&QPushButton::clicked,this,&scientific::bt0clicked);
    connect(bt1,&QPushButton::clicked,this,&scientific::bt1clicked);
    connect(bt2,&QPushButton::clicked,this,&scientific::bt2clicked);
    connect(bt3,&QPushButton::clicked,this,&scientific::bt3clicked);
    connect(bt4,&QPushButton::clicked,this,&scientific::bt4clicked);
    connect(bt5,&QPushButton::clicked,this,&scientific::bt5clicked);
    connect(bt6,&QPushButton::clicked,this,&scientific::bt6clicked);
    connect(bt7,&QPushButton::clicked,this,&scientific::bt7clicked);
    connect(bt8,&QPushButton::clicked,this,&scientific::bt8clicked);
    connect(bt9,&QPushButton::clicked,this,&scientific::bt9clicked);
    connect(btjia,&QPushButton::clicked,this,&scientific::btjiaclicked);
    connect(btjian,&QPushButton::clicked,this,&scientific::btjianclicked);
    connect(btcheng,&QPushButton::clicked,this,&scientific::btchengclicked);
    connect(btchu,&QPushButton::clicked,this,&scientific::btchuclicked);
    connect(btresult,&QPushButton::clicked,this,&scientific::btresultclicked);
    connect(btzf,&QPushButton::clicked,this,&scientific::btzfclicked);
    connect(btdian,&QPushButton::clicked,this,&scientific::btdianclicked);
    connect(btzs,&QPushButton::clicked,this,&scientific::btzsclicked);
    connect(bttg,&QPushButton::clicked,this,&scientific::bttgclicked);
    connect(btAC,&QPushButton::clicked,this,&scientific::btACclicked);
    connect(btyy,&QPushButton::clicked,this,&scientific::btyyclicked);
    connect(btye,&QPushButton::clicked,this,&scientific::btyeclicked);
    connect(btfb,&QPushButton::clicked,this,&scientific::btfbclicked);
    connect(btgbs,&QPushButton::clicked,this,&scientific::btgbsclicked);
    connect(btgys,&QPushButton::clicked,this,&scientific::btgysclicked);
    connect(btzshs,&QPushButton::clicked,this,&scientific::btzshsclicked);
    connect(btkl,&QPushButton::clicked,this,&scientific::btklclicked);
    connect(btkr,&QPushButton::clicked,this,&scientific::btkrclicked);
    connect(btpai,&QPushButton::clicked,this,&scientific::btpaiclicked);
    connect(btlg,&QPushButton::clicked,this,&scientific::btlgclicked);
    connect(btln,&QPushButton::clicked,this,&scientific::btlnclicked);
    connect(bte,&QPushButton::clicked,this,&scientific::bteclicked);
    connect(btsin,&QPushButton::clicked,this,&scientific::btsinclicked);
    connect(btcos,&QPushButton::clicked,this,&scientific::btcosclicked);
    connect(bttan,&QPushButton::clicked,this,&scientific::bttanclicked);


}
void scientific::sendst(){
    emit sst();
}
void scientific::sendp(){
    emit sp();
}

void scientific::bt0clicked(){
    if(input=="0")
        input = '0';
        else input = input + '0';
        data->setText(input);
}
void scientific::bt1clicked(){
    if(input=="0")
        input = '1';
        else input = input + '1';
        data->setText(input);
}
void scientific::bt2clicked(){
    if(input=="0")
        input = '2';
        else input = input + '2';
        data->setText(input);
}
void scientific::bt3clicked(){
    if(input=="0")
        input = '3';
        else input = input + '3';
        data->setText(input);
}
void scientific::bt4clicked(){
    if(input=="0")
        input = '4';
        else input = input + '4';
        data->setText(input);
}
void scientific::bt5clicked(){
    if(input=="0")
        input = '5';
        else input = input + '5';
        data->setText(input);
}
void scientific::bt6clicked(){
    if(input=="0")
        input = '6';
        else input = input + '6';
        data->setText(input);
}
void scientific::bt7clicked(){
    if(input=="0")
        input = '7';
        else input = input + '7';
        data->setText(input);
}
void scientific::bt8clicked(){
    if(input=="0")
        input = '8';
        else input = input + '8';
        data->setText(input);
}
void scientific::bt9clicked(){
    if(input=="0")
        input = '9';
        else input = input + '9';
        data->setText(input);
}
void scientific::btjiaclicked(){
    if(input=="0")
        input = '+';
        else input = input + '+';
        data->setText(input);
}
void scientific::btjianclicked(){
    if(input=="0")
        input = '-';
        else input = input + '-';
        data->setText(input);
}
void scientific::btchengclicked(){
    if(input=="0")
        input = '*';
        else input = input + '*';
        data->setText(input);
}
void scientific::btchuclicked(){
    if(input=="0")
        input = '/';
        else input = input + '/';
        data->setText(input);
}
void scientific::btresultclicked(){
    if(yyc){
            k2=input.right(input.length()-len2);
            string k1s=k1.toStdString();string k2s=k2.toStdString();
            double k1d=cv3(k1s);double k2d=cv3(k2s);
            double xd=-k2d/k1d;
            QString x=QString::number(xd);
            input+=" x:"+x;data->setText(input);
    }
    else if(yec){
        k3=input.right(input.length()-len3);
        string k1s = k1.toStdString();string k2s = k2.toStdString();
        string k3s = k3.toStdString();
        double k1d = cv3(k1s);double k2d = cv3(k2s);double k3d = cv3(k3s);
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
        input+=" x1:"+x1+" x2:"+x2;data->setText(input);
    }
    else if(fbc){
        k2=input.right(input.length()-len2);
        string k1s=k1.toStdString();string k2s=k2.toStdString();
        double k1d=cv3(k1s);double k2d=cv3(k2s);
        double xd=k2d/k1d;
        QString x=QString::number(xd);
        input+=" x:"+x;data->setText(input);
    }
    else if(gbsc){
        k2=input.right(input.length()-len2);
        string k1s=k1.toStdString();string k2s=k2.toStdString();
        double k1d=cv3(k1s);double k2d=cv3(k2s);int k1i=k1d,k2i=k2d;
        if(k1d!=k1i||k2d!=k2i){input+=" 输入错误";data->setText(input);}
        else{
             int r,t,m=k1d,n=k2d;//算法
             if(m<n){
                 t=m;m=n;n=t;}
            while(n!=0){
            r=m%n;m=n;n=r;
            }
            int gbs=k1d*k2d/m;
            QString x=QString::number(gbs);
            input+=" 最小公倍数为:"+x;data->setText(input);
        }
    }
    else if(gysc){
        k2=input.right(input.length()-len2);
        string k1s=k1.toStdString();string k2s=k2.toStdString();
        double k1d=cv3(k1s);double k2d=cv3(k2s);int k1i=k1d,k2i=k2d;
        if(k1d!=k1i||k2d!=k2i){input+=" 输入错误";data->setText(input);}
        else {
            int r,t,m=k1d,n=k2d;//算法
            if(m<n){
                t=m;m=n;n=t;}
           while(n!=0){
           r=m%n;m=n;n=r;
           }
           QString x=QString::number(m);
           input+=" 最大公约数为:"+x;data->setText(input);
        }
    }
    else if(zshsc){
        k2=input.right(input.length()-len2);
        string k1s=k1.toStdString();string k2s=k2.toStdString();
        double k1d=cv3(k1s);double k2d=cv3(k2s);
        double xd=log(k1d)/log(k2d);
        QString x=QString::number(xd);
        input+=" x:"+x;data->setText(input);
    }
    else {
        if(isbf)input=bf+input.right(input.length()-slen);
            data->setText(input);
            isbf=0;
            string s = input.toStdString();
            s=bdszh3(s);
            vector<string> V = hzbds3(s);
            double value = js3(V);
            if(value !=INT_MAX) {
              input=QString::number(value);

             data->setText(input);
            }else{
              input="表达式错误";
              data->setText(input);
            }
    }
}
void scientific::btzfclicked(){
    if(input=="0")
        input = '-';
    else {
    QString::iterator p = input.end();             //遍历至输入端的末尾，如果最后一位是负号，则取消
    p--;
    if(*p == '-')input = input.left(input.length()-1);
    else input = input + '-';
    }
    data->setText(input);
}
void scientific::btdianclicked(){
        if(input!="")input = input + '.';
        data->setText(input);
}
void scientific::bttgclicked(){
    input=input.left(input.length()-1);
        data->setText(input);
}
void scientific::btACclicked(){
        input = '0';bf='0';isbf=0;yyc=0;yec=0;fbc=0;gbsc=0;gysc=0;zshsc=0;
        data->setText(input);
}
void scientific::btzsclicked(){
    if(input=="0")
        input = '^';
        else input = input + '^';
        data->setText(input);
}
void scientific::btyyclicked(){
   yyc++;
   if(yyc==1){
       input="k:";data->setText(input);
       len1=input.length();
   }
   if(yyc==2){
       k1=input.right(input.length()-len1);
       input+=" b:";data->setText(input);
       len2=input.length();
   }

}
void scientific::btyeclicked(){
     yec++;
     if(yec==1){
         input="a:";data->setText(input);
         len1=input.length();
     }
     if(yec==2){
         k1=input.right(input.length()-len1);
         input+=" b:";data->setText(input);
         len2=input.length();
     }
     if(yec==3){
         k2=input.right(input.length()-len2);
         input+=" c:";data->setText(input);
         len3=input.length();
     }
}
void scientific::btfbclicked(){
    fbc++;
    if(fbc==1){
        input="y:";data->setText(input);
        len1=input.length();
    }
    if(fbc==2){
        k1=input.right(input.length()-len1);
        input+=" k:";data->setText(input);
        len2=input.length();
    }
}
void scientific::btgbsclicked(){
    gbsc++;
    if(gbsc==1){
        input="num1:";data->setText(input);
        len1=input.length();
    }
    if(gbsc==2){
        k1=input.right(input.length()-len1);
        input+=" num2:";data->setText(input);
        len2=input.length();
    }
}
void scientific::btgysclicked(){
    gysc++;
    if(gysc==1){
        input="num1:";data->setText(input);
        len1=input.length();
    }
    if(gysc==2){
        k1=input.right(input.length()-len1);
        input+=" num2:";data->setText(input);
        len2=input.length();
    }
}
void scientific::btzshsclicked(){
    zshsc++;
    if(zshsc==1){
        input="y:";data->setText(input);
        len1=input.length();
    }
    if(zshsc==2){
        k1=input.right(input.length()-len1);
        input+=" k:";data->setText(input);
        len2=input.length();
    }
}
void scientific::btklclicked(){
    if(input=="0")
        input = '(';
        else input = input + '(';
        data->setText(input);
}
void scientific::btkrclicked(){
    if(input=="0")
        input = ')';
        else input = input + ')';
        data->setText(input);
}
void scientific::btpaiclicked(){
    if(input=="0")
        input = "Π";
        else input = input + "Π";
        data->setText(input);slen=input.length();
        isbf=1;bf=input.left(input.length()-1)+"3.141592653589";

}
void scientific::btlgclicked(){
    if(input=="0")
        input = "lg";
        else input = input + "lg";
        data->setText(input);
}
void scientific::btlnclicked(){
    if(input=="0")
        input = "ln";
        else input = input + "ln";
        data->setText(input);
}
void scientific::bteclicked(){
    if(input=="0")
        input = 'e';
        else input = input + 'e';
        data->setText(input);slen=input.length();
        isbf=1;bf=input.left(input.length()-1)+"2.718281828459";

}
void scientific::btsinclicked(){
    if(input=="0")
        input = "sin";
        else input = input + "sin";
        data->setText(input);
}
void scientific::btcosclicked(){
    if(input=="0")
        input = "cos";
        else input = input + "cos";
        data->setText(input);
}
void scientific::bttanclicked(){
    if(input=="0")
        input = "tan";
        else input = input + "tan";
        data->setText(input);
}
bool isnum3(char x){
        if(x>='0'&&x<='9')return true;
        else return false;
}

bool isfh3(char x){
if(x=='+'||x=='-'||x=='*'||x=='/'||x=='('||x==')'||x=='^'||x=='s'||x=='c'||x=='t'||x=='g'||x=='n')return true;
else return false;
}
int  yxj3(char x){
    int fhyxj = 0;
    if(x=='(')fhyxj = 4;
    if(x=='c'||x=='s'||x=='t'||x=='g'||x=='n')fhyxj=3.5;
    if(x=='*'||x=='/'||x=='^')fhyxj = 3;
    if(x=='+'||x=='-')fhyxj = 2;
    if(x==')')fhyxj = 1;
    return fhyxj;
}
double cv3(string s){
    bool gs = true;                          //判断格式是否正确
    for(int i = 0; i < s.length(); i++) {
        if(i == 0 && s[i] == '-') continue; //负数仅有一个负号
        else if(s[i] == '.' && gs) {        //记录小数点，超过1个则表达式错误
            if(i > 0 && isnum3(s[i-1])) {
                gs = false;continue;
            }
            else return INT_MAX;
        }
        else if(isnum3(s[i])) continue;
        else return INT_MAX;
    }
    double result = atof(s.c_str());  //字符串改为浮点数
    return result;                                     //返回数值
}
string bdszh3(string s){
    int i=0;string re="";
    for(;i<s.length();i++){
        if(s[i]=='s'){
            i=i+2;re+="0s";
        }
        else if(s[i]=='c'){
            i=i+2;re+="0c";
        }
        else if(s[i]=='t'){
            i=i+2;re+="0t";
        }
        else if(s[i]=='l'&&s[i+1]=='g'){
            i=i+1;re+="0g";
        }
        else if(s[i]=='l'&&s[i+1]=='n'){
            i=i+1;re+="0n";
        }
        else {
            re+=s[i];
        }


    }
    return re;
}
vector<string> hzbds3(string s){
  stack<char> fh;                                       //存放临时符号的栈
  vector<string> V;                                     //返回后缀表达式
  int i = 0;
  while(i<s.length()){
      if(isnum3(s[i])){
          string str = "";
          while(isnum3(s[i])||s[i]=='.'){
              str +=s[i];i++;
          }
          V.push_back(str);                              //将数字放入容器
      }

      else{
          if(s[i]=='-'&&(i==0||isfh(s[i-1]))){
              string str = "-";i++;
              while(isnum3(s[i])||s[i]=='.'){
                  str+=s[i];i++;
              }
              V.push_back(str);                          //判断为负数的情况
          }
          else{
              if(fh.empty()){
                  fh.push(s[i]);i++;
              }                                   //将第一个符号入栈
              else{
                  int begin = yxj3(s[i]);        //记录第一个运算符的优先级
                  if(begin==1){                 //如果为右括号，则将对应左括号内的运算符放入容器
                      while(yxj3(fh.top())!=4&&!fh.empty()){
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
                      while(!fh.empty()&&begin<=yxj3(fh.top())&&yxj3(fh.top())!=4){
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
double js3(vector<string> V){
    stack<double> result;   //存放临时结果
    int i =0;
    for(;i<V.size();i++){
        if(V[i].length()==1&&isfh3(V[i][0])){ //判断是否为符号
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
                case 'c':
                   result.push(cos(a));break;
                case 't':
                   result.push(tan(a));break;
                case 'g':
                   result.push(log10(a));break;
                case 'n':
                   result.push(log(a));break;
                default:
                  return INT_MAX;
            }

        }
        else{
            if(cv3(V[i])==INT_MAX)return INT_MAX;
            else result.push(cv3(V[i]));//将容器内数值入栈
        }
    }
    if(result.empty()) return INT_MAX;

    double value = result.top();
    result.pop();
    return value;
}
