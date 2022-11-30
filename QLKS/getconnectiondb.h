#ifndef GETCONNECTIONDB_H
#define GETCONNECTIONDB_H

#include "qsqldatabase.h"
#include<QDebug>
class getconnectiondb
{
private:
    static QSqlDatabase mydb;
public:
    getconnectiondb();
    static QSqlDatabase getDB();
    void connclose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
bool connOpen(){
    mydb=QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("D:/tdcthanh/C++/hotel.db");
   if(!mydb.open()){
   qDebug()<<("Failed to open the database");
   return false;
   }else{
        qDebug()<<("Connected...");
       return true;
   }
}
};

#endif // GETCONNECTIONDB_H
