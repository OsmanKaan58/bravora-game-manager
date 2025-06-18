#ifndef PRODUCTMANAGEMENTPAGE_H
#define PRODUCTMANAGEMENTPAGE_H

#include <QWidget>

namespace Ui {
class ProductManagementPage;
}

class ProductManagementPage : public QWidget
{
    Q_OBJECT

public:
    explicit ProductManagementPage(QWidget *parent = nullptr);
    ~ProductManagementPage();

private:
    Ui::ProductManagementPage *ui;
};

#endif // PRODUCTMANAGEMENTPAGE_H
