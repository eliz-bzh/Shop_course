#include "categorywindow.h"
#include "ui_category.h"

CategoryWindow::CategoryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Category)
{
    ui->setupUi(this);
    this->setWindowTitle("Categories");
    setupCategoryModel();
    connect(ui->pushButton_Add, &QPushButton::clicked, this, &CategoryWindow::slotAddCategory);
}

CategoryWindow::~CategoryWindow()
{
    delete ui;
}

void CategoryWindow::setupCategoryModel()
{
   // categorymodel = new BaseListModel(QSqlQuery("SELECT id, c_name from categories"), this);
    //ui->listView_Category->setModel(categorymodel);
    categorymodel = new QSqlTableModel(this);
    categorymodel->setTable("categories");
    categorymodel->setHeaderData(1, Qt::Horizontal, "Categories");
    categorymodel->select();
    ui->tableView->setModel(categorymodel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->verticalHeader()->setVisible(false);
}

void CategoryWindow::changeModelSlotGoods()
{
    //ui->tableView->setModel(kmodel);
}


void CategoryWindow::slotAddCategory()
{
    if(!DataBase::insertIntoCategories(ui->lineEdit->text()))
    {
        QMessageBox::information(this, "Error", "Error");
    }
    else {
        QMessageBox::information(this, "Info Window", "You added");
        categorymodel->select();
    }
}

void CategoryWindow::on_pushButton_next_clicked()
{
      hide();
      Kindnew kwindow;
      kwindow.setModal(true);
      kwindow.exec();
}

void CategoryWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    qDebug() << ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0),0).toInt();
}
