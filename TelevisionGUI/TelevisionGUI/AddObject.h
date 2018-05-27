#pragma once

#include <QDialog>
#include "ui_AddObject.h"
#include "display_device.h"
#include "television.h"
#include "smarttv.h"
#include "projector.h"
#include "vector"

class AddObject : public QDialog
{
	Q_OBJECT

public:
	AddObject(QWidget *parent = Q_NULLPTR);
	~AddObject();
	DisplayDevice* createdDevice = nullptr;
	DisplayDevice* getDevicePointer() { return createdDevice; };

	public slots:
	Television* newTV();
	SmartTv* newSmart();
	Projector* newProjector();
	void checkText();
	void checkAppInput();
	void drawAppList();
	void onAddApp();
	void onRemoveApp();
	void appSelected();
	void submitForm();
	
private:
	Ui::AddObject ui;
	vector <string> apps;
};