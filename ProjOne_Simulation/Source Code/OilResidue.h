/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: OilResidue.h
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#pragma once

#include "Sensor.h"

class OilResidue : public Sensor
{
public:
	OilResidue(Sensor* tempSensor);
	~OilResidue();

private:

};

