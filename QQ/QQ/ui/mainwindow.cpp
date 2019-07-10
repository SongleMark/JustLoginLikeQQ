#include "include/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#define path ":/image/resource/timg.jpeg"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    move(500,250);
    regist = new Register();  //注册类
    setlabel(); //显示企鹅图片
    forget = new FogetPassword();//忘记密码类
    mysql = StorageMysql::getinstance();

    //响应注册槽函数
    connect(ui->pushButton_register,SIGNAL(clicked(bool)),this,SLOT(PushButtonRegist()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//设置初始企鹅图片 并设置忘记密码按钮
void MainWindow::setlabel()
{
    QImage *image = new QImage;
    setWindowTitle("QQ--松乐19版");

    if(!image->load(path))
    {
        qDebug() << "image->load failed" ;
        delete image;
        return ;
    }

    QSize size = ui->label->size();
    QImage newimage = image->scaled(size,Qt::IgnoreAspectRatio);
    ui->label->setPixmap(QPixmap::fromImage(newimage));

    ui->SetPassword->setText("<u>忘记密码</u>");
    ui->SetPassword->installEventFilter(this); //为忘记密码label安装时间过滤器

}

//点击免费注册按钮时的相应
void MainWindow::PushButtonRegist()
{
    //跳转到注册界面
    regist->show();
}

//重写的eventFilter设置鼠标左键点击SetPassword操作
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->SetPassword)//指定SetPassword
    {
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton)//当点击了鼠标左键
            {
                forget->show();
                return true;
            }
            else
            {
                return false;
            }
         }
         else
         {
            return false;
         }
     }
     else
     {
            // pass the event on to the parent class
            //return QMainWindow::eventFilter(obj, event);
     }
}

//点击登录按钮
void MainWindow::on_pushButton_login_clicked()
{
    QString user = ui->lineEdit_name->text();
    mysql->ConnectMysql();
    //根据输入的用户名从数据库查找密码
    log = mysql->FindFromMysql(user);
    QString input_password = ui->lineEdit_password->text();

    if(user == "" || input_password == "")
    {
        ui->lineEdit_name->setPlaceholderText(QStringLiteral("请输入用户名"));
        ui->lineEdit_password->setPlaceholderText(QStringLiteral("请输入密码"));
        return ;
    }

    if(log.password == input_password)
    {
        login = new Login();
        login->show();
    }
    else
    {
        ui->lineEdit_password->clear();
        ui->lineEdit_password->setPlaceholderText(QStringLiteral("密码输入错误"));
    }

}
