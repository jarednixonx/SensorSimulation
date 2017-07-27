/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Sensor.h
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
*
*   I attest that this program is entirely my own work
*******************************************************************/

#pragma once

#include <stdlib.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <time.h>

class Sensor
{
public:
	Sensor();											// Constructor for Sensor object.
	~Sensor();											// Destructor for Sensor object.

	virtual int GenerateData(double min, double max);	// Generates data for a specific material (Integer value).

	// Define functions for return values from dataParser.

	char* getType();
	char* getMaterial();
	int* getSensorID();
	char* getUnits();
	double* getValueMax();
	double* getValueMin();

	void setType(char* type);
	void setMaterial(char* material);
	void setSensorID(int* id);
	void setUnits(char* units);
	void setValueMax(double max);
	void setValueMin(double min);

protected:

	char m_chType[16];
	char m_chMaterial[16];
	int m_iSensorID;
	char m_chUnits[16];
	double m_dValueMax;
	double m_dValueMin;


private:

};

