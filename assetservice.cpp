#include "assetservice.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

AssetService::AssetService(QObject* parent) : QObject(parent)
{
}

bool AssetService::connectDatabase(const QString& dbPath)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    return db.open();
}

bool AssetService::createTable()
{
    QSqlQuery query(db);
    return query.exec("CREATE TABLE IF NOT EXISTS assets ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "name TEXT NOT NULL, "
                      "description TEXT, "
                      "filePath TEXT NOT NULL, "
                      "type INTEGER NOT NULL, "
                      "synced INTEGER DEFAULT 0)");
}

bool AssetService::addAsset(const Asset& asset)
{
    QSqlQuery query(db);
    query.prepare(
        "INSERT INTO assets (name, description, filePath, type, synced) "
        "VALUES (:name, :description, :filePath, :type, :synced)");
    query.bindValue(":name", QString::fromStdString(asset.getName()));
    query.bindValue(":description",
                    QString::fromStdString(asset.getDescription()));
    query.bindValue(":filePath", QString::fromStdString(asset.getFilePath()));
    query.bindValue(":type", static_cast<int>(asset.getType()));
    query.bindValue(":synced", asset.isSynced() ? 1 : 0);
    return query.exec();
}

QVector<Asset> AssetService::getAllAssets()
{
    QVector<Asset> assets;
    QSqlQuery query(db);
    query.exec("SELECT * FROM assets");

    while (query.next())
    {
        Asset asset;
        asset.setId(query.value("id").toInt());
        asset.setName(query.value("name").toString().toStdString());
        asset.setDescription(
            query.value("description").toString().toStdString());
        asset.setFilePath(query.value("filePath").toString().toStdString());
        asset.setType(static_cast<AssetType>(query.value("type").toInt()));
        asset.setSynced(query.value("synced").toInt() == 1);
        assets.append(asset);
    }
    return assets;
}

bool AssetService::updateAsset(int id, const Asset& asset)
{
    QSqlQuery query(db);
    query.prepare(
        "UPDATE assets SET name = :name, description = :description, "
        "filePath = :filePath, type = :type, synced = :synced WHERE id = :id");
    query.bindValue(":name", QString::fromStdString(asset.getName()));
    query.bindValue(":description",
                    QString::fromStdString(asset.getDescription()));
    query.bindValue(":filePath", QString::fromStdString(asset.getFilePath()));
    query.bindValue(":type", static_cast<int>(asset.getType()));
    query.bindValue(":synced", asset.isSynced() ? 1 : 0);
    query.bindValue(":id", id);
    return query.exec();
}

bool AssetService::deleteAsset(int id)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM assets WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}
