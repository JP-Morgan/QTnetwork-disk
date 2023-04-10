#ifndef OPEDB_H
#define OPEDB_H

#include <QObject>
//链接数据库
#include<Qtsql/QSqlDatabase>
//查询数据库
#include<Qtsql/QSqlQuery>
#include<QStringList>


class OpeDB : public QObject
{
    Q_OBJECT//支持信号
public:
    explicit OpeDB(QObject *parent = nullptr);
    //将数据库操作定义为单例
    //讲解https://blog.csdn.net/weixin_33933118/article/details/93205284
    static OpeDB &getInstance();
    //连接数据库(初始化)
    void init();
    //关闭数据库
    ~OpeDB();

    bool handleRegist(const char *name,const char *pwd);
    bool handleLogin(const char *name,const char *pwd);
    void handleOffine(const char *name);

    bool handleDeleteUser(const char *name,const char *pwd);

    QStringList handleAllOnline();

    void handleFirstBootOffine();

    int handleSearchUser(const char *name);


    int handAddFriend(const char * perName,const char * name);

    void handleAgreeAddFriend(const char * perName,const char * name);

    bool handledelFriend(const char * name,const char * friendName);

    QStringList handFlushFriend(const char * name);



signals:
private:
    //定义连接数据库
    QSqlDatabase m_db;

};

#endif // OPEDB_H
