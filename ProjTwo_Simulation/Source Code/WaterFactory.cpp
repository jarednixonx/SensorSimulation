/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: WaterFactory.cpp
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "WaterFactory.h"

WaterFactory::WaterFactory()
{

}

WaterFactory::~WaterFactory()
{

}

WaterFactory *WaterFactory::getInstance()
{
	static WaterFactory *theInstance = NULL;

	if (theInstance == NULL)
	{
		theInstance = new WaterFactory();
	}
	return theInstance;
}

WaterSensor* WaterFactory::CreateSensor(Sensor* tempSensor)
{
	WaterSensor* waterSensor = new WaterSensor(tempSensor);

	return waterSensor;
}