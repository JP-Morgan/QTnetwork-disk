#include "tcpserve.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpServe w;
    w.show();
    return a.exec();
}
