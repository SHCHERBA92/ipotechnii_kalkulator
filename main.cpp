#include "ipoteka.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ipoteka w;
    w.setWindowTitle("Ипотечный калькулятор от ТПБ");
    w.show();
    return a.exec();
}
