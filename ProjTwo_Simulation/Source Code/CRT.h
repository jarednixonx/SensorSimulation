/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: CRT.h
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once

#include "Display.h"

class CRT : public Display
{
public:

	CRT(Display* tempDisplay);
	~CRT();

	//char* getDisplayType();
	//int* getDisplayID();
	//int* getDisplayCountID();

	//void setDisplayType(char* type);
	//void setDisplayID(int* id);
	//void setDisplayCountID(int* countID);

	void Update(Sensor* sensor);

private:

};

