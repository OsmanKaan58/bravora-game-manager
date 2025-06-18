#ifndef PROGRAMMINGPAGE_H
#define PROGRAMMINGPAGE_H

#include <QWidget>

namespace Ui {
class ProgrammingPage;
}

class ProgrammingPage : public QWidget
{
    Q_OBJECT

public:
    explicit ProgrammingPage(QWidget *parent = nullptr);
    ~ProgrammingPage();

private:
    Ui::ProgrammingPage *ui;
};

#endif // PROGRAMMINGPAGE_H
