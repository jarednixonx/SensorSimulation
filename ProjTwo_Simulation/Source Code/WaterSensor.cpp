/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: WaterSensor.cpp
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "WaterSensor.h"

WaterSensor::WaterSensor(Sensor* tempSensor)
{
	setType(tempSensor->getType());
	setMaterial(tempSensor->getMaterial());
	setSensorID(tempSensor->getSensorID());
	setUnits(tempSensor->getUnits());
	setValueMax(*tempSensor->getValueMax());
	setValueMin(*tempSensor->getValueMin());
}

WaterSensor::~WaterSensor()
{

}