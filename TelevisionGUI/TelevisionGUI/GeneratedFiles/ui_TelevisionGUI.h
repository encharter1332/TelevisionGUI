/********************************************************************************
** Form generated from reading UI file 'TelevisionGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELEVISIONGUI_H
#define UI_TELEVISIONGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelevisionGUIClass
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_edit;
    QPushButton *pushButton_save;
    QPushButton *pushButton_load;
    QPushButton *pushButton_add;
    QPushButton *pushButton_delete;
    QLabel *label;
    QListWidget *listWidget_objects;
    QListWidget *listWidget_info;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TelevisionGUIClass)
    {
        if (TelevisionGUIClass->objectName().isEmpty())
            TelevisionGUIClass->setObjectName(QStringLiteral("TelevisionGUIClass"));
        TelevisionGUIClass->resize(774, 470);
        TelevisionGUIClass->setCursor(QCursor(Qt::ArrowCursor));
        centralWidget = new QWidget(TelevisionGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(false);
        graphicsView->setGeometry(QRect(360, 50, 131, 121));
        pushButton_exit = new QPushButton(centralWidget);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(30, 370, 131, 41));
        pushButton_edit = new QPushButton(centralWidget);
        pushButton_edit->setObjectName(QStringLiteral("pushButton_edit"));
        pushButton_edit->setEnabled(false);
        pushButton_edit->setGeometry(QRect(360, 260, 131, 41));
        pushButton_save = new QPushButton(centralWidget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setGeometry(QRect(30, 90, 131, 41));
        pushButton_load = new QPushButton(centralWidget);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));
        pushButton_load->setGeometry(QRect(30, 160, 131, 41));
        pushButton_add = new QPushButton(centralWidget);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setGeometry(QRect(30, 20, 131, 41));
        pushButton_delete = new QPushButton(centralWidget);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));
        pushButton_delete->setEnabled(false);
        pushButton_delete->setGeometry(QRect(360, 190, 131, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(450, 0, 211, 51));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        listWidget_objects = new QListWidget(centralWidget);
        listWidget_objects->setObjectName(QStringLiteral("listWidget_objects"));
        listWidget_objects->setGeometry(QRect(170, 20, 151, 391));
        listWidget_info = new QListWidget(centralWidget);
        listWidget_info->setObjectName(QStringLiteral("listWidget_info"));
        listWidget_info->setEnabled(false);
        listWidget_info->setGeometry(QRect(520, 50, 201, 361));
        listWidget_info->setSelectionMode(QAbstractItemView::NoSelection);
        TelevisionGUIClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(TelevisionGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TelevisionGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TelevisionGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TelevisionGUIClass->setStatusBar(statusBar);

        retranslateUi(TelevisionGUIClass);
        QObject::connect(pushButton_save, SIGNAL(clicked()), TelevisionGUIClass, SLOT(saveObjects()));
        QObject::connect(pushButton_exit, SIGNAL(clicked()), TelevisionGUIClass, SLOT(close()));
        QObject::connect(pushButton_load, SIGNAL(clicked()), TelevisionGUIClass, SLOT(loadObjects()));
        QObject::connect(pushButton_add, SIGNAL(clicked()), TelevisionGUIClass, SLOT(addObjects()));
        QObject::connect(listWidget_objects, SIGNAL(itemClicked(QListWidgetItem*)), TelevisionGUIClass, SLOT(checkIfObjectSelected()));
        QObject::connect(listWidget_objects, SIGNAL(itemClicked(QListWidgetItem*)), TelevisionGUIClass, SLOT(showSelectedObject()));
        QObject::connect(pushButton_delete, SIGNAL(clicked()), TelevisionGUIClass, SLOT(onDeleteClick()));
        QObject::connect(pushButton_edit, SIGNAL(clicked()), TelevisionGUIClass, SLOT(onEditClick()));

        QMetaObject::connectSlotsByName(TelevisionGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *TelevisionGUIClass)
    {
        TelevisionGUIClass->setWindowTitle(QApplication::translate("TelevisionGUIClass", "TelevisionGUI", nullptr));
#ifndef QT_NO_TOOLTIP
        graphicsView->setToolTip(QApplication::translate("TelevisionGUIClass", "<html><head/><body><p>Wybierz obiekt aby wy\305\233wietli\304\207 zdj\304\231cie</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        graphicsView->setWhatsThis(QApplication::translate("TelevisionGUIClass", "<html><head/><body><p>Zdj\304\231cie Obiektu</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_exit->setText(QApplication::translate("TelevisionGUIClass", "Wyj\305\233cie", nullptr));
        pushButton_edit->setText(QApplication::translate("TelevisionGUIClass", "Edytuj obiekt", nullptr));
        pushButton_save->setText(QApplication::translate("TelevisionGUIClass", "Zapisz kolekcje", nullptr));
        pushButton_load->setText(QApplication::translate("TelevisionGUIClass", "Wczytaj kolekcje", nullptr));
        pushButton_add->setText(QApplication::translate("TelevisionGUIClass", "Dodaj nowy obiekt", nullptr));
        pushButton_delete->setText(QApplication::translate("TelevisionGUIClass", "Usun Obiekt", nullptr));
        label->setText(QApplication::translate("TelevisionGUIClass", "Pregladany obiekt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TelevisionGUIClass: public Ui_TelevisionGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELEVISIONGUI_H
