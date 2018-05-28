#include "TelevisionGUI.h"
#include<iostream>
#include <string>
#include<fstream>
#include "qfile.h"
#include "qfiledialog.h"
#include "qmessagebox.h"
#include "AddObject.h"

TelevisionGUI::TelevisionGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	drawList();
	disableListView();
}

void TelevisionGUI::loadObjects() {
	fstream file;
	string file_name;
	string line;
	Projector *projectortoload;
	Television *televisiontoload;
	SmartTv *smarttvtoload;
	QString file_obj;
	if (collection.size() != 0) {
		for (int i = 0; i < collection.size(); i++)
			delete collection[i];
		collection.clear();
	}
	file_obj = QFileDialog::getOpenFileName(this, tr("Otworz Kolekcje"), "", tr("Kolekcja (*.clk);;All Files(*)"));
	if (file_obj.isEmpty())
		return;
	file_name = file_obj.toStdString();
	file.open(file_name, ios::in);
	if (file.is_open()) {
		do
		{
			getline(file, line);
			if (line == "Projector") {
				projectortoload = new Projector;
				projectortoload->load(file);
				collection.push_back(projectortoload);
			}
			else if (line == "Television") {
				televisiontoload = new Television;
				televisiontoload->load(file);
				collection.push_back(televisiontoload);
			}
			else if (line == "SmartTV") {
				smarttvtoload = new SmartTv;
				smarttvtoload->load(file);
				collection.push_back(smarttvtoload);
			}

		} while (!file.eof());
	}
	else {
		QMessageBox::information(this, tr("Blad otwarcia pliku"), tr("Nie udalo sie otworzyc pliku sproboj ponownie"));
	}
	file.close();
	disableListView();
	drawList();
}

void TelevisionGUI::disableListView()
{
	ui.listWidget_info->setEnabled(false);
	ui.graphicsView->setEnabled(false);
	ui.pushButton_edit->setEnabled(false);
	ui.pushButton_delete->setEnabled(false);
	ui.listWidget_info->clear();
}

void TelevisionGUI::saveObjects() {
	fstream file;
	string file_name;
	QString file_obj;
	if (collection.size() != 0) {
		file_obj = QFileDialog::getSaveFileName(this, tr("Zapisz kolekcje: "), "", tr("Kolekcja (*.clk);;All Files(*)"));
		if (file_obj.isEmpty()) {
			disableListView();
			return;
		}
		file_name = file_obj.toStdString();
		file.open(file_name, ios::out);
		if (file.is_open()) {
			for (int i = 0; i < collection.size(); i++)
				collection[i]->save(file);
		}
		else {
			QMessageBox::information(this, tr("Blad otwarcia pliku"), tr("Nie udalo sie utworzyc pliku sproboj ponownie"));
		}
		file.close();
	}
	else {
		QMessageBox::information(this, tr("Blad zapisu"), tr("Kolekcja jest pusta, brak danych do zapisu"));
	}
	disableListView();
}

void TelevisionGUI::addObjects() {
	AddObject addWindow;
	setVisible(false);
	addWindow.exec();
	if (addWindow.Accepted) {
		setVisible(true);
		disableListView();
		if (addWindow.getDevicePointer() != nullptr) {
			collection.push_back(addWindow.getDevicePointer());
			drawList();
		}
	}
	
}

void TelevisionGUI::drawList() {
	ui.listWidget_objects->clear();
	for (int i = 0; i < collection.size(); i++)
	{
		ui.listWidget_objects->addItem(QString::fromStdString(collection[i]->wholeDeviceName()));
	}
}

