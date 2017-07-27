/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: CarbonMonoxide.h
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#pragma once

#include "Sensor.h"

class CarbonMonoxide : public Sensor
{
public:
	CarbonMonoxide(Sensor* tempSensor);
	~CarbonMonoxide();

private:

};


