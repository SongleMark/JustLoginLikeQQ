#include "include/login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    move(500,250);
    mysql = StorageMysql::getinstance();
    mysql->ConnectMysql();
    user = mysql->GetUserName();
    QString show = "欢迎" + user + "登录";
    setWindowTitle(show);
    getInfoFromStorage();

}

Login::~Login()
{
    delete ui;
}

void Login::GetUserName(QString user)
{
    this->user = user;
}

//从数据库匹配登录信息
void Login::getInfoFromStorage()
{
    info.user = user;
    mysql->ReadFromMysql(info);
    ui->label_name->setText(info.name);
    ui->label_user->setText(info.user);
    ui->label_phone->setText(info.phone);
    ui->label_time->setText(info.time);
    ui->label_birthday->setText(info.birthday);
    ui->label_ID->setText(info.id);
    setMainPic();
}

//设置初始头像
void Login::setMainPic()
{
    QImage *image = new QImage;
    if(!image->load(":/image/resource/1-1Z5220UZ5.jpg"))
    {
        delete image;
        qDebug() << "image->load failed";
        return ;
    }

    QSize size = ui->label_pic->size();
    QImage newimage = image->scaled(size,Qt::IgnoreAspectRatio);
    ui->label_pic->setPixmap(QPixmap::fromImage(newimage));
}
