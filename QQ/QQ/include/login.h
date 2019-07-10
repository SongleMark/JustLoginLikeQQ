#ifndef LOGIN_H
#define LOGIN_H
#include "include/storage.h"
#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void GetUserName(QString user); //获取登录名

private:
    Ui::Login *ui;
    QString user;
    StorageMysql *mysql;

};

#endif // LOGIN_H
