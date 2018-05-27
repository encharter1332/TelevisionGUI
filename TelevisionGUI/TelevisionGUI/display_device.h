/*! \file display_device.h
\brief Plik zawierajacy deklaracje zmiennych i funkcji klasy WorkingParams
*/
#pragma once
#include <iostream>
#include <fstream>
#include "working_params.h"
#include "device_params.h"

using namespace std;

///Klasa abstrakcyjna
class DisplayDevice {
public:
	///Kontruktor domyœlny
	DisplayDevice();
	
	///Destruktor wirtualny
	virtual ~DisplayDevice();
	
	///Procedura wirtualna
	virtual void showWholeDeviceName() = 0;
	
	///Funkcja zwraca w formie String Pelna nazwe obiektu
	string wholeDeviceName();

	///Procedura wirtualna 
	virtual void turnOn() = 0;
	
	///Procedura wirtualna
	virtual void turnOff() = 0;
	
	///Procedura wirtualna
	virtual void showStatus() = 0;
	
	///Procedura wirtualna
	virtual void save(fstream &file); 
	
	///Procedura wirtualna
	virtual void load(fstream &file); 
	
	///Operator strumieniowy <<
	friend ostream& operator << (std::ostream &stream, DisplayDevice &electric_device);
	
	///Operator strumieniowy >>
	friend istream& operator >> (std::istream &stream, DisplayDevice &electric_device);

	///Ustawia ocene
	void setRating(int newRating) { rating = newRating; };

	///Ustawianie DeviceParams
	void setScreenHeight(int newHeight) { deviceParams.setScreenHeight(newHeight); };
	void setScreenWidth(int newWidth) { deviceParams.setScreenWidth(newWidth); };
	void setScreenType(string newType) { deviceParams.setScreenType(newType); };

	///Ustawianie modelu i producenta
	void setModel(string newModel) { model = newModel; };
	void setProducer(string newProducer) { producer = newProducer; };

protected:
	///Klasa Parametry urzadzenia
	DeviceParams deviceParams;
	
	///Zmienna zawierajaca nazwe modelu urzadzenia
	string model;
	
	///Zmienna zawierajaca nazwe producenta urzadzenia
	string producer;
	
	///Zmienna zawierajaca ocene sprzetu z przedzialu 1-10 
	int rating;
	
	///Zmienna zawierajaca nazwe typu urzadzenia
	string device_type;
};