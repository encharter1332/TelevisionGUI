/*! \file projector.h
\brief Plik zawierajacy deklaracje zmiennych i funkcji klasy Projector
*/
#pragma once
#include  "display_device.h"

using namespace std;

///Klasa Projector pochodna klasy DisplayDevice
class Projector : public DisplayDevice {
private :
	///Zmiena zawierajaca liczbe obiektow
	static int object_amount;
	
	///Zmienna przechowujaca sprawnosc lampy
	int lamp_efficiency;
	
	///Zmienna przechowujaca wartosc zoom'u ekranu
	int screen_zoom;
	
	///Zmienna przechowujaca wartosc rotacji ekranu
	int rotation;

public :
	///Konstruktor
	Projector();
	
	///Funkcja zwracajaca zoom ekranu
	int getDisplayZoom() { return screen_zoom; };
	
	///Funkcja zwracajaca rotacje ekranu
	int getDisplayRotation() { return rotation; };

	///funkcja zwracajaca wydajnosc lampy
	int getLampEfficiency() { return lamp_efficiency; };
	
	///Funkcja ustawiajaca rotacje na wartosc new_rotation
	void setDisplayRotation(double new_rotation) { rotation = new_rotation; }
	
	///Funkcja ustawiajaca zoom na wartosc new_zoom
	void setDisplayZoom(double new_zoom) { screen_zoom = new_zoom; }
	
	///Funkcja wypisujaca wszystkie informacje o danym urzadzeniu
	void showStatus();
	
	///Funkcja wypisujaca pelna nazwe urzadzenia
	void showWholeDeviceName();
	
	///Funkcja zapisujaca do pliku
	void save(fstream &file);
	
	///Funkcja wlaczajaca obiekt(tworzy nowe workingParams)
	void turnOn();
	
	///Funcja usuwajaca workingParams
	void turnOff();
	
	///Funkcja wlaczajaca sygnal w workingParams
	void turnOnSignal();
	
	///Funkcja wylaczajaca sygnal w workingParams
	void turnOffSignal();
	
	///Funkcja wczytujaca z pliku 
	void load(fstream &file);
	
	///Funkcja zwracajaca ilosc obiektow typu Projektor
	static int getObjectAmount() { return object_amount; };
	
	///Operator Projector = Projector
	Projector& operator= (const Projector &projector);
	
	///Operator strumieniowy <<
	friend ostream& operator << (std::ostream &stream, Projector &projector);
	
	///Operator strumieniowy >>
	friend istream& operator >> (std::istream &stream, Projector &projector);

	///Ustaw jasnosc
	void setScreenBrightness(int newBrightness) { workingParams->setScreenBrightness(newBrightness); };
	
	///Destruktor
	~Projector();
};