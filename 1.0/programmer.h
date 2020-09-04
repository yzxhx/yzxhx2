#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <QMainWindow>

class programmer : public QMainWindow
{
    Q_OBJECT
public:
    explicit programmer(QWidget *parent = nullptr);
public:
    void sendsst();
    void sendsc();
signals:
    void sstand();
    void sscin();

public slots:
};

#endif // PROGRAMMER_H
