/*
 * aSunCalcDeclination.cpp
 *
 *  Created on: 12 Dec 2022
 *      Author: jole
 */
#include "aSun.h"
//
// TODO - describe what we're calculating here...
//
void aSun::aSunCalcDeclination(void)
{
	aSunDeclination	= DEGREES(asin(sin(RADIANS(aSunObliquityCorrection)) *
		                      sin(RADIANS(aSunApparentLongitude))));

}
