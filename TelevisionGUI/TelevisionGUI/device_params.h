/*! \file device_params.h
\brief Plik zawierajacy deklaracje zmiennych i funkcji klasy DeviceParams
*/
#pragma once
#include<string>

using namespace std;
///Klasa Parametrow urzadzenia
class DeviceParams {
private:
	///Zmienna przechowujaca wysokosc ekranu
	int screen_height;
	
	///Zmienna przechowujaca szerokosc ekranu
	int screen_width;
	
	///Zmienna przehcowujaca typ ekranu
	string screen_type;

public:
	///Konstruktor domyslny
	DeviceParams();	
	
	///Destruktor
	~DeviceParams();
	
	///Funkcja zwracajaca wysokosc ekranu
	int getScreenHeight() { return screen_height; };
	
	///FUnkcja ustawiajaca wysokosc ekranu 
	void setScreenHeight(int new_height) { screen_height = new_height; };
	
	///Funkcja zwracajaca szerokosc ekranu
	int getScreenWidth() { return screen_width; };
	
	///Funkcja ustawiajaca szerokosc ekranu
	void setScreenWidth(int new_width) { screen_width = new_width; };
	
	///Funkcja zwracajaca pole powierzchni ekranu
	int getScreenSurface() { return (screen_height*screen_width); };
	
	///Funkcja ustawiajaca wymiary ekranu Wysokosc x Szerokosc
	void setScreenResolution(int new_height, int new_width);
	
	///Funkcja zwracajaca typ ekranu
	string getScreenType() { return screen_type; };
	
	///Funkcja ustawiajaca typ ekranu
	void setScreenType(string new_type);
	
	///Funkcja Zapisujaca parametry do pliku
	void save(fstream &file, DeviceParams &deviceParams);
	
	///Funkcja wczytujaca parametry z pliku 
	void load(fstream &file, DeviceParams &deviceParams);
	
	///Operator strumieniowy <<
	friend ostream& operator << (std::ostream &stream, DeviceParams &deviceParams);
	
	///Operator strumieniowy >>
	friend istream& operator >> (std::istream &stream, DeviceParams &deviceParams);
};