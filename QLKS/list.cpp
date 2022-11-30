#include "list.h"
#include "ui_list.h"

list::list(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::list)
{
    ui->setupUi(this);
   QListWidgetItem  *cus=new customer("Nguyen Van A");
   ui->listWidget->addItem("Customer");
}

list::~list()
{
    delete ui;
}
