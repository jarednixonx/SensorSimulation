/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: EarthFactory.cpp
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once

// This class will be implemented as a SINGLETON.

#include "SensorFactory.h"

class EarthFactory : public SensorFactory
{
public:	
	~EarthFactory();

	static EarthFactory *getInstance();
	EarthSensor* CreateSensor(Sensor* tempSensor);

private:
	EarthFactory();
	int instanceNumber;

};