/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: Main.cpp
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#include "Simulation.h"
#include <iostream>

using namespace std;

int main()
{
	Simulation* sensorSimulation = new Simulation();
	sensorSimulation->initializeSimulation();
	sensorSimulation->runSimulation();

	delete sensorSimulation;

	system("PAUSE");

	return 0;
}