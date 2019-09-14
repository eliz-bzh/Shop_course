#include "database.h"

#include <QDebug>


bool DataBase::queryRun(QSqlQuery &query, const char *table_name)
{
    if(!query.exec())
    {
        qDebug() << "error in " << table_name;
        qDebug() << query.lastError().text();
        return false;
    }
    qDebug() << "ok";
    return true;
}

DataBase::DataBase(QObject *parent) : QObject(parent)
{
#ifdef DEBUG
    qDebug() << "DataBase";
#endif
    if(!QFile(DATABASE_PATH).exists())
           {
               restoreDataBase();
           }
           else
           {
               openDataBase();
           }
}

bool DataBase::openDataBase()
{
#ifdef DEBUG
    qDebug() << "openDataBase";
#endif

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("server");
    db.setDatabaseName(DATABASE_PATH);
    return db.open();
}

void DataBase::restoreDataBase()
{
#ifdef DEBUG
    qDebug() << "restoreDataBase";
#endif
    openDataBase();
    createTables();
    insertIntoTables();
}

void DataBase::closeDataBase()
{

}

bool DataBase::createTables()
{
     QSqlQuery query;
     return query.exec(CREATE_AGE)&&
             query.exec(CREATE_CATEGORIES) &&
             query.exec(CREATE_KINDS) &&
             query.exec(CREATE_UNITS ) &&
             query.exec(CREATE_GOODS) &&
             query.exec(CREATE_POSITIONS);
}

bool DataBase::insertIntoGenders(const QVariantList &data)
{
   QSqlQuery query;
   query.prepare("INSERT INTO Age("
                 "age"
                 ")"
                 "values(:age)");
   query.bindValue(":age", data[0].toString());
   return queryRun(query, "Age");

}

bool DataBase::insertIntoCategories(const QString &data)
{
   QSqlQuery query;
   query.prepare("INSERT INTO categories("
                 "c_name"
                 ")"
                 "values(:c_name)");
   query.bindValue(":c_name", data);
   return queryRun(query, "categories");

}

bool DataBase::insertIntoUnits(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO units("
                  "u_name"
                  ")"
                  "values(:u_name)");
    query.bindValue(":u_name", data[0].toString());
    return queryRun(query, "units");
}

bool DataBase::insertIntoGoods(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO goods("
                  "g_name,"
                  "g_kind,"
                  "g_unit,"
                  "g_price"
                  ")"
                  "values(:g_name, :g_kind, :g_unit, :g_price)");
    query.bindValue(":g_name", data[0].toString());
    query.bindValue(":g_kind", data[1].toInt());
    query.bindValue(":g_unit", data[2].toInt());
    query.bindValue(":g_price", data[3].toReal());
    return queryRun(query, "goods");
}

bool DataBase::insertIntoPositions(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO positions("
                  "p_goods,"
                  "p_count,"
                  "p_weight"
                  ")"
                  "values(:p_goods, :p_count, :p_weight)");
    query.bindValue(":p_goods", data[0].toInt());
    query.bindValue(":p_count", data[1].toInt());
    query.bindValue(":p_weight", data[2].toInt());
    return queryRun(query, "positions");
}

bool DataBase::insertIntoDressKind(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO kinds("
                  "d_name,"
                  "d_category,"
                  "d_age"
                  ")"
                  "values(:d_name, :d_category, :d_age)");
    query.bindValue(":d_name", data[0].toString());
    query.bindValue(":d_category", data[1].toInt());
    query.bindValue(":d_age", data[2].toInt());
    return queryRun(query, "kinds");
}

