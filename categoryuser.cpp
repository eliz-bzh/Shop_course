#include "categoryuser.h"
#include "ui_categoryuser.h"

Categoryuser::Categoryuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Categoryuser)
{
    ui->setupUi(this);
    this->setWindowTitle("Categories");
    setupCategoryModel();
}

Categoryuser::~Categoryuser()
{
    delete ui;
}

void Categoryuser::setupCategoryModel()
{
    /*categorymodel = new BaseListModel(QSqlQuery("SELECT id, c_name from categories"), this);
    ui->listView_Category->setModel(categorymodel);
    categorymodel->select();*/
    categorymodel = new QSqlTableModel(this);
    categorymodel->setTable("categories");
    categorymodel->setHeaderData(1, Qt::Horizontal, "Categories");
    categorymodel->select();
    ui->tableViewCategory->setModel(categorymodel);
    ui->tableViewCategory->setColumnHidden(0,true);
    ui->tableViewCategory->verticalHeader()->setVisible(false);
}

void Categoryuser::changeModelSlotGoods()
{
    //ui->tableViewCategory->setModel(kmodel);
}

void Categoryuser::on_tableViewCategory_doubleClicked(const QModelIndex &index)
{
    qDebug() << ui->tableViewCategory->model()->data(ui->tableViewCategory->model()->index(index.row(),0),0).toInt();
}

void Categoryuser::on_pushButton_clicked()
{
    hide();
    Kinduser kwindow;
    kwindow.setModal(true);
    kwindow.exec();
}
