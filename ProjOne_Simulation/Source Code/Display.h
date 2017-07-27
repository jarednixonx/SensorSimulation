/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: Display.h
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#pragma once

#include "Sensor.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Display
{

public:
	Display();
	~Display();

	void Update(Display* display, Sensor* sensor, int Kindex, int data);

	char* getDisplayType();
	int* getDisplayID();
	int* getDisplayCountID();

	void setDisplayType(char* type);
	void setDisplayID(int* id);
	void setDisplayCountID(int* countID);

private:

	char m_chType[32];
	int m_iID[32];
	int m_iCountID;

};

