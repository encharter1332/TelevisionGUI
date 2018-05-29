/*! \file Projector.cpp
\brief Plik zawierajacy funkcje klasy Projector
*/
#include <fstream>
#include "projector.h"

streampos projector_position = 0;///<Zmienna przechowujaca pozycje w pliku
int Projector::object_amount = 0;///<Inicjalizacja zmiennej zawierajacej ilosc obiektow
Projector::Projector()
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor projektora" << endl;
#endif
	object_amount++;
	image.load("Resources/Projector.png");
	device_type = "Projector";
	model = "00kx00";
	producer = "Random";
	deviceParams.setScreenType("Projekcja");
	lamp_efficiency = 100;
	screen_zoom = 1;
	rotation = 0;
	workingParams = NULL;
}

void Projector::showStatus()
{
	cout << device_type << endl;
	showWholeDeviceName();
	cout << "Ocena: " << rating << endl;
	cout << "Rozdzielczosc projekcji to: " << deviceParams.getScreenWidth() << "x" << deviceParams.getScreenHeight() << endl;
	cout << "Typ ekranu to: " << deviceParams.getScreenType() << endl;
	if (workingParams == NULL)
		cout << "Projektor jest wylaczony" << endl;
	else
	{
		cout << "Jasnosc ekranu jest ustawiona na poziom: " << workingParams->getScreenBrightness() << endl;
		workingParams->showStatus();
	}
	cout << "Wydajnosc lampy: " << lamp_efficiency << "%" << endl;
	cout << "Rotacja ekranu: " << rotation << endl;
	cout << "Zoom ekranu: " << screen_zoom << endl <<endl;
}

void Projector::showWholeDeviceName()
{
	cout << producer << " " <<model << endl;
}

void Projector::save(fstream &file)
{
	file << *this;
	cout << "Zapisano projektor" << endl;
}

void Projector::turnOff()
{
	if (workingParams = NULL)
		cout << "Pojektor juz jest wylaczony" << endl;
	else
	{
		delete workingParams;
		workingParams = NULL;
	}
}

void Projector::turnOn()
{
	if (workingParams != NULL)
		cout << "Projektor juz wlaczony" << endl;
	else
	{
		workingParams = new WorkingParams;
	}
}

void Projector::turnOnSignal()
{
	if (workingParams == NULL)
		cout << "Najpierw wlacz projektor" << endl;
	else
		workingParams->turnOnSignal();
}

void Projector::turnOffSignal()
{
	if (workingParams == NULL)
		cout << "Najpierw wlacz projektor" << endl;
	else
		workingParams->turnOffSignal();
}

void Projector::load(fstream &file)
{
	file >> *this;
	cout << "Wczytano projektor" << endl;
}

Projector & Projector::operator=(const Projector & projector)
{
	deviceParams = projector.deviceParams;
	producer = projector.producer;
	model = projector.model;
	rating = projector.rating;
	lamp_efficiency = projector.lamp_efficiency;
	screen_zoom = projector.screen_zoom;
	rotation = projector.rotation;
	if (projector.workingParams == NULL)
		workingParams = projector.workingParams;
	else
	{
		workingParams = new WorkingParams;
		while (workingParams->getScreenBrightness() != projector.workingParams->getScreenBrightness())
		{
			workingParams->turnDownBrightness();
		}
		if (projector.workingParams->getSignalStatus() == true)
			workingParams->turnOnSignal();
		else
			workingParams->turnOffSignal();
	}
	return *this;
}

Projector::~Projector()
{
#ifdef _DEBUG
	cout << "Uruchomiono destruktor projektora" << endl;
#endif
	object_amount--;
	if (workingParams != NULL)
		delete workingParams;
}

std::ostream & operator<<(std::ostream & stream, Projector & projector)
{
	stream << (DisplayDevice&)projector;
	stream << projector.lamp_efficiency << endl;
	stream << projector.screen_zoom << endl;
	stream << projector.rotation << endl;
	if (projector.workingParams == NULL)
		stream << "NULL" << endl;
	else
		stream << *projector.workingParams;
	return stream;
}

std::istream & operator>>(std::istream & stream, Projector & projector)
{
	string line;
	streampos temp_pos;
	stream >> (DisplayDevice&)projector;
	stream >> projector.lamp_efficiency;
	stream >> projector.screen_zoom;
	stream >> projector.rotation;
	getline(stream, line);
	temp_pos = stream.tellg();
	getline(stream, line);
	if (line == "NULL")
		projector.workingParams = NULL;
	else {
		stream.seekg(temp_pos);
		projector.turnOn();
		stream >> *projector.workingParams;
	}

	return stream;
}
