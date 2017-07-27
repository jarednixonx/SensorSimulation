/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Meter.h
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once

#include "Display.h"

class Meter : public Display
{

public:
	Meter(Display* tempDisplay);
	~Meter();

	//char* getDisplayType();
	//int* getDisplayID();
	//int* getDisplayCountID();

	//void setDisplayType(char* type);
	//void setDisplayID(int* id);
	//void setDisplayCountID(int* countID);

	void Update(Sensor* sensor);

private:

};

