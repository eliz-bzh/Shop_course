#include "genderuser.h"
#include "ui_genderuser.h"

Genderuser::Genderuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Genderuser)
{
    ui->setupUi(this);
    this->setWindowTitle("Gender");
    setupGendersModel();
}

Genderuser::~Genderuser()
{
    delete ui;
}

void Genderuser::setupGendersModel()
{
    gendermodel = new QSqlTableModel(this);
    gendermodel->setTable("Age");
    gendermodel->setHeaderData(1, Qt::Horizontal, "Genders");
    gendermodel->select();
    ui->tableView->setModel(gendermodel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->verticalHeader()->setVisible(false);
}

void Genderuser::changeModelSlotCategory()
{
    //ui->tableView->setModel(categorymodel);
}

void Genderuser::on_tableView_doubleClicked(const QModelIndex &index)
{
    hide();
    category->show();
}
