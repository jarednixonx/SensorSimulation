/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: SensorMount.cpp
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
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

void SensorMount::propogateData(vector<Sensor>sensorContainer, vector<Display>displayContainer)
{
	int data;

	for (int j = 0; j < (int)displayContainer.size(); j++)
	{
		for (int i = 0; i < (int)sensorContainer.size(); i++)
		{
			if (*displayContainer[j].getDisplayCountID() > 1)
			{
				for (int k = 0; k < (int)sensorContainer.size(); k++)
				{
					if (displayContainer[j].getDisplayID()[k] == *sensorContainer[i].getSensorID())
					{
						data = sensorContainer[i].GenerateData(*sensorContainer[i].getValueMin(), *sensorContainer[i].getValueMax());
						displayContainer[j].Update(&displayContainer[j], &sensorContainer[i], k, data);
					}
				}
			}
			else if (*displayContainer[j].getDisplayID() == *sensorContainer[i].getSensorID())
			{
				int k = 0;
				data = sensorContainer[i].GenerateData(*sensorContainer[i].getValueMin(), *sensorContainer[i].getValueMax());
				displayContainer[j].Update(&displayContainer[j], &sensorContainer[i], k, data);
			}
		}
	}
}


