/*! \file working_params.h
\brief Plik zawierajacy deklaracje zmiennych i funkcji klasy WorkingParams
*/
#pragma once
#include<iostream>
using namespace std;

///Klasa WorkingParams Zawierajaca parametry pracy danego urzadzenia o sygnale czy jasnosci ekranu
class WorkingParams {
private:
	///Zmienna przechowujaca informacje o jasnosci ekranu
	int screen_brightness;
	
	///Zmienna przechowujaca true jesli jest sygnal lub false jesli go nie ma 
	bool signal_status;

public:
	///Konsturktor domyslny
	WorkingParams();
	
	///Destrutor
	~WorkingParams();
	
	///Funkcja wypisujaca pelna informacje o obiekcie
	void showStatus();
	
	///Funkcja ustawiajaca wartosc signal_status na True
	void turnOnSignal();
	
	///Funkcja ustawiajaca wartosc zmiennej signal_sttus na False
	void turnOffSignal();
	
	///Funkcja zwracajaca wartosc  jasnosci ekranu
	int getScreenBrightness() { return screen_brightness; };
	
	///Funkcja zwracajaca wartosc zmiennej signal_status
	bool getSignalStatus() { return signal_status; };
	
	///Funkcja zwiekszajaca jasnosc ekranu o 1
	void turnUpBrightness();
	
	///Funkcja zmniejszajaca wartsc ekranu o 1
	void turnDownBrightness();
	
	///Funkcja zapisujaca do pliku o nazwie file_name parametry workingParams
	void save(string file_name, WorkingParams &workingParams);
	
	///Funkcja wczytujaca ze strumienia file do parametrow workingParams
	void load(fstream &file, WorkingParams &workingParams);

	///Ustawia jasnosc
	void setScreenBrightness(int newBrightness) { screen_brightness = newBrightness; };
	
	///Operator strumieniowy <<
	friend ostream& operator << (ostream &stream, WorkingParams &workingParams);
	
	///Operator strumieniowy >>
	friend istream& operator >> (istream &stream, WorkingParams &workingParams);
};