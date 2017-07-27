/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: SensorMount.cpp
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "SensorMount.h"

SensorMount::SensorMount()
{

}

SensorMount::~SensorMount()
{

}

// Meter Display Device reads Chlorine and HeavyMetal-Cadmium
// CRT Display Device reads Petroleum, Raw Sewage, and Carbon Monoxide
// Plotter Display Device reads Nuclear Waste

void SensorMount::propogateData(vector<Sensor>sensorContainer, vector<Display*>displayContainer)
{
	//int data;

	for (int j = 0; j < (int)displayContainer.size(); j++)
	{
		cout << "Display Device: " << displayContainer[j]->getDisplayType() << endl << endl;

		for (int i = 0; i < (int)sensorContainer.size(); i++)
		{
				for (int k = 0; k < *displayContainer[j]->getDisplayCountID(); k++)
				{
					if (displayContainer[j]->getDisplayID()[k] == *sensorContainer[i].getSensorID())
					{
						if (displayContainer[j]->getStructure()[k].m_bToggle == true)				// Will not output every five seconds if the sensor is unsubscribed.
						{
							displayContainer[j]->Update(&sensorContainer[i]);						// Pass a single sensor to the appropriate display device.
						}
						else
						{
							cout << string(16, ' ') << "Sensor " << displayContainer[j]->getDisplayID()[k] << " is not being monitored" << endl << endl;
						}
					}
				}
		}
	}
}

SensorMount *SensorMount::getInstance()
{
	static SensorMount *theInstance = NULL;

	if (theInstance == NULL)
	{
		theInstance = new SensorMount();
	}
	return theInstance;
}
