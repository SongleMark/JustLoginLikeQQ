#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include "include/storage.h"

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();
    void GetValues();     //获取注册信息
    void ClearLineedit(); //注册完成后清除数据

private slots:
    void PushButtonClicked();
    void on_pushButton_quit_clicked();

private:
    Ui::Register *ui;
    StorageMysql *Mysql;
    Register_Info register_s;
    bool PASSWORDFLAG;
};

#endif // REGISTER_H
