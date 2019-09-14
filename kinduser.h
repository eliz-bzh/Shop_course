#ifndef KINDUSER_H
#define KINDUSER_H

#include <QDialog>
#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QStringListModel>
#include "database.h"
#include <QMessageBox>
#include "goodsuser.h"

namespace Ui {
class Kinduser;
}

class Kinduser : public QDialog
{
    Q_OBJECT

public:
    explicit Kinduser(QWidget *parent = nullptr);
    void setupKindModel();
    void setupKindUi();
    ~Kinduser();

private slots:



    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::Kinduser *ui;
    QSqlTableModel *kindmodel;
};

#endif // KINDUSER_H
