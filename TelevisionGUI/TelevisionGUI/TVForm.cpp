#include "TVForm.h"

TVForm::TVForm(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

TVForm::~TVForm()
{
}

void TVForm::submit()
{
	newtv = new Television;
	newtv->changeModel(ui.lineEdit_model->text().toStdString());
	newtv->changeProducer(ui.lineEdit_producer->text().toStdString());
	newtv->setRating(ui.spinBox_rating->text().toInt());
	newtv->setScreenHeight(ui.spinBox_height->text().toInt());
	newtv->setScreenWidth(ui.spinBox_height->text().toInt());
	newtv->setScreenType(ui.lineEdit_screen->text().toStdString());
	if (ui.radioButton_pwrOn->isChecked()) {
		newtv->turnOn();
		if (ui.radioButton_signalOn->isChecked())
			newtv->turnOnSignal();
		newtv->setScreenBrightness(ui.spinBox_brightness->text().toInt());
	}
	if (ui.radioButton_SpeakersOff->isChecked()) {
		newtv->setSpeakersStatus(false);
	}
	else {
		newtv->setSpeakersStatus(true);
		newtv->setSpeakersVolume(ui.spinBox_volume->text().toInt());
	}

	accept();
}

void TVForm::onTextChange() {
	if (ui.lineEdit_model->text().isEmpty() || ui.lineEdit_producer->text().isEmpty() || ui.lineEdit_screen->text().isEmpty())
		ui.pushButton_add->setEnabled(false);
	else
		ui.pushButton_add->setEnabled(true);
}
