/********************************************************************************
** Form generated from reading UI file 'AddObject.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOBJECT_H
#define UI_ADDOBJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddObject
{
public:
    QPushButton *pushButton_television;
    QPushButton *pushButton_smarttv;
    QPushButton *pushButton_projector;
    QLabel *label;

    void setupUi(QDialog *AddObject)
    {
        if (AddObject->objectName().isEmpty())
            AddObject->setObjectName(QStringLiteral("AddObject"));
        AddObject->resize(257, 351);
        pushButton_television = new QPushButton(AddObject);
        pushButton_television->setObjectName(QStringLiteral("pushButton_television"));
        pushButton_television->setGeometry(QRect(50, 100, 161, 61));
        pushButton_smarttv = new QPushButton(AddObject);
        pushButton_smarttv->setObjectName(QStringLiteral("pushButton_smarttv"));
        pushButton_smarttv->setGeometry(QRect(50, 180, 161, 61));
        pushButton_projector = new QPushButton(AddObject);
        pushButton_projector->setObjectName(QStringLiteral("pushButton_projector"));
        pushButton_projector->setGeometry(QRect(50, 260, 161, 61));
        label = new QLabel(AddObject);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 50, 151, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        retranslateUi(AddObject);
        QObject::connect(pushButton_television, SIGNAL(clicked()), AddObject, SLOT(newTV()));

        QMetaObject::connectSlotsByName(AddObject);
    } // setupUi

    void retranslateUi(QDialog *AddObject)
    {
        AddObject->setWindowTitle(QApplication::translate("AddObject", "AddObject", nullptr));
        pushButton_television->setText(QApplication::translate("AddObject", "Telewizor", nullptr));
        pushButton_smarttv->setText(QApplication::translate("AddObject", "SmartTV", nullptr));
        pushButton_projector->setText(QApplication::translate("AddObject", "Projektor", nullptr));
        label->setText(QApplication::translate("AddObject", "Wybierz typ obiektu :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddObject: public Ui_AddObject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOBJECT_H
