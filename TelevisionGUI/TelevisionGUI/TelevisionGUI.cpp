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
	drawList();
}

void TelevisionGUI::saveObjects() {
	fstream file;
	string file_name;
	QString file_obj;
	if (collection.size() != 0) {
		file_obj = QFileDialog::getSaveFileName(this, tr("Zapisz kolekcje: "), "", tr("Kolekcja (*.clk);;All Files(*)"));
		if (file_obj.isEmpty())
			return;
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
}

void TelevisionGUI::addObjects() {
	AddObject addWindow;
	setVisible(false);
	addWindow.exec();
	if (addWindow.Accepted)
		setVisible(true);
		if (addWindow.getDevicePointer() != nullptr) {
			collection.push_back(addWindow.getDevicePointer());
			drawList();
		}
	
}

void TelevisionGUI::drawList() {
	ui.listWidget->clear();
	for (int i = 0; i < collection.size(); i++)
	{
		ui.listWidget->addItem(QString::fromStdString(collection[i]->wholeDeviceName()));
	}
}