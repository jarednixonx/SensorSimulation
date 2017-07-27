/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Display.h
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once

#include "Sensor.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Toggle
{
	int m_iID;
	bool m_bToggle;
};

class Display
{

public:
	Display();
	~Display();

	void InitStruct();
	Toggle* getStructure();

	virtual void Update(Sensor* sensor);

	char* getDisplayType();
	int* getDisplayID();
	int* getDisplayCountID();

	void setDisplayType(char* type);
	void setDisplayID(int* id);
	void setDisplayCountID(int* countID);

protected:

	char m_chType[32];
	int m_iID[32];
	int m_iCountID;

	Toggle m_aStructure[16];

private:

};

