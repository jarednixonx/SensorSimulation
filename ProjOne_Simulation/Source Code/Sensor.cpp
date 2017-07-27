/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: Sensor.cpp
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#include "Sensor.h"

#include <iostream>

using namespace std;

Sensor::Sensor()
{
	srand((unsigned int)(time(NULL)));
}

Sensor::~Sensor()
{

}

int Sensor::GenerateData(double min, double max)
{
	return min + (rand() % (int)(max - min + 1));
}

char* Sensor::getType()
{
	return m_chType;
}

char* Sensor::getMaterial()
{
	return m_chMaterial;
}

int* Sensor::getSensorID()
{
	return &m_iSensorID;
}

char* Sensor::getUnits()
{
	return m_chUnits;
}

double* Sensor::getValueMax()
{
	return &m_dValueMax;
}

double* Sensor::getValueMin()
{
	return &m_dValueMin;
}

void Sensor::setType(char* type)
{
	strcpy(m_chType, type);
}

void Sensor::setMaterial(char* material)
{
	strcpy(m_chMaterial, material);
}

void Sensor::setSensorID(int* id)
{
	m_iSensorID = *id;
}

void Sensor::setUnits(char* units)
{
	strcpy(m_chUnits, units);
}

void Sensor::setValueMax(double max)
{
	m_dValueMax = max;
}

void Sensor::setValueMin(double min)
{
	m_dValueMin = min;
}