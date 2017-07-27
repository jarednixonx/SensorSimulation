/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: SensorMount.h
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once

#include "Sensor.h"
#include "Display.h"

#include <vector>

using namespace std;

class SensorMount
{
public:
	~SensorMount();

	void propogateData(vector<Sensor>sensorContainer, vector<Display*>displayContainer);
	static SensorMount *getInstance();

private:
	SensorMount();

};
