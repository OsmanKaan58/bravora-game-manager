#ifndef GOALSERVICE_H
#define GOALSERVICE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include "goal.h"

class GoalService : public QObject
{
    Q_OBJECT

public:
    explicit GoalService(QObject *parent = nullptr);
    bool connectDatabase(const QString &dbPath);
    bool createTable();
    bool addGoal(const Goal &goal);
    QVector<Goal> getAllGoals();
    bool updateGoal(int id, const Goal &goal); // assuming ID is used
    bool deleteGoal(int id);

private:
    QSqlDatabase db;
};

#endif // GOALSERVICE_H
