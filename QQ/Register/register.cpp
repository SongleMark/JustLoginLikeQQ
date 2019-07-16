#include "include/register.h"
#include "ui_register.h"
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    move(500,250);
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_surePass->setEchoMode(QLineEdit::Password);
    setWindowTitle("免费注册");
    Mysql = StorageMysql::getinstance();
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(PushButtonClicked()));

}

Register::~Register()
{
    delete ui;
}


//获取注册信息
void Register::GetValues()
{
    register_s.name = ui->lineEdit_name->text();
    register_s.birthday = ui->dateEdit->text();
    register_s.id = ui->lineEdit_id->text();
    register_s.password = ui->lineEdit_password->text();
    register_s.phone = ui->lineEdit_phone->text();
    register_s.question = ui->lineEdit_question->text();
#if 0
    if(!register_s.password.contains(QRegExp("[a-z]")) || !register_s.password.contains(QRegExp("[A-Z]")) ||
            !register_s.password.contains(QRegExp("[0-9]")))
    {
        ui->label_pass->setText("密码需有中文和大小写英文共同组成");
        PASSWORDFLAG = false;
    }
    else
    {
        PASSWORDFLAG = true;
    }
#endif
    QString sure = ui->lineEdit_surePass->text();
    if(register_s.password.length() < 6)
    {
        ui->label_pass->setText("输入的密码不能少于6位");
        PASSWORDFLAG = false;
    }
    else if(register_s.password.length() >= 6 && !register_s.password.isEmpty() && register_s.password == sure)
    {
        ui->label_pass->setText("格式正确");
        PASSWORDFLAG = true;
    }
    else if(register_s.password != sure)
    {
        ui->label_surePass->setText("两次输入密码不一致");
        PASSWORDFLAG = false;
    }

    ClearLineedit();
}

//注册完成后清除lineedit数据
void Register::ClearLineedit()
{
    ui->lineEdit_id->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_password->clear();
    ui->lineEdit_phone->clear();
    ui->lineEdit_question->clear();
    ui->lineEdit_surePass->clear();

}

//注册槽函数
void Register::PushButtonClicked()
{
    GetValues();
    Login_Info log;

    int choose;
    choose = QMessageBox::question(this,tr("注册"),QString(tr("是否注册?")),
                                   QMessageBox::Yes|QMessageBox::No);

    if(choose == QMessageBox::Yes && PASSWORDFLAG ==true)
    {
        bool ret = Mysql->ConnectMysql();
        if(!ret)
        {
            qDebug() << "connect mysql error";
            return ;
        }
        else
        {
            Mysql->InsertToMysql(register_s);
           // QDateTime currenttime = QDateTime::currentDateTime();
            //QString user_t = currenttime.toString("yyyyMMddhhmmsszzz");
            QString userr = Mysql->GetQQuser(register_s.name);
            label = new QLabel(this);
            QString user = "你的帐号是:" + userr + "（请务必记下）";
            qDebug() << "user = " << user;
            label->setText(user);
            layout = new QGridLayout(this);
            layout->addWidget(label);

        }
    }
    else if(choose == QMessageBox::No || PASSWORDFLAG == false)
    {
        qDebug() << "没有注册";
        return ;
    }
}

void Register::on_pushButton_quit_clicked()
{
    close();
}
