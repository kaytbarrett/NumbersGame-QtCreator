#ifndef NUMBERSGAME_H
#define NUMBERSGAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class NumbersGame;
}
QT_END_NAMESPACE

class NumbersGame : public QMainWindow
{
    Q_OBJECT

public:
    NumbersGame(QWidget *parent = nullptr);
    ~NumbersGame();

private slots:
    void processGuess();

private:
    Ui::NumbersGame *ui;
    std::vector<int> randomNumGenerator();
    std::vector<int> numberVec;
};

#endif // NUMBERSGAME_H
