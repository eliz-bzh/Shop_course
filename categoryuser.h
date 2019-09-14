#ifndef CATEGORYUSER_H
#define CATEGORYUSER_H
#include <QDialog>
#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QMainWindow>
#include <QStringListModel>
#include <QAbstractListModel>
#include "database.h"
#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include "baselistmodel.h"
#include "kinduser.h"

namespace Ui {
class Categoryuser;
}

class Categoryuser : public QDialog
{
    Q_OBJECT

public:
    explicit Categoryuser(QWidget *parent = nullptr);
    ~Categoryuser();

public slots:
    void changeModelSlotGoods();
    void setupCategoryModel();

private slots:



    //void on_listView_Category_doubleClicked(const QModelIndex &index);
    void on_tableViewCategory_doubleClicked(const QModelIndex &index);


    void on_pushButton_clicked();

private:
    Ui::Categoryuser *ui;
    QSqlTableModel *categorymodel;
};

#endif // CATEGORYUSER_H
