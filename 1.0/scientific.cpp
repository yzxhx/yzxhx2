#include "scientific.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
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
}
void scientific::sendst(){
    emit sst();
}
void scientific::sendp(){
    emit sp();
}
