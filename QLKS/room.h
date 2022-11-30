#ifndef ROOM_H
#define ROOM_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <hotel.h>
#include "database.h"
#include "qsqlquerymodel.h"
namespace Ui {
class room;
}

class room : public QDialog
{
    Q_OBJECT

public:
    explicit room(QWidget *parent = nullptr);
    ~room();
    void readData();
    void setPrice(int price);
    int getPrice();
    bool check();
private slots:
    void on_out_clicked();

    void on_pushButton_clicked();

    void on_update_clicked();

    void on_add_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

private:
    Ui::room *ui;
   Database db;
   int idroom;
   QString roomtype;
   QString roomsize;
   int price;
   QString available;
};

#endif // ROOM_H
