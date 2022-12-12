/*
 * aSunCalcRadiusVector.cpp
 *
 *  Created on: 11 Dec 2022
 *      Author: jole
 */
#include "aSun.h"
//
// TODO - describe what we're calculating here...
//
void aSun::aSunCalcRadiusVector(void)
{
	double e = aSunEccentricityOfEarthsOrbit;

	aSunRadiusVector =	(1.000001018 * (1. - e * e)) /
						(1. + e * cos(RADIANS(aSunTrueAnomaly)));
}
