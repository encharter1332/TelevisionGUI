/*! \file smarttv.cpp
\brief Plik zawierajacy funkcje klasy SmartTv
*/
#include "smarttv.h"
#include <fstream>

streampos smarttv_position = 0;///<Zmienna przechowujaca pozycje w pliku
int SmartTv::object_amount = 0;///<Inicjalizacja zmiennej przechowujacej ilosc obiektow

SmartTv::SmartTv()
{
#ifdef _DEBUG
	std::cout << "Uruchomiono konstruktor SmartTV" << endl;
#endif	
	object_amount++;
	device_type = "SmartTV";
	producer = "producer";
	model = "model";
	software = 1.00;
	apps.push_back("HomeApp");
} 

void SmartTv::updateSoftware(double new_version)
{
	std::cout << "Zaktualizowano software z wersji: " << software << "do wersji: " << new_version << endl;
	software = new_version;
}

void SmartTv::showStatus()
{
	std::cout << device_type << std::endl;
	showWholeDeviceName();
	std::cout << "Ocena: " << getRating() << std::endl;
	std::cout << "Wymiary to: " << deviceParams.getScreenWidth() << "x" << deviceParams.getScreenHeight() << std::endl;
	std::cout << "Typ ekranu to: " << deviceParams.getScreenType() << std::endl;
	std::cout << "Wersja software'u to : " << software << std::endl;
	std::cout << "Aplikacje zainstalowane to: " << std::endl;
	for (auto app : apps)
		cout << " - " << app << endl;;
	if (workingParams == NULL)
		std::cout << "Telewizor jest wylaczony" << std::endl;
	else
	{
		std::cout << "Jasnosc ekranu jest ustawiona na poziom: " << workingParams->getScreenBrightness() <<std::endl;
		workingParams->showStatus();
	}
	speakers.showStatus();
	std::cout << "Poziom glosnosci to: " << speakers.getVolumeLevel() <<std::endl << std::endl;
}

void SmartTv::save(fstream &file)
{
	file << *this;
	cout << "Zapisano SmartTv"<<endl;
}

SmartTv::~SmartTv()
{
#ifdef _DEBUG
	cout << "Uruchomiono destruktor SmartTV" << endl;
#endif
	object_amount--;
	if (workingParams != NULL)
		delete workingParams;
}

SmartTv & SmartTv::operator=(const SmartTv & smarttv)
{
	deviceParams = smarttv.deviceParams;
	producer = smarttv.producer;
	model = smarttv.model;
	rating = smarttv.rating;
	software = smarttv.software;
	apps = smarttv.apps;
	if (smarttv.workingParams == NULL)
		workingParams = smarttv.workingParams;
	else
	{
		workingParams = new WorkingParams;
		while (workingParams->getScreenBrightness() != smarttv.workingParams->getScreenBrightness())
		{
			workingParams->turnDownBrightness();
		}
		if (smarttv.workingParams->getSignalStatus() == true)
			workingParams->turnOnSignal();
		else
			workingParams->turnOffSignal();
	}
	return *this;
}

void SmartTv::load(fstream &file)
{
	file >> *this;
	cout << "Wczytano SmartTv" << endl;
}

void SmartTv::addApp(string app_name)
{
	apps.push_back(app_name);
}

std::ostream & operator<<(std::ostream & stream, SmartTv & smarttv)
{
	stream << (Television&)smarttv;
	stream << smarttv.software << endl;
	for (auto app : smarttv.apps)
		stream << app << endl;
	return stream;
}

std::istream & operator>>(std::istream & stream, SmartTv & smarttv)
{
	string line;
	streampos temp_pos;
	stream >> (Television&)smarttv;
	stream >> smarttv.software;
	temp_pos = stream.tellg();
	getline(stream, line);
	while (line != "Television" && line != "Projector" && line != "SmartTV" && line != "") {
		temp_pos = stream.tellg();
		getline(stream, line);
		if (line != "Television" && line != "Projector" && line != "SmartTV" && line != "") {
			smarttv.apps.push_back(line);
		}
	}
		stream.seekg(temp_pos);
	return stream;
}
