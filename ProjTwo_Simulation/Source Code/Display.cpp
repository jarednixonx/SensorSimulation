/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Display.cpp
*   Author: Jared Nixon
*   Desc: Simulates environmental sensor readings.
*   Date: 7/29/2016
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

void Display::Update(Sensor* sensor)
{

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

void Display::InitStruct()
{
	for (int i = 0; i < m_iCountID; i++)
	{
		m_aStructure[i].m_bToggle = true;
		m_aStructure[i].m_iID = m_iID[i];
	}
}

Toggle* Display::getStructure()
{
	return m_aStructure;
}