/*
 * spCalcEqOfTime.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */
#include "aSun.h"
//
// TODO - describe what we're calculating here...
//
//	p.185 Meeus 28.3 low accuracy
//
void aSun::aSunCalcEquationOfTime(void)
{
	aSunEquationOfTime	=	4. * DEGREES(aSunVariableY * sin(2. * RADIANS(aSunGeometricMeanLongitude)) -
							2. * aSunEccentricityOfEarthsOrbit *
							sin(RADIANS(aSunMeanAnomaly)) +
							4. * aSunEccentricityOfEarthsOrbit * aSunVariableY *
							sin(RADIANS(aSunMeanAnomaly)) *
							cos(2. * RADIANS(aSunGeometricMeanLongitude)) -
							0.5 * aSunVariableY * aSunVariableY *
							sin(4 * RADIANS(aSunGeometricMeanLongitude)) -
							1.25 * aSunEccentricityOfEarthsOrbit * aSunEccentricityOfEarthsOrbit *
							sin(2. * RADIANS(aSunMeanAnomaly)));

	//aSunEquationOfTime	=	4;


}
