#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QFile>
#include <QTcpSocket>
#include <QDebug>
#include <QMessageBox>
#include <iostream>
#include <QHostAddress>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpClient; }
QT_END_NAMESPACE

class TcpClient : public QWidget
{
    Q_OBJECT
//warning: Included header protocol.h is not used directly (fix available)
public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();
    void loadConfig();
public slots:
    //判断是否链接成功
    void showConnect();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TcpClient *ui;
        QString m_strIP;
        quint16 m_usPort;
        //连接服务器，和服务器数据交互
        //链接服务器
        QTcpSocket m_tcpS0cket;
};
#endif // TCPCLIENT_H
