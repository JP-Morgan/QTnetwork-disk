#include "tcpclient.h"
#include "ui_tcpclient.h"
#include "protocol.h"
TcpClient::TcpClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    loadConfig();
     connect(&m_tcpS0cket,SIGNAL(connected())
             ,this,SLOT(showConnect()));
     //链接服务器
     m_tcpS0cket.connectToHost(QHostAddress(m_strIP),m_usPort);
}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::loadConfig()
{
    QFile file(":/client.config");
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

void TcpClient::showConnect()
{
    QMessageBox::information(this,"连接服务器","连接服务器成功");
}

//发送信号

void TcpClient::on_pushButton_clicked()
{
    QString strMsg = ui->pushButton->text();
    if(!strMsg.isEmpty())
    {
         PDU *pdu=mkPDU(strMsg.size());
         pdu->uiMsgType =8888;
         memcpy(pdu->caData,strMsg.toStdString().c_str(),strMsg.size());
         m_tcpS0cket.write((char*)pdu,pdu->uiPDULen);
         free(pdu);
         pdu=NULL;
    }
    else
    {
        QMessageBox::warning(this,"信息发送","发送的信息不能为空");
    }
}



