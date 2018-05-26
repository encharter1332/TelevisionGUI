/*! \file speakers.cpp
\brief Plik zawierajacy funkcje klasy Speakers
*/
#include "speakers.h"
#include<iostream>
#include<fstream>

Speakers::Speakers()
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor domyslny glosnikow" << endl;
#endif
	volume_level = 50;
	arePlugged = true;
}

Speakers::~Speakers()
{
#ifdef _DEBUG
	cout << "Uruchomiono destruktor glosnikow" << endl;
#endif
}

void Speakers::turnDownVolume()
{
	if (volume_level == 0)
		std::cout << "Glosnosc nie moze zejsc ponizej 0" << endl;
	else
		volume_level--;
}

void Speakers::turnUpVolume()
{
	if (volume_level == 100)
		std::cout << "Glosnosc nie moze byc wyzsza niz 100" << endl;
	else
		volume_level++;
}

void Speakers::showStatus()
{
	if (arePlugged)
		std::cout << "Glosniki sa podlaczone do telewizora" << endl;
	else
		std::cout << "Glosniki nie sa podlaczone do telewizora" << endl;
}

void Speakers::save(fstream &file, Speakers& speakers)
{
	file >> speakers;
}

void Speakers::load(fstream& file, Speakers& speakers)
{
	file >> speakers;
}

ostream & operator<<(std::ostream & stream, Speakers & speakers)
{
	stream << speakers.volume_level<<endl;
	stream << speakers.arePlugged<<endl;
	return stream;
}

istream & operator>>(std::istream & stream, Speakers & speakers)
{
	stream >> speakers.volume_level;
	stream >> speakers.arePlugged;
	return stream;
}
