/*
 * aSunCalcTrueGeometricLongitude.cpp
 *
 *  Created on: 11 Dec 2022
 *      Author: jole
 */
#include "aSun.h"
//
// TODO - describe what we're calculating here...
//
void aSun::aSunCalcTrueGeometricLongitude(void)
{
	aSunTrueGeometricLongitude = aSunEquationOfTheCenter + aSunGeometricMeanLongitude;
}
