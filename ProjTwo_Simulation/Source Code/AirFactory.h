/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: AirFactory.h
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once

// This class will be implemented as a SINGLETON.

#include "SensorFactory.h"

class AirFactory : public SensorFactory
{
public:
	~AirFactory();

	static AirFactory *getInstance();
	AirSensor* CreateSensor(Sensor* tempSensor);

private:
	AirFactory();

};