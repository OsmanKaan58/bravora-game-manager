#include "gameartpage.h"
#include "ui_gameartpage.h"
#include "QVBoxLayout"
#include "QLabel"
GameArtPage::GameArtPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameArtPage)
{
    ui->setupUi(this);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Layout with a label
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Game Art Page");
    QFont font;
    font.setPointSize(20);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    this->setStyleSheet("background-color: blue;");
}

GameArtPage::~GameArtPage()
{
    delete ui;
}
