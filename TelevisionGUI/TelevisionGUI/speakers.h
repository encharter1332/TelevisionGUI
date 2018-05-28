/*! \file speakers.h
\brief Plik zawierajacy deklaracje zmiennych i funkcji klasy Speakers
*/
#pragma once
#include<string>
using namespace std;

///Klasa Speakers zawierajaca informacje o glosnikach nalezacych do obiektow
class Speakers {
private:
	///Zmienna przechowujaca poziom glosnosci
	int volume_level ;
	
	///Zmienna zwracajaca true jezeli glosniki sa podpiete w przeciwnym razie false
	bool arePlugged;

public:
	///Konstruktor domyslny
	Speakers();
	
	///Destruktor
	~Speakers();
	
	///Funkcja zwracajaca poziom glosnosci (volume_level)
	int getVolumeLevel() { return volume_level; };

	///Funkcja zwracajaca czyglosniki sa podpiete
	bool getSpeakersStatus() { return arePlugged; };
	
	///Funkcja zmniejszajaca glosnosc o 1 
	void turnDownVolume();
	
	///Funkcja zwiekszajaca glosnosc o 1
	void turnUpVolume();
	
	///Funkcja zwracajaca pelna informacje o obiekcie
	void showStatus();
	
	///Funkcja zapisujaca do pliku o nazwie file_name dane speakers
	void save(fstream &file, Speakers& speakers);
	
	///Funkcja wczytujaca ze strumienia file  do danych speakers
	void load(fstream& file, Speakers& speakers);
	
	///Ustaw glosnosc
	void setVolume(int newVolume) { volume_level = newVolume; };

	///Ustaw czy podpiete
	void setPlugged(bool plugged) { arePlugged = plugged; };

	///Operator strumieniowy <<
	friend ostream& operator << (std::ostream &stream, Speakers &speakers);
	
	///Operator strumieniowy >>1
	friend istream& operator >> (std::istream &stream, Speakers &speakers);


};