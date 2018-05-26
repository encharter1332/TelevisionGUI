/********************************************************************************
** Form generated from reading UI file 'TVForm.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TVFORM_H
#define UI_TVFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_TVForm
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QFrame *line;
    QFrame *line_2;
    QLineEdit *lineEdit_producer;
    QLineEdit *lineEdit_model;
    QLineEdit *lineEdit_screen;
    QSpinBox *spinBox_rating;
    QSpinBox *spinBox_height;
    QSpinBox *spinBox_width;
    QSpinBox *spinBox_brightness;
    QSpinBox *spinBox_volume;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_add;
    QGroupBox *groupBox_power;
    QRadioButton *radioButton_pwrOn;
    QRadioButton *radioButton_pwrOff;
    QGroupBox *groupBox_signal;
    QRadioButton *radioButton_signalOf;
    QRadioButton *radioButton_signalOn;
    QGroupBox *groupBox_speakers;
    QRadioButton *radioButton_SpeakersOn;
    QRadioButton *radioButton_SpeakersOff;

    void setupUi(QDialog *TVForm)
    {
        if (TVForm->objectName().isEmpty())
            TVForm->setObjectName(QStringLiteral("TVForm"));
        TVForm->resize(400, 574);
        label = new QLabel(TVForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 121, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(TVForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 70, 121, 21));
        label_2->setFont(font);
        label_3 = new QLabel(TVForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 110, 121, 21));
        label_3->setFont(font);
        label_4 = new QLabel(TVForm);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 150, 141, 21));
        label_4->setFont(font);
        label_5 = new QLabel(TVForm);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 190, 131, 21));
        label_5->setFont(font);
        label_6 = new QLabel(TVForm);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 230, 131, 21));
        label_6->setFont(font);
        label_7 = new QLabel(TVForm);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 320, 131, 21));
        label_7->setFont(font);
        label_8 = new QLabel(TVForm);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 350, 131, 21));
        label_8->setFont(font);
        label_9 = new QLabel(TVForm);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 430, 131, 21));
        label_9->setFont(font);
        label_10 = new QLabel(TVForm);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 290, 131, 21));
        label_10->setFont(font);
        label_11 = new QLabel(TVForm);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 400, 131, 21));
        label_11->setFont(font);
        line = new QFrame(TVForm);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(40, 260, 331, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(TVForm);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(40, 380, 331, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        lineEdit_producer = new QLineEdit(TVForm);
        lineEdit_producer->setObjectName(QStringLiteral("lineEdit_producer"));
        lineEdit_producer->setGeometry(QRect(190, 30, 171, 20));
        lineEdit_model = new QLineEdit(TVForm);
        lineEdit_model->setObjectName(QStringLiteral("lineEdit_model"));
        lineEdit_model->setGeometry(QRect(190, 70, 171, 20));
        lineEdit_screen = new QLineEdit(TVForm);
        lineEdit_screen->setObjectName(QStringLiteral("lineEdit_screen"));
        lineEdit_screen->setGeometry(QRect(190, 230, 171, 20));
        spinBox_rating = new QSpinBox(TVForm);
        spinBox_rating->setObjectName(QStringLiteral("spinBox_rating"));
        spinBox_rating->setGeometry(QRect(190, 110, 81, 22));
        spinBox_rating->setMinimum(1);
        spinBox_rating->setMaximum(10);
        spinBox_height = new QSpinBox(TVForm);
        spinBox_height->setObjectName(QStringLiteral("spinBox_height"));
        spinBox_height->setGeometry(QRect(190, 150, 81, 22));
        spinBox_height->setMinimum(1);
        spinBox_height->setMaximum(8000);
        spinBox_height->setSingleStep(100);
        spinBox_width = new QSpinBox(TVForm);
        spinBox_width->setObjectName(QStringLiteral("spinBox_width"));
        spinBox_width->setGeometry(QRect(190, 190, 81, 22));
        spinBox_width->setMinimum(1);
        spinBox_width->setMaximum(8000);
        spinBox_width->setSingleStep(100);
        spinBox_brightness = new QSpinBox(TVForm);
        spinBox_brightness->setObjectName(QStringLiteral("spinBox_brightness"));
        spinBox_brightness->setEnabled(false);
        spinBox_brightness->setGeometry(QRect(170, 320, 81, 22));
        spinBox_brightness->setMinimum(1);
        spinBox_brightness->setMaximum(100);
        spinBox_brightness->setSingleStep(1);
        spinBox_brightness->setValue(100);
        spinBox_volume = new QSpinBox(TVForm);
        spinBox_volume->setObjectName(QStringLiteral("spinBox_volume"));
        spinBox_volume->setEnabled(false);
        spinBox_volume->setGeometry(QRect(170, 430, 81, 22));
        spinBox_volume->setMinimum(1);
        spinBox_volume->setMaximum(100);
        spinBox_volume->setSingleStep(1);
        spinBox_volume->setValue(50);
        pushButton_cancel = new QPushButton(TVForm);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(220, 522, 111, 31));
        pushButton_add = new QPushButton(TVForm);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setEnabled(true);
        pushButton_add->setGeometry(QRect(80, 520, 111, 31));
        groupBox_power = new QGroupBox(TVForm);
        groupBox_power->setObjectName(QStringLiteral("groupBox_power"));
        groupBox_power->setGeometry(QRect(140, 290, 211, 21));
        radioButton_pwrOn = new QRadioButton(groupBox_power);
        radioButton_pwrOn->setObjectName(QStringLiteral("radioButton_pwrOn"));
        radioButton_pwrOn->setGeometry(QRect(10, 0, 82, 21));
        radioButton_pwrOff = new QRadioButton(groupBox_power);
        radioButton_pwrOff->setObjectName(QStringLiteral("radioButton_pwrOff"));
        radioButton_pwrOff->setGeometry(QRect(90, 0, 82, 21));
        radioButton_pwrOff->setChecked(true);
        groupBox_signal = new QGroupBox(TVForm);
        groupBox_signal->setObjectName(QStringLiteral("groupBox_signal"));
        groupBox_signal->setEnabled(true);
        groupBox_signal->setGeometry(QRect(140, 350, 211, 21));
        radioButton_signalOf = new QRadioButton(groupBox_signal);
        radioButton_signalOf->setObjectName(QStringLiteral("radioButton_signalOf"));
        radioButton_signalOf->setEnabled(false);
        radioButton_signalOf->setGeometry(QRect(90, 0, 82, 21));
        radioButton_signalOf->setChecked(true);
        radioButton_signalOn = new QRadioButton(groupBox_signal);
        radioButton_signalOn->setObjectName(QStringLiteral("radioButton_signalOn"));
        radioButton_signalOn->setEnabled(false);
        radioButton_signalOn->setGeometry(QRect(10, 0, 82, 21));
        groupBox_speakers = new QGroupBox(TVForm);
        groupBox_speakers->setObjectName(QStringLiteral("groupBox_speakers"));
        groupBox_speakers->setGeometry(QRect(150, 400, 201, 21));
        radioButton_SpeakersOn = new QRadioButton(groupBox_speakers);
        radioButton_SpeakersOn->setObjectName(QStringLiteral("radioButton_SpeakersOn"));
        radioButton_SpeakersOn->setGeometry(QRect(0, 0, 82, 21));
        radioButton_SpeakersOn->setChecked(false);
        radioButton_SpeakersOff = new QRadioButton(groupBox_speakers);
        radioButton_SpeakersOff->setObjectName(QStringLiteral("radioButton_SpeakersOff"));
        radioButton_SpeakersOff->setGeometry(QRect(90, 0, 82, 21));
        radioButton_SpeakersOff->setChecked(true);

        retranslateUi(TVForm);
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), TVForm, SLOT(close()));
        QObject::connect(radioButton_pwrOn, SIGNAL(toggled(bool)), radioButton_signalOn, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_SpeakersOn, SIGNAL(toggled(bool)), spinBox_volume, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_pwrOn, SIGNAL(toggled(bool)), spinBox_brightness, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_pwrOn, SIGNAL(toggled(bool)), radioButton_signalOf, SLOT(setEnabled(bool)));
        QObject::connect(lineEdit_model, SIGNAL(textChanged(QString)), TVForm, SLOT(onTextChange()));
        QObject::connect(lineEdit_producer, SIGNAL(textChanged(QString)), TVForm, SLOT(onTextChange()));
        QObject::connect(lineEdit_screen, SIGNAL(textChanged(QString)), TVForm, SLOT(onTextChange()));
        QObject::connect(pushButton_add, SIGNAL(clicked()), TVForm, SLOT(submit()));

        QMetaObject::connectSlotsByName(TVForm);
    } // setupUi

    void retranslateUi(QDialog *TVForm)
    {
        TVForm->setWindowTitle(QApplication::translate("TVForm", "TVForm", nullptr));
        label->setText(QApplication::translate("TVForm", "Producent:", nullptr));
        label_2->setText(QApplication::translate("TVForm", "Model:", nullptr));
        label_3->setText(QApplication::translate("TVForm", "Ocena:", nullptr));
        label_4->setText(QApplication::translate("TVForm", "Wysokosc ekranu:", nullptr));
        label_5->setText(QApplication::translate("TVForm", "Szerokosc ekranu:", nullptr));
        label_6->setText(QApplication::translate("TVForm", "Typ ekranu: ", nullptr));
        label_7->setText(QApplication::translate("TVForm", "Jasnosc ekranu:", nullptr));
        label_8->setText(QApplication::translate("TVForm", "Sygnal:", nullptr));
        label_9->setText(QApplication::translate("TVForm", "Glosnosc:", nullptr));
        label_10->setText(QApplication::translate("TVForm", "Zasilanie :", nullptr));
        label_11->setText(QApplication::translate("TVForm", "Glosniki :", nullptr));
        lineEdit_producer->setText(QApplication::translate("TVForm", "domyslny", nullptr));
        lineEdit_model->setText(QApplication::translate("TVForm", "domyslny", nullptr));
        lineEdit_screen->setText(QApplication::translate("TVForm", "domyslny", nullptr));
        pushButton_cancel->setText(QApplication::translate("TVForm", "Anuluj", nullptr));
        pushButton_add->setText(QApplication::translate("TVForm", "Dodaj", nullptr));
        groupBox_power->setTitle(QString());
        radioButton_pwrOn->setText(QApplication::translate("TVForm", "Wlaczone", nullptr));
        radioButton_pwrOff->setText(QApplication::translate("TVForm", "Wylaczone", nullptr));
        groupBox_signal->setTitle(QString());
        radioButton_signalOf->setText(QApplication::translate("TVForm", "Wylaczony", nullptr));
        radioButton_signalOn->setText(QApplication::translate("TVForm", "Wlaczony", nullptr));
        groupBox_speakers->setTitle(QString());
        radioButton_SpeakersOn->setText(QApplication::translate("TVForm", "Podpiete", nullptr));
        radioButton_SpeakersOff->setText(QApplication::translate("TVForm", "Odpiete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TVForm: public Ui_TVForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TVFORM_H
