#ifndef SCIENTIFIC_H
#define SCIENTIFIC_H

#include <QMainWindow>

class scientific : public QMainWindow
{
    Q_OBJECT
public:
    explicit scientific(QWidget *parent = nullptr);
public:
    void sendst();
    void sendp();
signals:
   void sst();
   void sp();

public slots:
};

#endif // SCIENTIFIC_H
