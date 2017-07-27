/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: Cadmium.cpp
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#include "Cadmium.h"

Cadmium::Cadmium(Sensor* tempSensor)
{
	setType(tempSensor->getType());
	setMaterial(tempSensor->getMaterial());
	setSensorID(tempSensor->getSensorID());
	setUnits(tempSensor->getUnits());
	setValueMax(*tempSensor->getValueMax());
	setValueMin(*tempSensor->getValueMin());
}

Cadmium::~Cadmium()
{

}