void TelevisionGUI::showSelectedObject(){
	int index = ui.listWidget_objects->currentIndex().row();
	ui.listWidget_info->clear();
	ui.listWidget_info->addItem(QString::fromStdString("Typ urzadzenia: " + collection[index]->getDeviceType()));///<- wypiswanie pol wspolnych
	ui.listWidget_info->addItem(QString::fromStdString("Producent: " + collection[index]->getProducer()));
	ui.listWidget_info->addItem(QString::fromStdString("Model: " + collection[index]->getModel()));
	ui.listWidget_info->addItem(QString::fromStdString("Ocena: " + std::to_string(collection[index]->getRating())));
	ui.listWidget_info->addItem(QString::fromStdString("Typ ekranu: " + collection[index]->getScreenType()));
	ui.listWidget_info->addItem(QString::fromStdString("Rozdzielczosc: " + collection[index]->getScreenSurface()));
	if (collection[index]->getWorkingParams() != NULL) {
		if (collection[index]->getSignal() == true) 
			ui.listWidget_info->addItem(QString::fromStdString("Sygnal: wlaczony"));
		else
			ui.listWidget_info->addItem(QString::fromStdString("Sygnal: wylaczony"));
		ui.listWidget_info->addItem(QString::fromStdString("Jansosc ekranu: " + std::to_string(collection[index]->getScreenBrightness())));
	}
	else 
		ui.listWidget_info->addItem(QString::fromStdString("Urzadzenie wylaczone"));


	if (Television* temporary_tv = dynamic_cast <Television*> (collection[index])) {		/// <- wypisywanie pol wspolnych dla telewizora i SmartTV
		if (temporary_tv->getSpeakersStatus()) {
			ui.listWidget_info->addItem(QString::fromStdString("Glosniki podlaczone"));
			ui.listWidget_info->addItem(QString::fromStdString("Poziom glosnosci: " + std::to_string(temporary_tv->getVolumeLevel())));
		}
		else
			ui.listWidget_info->addItem(QString::fromStdString("Glosniki odlaczone"));
		
		if (SmartTv* temporary_smart = dynamic_cast <SmartTv*> (collection[index])) {    /// <- wypisywanie pol dla SmartTV
			ui.listWidget_info->addItem(QString::fromStdString("Wersja oprogramowania: ").append(QString::number(temporary_smart->getSoftware()))); ///<- pobieramy wartosc software i konwertujemy ja na string 
			ui.listWidget_info->addItem(QString::fromStdString("Aplikacje: "));
			for(auto app : temporary_smart->getApps())
				ui.listWidget_info->addItem(QString::fromStdString(app));
		}
	}
	else if (Projector* temporary_projector = dynamic_cast <Projector*> (collection[index])) {
		ui.listWidget_info->addItem(QString::fromStdString("Wydajnosc lampy: " + std::to_string(temporary_projector->getLampEfficiency()) + "%"));
		ui.listWidget_info->addItem(QString::fromStdString("Rotacja obrazu: " + std::to_string(temporary_projector->getDisplayRotation())).append(QString::fromLatin1("°")));
		ui.listWidget_info->addItem(QString::fromStdString("Przyblizenie obrazu x" + std::to_string(temporary_projector->getDisplayZoom())));
	}

}

void TelevisionGUI::checkIfObjectSelected()
{
	if (ui.listWidget_objects->SelectedClicked) {
		ui.listWidget_info->setEnabled(true);
		ui.graphicsView->setEnabled(true);
		ui.pushButton_edit->setEnabled(true);
		ui.pushButton_delete->setEnabled(true);
	}
	else {
		disableListView();
	}
}

void TelevisionGUI::onDeleteClick() {
	int index = ui.listWidget_objects->currentIndex().row();
	delete collection[index];
	collection.erase(collection.begin()+index);
	disableListView();
	drawList();
}

void TelevisionGUI::onEditClick() {
	int index = ui.listWidget_objects->currentIndex().row();
	AddObject editWindow(collection[index]);
	editWindow.exec();
	setVisible(false);
	if (editWindow.Accepted) {
		delete collection[index];
		collection[index] = editWindow.getDevicePointer();
		disableListView();
		if (collection[index] != nullptr)
			drawList();
		setVisible(true);
		 
	}
}
