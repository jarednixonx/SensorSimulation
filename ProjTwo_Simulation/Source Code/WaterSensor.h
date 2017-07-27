/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: WaterSensor.h
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once

#include "Sensor.h"

class WaterSensor : public Sensor
{
public:
	WaterSensor(Sensor* tempSensor);
	~WaterSensor();

private:

};