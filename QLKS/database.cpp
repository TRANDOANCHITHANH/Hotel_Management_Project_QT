#include "database.h"

Database::Database()
{

}

bool Database::connOpen(){

    mydb=QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("D:/tdcthanh/C++/QLKS/hotel.db");
   if(!mydb.open()){
   qDebug()<<("Failed to open the database");
   return false;
   }else{
        qDebug()<<("Connected...");
       return true;
   }

}
void Database::connclose(){
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}
QSqlDatabase Database::getDB(){
    return mydb;
}
