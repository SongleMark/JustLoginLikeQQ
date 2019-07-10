#ifndef FOGETPASSWORD_H
#define FOGETPASSWORD_H

#include <QWidget>

namespace Ui {
class FogetPassword;
}

class FogetPassword : public QWidget
{
    Q_OBJECT

public:
    explicit FogetPassword(QWidget *parent = 0);
    ~FogetPassword();

private:
    Ui::FogetPassword *ui;
};

#endif // FOGETPASSWORD_H
