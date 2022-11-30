#include "guest.h"

Guest::Guest()
{

}
Guest::Guest(int id,QString name,QString cccd,QString sdt,QString address,int room_no){
    this->id=id;
    this->name=name;
    this->cccd=cccd;
    this->sdt=sdt;
    this->address=address;
    this->room_no=room_no;
}
QString Guest::getName(){
    return this->name;
}
QString Guest::getAddress(){
    return this->address;
}
QString Guest::getDatetime(){
    return this->datetime;
}
QString Guest::getRoomType(){
    return this->room_type;
}
QString Guest::getStatus(){
    return this->status;
}

int Guest::getID(){
    return this->id;
}

int Guest::getRoomNo(){
    return this->room_no;
}
QString Guest::getCccd(){
    return this->cccd;
}

QString Guest::getSdt(){
    return this->sdt;

}
int Guest::getDays(){
    return this->day;

}
///////////////////////////////////////////////////
/// SETTERS
////////////////////////////////////////////////////
/// /////////////////////////////////////////////////.


void Guest::setName(QString name){
    this->name = name;
}

void Guest::setAddress(QString address){
    this->address = address;
}


void Guest::setDatetime(QString datetime){
    this->datetime = datetime;
}


void Guest::setStatus(QString status){
    this->status = status;
}

void Guest::setID(int id){
    this->id = id;
}

void Guest::setRoomNo(int room_no){
    this->room_no = room_no;
}
void Guest::setCccd(QString cccd){
    this->cccd=cccd;
}
void Guest::setSdt(QString sdt){
    this->sdt=sdt;
}
void Guest::setDays(int day){
    this->day=day;
}
