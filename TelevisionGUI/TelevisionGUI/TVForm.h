#pragma once

#include <QDialog>
#include "ui_TVForm.h"
#include "television.h"

class TVForm : public QDialog
{
	Q_OBJECT

public:
	TVForm(QWidget *parent = Q_NULLPTR);
	~TVForm();
	Television* getPointer() { return newtv; };

	public slots:
	void onTextChange();
	void submit();
	

private:
	Ui::TVForm ui;
	Television *newtv = nullptr;
};
