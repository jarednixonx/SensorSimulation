/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: Sensor.h
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
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

	virtual void setType(char* type);
	virtual void setMaterial(char* material);
	virtual void setSensorID(int* id);
	virtual void setUnits(char* units);
	virtual void setValueMax(double max);
	virtual void setValueMin(double min);

protected:

	char m_chType[32];
	char m_chMaterial[32];
	int m_iSensorID;
	char m_chUnits[32];
	double m_dValueMax;
	double m_dValueMin;

private:

};

