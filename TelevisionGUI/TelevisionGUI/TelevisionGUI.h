#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TelevisionGUI.h"
#include "television.h"
#include "smarttv.h"
#include "device_params.h"
#include "working_params.h"
#include "display_device.h"
#include "projector.h"
#include "speakers.h"
#include <vector>

class TelevisionGUI : public QMainWindow
{
	Q_OBJECT

public:
	TelevisionGUI(QWidget *parent = Q_NULLPTR);

	void disableListView();

	public slots:
		void loadObjects();
		void saveObjects();
		void addObjects();
		void drawList();
		void showSelectedObject();
		void checkIfObjectSelected();
		void onDeleteClick();
		void onEditClick();

private:
	Ui::TelevisionGUIClass ui;
	vector <DisplayDevice*> collection;
};
