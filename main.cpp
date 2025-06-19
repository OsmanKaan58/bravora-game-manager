#include "mainwindow.h"

#include <QApplication>
#include "goalservice.h"
#include "taskservice.h"
#include "QMessageBox"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GoalService goalService;
    TaskService taskService;

    const QString dbPath = "planner.db";

    // Connect both services to the same SQLite database
    if (!goalService.connectDatabase(dbPath) || !taskService.connectDatabase(dbPath)) {
        QMessageBox::critical(nullptr, "Database Error", "Failed to connect to the database.");
        return -1;
    }

    // Ensure required tables exist
    if (!goalService.createTable() || !taskService.createTable()) {
        QMessageBox::critical(nullptr, "Database Error", "Failed to create necessary tables.");
        return -1;
    }

    MainWindow w(nullptr, &taskService, &goalService);
    w.show();
    return a.exec();
}
