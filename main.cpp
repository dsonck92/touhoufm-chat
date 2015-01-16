#include "chatwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatWidget w;
    w.show();

    return a.exec();
}
