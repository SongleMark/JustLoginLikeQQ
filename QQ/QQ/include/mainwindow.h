#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QMouseEvent>
#include <QMessageBox>
#include <QMainWindow>
#include "include/register.h"
#include "include/fogetpassword.h"
#include "include/login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setlabel();   //显示图片
    bool eventFilter(QObject *obj, QEvent *event);

private:
    Ui::MainWindow *ui;
    Register *regist;  //注册类
    FogetPassword *forget;
    Login *login;
    StorageMysql *mysql;
    Login_Info log;

private slots:
    void PushButtonRegist();
    void on_pushButton_login_clicked();
};



#endif // MAINWINDOW_H
