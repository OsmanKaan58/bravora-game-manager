#include "goalservice.h"
#include <QSqlError>
#include <QVariant>
#include <QDebug>

GoalService::GoalService(QObject *parent) : QObject(parent) {}

bool GoalService::connectDatabase(const QString &dbPath)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    return db.open();
}

bool GoalService::createTable()
{
    QSqlQuery query;
    return query.exec(
        "CREATE TABLE IF NOT EXISTS goals ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "title TEXT, "
        "description TEXT, "
        "priority INTEGER, "
        "category INTEGER)");
}

bool GoalService::addGoal(const Goal &goal)
{
    QSqlQuery query;
    query.prepare("INSERT INTO goals (title, description, priority, category) "
                  "VALUES (:title, :description, :priority, :category)");
    query.bindValue(":title", QString::fromStdString(goal.getGoalTitle()));
    query.bindValue(":description", QString::fromStdString(goal.getGoalDescription()));
    query.bindValue(":priority", static_cast<int>(goal.getPriorityDegree()));
    query.bindValue(":category", static_cast<int>(goal.getCategory()));
    return query.exec();
}

QVector<Goal> GoalService::getAllGoals()
{
    QVector<Goal> goals;
    QSqlQuery query("SELECT * FROM goals");
    while (query.next())
    {
        Goal goal;
        goal.setGoalTitle(query.value("title").toString().toStdString());
        goal.setGoalDescription(query.value("description").toString().toStdString());
        goal.setPriorityDegree(static_cast<GoalPriority>(query.value("priority").toInt()));
        goal.setCategory(static_cast<TaskCategory>(query.value("category").toInt()));
        goals.append(goal);
    }
    return goals;
}

bool GoalService::updateGoal(int id, const Goal &goal)
{
    QSqlQuery query;
    query.prepare("UPDATE goals SET title = :title, description = :description, "
                  "priority = :priority, category = :category WHERE id = :id");
    query.bindValue(":title", QString::fromStdString(goal.getGoalTitle()));
    query.bindValue(":description", QString::fromStdString(goal.getGoalDescription()));
    query.bindValue(":priority", static_cast<int>(goal.getPriorityDegree()));
    query.bindValue(":category", static_cast<int>(goal.getCategory()));
    query.bindValue(":id", id);
    return query.exec();
}

bool GoalService::deleteGoal(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM goals WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}
