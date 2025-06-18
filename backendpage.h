#ifndef BACKENDPAGE_H
#define BACKENDPAGE_H

#include <QWidget>

namespace Ui {
class BackendPage;
}

class BackendPage : public QWidget
{
    Q_OBJECT

public:
    explicit BackendPage(QWidget *parent = nullptr);
    ~BackendPage();

private:
    Ui::BackendPage *ui;
};

#endif // BACKENDPAGE_H
