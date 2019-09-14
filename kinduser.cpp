#include "kinduser.h"
#include "ui_kinduser.h"

Kinduser::Kinduser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kinduser)
{
    ui->setupUi(this);
    this->setWindowTitle("Kinds");
    setupKindModel();
    setupKindUi();

}

Kinduser::~Kinduser()
{
    delete ui;
}

void Kinduser::setupKindModel()
{
    kindmodel = new QSqlTableModel(this);
    kindmodel->setTable("kinds");
    //kindmodel->setFilter("Select from kinds where d_category = k");
    kindmodel->setHeaderData(1, Qt::Horizontal, "Kinds");
    kindmodel->setHeaderData(2, Qt::Horizontal, "Category");
    kindmodel->setHeaderData(3, Qt::Horizontal, "Gender");
    kindmodel->select();
}

void Kinduser::setupKindUi()
{
    ui->tableView->setModel(kindmodel);
    ui->tableView->setColumnWidth(1,183);
    ui->tableView->setColumnHidden(0,true);
    //ui->tableView->setColumnHidden(2,true);
   // ui->tableView->setColumnHidden(3,true);
    ui->tableView->verticalHeader()->setVisible(false);
}

void Kinduser::on_tableView_doubleClicked(const QModelIndex &index)
{
    qDebug() << ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0),0).toInt();
}

void Kinduser::on_pushButton_clicked()
{
    hide();
    Goodsuser gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}
