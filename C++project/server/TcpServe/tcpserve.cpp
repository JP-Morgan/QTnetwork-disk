#include "tcpserve.h"
#include "ui_tcpserve.h"
//F:\C++project\server\TcpServe\tcpserve.cpp:2: error: 'ui_tcpserve.h' file not found
#include "mytcpserver.h"
TcpServe::TcpServe(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::TcpServe)
{
    ui->setupUi(this);
    loadConfig();
    MyTcpServer::getInstance().listen(QHostAddress(m_strIP),m_usPort);
}

TcpServe::~TcpServe()
{
    delete ui;
}

void TcpServe::loadConfig()
{
    QFile file(":/server.config");
     if(file.open(QIODevice::ReadOnly))
     {
         QByteArray baData = file.readAll();
         QString strData = baData.toStdString().c_str();

         file.close();

         strData.replace("\r\n"," ");
         //qDebug() << strData;
         QStringList strList = strData.split(" ");
//         for (int i=0;i<strList.size();i++)
//         {
//             qDebug() <<strList[i];
//         }
         m_strIP=strList.at(0);
         m_usPort=strList.at(1).toUShort();
         qDebug() <<"ip:"<<m_strIP<<"port:"<<m_usPort;
     }
     else
     {
         QMessageBox::critical(this,"open conf","open config failed");
     }
}

