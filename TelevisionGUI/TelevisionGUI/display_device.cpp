/*! \file display_device.cpp
\brief Plik zawierajacy funkcje klasy DisplayDevice
*/
#include <iostream>
#include <string>
#include <fstream>
#include "display_device.h"

using namespace std;

DisplayDevice::DisplayDevice() {
#ifdef _DEBUG  
	cout << "Wywolano domyslny konstruktor DisplayDevice" << endl;
#endif
	device_type = "domyslny_typ";
}

///Zdefiniowany operator strumieniowy
std::ostream& operator << (std::ostream &stream, DisplayDevice &electric_device) {
	stream << electric_device.device_type << endl;
	stream << electric_device.producer <<endl;
	stream << electric_device.model <<endl;
	stream << electric_device.rating <<endl;
	stream << electric_device.deviceParams;
	return stream;
}

///Zdefiniowany operator strumieniowy
std::istream& operator >> (std::istream& stream, DisplayDevice &electric_device) {
	stream >> electric_device.producer;
	stream >> electric_device.model;
	stream >> electric_device.rating;
	stream >> electric_device.deviceParams;
	return stream;
}

DisplayDevice::~DisplayDevice()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~DisplayDevice" << endl;
#endif
}

string DisplayDevice::wholeDeviceName()
{
	return producer + " " + model;
}

void DisplayDevice::save(fstream & file)
{
	file << *this;
	cout << "Zapisano " << this->device_type <<endl;
}

void DisplayDevice::load(fstream & file)
{
	file >> *this;
	cout << "Wczytano " << this->device_type <<endl;
}
