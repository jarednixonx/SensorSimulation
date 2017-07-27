/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: EarthFactory.cpp
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "EarthFactory.h"

EarthFactory::EarthFactory()
{

}

EarthFactory::~EarthFactory()
{

}

EarthFactory *EarthFactory::getInstance()
{
	static EarthFactory *theInstance = NULL;

	if (theInstance == NULL)
	{
		theInstance = new EarthFactory();
	}
	return theInstance;
}

EarthSensor* EarthFactory::CreateSensor(Sensor* tempSensor)
{
	EarthSensor* earthSensor = new EarthSensor(tempSensor);

	return earthSensor;
}