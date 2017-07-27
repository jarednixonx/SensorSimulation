/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: WaterFactory.h
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once

// This class will be implemented as a SINGLETON.

#include "SensorFactory.h"

class WaterFactory : public SensorFactory
{
public:
	~WaterFactory();

	static WaterFactory *getInstance();
	WaterSensor* CreateSensor(Sensor* tempSensor);

private:
	WaterFactory();
	int instanceNumber;

};