/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: Chlorine.h
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#pragma once

#include "Sensor.h"

class Chlorine : public Sensor
{
public:
	Chlorine(Sensor* tempSensor);
	~Chlorine();

private:

};

