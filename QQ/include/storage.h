#ifndef STORAGE_H
#define STORAGE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>
#include <QWidget>
#include <QDateTime>
#include <QString>
#include <QVariant>
#include <QDebug>

//数据库相关信息
typedef struct MYSQLInfo
{
    QSqlQuery *query;
    QSqlDatabase db;
}Mysql_Info;

//注册信息
typedef struct RegisterInfo
{
    QString name;    //姓名
    QString password;//密码
    QString birthday;//出生日期
    QString question;//密保问题
    QString phone;   //电话号码
    QString id;      //身份证号
    QString time;    //注册时间
    QString user;    //QQ号
}Register_Info;

typedef struct LoginInfo
{
    QString password;
    QString user;
}Login_Info;

//存入信息MYSQL类
class StorageMysql : public QWidget
{
public:
    static StorageMysql *instance;
    static StorageMysql *getinstance();     //用于单例模式
    ~StorageMysql();
    bool ConnectMysql();                    //连接数据库
    void InsertToMysql(Register_Info info); //插入数据库
    void ReadFromMysql(Register_Info &info);//从数据库读信息
    Login_Info FindFromMysql(QString name); //根据帐号查找密码、昵称
    QString GetUserName();                  //返回昵称
    QString CreateUser(QString name);       //返回生成的qq号码
    QString GetQQuser(QString name);

private:
    StorageMysql();
    Mysql_Info mysql;
    Register_Info register_info;
    Login_Info log;

};

#endif // STORAGE_H
