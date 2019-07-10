#include "include/fogetpassword.h"
#include "ui_fogetpassword.h"

FogetPassword::FogetPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FogetPassword)
{
    ui->setupUi(this);
    setWindowTitle("重置密码");
    move(500,250);
}

FogetPassword::~FogetPassword()
{
    delete ui;
}
