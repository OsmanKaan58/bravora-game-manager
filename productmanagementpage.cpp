#include "productmanagementpage.h"
#include "ui_productmanagementpage.h"
#include "QVBoxLayout"
#include "QLabel"
ProductManagementPage::ProductManagementPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProductManagementPage)
{
    ui->setupUi(this);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Layout with a label
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Product Management Page");
    QFont font;
    font.setPointSize(20);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    this->setStyleSheet("background-color: blue;");
}

ProductManagementPage::~ProductManagementPage()
{
    delete ui;
}
