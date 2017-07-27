/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Plotter.cpp
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "Plotter.h"

Plotter::Plotter(Display* tempDisplay)
{
	setDisplayType(tempDisplay->getDisplayType());
	setDisplayCountID(tempDisplay->getDisplayCountID());
	setDisplayID(tempDisplay->getDisplayID());

	InitStruct();
}

Plotter::~Plotter()
{

}

void Plotter::Update(Sensor* sensor)
{
	//cout << "Display Device: " << m_chType << endl;
	cout << string(8, ' ') << "Sensor" << string(2, ' ') << *sensor->getSensorID() << endl;
	cout << string(16, ' ') << "Type = " << sensor->getType() << "   Material = " << sensor->getMaterial() << endl;
	cout << string(16, ' ') << "Current Reading: " << sensor->GenerateData(*sensor->getValueMin(), *sensor->getValueMax()) << " " << sensor->getUnits() << endl << endl;
}