#include "backendpage.h"
#include "ui_backendpage.h"
#include "QVBoxLayout"
#include "QLabel"
BackendPage::BackendPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BackendPage)
{
    ui->setupUi(this);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Layout with a label
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Backend Page");
    QFont font;
    font.setPointSize(20);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    this->setStyleSheet("background-color: blue;");
}

BackendPage::~BackendPage()
{
    delete ui;
}
