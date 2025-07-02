#ifndef ASSETSERVICE_H
#define ASSETSERVICE_H

#include <QObject>
#include <QSqlDatabase>
#include <QVector>
#include "asset.h"

class AssetService : public QObject
{
    Q_OBJECT

  public:
    explicit AssetService(QObject* parent = nullptr);
    bool connectDatabase(const QString& dbPath);
    bool createTable();
    bool addAsset(const Asset& asset);
    QVector<Asset> getAllAssets();
    bool updateAsset(int id, const Asset& asset);
    bool deleteAsset(int id);

  private:
    QSqlDatabase db;
};

#endif // ASSETSERVICE_H
