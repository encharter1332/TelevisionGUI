/*! \file smarttv.h
\brief Plik zawierajacy deklaracje zmiennych i funkcji klasy SmartTv
*/
#pragma once

#include<iostream>
#include<string>
#include <vector>
#include "television.h"

using namespace std;
///Klasa SamrtTv pochodna klasy Television
class SmartTv : public Television{
private:
	///Zmienna przehcowujaca ilosc obiektow typu SmartTv
	static int object_amount;
	
	///Zmienna przechowujaca werjse software'u telewizora
	double software=1.00;
	
	///Kontener typu vector przechowujacy dane typu String ktorymi sa nazwy aplikacji
	vector <string> apps;

public:
	///Konstruktor domyslny
	SmartTv();
	
	///Funkcja zwracajaca zmienna software
	double getSoftware() { return software; };
	
	///Funkcja ustawiajaca software na wartosc new_version
	void updateSoftware(double new_version);
	
	///Funkcja pokazujaca pelna informacje o obiekcie
	void showStatus();
	
	///Funkcja pozwalajaca dodac aplikacje o nazwie app_name na koniec vectora apps 
	void addApp(string app_name);
	
	///Funkcja wczytujaca z pliku 
	void load(fstream &file);
	
	///Funkcja zwraca zmienna object_amount
	static int getObjectAmount() { return object_amount; };
	
	///Funkcja zapisujaca do pliku
	void save(fstream &file); 

	vector <string> getApps() { return apps; };
	
	///Destruktor
	~SmartTv();
	
	///Opertator SmartTv = SmartTv
	SmartTv& operator= (const SmartTv &smarttv);
	
	///Operator strumieniowy <<
	friend ostream& operator << (std::ostream &stream, SmartTv &smarttv);
	
	///Operator strumieniowy >>
	friend istream& operator >> (std::istream &stream, SmartTv &smarttv);
};