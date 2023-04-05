#include "mytcpserver.h"
#include <QDebug>
MyTcpServer::MyTcpServer(QObject *parent)
    : QTcpServer{parent}
{

}

MyTcpServer &MyTcpServer::getInstance()
{
    static MyTcpServer instance;
    return instance;
}

void MyTcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug()<<"new client connected";
}

