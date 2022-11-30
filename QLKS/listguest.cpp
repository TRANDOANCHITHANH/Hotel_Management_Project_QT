#include "listguest.h"
#include "ui_listguest.h"

listguest::listguest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listguest)
{
    ui->setupUi(this);
     this->setWindowTitle("LIST GUEST");
}

listguest::~listguest()
{
    delete ui;
}

void listguest::on_load_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    if(!conn.connOpen()){
        qDebug() << "Database loaded not successfull!";
    } else{
        qDebug() << "Database loaded successfull!";
   }
    QSqlQuery* query=new QSqlQuery();
    query->prepare("select * from guest");
    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
    conn.connclose();
    qDebug()<<(modal->rowCount());
}


void listguest::on_save_clicked()
{
    int in_dex=ui->index->text().toInt();

    if(!conn.connOpen()){
        qDebug() << "Database loaded not successfull!";
    } else{
        qDebug() << "Database loaded successfull!";
      }
    QSqlQuery query;
    query.prepare("select * from guest where id='"+QString::number(in_dex)+"'");
    if(!query.exec()){
        qDebug() << query.lastError().text() << query.lastQuery();
    }else{
        qDebug() << "Fetch was successful";

    if(query.next()){
        ui->ename->setText(query.value(1).toString());
        ui->eccd->setText(query.value(2).toString());
        ui->ephone->setText(query.value(3).toString());
        ui->eaddress->setText(query.value(4).toString());
        ui->eroom->setText(query.value(5).toString());
        ui->esta->setText(query.value(7).toString());

   }else{
        QMessageBox::information(this,"NOTIFICATION","SOS !! Không Tìm Thấy Khách Cần Tìm");
    }
   }
    conn.connclose();
}


void listguest::on_exit_clicked()
{
    this->hide();
}


void listguest::on_tableView_activated(const QModelIndex &index)
{
   QString val=ui->tableView->model()->data(index).toString();
   if(!conn.connOpen()){
       qDebug() << "Database loaded not successfull!";
   } else{
       qDebug() << "Database loaded successfull!";
     }
   QSqlQuery query;
   query.prepare("select * from guest where id='"+val+"' or name='"+val+"' or cccd='"+val+"' or sdt='"+val+"' or diachi='"+val+"' or maphong='"+val+"' or status='"+val+"'");
   if(query.exec()){
       while(query.next()){
           ui->ename->setText(query.value(1).toString());
           ui->eccd->setText(query.value(2).toString());
           ui->ephone->setText(query.value(3).toString());
           ui->eaddress->setText(query.value(4).toString());
           ui->eroom->setText(query.value(5).toString());
           ui->esta->setText(query.value(7).toString());
       }
       conn.connclose();
   }
   else{
       QMessageBox::critical(this,tr("Error::"),query.lastError().text());
   }
}


void listguest::on_update_clicked()
{
//    int in_dex=ui->index->text().toInt();
//    QString name=ui->ename->text();
//    QString cccd=ui->eccd->text();
//    QString sdt=ui->ephone->text();
//    QString address=ui->eaddress->text();
    listguest list;
    list.setID(ui->index->text().toInt());
    list.setName(ui->ename->text());
    list.setCccd(ui->eccd->text());
    list.setSdt(ui->ephone->text());
    list.setAddress(ui->eaddress->text());
    if(!conn.connOpen()){
        qDebug() << "Database loaded not successfull!";
    } else{
        qDebug() << "Database loaded successfull!";
      }
    QSqlQuery query;
    query.prepare("update guest set name='"+list.getName()+"',cccd='"+list.getCccd()+"',sdt='"+list.getSdt()+"',diachi='"+list.getAddress()+"' where id='"+QString::number(list.getID())+"'");
    if(query.exec()){
        QMessageBox::information(this,tr("Edit"),tr("CẬP NHẬT THÔNG TIN THÀNH CÔNG !!"));
        conn.connclose();
    }else{
        QMessageBox::critical(this,tr("Error::"),query.lastError().text());
    }
}


void listguest::on_remove_clicked()
{

int in_dex=ui->index->text().toInt();
    if(!conn.connOpen()){
        qDebug() << "Database loaded not successfull!";
    } else{
        qDebug() << "Database loaded successfull!";
      }
    QSqlQuery query;
    query.prepare("Delete from guest where id='"+QString::number(in_dex)+"'");
    int ok=QMessageBox::warning(this,"Xác Nhận Thông Tin","Bạn có chắc chắn muốn xoá??",QMessageBox::Yes,QMessageBox::No);
    if(ok==QMessageBox::No){
        return ;
    }else{
    if(query.exec()){
        QMessageBox::critical(this,tr("Delete"),tr("Xóa Thông Tin Khách Thành Công !!"));
        conn.connclose();
    }else{
        QMessageBox::critical(this,tr("Error::"),query.lastError().text());
    }
    }
}


void listguest::on_note_2_clicked()
{
    QString name=ui->ename->text();
    if(!conn.connOpen()){
        qDebug() << "Database loaded not successfull!";
    } else{
        qDebug() << "Database loaded successfull!";
      }
    QSqlQuery query;
    query.prepare("select * from management where name='"+name+"'");
    if(query.exec()){
        while(query.next()){
         ui->note->setText(query.value(8).toString());
        }
        conn.connclose();
    }
    else{
        QMessageBox::critical(this,tr("Error::"),query.lastError().text());
    }
 }

