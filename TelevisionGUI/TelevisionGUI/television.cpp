/*! \file television.cpp
\brief Plik zawierajacy funkcje klasy Television
*/
#include<iostream>
#include<string>
#include<fstream>
#include "television.h"

int Television::object_amount = 0; ///<Inicjalizacja zmiennej przechowujacej ilosc obiektow
Television::Television()
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor domyslny telewizora" << endl;
#endif

	image.load("Resources/TV.png");
	device_type = "Television";
	model = "domyslny";
	producer = "domyslny";
	rating = 1;
	object_amount++;
	workingParams = NULL;
}

Television::Television(string new_producer, string new_model)
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor z producentem i modelem telewizora" << endl;
#endif
	model = new_producer;
	producer = new_model;
	rating = 1;
	object_amount++;
	workingParams = NULL;
}

Television::~Television()
{
#ifdef _DEBUG
	cout << "Uruchomiono destruktor  telewizora" << endl;
#endif
	if (workingParams != NULL)
		delete workingParams;
	--object_amount;

}

Television::Television(Television & television)
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor kopiujacy telewizora" << endl;
#endif
	model = television.getModel();
	producer = television.getProducer();
	rating = television.getRating();
	deviceParams = television.deviceParams;
	speakers = television.speakers;
	if (television.workingParams == NULL)
		workingParams = television.workingParams;
	else
	{
		workingParams = new WorkingParams;
		while (workingParams->getScreenBrightness() != television.workingParams->getScreenBrightness())
		{
			workingParams->turnDownBrightness();
		}
		if (television.workingParams->getSignalStatus() == true)
			workingParams->turnOnSignal();
		else
			workingParams->turnOffSignal();
	}
}


void Television::showWholeDeviceName()
{
	cout << producer << " " << model << endl;
}

void Television::changeModel(string new_model)
{
	model = new_model;
}

void Television::showStatus()
{
	cout << device_type << endl;
	showWholeDeviceName();
	cout << "Ocena: " << getRating() << endl;
	cout << "Wymiary to: " << deviceParams.getScreenWidth() << "x" << deviceParams.getScreenHeight() << endl;
	cout << "Typ ekranu to: " << deviceParams.getScreenType() << endl;
	if (workingParams == NULL)
		cout << "Telewizor jest wylaczony" << endl;
	else
	{
		cout << "Jasnosc ekranu jest ustawiona na poziom: " << workingParams->getScreenBrightness() << endl;
		workingParams->showStatus();
	}
	speakers.showStatus();
	cout << "Poziom glosnosci to: " << speakers.getVolumeLevel() << endl << endl;
}


void Television::turnOff()
{
	if (workingParams = NULL)
		cout << "Telewizor juz jest wylaczony" << endl;
	else
	{
		workingParams->~WorkingParams();
		workingParams = NULL;
	}
}

void Television::turnOn()
{
	if (workingParams != NULL)
		cout << "Telewizor juz wlaczony" << endl;
	else
	{
		workingParams = new WorkingParams;
	}
}

void Television::turnOnSignal()
{
	if (workingParams == NULL)
		cout << "Najpierw wlacz telewizor" << endl;
	else
		workingParams->turnOnSignal();
}

void Television::turnOffSignal()
{
	if (workingParams == NULL)
		cout << "Najpierw wlacz telewizor" << endl;
	else
		workingParams->turnOffSignal();
}

void Television::save(fstream &file)
{
	file << *this;
	cout << "Zapisano Telewizor" << endl;
} 

 void Television::load(fstream &file)
{
	file >> *this;
	cout << "Wczytano Telewizor" << endl;
} 

bool operator==(Television &television1, Television &television2)
{
	if (television1.producer == television2.producer && television1.model == television2.model)
		return true;
	else
		return false;
}

std::ostream & operator<<(std::ostream & stream, Television & television)
{
	stream << (DisplayDevice&)television;
	if (television.workingParams == NULL)
		stream << "NULL" << endl;
	else
		stream << *television.workingParams; 
	stream << television.speakers;
	return stream;
}

std::istream & operator>>(std::istream & stream, Television & television)
{
	string line;
	streampos temp_pos;
	stream >> (DisplayDevice&)television;
	getline(stream, line);
	temp_pos = stream.tellg();
	getline(stream, line);
	if (line == "NULL")
		television.workingParams = NULL;
	else {
		stream.seekg(temp_pos);
		television.turnOn();
		stream >> *television.workingParams;
	}
	stream >> television.speakers;
	return stream;
}

bool Television::operator<(Television & television)
{
	if (deviceParams.getScreenSurface() < television.deviceParams.getScreenSurface())
		return true;
	else
		return false;
}

bool Television::operator>(Television & television)
{
	if (deviceParams.getScreenSurface() > television.deviceParams.getScreenSurface())
		return true;
	else
		return false;
}

bool Television::operator||(const Television & television)
{
	if (workingParams->getSignalStatus() || television.workingParams->getSignalStatus() && workingParams != NULL)
		return true;
	else
		return false;
}

Television &Television::operator =(const Television & television)
{
	deviceParams = television.deviceParams;
	producer = television.producer;
	model = television.model;
	rating = television.rating;
	if (television.workingParams == NULL)
		workingParams = television.workingParams;
	else
	{
		workingParams = new WorkingParams;
		while (workingParams->getScreenBrightness() != television.workingParams->getScreenBrightness())
		{
			workingParams->turnDownBrightness();
		}
		if (television.workingParams->getSignalStatus() == true)
			workingParams->turnOnSignal();
		else
			workingParams->turnOffSignal();
	}
	return *this;
}

Television Television::operator+(Television & television)
{
	Television new_television(*this);
	new_television.deviceParams.setScreenHeight(new_television.deviceParams.getScreenHeight() + television.deviceParams.getScreenHeight());
	new_television.deviceParams.setScreenWidth(new_television.deviceParams.getScreenWidth() + television.deviceParams.getScreenWidth());
	return new_television;
}



Television::operator int()
{
	return rating;
}


Television &Television::operator[](int i)
{
	if (i > 10 || i<0)
		cout << "Ocena musi byc z przedzialu 0-10" << endl;
	else
		rating = i;
	return *this;
}


Television &Television::operator++(int)
{
	if (rating == 10)
		cout << "Ocena nie moze byc wyzsza niz 10" << endl;
	else
		rating++;

	return *this;
}

Television & Television::operator--(int)
{
	//zmniejszyc ocene telewizora
	if (rating == 0)
		cout << "Ocenia nie moze byc nizsza niz 10" << endl;
	else
		rating--;

	return *this;
}

void Television::changeProducer(string new_name)
{
	//zmiana nazwy producenta
	producer = new_name;
}
