/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: Chlorine.cpp
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#include "Chlorine.h"

Chlorine::Chlorine(Sensor* tempSensor)
{
	setType(tempSensor->getType());
	setMaterial(tempSensor->getMaterial());
	setSensorID(tempSensor->getSensorID());
	setUnits(tempSensor->getUnits());
	setValueMax(*tempSensor->getValueMax());
	setValueMin(*tempSensor->getValueMin());
}

Chlorine::~Chlorine()
{

}
