/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: DisplayFactory.cpp
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "DisplayFactory.h"

DisplayFactory::DisplayFactory()
{

}

DisplayFactory::~DisplayFactory()
{

}

Display* DisplayFactory::CreateDisplay (Display* tempDisplay)
{
	if (strcmp(tempDisplay->getDisplayType(),"CRT") == 0)
	{
		crtDisplay = new CRT(tempDisplay);

		return crtDisplay;
	}
	else if (strcmp(tempDisplay->getDisplayType(), "METER") == 0)
	{
		meterDisplay = new Meter(tempDisplay);

		return meterDisplay;
	}
	else if (strcmp(tempDisplay->getDisplayType(), "PLOTTER") == 0)
	{
		plotterDisplay = new Plotter(tempDisplay);

		return plotterDisplay;
	}
}

DisplayFactory *DisplayFactory::getInstance()
{
	static DisplayFactory *theInstance = NULL;

	if (theInstance == NULL)
	{
		theInstance = new DisplayFactory();
	}
	return theInstance;
}