void DataBase::insertIntoTables()
{
    insertIntoGenders(QVariantList{QVariant("Women")});
    insertIntoGenders(QVariantList{QVariant("Men")});

    insertIntoDressKind(QVariantList{QVariant("T-shirts and body"), QVariant(1), QVariant(1)});//1
    insertIntoDressKind(QVariantList{QVariant("T-shirts"), QVariant(4), QVariant(2)});
    insertIntoDressKind(QVariantList{QVariant("Cardigans and Sweater"), QVariant(1), QVariant(1)});
    insertIntoDressKind(QVariantList{QVariant("Sweater and Cardigans"), QVariant(4), QVariant(2)});
    insertIntoDressKind(QVariantList{QVariant("Sweatshirts and Shirts"), QVariant(1), QVariant(1)});
    insertIntoDressKind(QVariantList{QVariant("Shirts and Sweatshirts"), QVariant(4), QVariant(2)});
    insertIntoDressKind(QVariantList{QVariant("Dresses"), QVariant(1), QVariant(1)});
    insertIntoDressKind(QVariantList{QVariant("Skirts"), QVariant(1), QVariant(1)});
    insertIntoDressKind(QVariantList{QVariant("Trousers"), QVariant(1), QVariant(1)});
    insertIntoDressKind(QVariantList{QVariant("Jeans"), QVariant(1), QVariant(1)});//10
    insertIntoDressKind(QVariantList{QVariant("Shorts and capri"), QVariant(1), QVariant(1)});
    insertIntoDressKind(QVariantList{QVariant("Trousers "), QVariant(4), QVariant(2)});
    insertIntoDressKind(QVariantList{QVariant("Jeans "), QVariant(4), QVariant(2)});//13
    insertIntoDressKind(QVariantList{QVariant("Shorts"), QVariant(4), QVariant(2)});
    insertIntoDressKind(QVariantList{QVariant("Underwear and pajamas"), QVariant(1), QVariant(1)});
    insertIntoDressKind(QVariantList{QVariant("Bathing suit"), QVariant(1), QVariant(1)});
    insertIntoDressKind(QVariantList{QVariant("Underwear and pajamas "), QVariant(4), QVariant(2)});
    insertIntoDressKind(QVariantList{QVariant("Bathing suit "), QVariant(4), QVariant(2)});

    insertIntoDressKind(QVariantList{QVariant("Coats, jackets and vests"), QVariant(2), QVariant(1)});//19
    insertIntoDressKind(QVariantList{QVariant("Sportswear"), QVariant(2), QVariant(1)});
    insertIntoDressKind(QVariantList{QVariant("Coats, jackets and vests "), QVariant(5), QVariant(2)});
    insertIntoDressKind(QVariantList{QVariant("Sportswear "), QVariant(5), QVariant(2)});

    insertIntoCategories("Underwear women");
    insertIntoCategories("Outerwear women");
    insertIntoCategories("Boots women");
    insertIntoCategories("Underwear men");
    insertIntoCategories("Outerwear men");
    insertIntoCategories("Boots men");

    insertIntoUnits(QVariantList{QVariant("All")});
    insertIntoUnits(QVariantList{QVariant("XS")});
    insertIntoUnits(QVariantList{QVariant("S")});
    insertIntoUnits(QVariantList{QVariant("M")});
    insertIntoUnits(QVariantList{QVariant("L")});
    insertIntoUnits(QVariantList{QVariant("XL")});
    insertIntoUnits(QVariantList{QVariant("XXL")});
    insertIntoUnits(QVariantList{QVariant("XXXL")});

    insertIntoGoods(QVariantList{QVariant("Dress"), QVariant(1), QVariant(1), QVariant(100)});
    insertIntoGoods(QVariantList{QVariant("Black jeans"), QVariant(10), QVariant(1), QVariant(350)});
    insertIntoGoods(QVariantList{QVariant("Jeans skirt"), QVariant(8), QVariant(1), QVariant(75)});
    insertIntoGoods(QVariantList{QVariant("Trousers"), QVariant(12), QVariant(1), QVariant(144)});
    insertIntoGoods(QVariantList{QVariant("Gray coat"), QVariant(21), QVariant(1), QVariant(586)});
    insertIntoGoods(QVariantList{QVariant("Men pajama"), QVariant(17), QVariant(1), QVariant(79)});
}

void DataBase::deleteCategory(QString index)
{
    QSqlQuery query;
    query.prepare("delete from categories where c_name = :index");
    query.bindValue(":index", index.toInt());
    query.exec();
}


