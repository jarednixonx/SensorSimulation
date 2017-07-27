/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: Simulation.cpp
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#include "Simulation.h"

struct _timeb64
{
	int   dstflag;   // holds a non-zero value if daylight saving time is in effect
	long  millitm;   // time in milliseconds since the last one-second hack
	long  time;      // time in seconds since 00:00:00 1/1/1970
	long  timezone;  // difference in minutes moving west from UTC
};

Simulation::Simulation()
{
	sensorMount = new SensorMount();

	tempSensor = new Sensor();

	tempDisplay = new Display();
}

Simulation::~Simulation()
{
	delete sensorMount;
	delete tempSensor;
	delete cadmiumSensor;
	delete nuclearSensor;
	delete monoxideSensor;
	delete chlorineSensor;
	delete residueSensor;
	delete sewageSensor;
}

// Function used to build all of the sensors required.

void Simulation::initializeSimulation()
{
	cout << string(62, '=') << endl;
	cout << "|      ENVIRONMENTAL SENSORS SIMULATION DEMONSTRATION        |" << endl;
	cout << "|            CS 307 -- Programming Assignment 1              |" << endl;
	cout << string(62, '=') << endl;

	cout << "Please enter the name of the simulation data file then press Enter: ";

	cin.getline(m_chInFile, 32, '\n');
	EnviroSimDataParser* dataParser = new EnviroSimDataParser(m_chInFile);

	int m_iCounterSensors = 0;
	int m_iCounterDisplay = 0;

	while (m_iCounterSensors < dataParser->getSensorCount())
	{
		dataParser->getSensorData(tempSensor->getType(), tempSensor->getMaterial(), tempSensor->getSensorID(), tempSensor->getUnits(), tempSensor->getValueMin(), tempSensor->getValueMax());

		if(strcmp((tempSensor->getType()), "Earth"))
		{
			if(strcmp((tempSensor->getMaterial()), "HeavyMetal-Cadmium"))
			{
				cadmiumSensor = new Cadmium(tempSensor);

				sensorContainer.push_back(*cadmiumSensor);
			}
			else if(strcmp((tempSensor->getMaterial()), "Nuclear Waste"))
			{
				nuclearSensor = new NuclearWaste(tempSensor);
				
				sensorContainer.push_back(*nuclearSensor);
			}
		}
		else if(strcmp((tempSensor->getType()), "Air"))
		{
			if(strcmp((tempSensor->getMaterial()), "Carbon Monoxide"))
			{
				monoxideSensor = new CarbonMonoxide(tempSensor);
				
				sensorContainer.push_back(*monoxideSensor);
			}
			else if(strcmp((tempSensor->getMaterial()), "Chlorine"))
			{
				chlorineSensor = new Chlorine(tempSensor);
				
				sensorContainer.push_back(*chlorineSensor);
			}
		}
		else if(strcmp((tempSensor->getType()), "Water"))
		{
			if(strcmp((tempSensor->getMaterial()), "Petroleum"))
			{
				residueSensor = new OilResidue(tempSensor); 
				
				sensorContainer.push_back(*residueSensor);
			}
			else if(strcmp((tempSensor->getMaterial()), "Raw Sewage"))
			{
				sewageSensor = new RawSewage(tempSensor); 
				
				sensorContainer.push_back(*sewageSensor);
			}
		}

		m_iCounterSensors++;
	}

	while(m_iCounterDisplay < dataParser->getDisplayCount())
	{
		dataParser->getDisplayData(tempDisplay->getDisplayType(), tempDisplay->getDisplayID(), tempDisplay->getDisplayCountID());
		if(strcmp(tempDisplay->getDisplayType(), "CRT"))
		{
			crtDisplay = new CRT(tempDisplay);

			displayContainer.push_back(*crtDisplay);
		}
		else if(strcmp(tempDisplay->getDisplayType(), "Plotter"))
		{
			plotterDisplay = new Plotter(tempDisplay);
			
			displayContainer.push_back(*plotterDisplay);
		}
		else if(strcmp(tempDisplay->getDisplayType(), "Meter"))
		{
			meterDisplay = new Meter(tempDisplay);

			displayContainer.push_back(*meterDisplay);
		}

		m_iCounterDisplay++;
	}

	// Cout some stuff to show all sensors that are being held by sensor mount.

	cout << "Sensor Mount holds the following sensors: " << endl;
	
	for(unsigned int i = 0; i < sensorContainer.size(); i++)
	{
		cout << string(7, ' ') << "Type = " << sensorContainer[i].getType() << string(3, ' ') << "ID = " << *sensorContainer[i].getSensorID() << endl;
		cout << string(15, ' ') << "Material = " << sensorContainer[i].getMaterial() << string(2, ' ') << "Units = " << sensorContainer[i].getUnits() << endl;
		cout << string(15, ' ') << "Min = " << *sensorContainer[i].getValueMin() << string(2, ' ') << "Max = " << *sensorContainer[i].getValueMax() << string(2, ' ') << "Cur = 0" << endl;
	}

	cout << endl;

	cout << "Sensor Mount holds the following display devices: " << endl;

	for (unsigned int i = 0; i < displayContainer.size(); i++)
	{
		cout << string(7, ' ') << "Type = " << displayContainer[i].getDisplayType() << endl;
		cout << string(15, ' ') << "Sensor 0 ID = " << displayContainer[i].getDisplayID()[0] << endl;

		if (*displayContainer[i].getDisplayCountID() > 1)
		{
			for (int j = 1; j < *displayContainer[i].getDisplayCountID(); j++)
			{
				cout << string(15, ' ') << "Sensor " << j << " ID = " << displayContainer[i].getDisplayID()[j] << endl;
			}
		}
	}

	cout << endl << endl;
	cout << "Beginning simulation run..." << endl << endl;
	cout << "================= Running simulation =================" << endl << endl;
	cout << "Press Ctrl-C to terminate the demonstration..." << endl;
	cout << string(54, '=') << endl << endl;
}

void Simulation::runSimulation()
{
	_timeb			tStruct;
	double          thisTime;
	double			startingTime;
	double          outputTime;
	bool            done = false;													// while loop flag
																					// Get start time
	_ftime(&tStruct);

	startingTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0);

	thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0);				// Convert to double
	outputTime = thisTime + 5.0;													// Set next 5 second interval time

	while (!done)																	// Start an eternal loop
	{
		_ftime(&tStruct);															// Get the current time
		thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0);			// Convert to double
																					// Check for 5 second interval to print status to screen
		if (thisTime >= outputTime)
		{
			cout << "The simulation has been running for " << (outputTime - startingTime) << " seconds." << endl << endl;

			sensorMount->propogateData(sensorContainer, displayContainer);				// Call functions to perform actions at 5 second intervals
			
			outputTime += 5.0;														// Set time for next 5 second interval
		}
	}	
}