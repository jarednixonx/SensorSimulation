/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Simulation.cpp
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
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
	airFactory = AirFactory::getInstance();
	earthFactory = EarthFactory::getInstance();
	waterFactory = WaterFactory::getInstance();

	displayFactory = DisplayFactory::getInstance();

	sensorMount = SensorMount::getInstance();

	tempSensor = new Sensor();
	tempDisplay = new Display();
}

Simulation::~Simulation()
{
	delete sensorMount;
	delete tempSensor;
}

// Function used to build all of the sensors required.

void Simulation::initializeSimulation()
{
	cout << string(62, '=') << endl;
	cout << "|      ENVIRONMENTAL SENSORS SIMULATION DEMONSTRATION        |" << endl;
	cout << "|            CS 307 -- Programming Assignment 2              |" << endl;
	cout << string(62, '=') << endl;

	cout << "Please enter the name of the simulation data file then press Enter: ";

	cin.getline(m_chInFile, 32, '\n');

	EnviroSimDataParser* dataParser = EnviroSimDataParser::getInstance();
	dataParser->initDataParser(m_chInFile);

	int m_iCounterDisplay = 0;

	dataParser->getSensorCounts(m_iNumEarth, m_iNumAir, m_iNumWater);

	for (int i = 0; i < *m_iNumAir; i++)
	{
		char air[5];
		strcpy(air, "Air");

		tempSensor->setType(air);

		dataParser->getSensorData(tempSensor->getType(), tempSensor->getMaterial(), tempSensor->getSensorID(), tempSensor->getUnits(), tempSensor->getValueMin(), tempSensor->getValueMax());

		airSensor = airFactory->CreateSensor(tempSensor);

		sensorContainer.push_back(*airSensor);
	}

	for (int i = 0; i < *m_iNumEarth; i++)
	{
		char earth[6];
		strcpy(earth, "Earth");

		tempSensor->setType(earth);

		dataParser->getSensorData(tempSensor->getType(), tempSensor->getMaterial(), tempSensor->getSensorID(), tempSensor->getUnits(), tempSensor->getValueMin(), tempSensor->getValueMax());

		earthSensor = earthFactory->CreateSensor(tempSensor);

		sensorContainer.push_back(*earthSensor);
	}

	for (int i = 0; i < *m_iNumWater; i++)
	{
		char water[6];
		strcpy(water, "Water");

		tempSensor->setType(water);

		dataParser->getSensorData(tempSensor->getType(), tempSensor->getMaterial(), tempSensor->getSensorID(), tempSensor->getUnits(), tempSensor->getValueMin(), tempSensor->getValueMax());

		waterSensor = waterFactory->CreateSensor(tempSensor);

		sensorContainer.push_back(*waterSensor);
	}

	while(m_iCounterDisplay < dataParser->getDisplayCount())
	{
		dataParser->getDisplayData(tempDisplay->getDisplayType(), tempDisplay->getDisplayID(), tempDisplay->getDisplayCountID());

		displayContainer.push_back(displayFactory->CreateDisplay(tempDisplay));

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

	cout << "Sensor Mount holds the following display devices: " << endl << endl;

	for (unsigned int i = 0; i < displayContainer.size(); i++)
	{
		cout << string(7, ' ') << "Type = " << displayContainer[i]->getDisplayType() << endl;
		cout << string(15, ' ') << "Sensor 0 ID = " << displayContainer[i]->getDisplayID()[0] << endl;

		if (*displayContainer[i]->getDisplayCountID() > 1)
		{
			for (int j = 1; j < *displayContainer[i]->getDisplayCountID(); j++)
			{
				cout << string(15, ' ') << "Sensor " << j << " ID = " << displayContainer[i]->getDisplayID()[j] << endl;
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

		hit = _kbhit(); //See if a key has been pressed
		if (hit)
		{
			ch = _getch();	// Get the key pressed

			if (ch == 's')
			{
				// Lets output which devices are monitoring and which ones are not.

				cout << "Display Devices" << endl << endl;

				for (unsigned int i = 0; i < displayContainer.size(); i++)
				{
					cout << string(7, ' ') << (i + 1) << "." << " Device " << displayContainer[i]->getDisplayType() << endl;

						for (int k = 0; k < *displayContainer[i]->getDisplayCountID(); k++)
						{
							cout << string(15, ' ') << (k + 1) << "." << " Sensor " << displayContainer[i]->getDisplayID()[k];

							if (displayContainer[i]->getStructure()[k].m_bToggle == true)
							{
								cout << " is monitoring." << endl;
							}
							else
							{
								cout << " not monitoring." << endl;
							}
						}

					}
				// Code for input on subscribe and unsubscribe.

				cin >> disp >> sens;

				for (unsigned int k = 0; k < *displayContainer[disp - 1]->getDisplayCountID(); k++)
				{
					if ((displayContainer[disp - 1]->getStructure()[k].m_bToggle) == true && (displayContainer[disp - 1]->getStructure()[k].m_iID == sens))
					{
						displayContainer[disp - 1]->getStructure()[k].m_bToggle = false;
					}
					else if ((displayContainer[disp - 1]->getStructure()[k].m_bToggle) == false && (displayContainer[disp - 1]->getStructure()[k].m_iID == sens))
					{
						displayContainer[disp - 1]->getStructure()[k].m_bToggle = true;
					}
				}
			}
		}
	}
}	

Simulation *Simulation::getInstance()
{
	static Simulation *theInstance = NULL;

	if (theInstance == NULL)
	{
		theInstance = new Simulation();
	}
	return theInstance;
}