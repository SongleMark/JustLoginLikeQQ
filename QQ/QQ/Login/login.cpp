#include "include/login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    mysql = StorageMysql::getinstance();
    mysql->ConnectMysql();
    user = mysql->GetUserName();
    QString show = "欢迎" + user + "登录";
    setWindowTitle(show);
    move(500,250);
}

Login::~Login()
{
    delete ui;
}

void Login::GetUserName(QString user)
{
    this->user = user;
}
