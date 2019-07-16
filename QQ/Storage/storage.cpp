#include "include/storage.h"
#include <QMessageBox>
#define TABLE "register"

StorageMysql *StorageMysql::instance = nullptr;

//用于构造单例模式
StorageMysql *StorageMysql::getinstance()
{
    if(instance == nullptr)
    {
        instance = new StorageMysql();
    }

    return instance;
}

//构造
StorageMysql::StorageMysql()
{
}

//析构
StorageMysql::~StorageMysql()
{
}

//连接数据库
bool StorageMysql::ConnectMysql()
{
    mysql.db = QSqlDatabase::addDatabase("QMYSQL");
    mysql.db.setHostName("localhost");
    mysql.db.setPort(3306);
    mysql.db.setDatabaseName("QQINFO");
    mysql.db.setUserName("root");
    mysql.db.setPassword("123456");

    if(!mysql.db.open())
    {
        QMessageBox::critical(0,QObject::tr("无法打开数据库"),"无法打开数据库" , QMessageBox::Cancel);
        return false;
    }

    mysql.query = new QSqlQuery(mysql.db);
    return true;
}

//注册信息
/*
typedef struct RegisterInfo
{
    QString name;    //姓名
    QString password;//密码
    QString birthday;//出生日期
    QString question;//密保问题
    QString phone;   //电话号码
    QString id;      //身份证号
}Register_Info;*/
//向数据库插入信息
void StorageMysql::InsertToMysql(Register_Info info)
{
    QStringList tables = mysql.db.tables();

    //先看是否存在表 不存在则创建
    if(!tables.contains(TABLE))
    {
        QString sqlcreat = QString("CREATE TABLE register(name varchar(32) not null default 'QQ2019',"
                                   " password varchar(32) not null default '123456',"
                                   " birthday varchar(32) not null default '2019-7-9',"
                                   " question varchar(40) not null default 'abcdefg',"
                                   " phone varchar(32) not null default '11111111111',"
                                   " id varchar(32)  primary key not null default '340825************',"
                                   " time varchar(32) not null default '2019-07-09',"
                                   " user varchar(32) not null default '123456789');");
        qDebug() << "sqlcreat = " << sqlcreat;
        mysql.query->exec(sqlcreat);
    }

    //查看id是否已经注册
    QString sql_check = QString("select count(id) from register where id='%1';").arg(info.id);
    qDebug() << "sql_check = " << sql_check;
    mysql.query->exec(sql_check);
    if(mysql.query->next())
    {
        int count = mysql.query->value(0).toInt();
        if(count >= 1)
        {
            //CommonFlag = false;
            QMessageBox::information(NULL,"已经注册","该身份证号已经注册",
                                    QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
            return ;
        }
    }

    //插入数据
    QDateTime currenttime = QDateTime::currentDateTime();
    QString time = currenttime.toString("yyyy-MM-dd||hh:mm:ss.zzz");
    QString user = currenttime.toString("yyyyMMddhhmmsszzz");
    QString sql = QString("insert into register values('%1' , '%2' , '%3' , '%4' , '%5' , '%6' , '%7','%8');")
                          .arg(info.name)
                          .arg(info.password)
                          .arg(info.birthday)
                          .arg(info.question)
                          .arg(info.phone)
                          .arg(info.id)
                          .arg(time)
                          .arg(user);
    qDebug() << "sql = " << sql;
    mysql.query->exec(sql);
}

//查看数据
void StorageMysql::ReadFromMysql(Register_Info &info)
{
    QString sql = QString("select * from register where name='%1';").arg(info.user);
    qDebug() << "sql = " << sql;

    mysql.query->exec(sql);

    if(mysql.query->next())
    {
        info.name = mysql.query->value(0).toString();
        info.password = mysql.query->value(1).toString();
        info.birthday = mysql.query->value(2).toString();
        info.question = mysql.query->value(3).toString();
        info.phone = mysql.query->value(4).toString();
        info.id = mysql.query->value(5).toString();
        info.time = mysql.query->value(6).toString();
        info.user = mysql.query->value(7).toString();
    }
    qDebug() << "name = " << info.name << "password = " << info.password
             << "birthday = " << info.birthday << "question = " << info.question
             << "phone = " << info.question << "id = " << info.id << "time = " << info.time
             << "QQuser = " << info.user;

}

//根据帐号从数据库匹配
Login_Info StorageMysql::FindFromMysql(QString name)
{
    QString sql_p = QString("select password from register where user='%1';").arg(name);
    qDebug() << "sql = " << sql_p ;
    QString sql_u = QString("select name from register where user='%1'").arg(name);
    qDebug() << "sql_u" << sql_u;


    mysql.query->exec(sql_p);
    if(mysql.query->next())
    {
        log.password = mysql.query->value(0).toString();
        qDebug() << "password = " << log.password;
    }

    mysql.query->exec(sql_u);
    if(mysql.query->next())
    {
        log.user = mysql.query->value(0).toString();
        qDebug() << "name = " << log.user;
    }
    return log;

}

//返回昵称
QString StorageMysql::GetUserName()
{
    return log.user;
}

QString StorageMysql::GetQQuser(QString name)
{
    QString sql = QString("select user from register where name='%1';").arg(name);
    qDebug() << "sql = " << sql;

    QString user;
    mysql.query->exec(sql);
    if(mysql.query->next())
    {
        user = mysql.query->value(0).toString();
        qDebug() << "query user = " << user;
    }

    return user;
}
