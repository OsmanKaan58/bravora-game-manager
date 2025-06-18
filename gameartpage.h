#ifndef GAMEARTPAGE_H
#define GAMEARTPAGE_H

#include <QWidget>

namespace Ui {
class GameArtPage;
}

class GameArtPage : public QWidget
{
    Q_OBJECT

public:
    explicit GameArtPage(QWidget *parent = nullptr);
    ~GameArtPage();

private:
    Ui::GameArtPage *ui;
};

#endif // GAMEARTPAGE_H
