#include "AddObject.h"
#include "TVForm.h"

AddObject::AddObject(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

AddObject::~AddObject()
{

}

void AddObject::newSmart()
{

}

void AddObject::newProjector()
{

}
 
void AddObject::newTV(){
	TVForm form;
	form.exec();
	if (form.Accepted) {
		createdDevice = form.getPointer();
	}
	accept();
}
