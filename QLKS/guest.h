#ifndef GUEST_H
#define GUEST_H
#include <QString>

class Guest
{
public:
    Guest();
    Guest(int id,QString name,QString cccd,QString sdt,QString address,int room_no);
        QString getName();
       QString getAddress();
        QString getDatetime();
        QString getRoomType();
        QString getStatus();
        int getRoomNo();
       int getID();
       QString getCccd();
       QString getSdt();
        int getDays();
        void setName(QString name);
        void setAddress(QString address);
        void setDatetime(QString datetime);
        void setStatus(QString status);
        void setRoomNo(int room_no);
        void setID(int id);
        void setCccd(QString cccd);
        void setSdt(QString sdt);
       void setDays(int day);
// friend class checkin;
//  friend class employee;
    private:
        int id;
        int room_no;
        QString cccd;
        QString sdt;
        int day;
        QString name;
        QString address;
        QString checkin;
        QString checkout;
        QString identity;
        QString room_type;
        QString datetime;
        int total_amount;
        int paid_amount;
        int due_amount;
        QString status;
};

#endif // GUEST_H
