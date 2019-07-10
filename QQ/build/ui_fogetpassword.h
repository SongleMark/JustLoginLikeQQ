/********************************************************************************
** Form generated from reading UI file 'fogetpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOGETPASSWORD_H
#define UI_FOGETPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FogetPassword
{
public:

    void setupUi(QWidget *FogetPassword)
    {
        if (FogetPassword->objectName().isEmpty())
            FogetPassword->setObjectName(QStringLiteral("FogetPassword"));
        FogetPassword->resize(445, 584);
        FogetPassword->setStyleSheet(QStringLiteral("background-color: rgb(114, 159, 207);"));

        retranslateUi(FogetPassword);

        QMetaObject::connectSlotsByName(FogetPassword);
    } // setupUi

    void retranslateUi(QWidget *FogetPassword)
    {
        FogetPassword->setWindowTitle(QApplication::translate("FogetPassword", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FogetPassword: public Ui_FogetPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOGETPASSWORD_H
