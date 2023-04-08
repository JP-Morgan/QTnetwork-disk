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
    Q_OBJECT//支持信号槽
public:
    explicit OpeDB(QObject *parent = nullptr);
    //定义为单例
    //在静态的函数中定义静态的函数对象
    static OpeDB& getInstance();
    //初始化数据库
    void init();
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
    //用来链接数据库
    QSqlDatabase m_db;

};

#endif // OPEDB_H
