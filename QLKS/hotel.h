#ifndef HOTEL_H
#define HOTEL_H

#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include<vector>
#include "iostream"
#include "database.h"
using namespace std;
//#include "guest.h"
class hotel
{
public:
    hotel();
    static hotel * instance;
//    void updateHotelData(int room); //update DB & Vector
public:
    int BookRoom( QString name,QString cccd,QString sdt, QString address,int room_no,int day,QString status,QString time_in);
    int CheckOut(int room_no);
    int Receive(int id,QString name,QString cccd,QString sdt,QString address,QString datetime);
    QString getPrice(int index);
    QString getTotalGuest();
    QString getTotalEpl();
    QString getTotalRoom();
    QString getTotalPay();
    std::vector<int> RoomAvailability();
    std::vector<int> getRoomList(QString);
    std::vector<int>paid_amout(int,int);
   int days(int);
     void readData();
    static hotel* getInstance();
    Database conn;
//    Guest *guest;
};

#endif // HOTEL_H
