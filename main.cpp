#include "numbersGame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NumbersGame w;
    w.show();
    return a.exec();
}
