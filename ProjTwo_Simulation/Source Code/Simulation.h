/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Simulation.h
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "EnviroSimDataParser.h"
#include "Simulation.h"
#include "SensorMount.h"
#include "Sensor.h"
#include "Display.h"

#include "AirFactory.h"
#include "EarthFactory.h"
#include "WaterFactory.h"

#include "DisplayFactory.h"

#include <sys/types.h>							// needed for the _ftime() function
#include <sys/timeb.h>							// contains definition of _timeb struct
#include <time.h>								// needed for other time functions and structures

#include <vector>								// needed to create vector containers
#include <string>
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

class Simulation
{
public:
	
	~Simulation();

	void initializeSimulation();
	void runSimulation();

	static Simulation *getInstance();

protected:

private:

	AirSensor* airSensor;
	EarthSensor* earthSensor;
	WaterSensor* waterSensor;

	Display* display;

	Sensor* tempSensor;
	Display* tempDisplay;

	vector<Sensor>sensorContainer;				// Creates a vector container for sensor objects.
	vector<Display*>displayContainer;			// Creates a vector container for display objects.
	char m_chInFile[32];						// Variable to hold the name of the input file.

	SensorMount* sensorMount;

	Simulation();

	int m_iNumAir[1];								// Holds number of Air sensors.
	int m_iNumEarth[1];								// Holds number of Earth sensors.
	int m_iNumWater[1];								// Holds number of Water sensors.

	AirFactory* airFactory;							// Object for the Air SINGLETON.
	EarthFactory* earthFactory;						// Object for the Earth SINGLETON.
	WaterFactory* waterFactory;						// Object for the Water SINGLETON.

	DisplayFactory* displayFactory;					// Object for the Display SINGLETON.

	int hit;     // key hit flag
	char ch;     // character key which was hit

	int disp;	// Display device holding the sensor.
	int sens;	// Sensor to unsubscribe or resubscribe.
};