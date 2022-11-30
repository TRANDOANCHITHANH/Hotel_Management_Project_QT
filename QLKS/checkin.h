#ifndef CHECKIN_H
#define CHECKIN_H
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QTimer>
#include <QDateTime>
#include <iostream>
#include "database.h"
#include "guest.h"
#include "hotel.h"
using namespace std;
namespace Ui {
class checkin;
}

class checkin : public QDialog,public Guest, public hotel
{
    Q_OBJECT
public:
    explicit checkin(QWidget *parent = nullptr);
    ~checkin();
    void readData();
    bool check();
    void check_2();
private slots:
    void on_submit_clicked();

    void on_cancel_clicked();
    void showtime();
    void on_clear_clicked();

private:
    Ui::checkin *ui;
    Guest *guest;
    Database conn;
};

#endif // CHECKIN_H

