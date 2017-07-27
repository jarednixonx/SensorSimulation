/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: AirSensor.h
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once

#include "Sensor.h"

class AirSensor : public Sensor
{
public:

	AirSensor(Sensor* tempSensor);
	~AirSensor();

private:

};
