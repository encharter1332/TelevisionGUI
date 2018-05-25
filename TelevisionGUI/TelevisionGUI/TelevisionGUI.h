#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TelevisionGUI.h"

class TelevisionGUI : public QMainWindow
{
	Q_OBJECT

public:
	TelevisionGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::TelevisionGUIClass ui;
};
