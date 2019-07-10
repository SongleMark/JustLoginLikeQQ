/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label_3;
    QLabel *label_pass;
    QLabel *label_surePass;
    QPushButton *pushButton;
    QPushButton *pushButton_quit;
    QLabel *label_6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QWidget *widget2;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QLineEdit *lineEdit_question;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *lineEdit_phone;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLineEdit *lineEdit_id;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_password;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_surePass;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(587, 713);
        Register->setStyleSheet(QStringLiteral("background-color: rgb(114, 159, 207);"));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(56, 300, 81, 41));
        label_pass = new QLabel(Register);
        label_pass->setObjectName(QStringLiteral("label_pass"));
        label_pass->setGeometry(QRect(400, 500, 161, 31));
        label_pass->setStyleSheet(QStringLiteral(""));
        label_surePass = new QLabel(Register);
        label_surePass->setObjectName(QStringLiteral("label_surePass"));
        label_surePass->setGeometry(QRect(400, 550, 161, 31));
        label_surePass->setStyleSheet(QStringLiteral(""));
        pushButton = new QPushButton(Register);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 640, 89, 25));
        pushButton_quit = new QPushButton(Register);
        pushButton_quit->setObjectName(QStringLiteral("pushButton_quit"));
        pushButton_quit->setGeometry(QRect(70, 640, 89, 25));
        label_6 = new QLabel(Register);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(-4, -4, 591, 181));
        label_6->setStyleSheet(QStringLiteral("background-color: rgb(138, 226, 52);"));
        widget = new QWidget(Register);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 190, 321, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        horizontalLayout->addWidget(lineEdit_name);

        widget1 = new QWidget(Register);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(71, 250, 321, 41));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        dateEdit = new QDateEdit(widget1);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        horizontalLayout_2->addWidget(dateEdit);

        widget2 = new QWidget(Register);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(160, 300, 231, 91));
        verticalLayout = new QVBoxLayout(widget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(widget2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        lineEdit_question = new QLineEdit(widget2);
        lineEdit_question->setObjectName(QStringLiteral("lineEdit_question"));

        verticalLayout->addWidget(lineEdit_question);

        widget3 = new QWidget(Register);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(70, 390, 321, 191));
        verticalLayout_2 = new QVBoxLayout(widget3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(widget3);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        lineEdit_phone = new QLineEdit(widget3);
        lineEdit_phone->setObjectName(QStringLiteral("lineEdit_phone"));

        horizontalLayout_5->addWidget(lineEdit_phone);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(widget3);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        lineEdit_id = new QLineEdit(widget3);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));

        horizontalLayout_6->addWidget(lineEdit_id);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(widget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_password = new QLineEdit(widget3);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));

        horizontalLayout_3->addWidget(lineEdit_password);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(widget3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        lineEdit_surePass = new QLineEdit(widget3);
        lineEdit_surePass->setObjectName(QStringLiteral("lineEdit_surePass"));

        horizontalLayout_4->addWidget(lineEdit_surePass);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("Register", "<html><head/><body><p align=\"center\">\345\257\206\344\277\235\351\227\256\351\242\230</p></body></html>", Q_NULLPTR));
        label_pass->setText(QString());
        label_surePass->setText(QString());
        pushButton->setText(QApplication::translate("Register", "\347\241\256\350\256\244\346\263\250\345\206\214", Q_NULLPTR));
        pushButton_quit->setText(QApplication::translate("Register", "\345\217\226\346\266\210", Q_NULLPTR));
        label_6->setText(QApplication::translate("Register", "<html><head/><body><p><img src=\":/image/resource/1-1Z5220UZ5.jpg\"/></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "<html><head/><body><p align=\"center\">\346\230\265\347\247\260</p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Register", "<html><head/><body><p align=\"center\">\345\207\272\347\224\237\346\227\245\346\234\237</p></body></html>", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Register", "\346\210\221\347\232\204\345\260\217\345\255\246\346\225\231\345\270\210\345\217\253\344\273\200\344\271\210", Q_NULLPTR)
         << QApplication::translate("Register", "\346\210\221\346\234\200\345\226\234\346\254\242\347\232\204\345\256\240\347\211\251", Q_NULLPTR)
         << QApplication::translate("Register", "\346\210\221\347\232\204\345\256\266\344\271\241\345\234\250\345\223\252\351\207\214", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("Register", "<html><head/><body><p align=\"center\">\345\257\206\344\277\235\346\211\213\346\234\272</p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("Register", "<html><head/><body><p align=\"center\">\350\272\253\344\273\275\350\257\201\345\217\267</p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("Register", "<html><head/><body><p align=\"center\">\345\257\206\347\240\201\357\274\232</p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("Register", "<html><head/><body><p align=\"center\">\350\257\267\347\241\256\350\256\244</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
