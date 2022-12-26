/*
 * aSunApparentLongitude.cpp
 *
 *  Created on: 11 Dec 2022
 *      Author: jole
 */
#include "aSun.h"
//
// TODO - describe what we're calculating here...
//
void aSun::aSunCalcApparentLongitude(long double T)
{
	aSunApparentLongitude	=		aSunTrueGeometricLongitude
								-	0.00569
								-	(0.00478 * sin(RADIANS(125.04 - 1934.136 * T)));
}
