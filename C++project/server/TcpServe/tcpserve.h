#ifndef TCPSERVE_H
#define TCPSERVE_H
#include <QWidget>
#include <iostream>
#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QTcpSocket>
#include <QHostAddress>
#include <iostream>
QT_BEGIN_NAMESPACE
namespace Ui { class TcpServe; }
QT_END_NAMESPACE

class TcpServe : public QWidget
{
    Q_OBJECT

public:
    TcpServe(QWidget *parent = nullptr);
    ~TcpServe();
    void loadConfig();


private:
    Ui::TcpServe *ui;
    QString m_strIP;
    quint16 m_usPort;
};
#endif // TCPSERVE_H
