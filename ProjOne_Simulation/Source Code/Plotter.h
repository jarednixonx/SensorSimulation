/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: Plotter.h
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#pragma once

#include "Display.h"

class Plotter : public Display
{

public:
	Plotter(Display* tempDisplay);
	~Plotter();

private:

};

