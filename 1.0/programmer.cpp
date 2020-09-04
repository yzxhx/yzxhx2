#include "programmer.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>

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
}
void programmer::sendsst(){
    emit sstand();
}
void programmer::sendsc(){
    emit sscin();
}
