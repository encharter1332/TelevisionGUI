#pragma once

#include <QDialog>
#include "ui_AddObject.h"
#include "display_device.h"
#include "television.h"
#include "smarttv.h"
#include "projector.h"

class AddObject : public QDialog
{
	Q_OBJECT

public:
	AddObject(QWidget *parent = Q_NULLPTR);
	~AddObject();
	DisplayDevice* createdDevice = nullptr;
	DisplayDevice* getDevicePointer() { return createdDevice; };

	public slots:
	void newTV();
	void newSmart();
	void newProjector();
	
private:
	Ui::AddObject ui;
};