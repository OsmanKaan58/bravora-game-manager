#include "homepage.h"
#include "ui_homepage.h"
#include "QVBoxLayout"
#include "QLabel"
HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Layout with a label
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("New Home Page");
    QFont font;
    font.setPointSize(20);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    this->setStyleSheet("background-color: blue;");

}

HomePage::~HomePage()
{
    delete ui;
}
