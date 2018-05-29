/*! \file display_device.h
\brief Plik zawierajacy deklaracje zmiennych i funkcji klasy WorkingParams
*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "qpixmap.h"
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

	///Zwracanie typu urzadzenia
	string getDeviceType() { return device_type; };

	///Zwracanie producenta
	string getProducer() { return producer; };

	///Zwracanie modelu
	string getModel() { return model; };

	///Zwracanie oceny
	int  getRating() { return rating; };

	///Zwracanie deviceParams
	string getScreenType() { return deviceParams.getScreenType(); };
	string getScreenSurface() { return (std::to_string(deviceParams.getScreenWidth()) + " x " + std::to_string(deviceParams.getScreenHeight())); };
	int getScreenHeight() { return deviceParams.getScreenHeight(); };
	int getScreenWidth() { return deviceParams.getScreenWidth(); };

	///Ustaw jasnosc
	void setScreenBrightness(int newBrightness) { workingParams->setScreenBrightness(newBrightness); };

	///Pobieranie wartosci working params
	bool getSignal() { return workingParams->getSignalStatus(); };
	int getScreenBrightness() { return workingParams->getScreenBrightness(); };
	WorkingParams* getWorkingParams() { return workingParams; };

	///Zwroc obraz
	QPixmap getImage() { return image; };
	
protected:
	///Zmienna zawierajaca wskaznik na parametry pracy (WorkingParams)
	WorkingParams * workingParams = NULL;

	///Obraz obiektu
	QPixmap image;
	
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