/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: Simulation.h
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#pragma once

#include "EnviroSimDataParser.h"
#include "Simulation.h"
#include "SensorMount.h"
#include "Sensor.h"
#include "Display.h"

// Include display types.
#include "CRT.h"
#include "Meter.h"
#include "Plotter.h"

// Include sensor types.
#include "Cadmium.h"							// Type: Earth
#include "NuclearWaste.h"						// Type: Earth
#include "CarbonMonoxide.h"						// Type: Air
#include "Chlorine.h"							// Type: Air
#include "RawSewage.h"							// Type: Water
#include "OilResidue.h"							// Type: Water

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
	Simulation();
	~Simulation();

	void initializeSimulation();
	void runSimulation();

protected:

	// Create the specific display objects (Must be protected so sensor mount can send information to the objects)

	CRT* crtDisplay;							// Type: CRT
	Plotter* plotterDisplay;					// Type: Plotter
	Meter* meterDisplay;						// Type: Meter

private:

	Sensor* tempSensor;
	Display* tempDisplay;

	vector<Sensor>sensorContainer;				// Creates a vector container for sensor objects.
	vector<Display>displayContainer;			// Creates a vector container for display objects.
	char m_chInFile[32];						// Variable to hold the name of the input file.

	// Create the specific sensor objects.
	Cadmium* cadmiumSensor;						// Type: Earth
	NuclearWaste* nuclearSensor;				// Type: Earth
	CarbonMonoxide* monoxideSensor;				// Type: Air
	Chlorine* chlorineSensor;					// Type: Air
	OilResidue* residueSensor;					// Type: Water
	RawSewage* sewageSensor;					// Type: Water

	SensorMount* sensorMount;

};