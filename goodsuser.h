#ifndef GOODSUSER_H
#define GOODSUSER_H

#include <QDialog>
#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QMainWindow>
#include <QStringListModel>
#include "database.h"
#include <QDialog>
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Goodsuser;
}

class Goodsuser : public QDialog
{
    Q_OBJECT

public:
    explicit Goodsuser(QWidget *parent = nullptr);
    void setupGoodsModel();
    void setupUi();
    ~Goodsuser();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_pushButton_clicked();

private:
    Ui::Goodsuser *ui;
    QSqlTableModel *goodsmodel;
};

#endif // GOODSUSER_H
