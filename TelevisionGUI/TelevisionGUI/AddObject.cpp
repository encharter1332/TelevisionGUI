#include "AddObject.h"
#include "qlistwidget.h"

AddObject::AddObject(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	drawAppList();
}

AddObject::~AddObject()
{

}

SmartTv* AddObject::newSmart()
{
	SmartTv *new_smart = new SmartTv;
	new_smart->changeModel(ui.lineEdit_model_smart->text().toStdString());
	new_smart->changeProducer(ui.lineEdit_producer_smart->text().toStdString());
	new_smart->setRating(ui.spinBox_rating_smart->text().toInt());
	new_smart->setScreenHeight(ui.spinBox_height_smart->text().toInt());
	new_smart->setScreenWidth(ui.spinBox_height_smart->text().toInt());
	new_smart->setScreenType(ui.lineEdit_screen_smart->text().toStdString());
	if (ui.radioButton_pwrOn_smart->isChecked()) {
		new_smart->turnOn();
		if (ui.radioButton_signalOn_smart->isChecked())
			new_smart->turnOnSignal();
		new_smart->setScreenBrightness(ui.spinBox_brightness_smart->text().toInt());
	}
	if (ui.radioButton_SpeakersOff_smart->isChecked()) {
		new_smart->setSpeakersStatus(false);
	}
	else {
		new_smart->setSpeakersStatus(true);
		new_smart->setSpeakersVolume(ui.spinBox_volume_smart->text().toInt());
	}
	new_smart->updateSoftware(ui.doubleSpinBox_soft->text().toDouble());
	for (auto app : apps) {
		new_smart->addApp(app);
	}
	
	return new_smart;
}

Projector* AddObject::newProjector()
{
	Projector *new_projector = new Projector;
	new_projector->setModel(ui.lineEdit_model_projector->text().toStdString());
	new_projector->setProducer(ui.lineEdit_producer_projector->text().toStdString());
	new_projector->setRating(ui.spinBox_rating_projector->text().toInt());
	new_projector->setScreenHeight(ui.spinBox_height_projector->text().toInt());
	new_projector->setScreenWidth(ui.spinBox_height_projector->text().toInt());
	if (ui.radioButton_pwrOn_projector->isChecked()) {
		new_projector->turnOn();
		if (ui.radioButton_signalOn_projector->isChecked())
			new_projector->turnOnSignal();
		new_projector->setScreenBrightness(ui.spinBox_brightness_projector->text().toInt());
	}

	return new_projector;
}

void AddObject::drawAppList() {
	ui.listWidget_apps->clear();
	for (int i = 0; i < apps.size(); i++)
	{
		ui.listWidget_apps->addItem(QString::fromStdString(apps[i]));
	}
}

void AddObject::onAddApp()
{
	apps.push_back(ui.lineEdit_apps->text().toStdString());
	drawAppList();
}

void AddObject::onRemoveApp()
{
	QModelIndex selectionIndex = ui.listWidget_apps->currentIndex();
	int appIndex = selectionIndex.row();
	if (appIndex != 0)
		apps.erase(apps.begin() + appIndex);
	else
		apps.erase(apps.begin());
	ui.pushButton_removeapp->setEnabled(false);
	drawAppList();
}

void AddObject::appSelected() {
	if (ui.listWidget_apps->SelectedClicked)
		ui.pushButton_removeapp->setEnabled(true);
	else
		ui.pushButton_removeapp->setEnabled(false);

}

void AddObject::submitForm()
{
	if (ui.tabWidget->currentIndex() == 0)
		createdDevice = newTV();
	else if (ui.tabWidget->currentIndex() == 1)
		createdDevice = newProjector();
	else if (ui.tabWidget->currentIndex() == 2)
		createdDevice = newSmart();

	accept();
}

void AddObject::checkText()
{
	if (ui.tabWidget->currentIndex() == 0) {
		if (ui.lineEdit_model->text().isEmpty() || ui.lineEdit_producer->text().isEmpty() || ui.lineEdit_screen->text().isEmpty())
			ui.pushButton_add->setEnabled(false);
		else
			ui.pushButton_add->setEnabled(true);

	}
	else if (ui.tabWidget->currentIndex() == 1) {
		if (ui.lineEdit_model_projector->text().isEmpty() || ui.lineEdit_producer_projector->text().isEmpty())
			ui.pushButton_add->setEnabled(false);
		else
			ui.pushButton_add->setEnabled(true);
	}
	else if (ui.tabWidget->currentIndex() == 2) {
		if (ui.lineEdit_model_smart->text().isEmpty() || ui.lineEdit_producer_smart->text().isEmpty() || ui.lineEdit_screen_smart->text().isEmpty())
			ui.pushButton_add->setEnabled(false);
		else
			ui.pushButton_add->setEnabled(true);

	}
}

void AddObject::checkAppInput()
{
	if (ui.lineEdit_apps->text().isEmpty())
		ui.pushButton_addapp->setEnabled(false);
	else
		ui.pushButton_addapp->setEnabled(true);
}

 
Television* AddObject::newTV(){
	Television *new_tv = new Television;
	new_tv->changeModel(ui.lineEdit_model->text().toStdString());
	new_tv->changeProducer(ui.lineEdit_producer->text().toStdString());
	new_tv->setRating(ui.spinBox_rating->text().toInt());
	new_tv->setScreenHeight(ui.spinBox_height->text().toInt());
	new_tv->setScreenWidth(ui.spinBox_height->text().toInt());
	new_tv->setScreenType(ui.lineEdit_screen->text().toStdString());
	if (ui.radioButton_pwrOn->isChecked()) {
		new_tv->turnOn();
		if (ui.radioButton_signalOn->isChecked())
			new_tv->turnOnSignal();
		new_tv->setScreenBrightness(ui.spinBox_brightness->text().toInt());
	}
	if (ui.radioButton_SpeakersOff->isChecked()) {
		new_tv->setSpeakersStatus(false);
	}
	else {
		new_tv->setSpeakersStatus(true);
		new_tv->setSpeakersVolume(ui.spinBox_volume->text().toInt());
	}

	return new_tv;
}
