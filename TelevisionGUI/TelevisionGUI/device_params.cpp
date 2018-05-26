/*! \file device_params.cpp
\brief Plik zawierajacy funkcje klasy DeviceParams
*/
#include "device_params.h"
#include<iostream>
#include<fstream>

DeviceParams::DeviceParams()
{
#ifdef _DEBUG
	std::cout << "Uruchomiono konstruktor Parametrow urzadzenia" << endl;
#endif	
	screen_height = 1080;
	screen_width = 1920;
	screen_type = "LCD";
}

DeviceParams::~DeviceParams()
{
#ifdef _DEBUG
	std::cout << "Uruchomiono destruktor Parametrow urzadzenia" << endl;
#endif	

}



void DeviceParams::setScreenResolution(int new_height, int new_width)
{
	screen_height = new_height;
	screen_width = new_width;
	std::cout << "Zmieniono rozdzielczosc na: " << screen_height << " x " << screen_width << endl;
}

void DeviceParams::setScreenType(string new_type)
{
	screen_type = new_type;
}

void DeviceParams::save(fstream &file, DeviceParams & deviceParams)
{
	file << deviceParams;
}

void DeviceParams::load(fstream &file, DeviceParams & deviceParams)
{
	file>> deviceParams;
}

ostream & operator<<(std::ostream & stream, DeviceParams & deviceParams)
{
	stream << deviceParams.screen_height << endl;
	stream << deviceParams.screen_width << endl;
	stream << deviceParams.screen_type << endl;
	return stream;
}

istream & operator>>(std::istream & stream, DeviceParams & deviceParams)
{
	stream >> deviceParams.screen_height;
	stream >> deviceParams.screen_width;
	stream >> deviceParams.screen_type;
	return stream;
}
