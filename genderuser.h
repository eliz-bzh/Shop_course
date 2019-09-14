#ifndef GENDERUSER_H
#define GENDERUSER_H

#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QMainWindow>
#include <QStringListModel>
#include "database.h"
#include "categorywindow.h"
#include <QDialog>

namespace Ui {
class Genderuser;
}

class Genderuser : public QDialog
{
    Q_OBJECT

public:
    explicit Genderuser(QWidget *parent = nullptr);
    ~Genderuser();

private:
    Ui::Genderuser *ui;
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *gendermodel;
    QSqlTableModel *categorymodel;
    QSqlTableModel *goodsmodel;
    CategoryWindow *category;
    void setupGendersModel();
    void setupStringListModel();

public slots:
    void changeModelSlotCategory();


private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
};

#endif // GENDERUSER_H
