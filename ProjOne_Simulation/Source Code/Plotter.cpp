/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: Plotter.cpp
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#include "Plotter.h"

Plotter::Plotter(Display* tempDisplay)
{
	setDisplayType(tempDisplay->getDisplayType());
	setDisplayCountID(tempDisplay->getDisplayCountID());
	setDisplayID(tempDisplay->getDisplayID());
}

Plotter::~Plotter()
{

}
