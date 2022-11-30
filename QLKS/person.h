#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <QString>
using namespace std;
class person
{
        QString name;
        string address;
        string phone;

    public:
        QString getName();
       void setName(QString name){
           this->name=name;
       }
        string getAddress();
        void setAddress(string address){
            this->address=address;
        }
        string getPhone();
        void setPhone(string phone){
            this->phone=phone;
        }

        friend class room;

public:
    person();
};

#endif // PERSON_H
