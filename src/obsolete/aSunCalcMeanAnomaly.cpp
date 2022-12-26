/*
 * aSunCalcMeanAnomaly.cpp
 *
 *  Created on: 10 Dec 2022
 *      Author: jole
 */

#include "aSun.h"

//
// TODO - describe what we're calculating here...
//
void aSun::aSunCalcMeanAnomaly(long double T)
{
	aSunMeanAnomaly = fmod((357.52911 + T * (35999.05029 - 0.0001537 * T)), 360.);;

	//
	//	Correct for negative values...
	//
	if(aSunMeanAnomaly < 0)
		aSunMeanAnomaly += 360.;

	return;
}
