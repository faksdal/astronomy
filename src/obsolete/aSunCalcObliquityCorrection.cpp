/*
 * aSunCalcObliquityCorrection.cpp
 *
 *  Created on: 12 Dec 2022
 *      Author: jole
 */
#include "aSun.h"
//
// TODO - describe what we're calculating here...
//
void aSun::aSunCalcObliquityCorrection(long double T)
{
	aSunObliquityCorrection	=		aSunMeanObliquityOfTheEcliptic
								+	(long double)0.00256 * cos(RADIANS((long double)125.04 - (long double)1934.136 * T));
}

/*
 *
 * see: https://gml.noaa.gov/grad/solcalc/main.js
 *
 * function calcObliquityCorrection(t) {
	var e0 = calcMeanObliquityOfEcliptic(t);
	var omega = 125.04 - 1934.136 * t;
	var e = e0 + 0.00256 * Math.cos(degToRad(omega));
	return e;		// in degrees
}
 */
