#include "programmingpage.h"
#include "ui_programmingpage.h"
#include "QVBoxLayout"
#include "QLabel"
ProgrammingPage::ProgrammingPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProgrammingPage)
{
    ui->setupUi(this);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Layout with a label
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Game Programming Page");
    QFont font;
    font.setPointSize(20);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    this->setStyleSheet("background-color: blue;");
}

ProgrammingPage::~ProgrammingPage()
{
    delete ui;
}
