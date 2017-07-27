/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: AirFactory.cpp
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "AirFactory.h"

AirFactory::AirFactory()
{

}

AirFactory::~AirFactory()
{

}

AirFactory *AirFactory::getInstance()
{
	static AirFactory *theInstance = NULL;

	if (theInstance == NULL)
	{
		theInstance = new AirFactory();
	}
	return theInstance;
}

AirSensor* AirFactory::CreateSensor(Sensor* tempSensor)
{
	AirSensor* airSensor = new AirSensor(tempSensor);

	return airSensor;
}