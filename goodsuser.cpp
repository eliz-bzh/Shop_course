#include "goodsuser.h"
#include "goodsuser.h"
#include "ui_goodsuser.h"

Goodsuser::Goodsuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Goodsuser)
{
    ui->setupUi(this);
    this->setWindowTitle("Goods");
    setupGoodsModel();
    setupUi();
}

Goodsuser::~Goodsuser()
{
    delete ui;
}

void Goodsuser::setupGoodsModel()
{
    goodsmodel = new QSqlTableModel(this);
    goodsmodel->setTable("goods");
    goodsmodel->setHeaderData(1, Qt::Horizontal, "Goods");
    goodsmodel->setHeaderData(2, Qt::Horizontal, "Kind");
    goodsmodel->setHeaderData(3, Qt::Horizontal, "Unit");
    goodsmodel->setHeaderData(4, Qt::Horizontal, "Price");
    goodsmodel->select();
}

void Goodsuser::setupUi()
{
    ui->tableView->setModel(goodsmodel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnWidth(1,190);
    ui->tableView->setColumnWidth(2,100);
    ui->tableView->setColumnWidth(3,100);
    ui->tableView->verticalHeader()->setVisible(false);
}

void Goodsuser::on_tableView_doubleClicked(const QModelIndex &index)
{
    qDebug() << ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4),0).toInt();
    ui->cost->setText(QString::number(ui->cost->text().toInt() +
                                      ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4),0).toInt()));
}

void Goodsuser::on_pushButton_clicked()
{
    QMessageBox::information(this, "Receipt", "With you " + ui->cost->text() + "$");
}
