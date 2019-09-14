#include "agewindow.h"
#include "ui_agewindow.h"

Agewindow::Agewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Genderwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Genders");
    setupGendersModel();
}

Agewindow::~Agewindow()
{
    delete ui;
}

void Agewindow::setupGendersModel()
{
    gendermodel = new QSqlTableModel(this);
    gendermodel->setTable("Age");
    gendermodel->setHeaderData(1, Qt::Horizontal, "Genders");
    gendermodel->select();
    ui->tableView->setModel(gendermodel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->verticalHeader()->setVisible(false);
}

void Agewindow::changeModelSlotCategory()
{
    ui->tableView->setModel(categorymodel);
}

void Agewindow::on_pushButton_clicked()
{
    hide();
    CategoryWindow categorywindow;
    categorywindow.setModal(true);
    categorywindow.exec();
}

void Agewindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    qDebug() << ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0),0).toInt();
}
