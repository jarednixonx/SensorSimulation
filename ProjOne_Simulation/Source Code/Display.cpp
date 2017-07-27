/*******************************************************************
	*   CS 307 Programming Assignment 1
	*   File: Display.cpp
	*   Author: Jared Nixon
	*   Desc: Simulates environmental sensor readings.
	*   Date: 7/12/2016
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/

#include "Display.h"

Display::Display()
{

}

Display::~Display()
{

}

void Display::Update(Display* display, Sensor* sensor, int Kindex, int data)
{
	cout << "Display Device: " << display->getDisplayType() << endl;
	cout << string(8, ' ') << "Sensor " << display->getDisplayID()[Kindex] << endl;
	cout << string(16, ' ') << "Type = " << sensor->getType() << string(2, ' ') << "Material = " << sensor->getMaterial() << endl;
	cout << string(16, ' ') << "Current Reading = " << data << string(2,' ') << sensor->getUnits() << endl << endl;
}

char* Display::getDisplayType()
{
	return m_chType;
}

int* Display::getDisplayID()
{
	return m_iID;
}

int* Display::getDisplayCountID()
{
	return &m_iCountID;
}

void Display::setDisplayType(char* type)
{
	strcpy(m_chType, type);
}

void Display::setDisplayID(int* id)
{
	for (int i = 0; i < m_iCountID; i++)
	{
		m_iID[i] = id[i];
	}
}

void Display::setDisplayCountID(int* countID)
{
	m_iCountID = *countID;
}
