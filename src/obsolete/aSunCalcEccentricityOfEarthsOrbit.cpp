/*
 * aSunCalcEccentricityOfEarthsOrbit.cpp
 *
 *  Created on: 10 Dec 2022
 *      Author: jole
 */
#include "aSun.h"
//
// TODO - describe what we're calculating here...
//
void aSun::aSunCalcEccentricityOfEarthsOrbit(long double T)
{
	aSunEccentricityOfEarthsOrbit = 0.016708634 - (T * 0.000042037) - (0.0000001267 * T * T);
}
