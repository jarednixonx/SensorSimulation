/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: DisplayFactory.h
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once

#include "Display.h"
#include "CRT.h"
#include "Meter.h"
#include "Plotter.h"

class DisplayFactory
{
public:
	~DisplayFactory();
	static DisplayFactory *getInstance();

	Display* CreateDisplay(Display* tempDisplay);

private:
	DisplayFactory();

	CRT* crtDisplay;
	Meter* meterDisplay;
	Plotter* plotterDisplay;
};