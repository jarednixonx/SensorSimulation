/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: SensorMount.h
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#pragma once

#include "Sensor.h"
#include "Display.h"

// Include files for display data.
#include "CRT.h"
#include "Plotter.h"
#include "Meter.h"

#include <vector>

using namespace std;

class SensorMount
{
public:
	SensorMount();
	~SensorMount();

	void propogateData(vector<Sensor>sensorContainer, vector<Display>displayContainer);

private:

};
