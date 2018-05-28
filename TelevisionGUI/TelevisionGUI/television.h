/*! \file television.h
\brief Plik zawierajacy deklaracje zmiennych i funkcji klasy Television
*/
#pragma once

#include<iostream>
#include<string>
#include "speakers.h"
#include "display_device.h"

using namespace std;

///KLasa Television pochodna DisplayDevice
class Television : public DisplayDevice {
private:
	///Zmiennna przehcowujaca ilosc obiektow typu Television
	static int object_amount;

public:
	///Konstruktor domyslny
	Television();
	
	///Konstruktor z parametrami tworzacy obiekt o nazwie producenra "producer" i nazwie modelu "model"
	Television(string producer, string model);
	
	///Destruktor
	~Television();
	
	///Konstruktor kopiujacy
	Television(Television &television);
	
	
	///Funkcja wypisujaca pelna nazwe obiektu
	void showWholeDeviceName();
	
	///Funkcja zmieniajaca wartosc zmiennej model na new_model
	void changeModel(string new_model);
	
	///Funkcja zmieniajaca wartosc zmiennej producer na new_name
	void changeProducer(string new_name);
	
	///Funkcja wypisujaca pelna informacje o obiekcie
	void showStatus();
	
	///Funkcja usuwajaca workingParams z obiektu (wylacza telewizor)
	void turnOff();
	
	///Funkcja dodajaca workingParams do obiektu (wlacza telewizor)
	void turnOn();
	
	///Funkcja wlaczajaca sygnal w workingParams
	void turnOnSignal();
	
	///Funkcja wylaczajaca sygnal w workingParams
	void turnOffSignal();
	
	///Funkcja zapisujaca obiekt do pliku
	void save(fstream &file);
	
	///Funkcja wczytujaca obiekt z pliku
	void load(fstream &file);
	
	///Funkcja zwracajaca ilosc obiektow
	static int getObjectAmount() { return object_amount; };
	
	///Operator ==
	friend bool operator== (Television &television1, Television &television2);
	
	///Operator strumieniowy <<
	friend ostream& operator << (std::ostream &stream, Television &television);
	
	///Operator strumieniowy >>
	friend istream& operator >> (std::istream &stream, Television &television);
	
	///Operator < zwraca True dla telewizora o mniejszej powierzchni ekranu
	bool operator < (Television &television);
	
	///Opertaor > zwraca True dla telewizora o wiekszej powierzchni ekranu
	bool operator > (Television &television);
	
	///Operator || zwraca True jezeli w jednym z telewizorow jest sygnal
	bool operator || (const Television &television);
	
	///Opertaor Television = Television
	Television& operator= (const Television &television);
	
	///Operator + dodaje do siebie wielkosci ekranow telewizora i zwraca telewizor
	Television operator + (Television &television);
	
	///Operator rzutowania na int() zwraca ocene telewizora
	operator int();
	
	///operator [] ustawia na konkretna ocene w zaleznosci od i z przedzialu 1/10
	Television& operator[](int i);
	
	///Operator ++ zwieksza ocene o 1
	Television& operator ++(int);
	
	///Operator -- zmniejsza ocene o 1
	Television& operator --(int);



	///Opcje Speakers
	void setSpeakersVolume(int newVolume) { speakers.setVolume(newVolume); };
	void setSpeakersStatus(bool plugged) { speakers.setPlugged(plugged); };

	///Get Speakers
	bool getSpeakersStatus() { return speakers.getSpeakersStatus(); };
	bool getVolumeLevel() { return speakers.getVolumeLevel(); };

protected:
	
	///zmienna zawierajaca obiekt typu Speakers
	Speakers speakers;

};