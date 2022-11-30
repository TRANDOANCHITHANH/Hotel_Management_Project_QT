#include "employee.h"
#include "ui_employee.h"

employee::employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employee)
{
    ui->setupUi(this);
    this->setWindowTitle("Employee");
}

employee::~employee()
{
    delete ui;
}

void employee::on_receive_clicked()//Nhan ca
{
    employee nv;
    nv.setID(ui->eid->text().toInt());
        nv.setName(ui->ename->text().trimmed());
        nv.setCccd(ui->ecccd->text().trimmed());
       nv.setSdt(ui->ephone->text().trimmed());
       nv.setAddress(ui->eaddress->text().trimmed());
      QDateTime datetime=QDateTime::currentDateTime();
      QString datetimetext=datetime.toString();
      nv.setDatetime(datetimetext);
    db.connOpen();
    QSqlQuery query;
    query.prepare("insert into employee (id,name,cccd,phone,diachi,time_in) values('"+QString::number(nv.getID())+"','"+nv.getName()+"','"+nv.getCccd()+"','"+nv.getSdt()+"','"+nv.getAddress()+"','"+nv.getDatetime()+"')");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
         QMessageBox::information( this,tr("Success!"), tr("Nhận ca thành công!") );
    }
    db.connclose();
}


void employee::on_exit_clicked()
{
 this->hide();

}


void employee::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
        if(!db.connOpen()){
            qDebug() << "Database loaded not successfull!";
        } else{
            qDebug() << "Database loaded successfull!";
          }
        QSqlQuery query;
        query.prepare("select * from employee where id='"+val+"' or name='"+val+"' or cccd='"+val+"' or phone='"+val+"' or diachi='"+val+"' ");
        if(query.exec()){
            while(query.next()){
                ui->eid->setText(query.value(0).toString());
                ui->ename->setText(query.value(1).toString());
                ui->ecccd->setText(query.value(2).toString());
                ui->ephone->setText(query.value(3).toString());
                ui->eaddress->setText(query.value(4).toString());
            }
            db.connclose();
        }
        else{
            QMessageBox::critical(this,tr("Error::"),query.lastError().text());
        }

}


void employee::on_load_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    if(!db.connOpen()){
        qDebug() << "Database loaded not successfull!";
    } else{
        qDebug() << "Database loaded successfull!";
   }
    QSqlQuery* query=new QSqlQuery();
    query->prepare("select * from employee");
    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
    db.connclose();
    qDebug()<<(modal->rowCount());

}


void employee::on_leave_clicked()//Giao ca
{
        int id=ui->eid->text().toInt();
    QDateTime datetime=QDateTime::currentDateTime();
    QString datetimetext=datetime.toString();
    db.connOpen();
    QSqlQuery query;
    query.prepare("update employee set time_out='"+datetimetext+"' where id='"+QString::number(id)+"'");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
          QMessageBox::information( this,tr("Success!"), tr("Giao ca thành công!") );

   db.connclose();
}

bool employee::check(){
    db.connOpen();
    int c_id;
    c_id=ui->eid->text().toInt();
    QSqlQuery qrycheck;
    qrycheck.prepare("select *from employee where id='"+QString::number(c_id)+"'");
    if(qrycheck.exec()){
        while (qrycheck.next()){
            int idDb;
            idDb=qrycheck.value(0).toInt();
           if(c_id==idDb){
               return false;
           }
        }
    }
    db.connclose();
    return true;
}
void employee::on_add_clicked()
{
    QString id,sdt,cccd;
           sdt=ui->ephone->text();
           cccd=ui->ecccd->text();
         id=ui->eid->text();

           bool cccd_check=false,phone_check=false,id_check=false;
           QRegularExpression idrx("^[0-9]{4}$",
                                         QRegularExpression::CaseInsensitiveOption);
           QRegularExpression phonerx("^[0-9]{10}$",
                                         QRegularExpression::CaseInsensitiveOption);
           QRegularExpression cccdrx("^[0-9]{12}$",
                                         QRegularExpression::CaseInsensitiveOption);

            if(!idrx.match(id).hasMatch()){
                        QMessageBox::warning(this,"Không Hợp Lệ","SOS ! ID Nhập Vào Gồm 4 Chữ Số!");
                        id_check = true;
                        return ;
        }else if(ui->ename->text()==""){
            QMessageBox::information(this,"Notification","Họ Và Tên Không Được Để Trống !");
             return;
        }else if(!cccdrx.match(cccd).hasMatch()){
            QMessageBox::warning(this,"Không Hợp Lệ","SOS ! Số CCCD Nhập Vào Gồm 12 Chữ Số!");
            cccd_check = true;
            return ;
        } else if(!phonerx.match(sdt).hasMatch()){
            QMessageBox::warning(this,"Không Hợp Lệ","SOS ! Số Điện Thoại Nhập Vào Gồm 10 Chữ Số!");
            phone_check = true;
            return ;
        }else if(ui->eaddress->text()==""){
            QMessageBox::information(this,"Notification","Địa Chỉ Không Được Để Trống !");
             return;
         }else if(check()==false){
                       QMessageBox::critical(this,"ERROR","ID Đã Bị Trùng !");
                        return ;
        }else{
                    int ok=QMessageBox::warning(this,"Xác Nhận Thông Tin","Bạn có chắc chắn thông tin nhập vào là chính xác ??",QMessageBox::Yes,QMessageBox::No);
                    if(ok==QMessageBox::No){
                        return ;
                    }else{
                        employee nv;
                        nv.setID(ui->eid->text().toInt());
                            nv.setName(ui->ename->text().trimmed());
                            nv.setCccd(ui->ecccd->text().trimmed());
                           nv.setSdt(ui->ephone->text().trimmed());
                           nv.setAddress(ui->eaddress->text().trimmed());
    db.connOpen();
    QSqlQuery query;
    query.prepare("insert into employee (id,name,cccd,phone,diachi,time_in) values('"+QString::number(nv.getID())+"','"+nv.getName()+"','"+nv.getCccd()+"','"+nv.getSdt()+"','"+nv.getAddress()+"','"+nv.getDatetime()+"')");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
        QMessageBox::information(this,"Information","THÊM THÀNH CÔNG !!");
        qDebug() << "Update was successful "<< query.lastQuery();
    }
   db.connclose();
}
}
}

void employee::on_search_clicked()
{
    int in_dex=ui->index->text().toInt();
    if(!db.connOpen()){
        qDebug() << "Database loaded not successfull!";
    } else{
        qDebug() << "Database loaded successfull!";
      }
    QSqlQuery query;
    query.prepare("select * from employee where id='"+QString::number(in_dex)+"'");
    if(!query.exec()){
        qDebug() << query.lastError().text() << query.lastQuery();
    }else{
        qDebug() << "Fetch was successful";

    if(query.next()){
        ui->eid->setText(query.value(0).toString());
        ui->ename->setText(query.value(1).toString());
        ui->ecccd->setText(query.value(2).toString());
        ui->ephone->setText(query.value(3).toString());
        ui->eaddress->setText(query.value(4).toString());

   }else{
        QMessageBox::information(this,"NOTIFICATION","SOS !! Không Tìm Thấy Nhân Viên Cần Tìm");
    }
   }
    db.connclose();
}

