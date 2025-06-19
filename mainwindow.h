#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "goalservice.h"
#include "programmingpage.h"
#include "gameartpage.h"
#include "homepage.h"
#include "backendpage.h"
#include "productmanagementpage.h"
#include "taskservice.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, TaskService* taskServicePtr = nullptr, GoalService* goalServicePtr = nullptr);
    ~MainWindow();

private slots:
    void on_hideSideBarBtn_clicked();

    void on_homeBtn_clicked();

    void on_artBtn_clicked();

    void on_progBtn_clicked();

    void on_beBtn_clicked();

    void on_pmBtn_clicked();

private:
    Ui::MainWindow *ui;
    HomePage* homePage;
    GameArtPage* artPage;
    ProgrammingPage* progPage;
    BackendPage* backendPage;
    ProductManagementPage* productPage;
    TaskService* taskServicePtr;
    GoalService* goalServicePtr;
};
#endif // MAINWINDOW_H
