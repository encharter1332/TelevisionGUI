/*! \file working_params.cpp
\brief Plik zawierajacy funkcje klasy WorkingParams
*/
#include "working_params.h"
#include <iostream>
#include <fstream>

WorkingParams::WorkingParams()
{
	signal_status = false;
	screen_brightness = 100;
}

WorkingParams::~WorkingParams()
{
#ifdef _DEBUG
	std::cout << "Uruchomiono destruktor parametrow pracy" << std::endl;
#endif
}

void WorkingParams::showStatus()
{
	if (signal_status)
		std::cout << "Sygnal wlaczony" << std::endl;
	else
		std::cout << "Sygnal wylaczony" << std::endl;
}

void WorkingParams::turnOnSignal()
{
	if (signal_status)
		std::cout << "Sygnal juz wlaczony" << std::endl;
	else
		signal_status = true;
}

void WorkingParams::turnOffSignal()
{
	if (!signal_status)
		std::cout << "Sygnal juz wylaczony" << std::endl;
	else
		signal_status = false;
}

void WorkingParams::turnUpBrightness()
{
	if (screen_brightness == 100)
		std::cout << "Nie mozna rozjasnic niz 100" << std::endl;
	else
		screen_brightness++;
}

void WorkingParams::turnDownBrightness()
{
	if (screen_brightness == 0)
		std::cout << "Nie mozna zmniejszyc jasnosci  ponizej 0" << std::endl;
	else
		screen_brightness--;
}

void WorkingParams::save(string file_name, WorkingParams & workingParams)
{
	fstream file(file_name, ios::app);
	file << workingParams;
	file.close();
}

void WorkingParams::load(fstream &file, WorkingParams &workingParams)
{
	file >> workingParams;
}

ostream & operator<<(ostream & stream, WorkingParams& workingParams)
{
	stream << workingParams.signal_status << endl;
	stream << workingParams.screen_brightness << endl;

	return stream;
}

istream & operator >> (istream & stream, WorkingParams & workingParams)
{
	stream >> workingParams.signal_status;
	stream >> workingParams.screen_brightness;

	return stream;
}
