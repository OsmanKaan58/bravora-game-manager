#include "taskservice.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

TaskService::TaskService(QObject *parent) : QObject(parent) {}

bool TaskService::connectDatabase(const QString &dbPath)
{
    // Use existing connection if one already exists
    if (QSqlDatabase::contains("default"))
        db = QSqlDatabase::database("default");
    else {
        db = QSqlDatabase::addDatabase("QSQLITE", "default");
        db.setDatabaseName(dbPath);
    }
    return db.open();
}

bool TaskService::createTable()
{
    QSqlQuery query(db);
    return query.exec(
        "CREATE TABLE IF NOT EXISTS tasks ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "title TEXT, "
        "description TEXT, "
        "category INTEGER, "
        "type INTEGER, "
        "imagePath TEXT)"); // NEW
}

bool TaskService::addTask(const Task &task)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO tasks (title, description, category, type) "
                  "VALUES (:title, :description, :category, :type)");
    query.bindValue(":title", QString::fromStdString(task.getTitle()));
    query.bindValue(":description", QString::fromStdString(task.getDescription()));
    query.bindValue(":category", static_cast<int>(task.getTaskCategory()));
    query.bindValue(":type", static_cast<int>(task.getTaskType()));
     query.bindValue(":imagePath", QString::fromStdString(task.getImagePath()));
    return query.exec();
}

QVector<Task> TaskService::getAllTasks()
{
    QVector<Task> tasks;
    QSqlQuery query(db);
    query.exec("SELECT * FROM tasks");
    while (query.next()) {
        Task task;
        task.setTitle(query.value("title").toString().toStdString());
        task.setDescription(query.value("description").toString().toStdString());
        task.setTaskCategory(static_cast<TaskCategory>(query.value("category").toInt()));
        task.setTaskType(static_cast<TaskType>(query.value("type").toInt()));
        task.setImagePath(query.value("imagePath").toString().toStdString());
        tasks.append(task);
    }
    return tasks;
}

bool TaskService::updateTask(int id, const Task &task)
{
    QSqlQuery query(db);
    query.prepare("UPDATE tasks SET title = :title, description = :description, "
                  "category = :category, type = :type WHERE id = :id");
    query.bindValue(":title", QString::fromStdString(task.getTitle()));
    query.bindValue(":description", QString::fromStdString(task.getDescription()));
    query.bindValue(":category", static_cast<int>(task.getTaskCategory()));
    query.bindValue(":type", static_cast<int>(task.getTaskType()));
    query.bindValue(":id", id);
    query.bindValue(":imagePath", QString::fromStdString(task.getImagePath()));
    return query.exec();
}

bool TaskService::deleteTask(int id)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM tasks WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}
