/*
 * aSunCalcMeanObliquityOfTheEcliptic.cpp
 *
 *  Created on: 12 Dec 2022
 *      Author: jole
 */
#include "aSun.h"
//
// TODO - describe what we're calculating here...
//
void aSun::aSunCalcMeanObliquityOfTheEcliptic(double T)
{
	aSunMeanObliquityOfTheEcliptic	= 23. + (26. + ((21.448 - T * (46.815 + T * (0.00059 - T * 0.001813)))) / 60.) / 60.;
}
