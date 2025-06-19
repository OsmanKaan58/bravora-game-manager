#ifndef TASKSERVICE_H
#define TASKSERVICE_H

#include <QObject>
#include <QSqlDatabase>
#include <QVector>
#include "task.h"

class TaskService : public QObject
{
    Q_OBJECT

public:
    explicit TaskService(QObject *parent = nullptr);
    bool connectDatabase(const QString &dbPath);
    bool createTable();
    bool addTask(const Task &task);
    QVector<Task> getAllTasks();
    bool updateTask(int id, const Task &task);
    bool deleteTask(int id);

private:
    QSqlDatabase db;
};

#endif // TASKSERVICE_H
