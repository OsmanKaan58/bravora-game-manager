#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent, TaskService* taskServicePtr, GoalService* goalServicePtr)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    taskServicePtr(taskServicePtr),
    goalServicePtr(goalServicePtr)
{
    ui->setupUi(this);

    // Replace placeholder pages with real ones
    homePage = new HomePage();
    artPage = new GameArtPage();
    progPage = new ProgrammingPage();
    backendPage = new BackendPage();
    productPage = new ProductManagementPage();

    int homeIndex = ui->pageStack->indexOf(ui->homePage);
    ui->pageStack->removeWidget(ui->homePage);
    ui->pageStack->insertWidget(homeIndex, homePage);

    int artIndex = ui->pageStack->indexOf(ui->artPage);
    ui->pageStack->removeWidget(ui->artPage);
    ui->pageStack->insertWidget(artIndex, artPage);

    int progIndex = ui->pageStack->indexOf(ui->programmingPage);
    ui->pageStack->removeWidget(ui->programmingPage);
    ui->pageStack->insertWidget(progIndex, progPage);

    int backendIndex = ui->pageStack->indexOf(ui->backendPage);
    ui->pageStack->removeWidget(ui->backendPage);
    ui->pageStack->insertWidget(backendIndex, backendPage);

    int productIndex = ui->pageStack->indexOf(ui->productPage);
    ui->pageStack->removeWidget(ui->productPage);
    ui->pageStack->insertWidget(productIndex, productPage);
}

MainWindow::~MainWindow()
{
    delete ui;
    // Optional: delete pages if needed
}

void MainWindow::on_hideSideBarBtn_clicked()
{

    ui->leftSideBar->setVisible(!ui->leftSideBar->isVisible());
}

void MainWindow::on_homeBtn_clicked()
{
    qDebug() << "home button is cliked";
    ui->pageStack->setCurrentWidget(homePage);
}

void MainWindow::on_artBtn_clicked()
{
    ui->pageStack->setCurrentWidget(artPage);
}

void MainWindow::on_progBtn_clicked()
{
    ui->pageStack->setCurrentWidget(progPage);
}

void MainWindow::on_beBtn_clicked()
{
    ui->pageStack->setCurrentWidget(backendPage);
}


void MainWindow::on_pmBtn_clicked()
{
    ui->pageStack->setCurrentWidget(productPage);
}

