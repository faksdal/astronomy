/*
 * aSunCalcGeometricMeanLongitude.cpp
 *
 *  Created on: 10 Dec 2022
 *      Author: jole
 */

#include "aSun.h"

//
// TODO - describe what we're calculating here...
//

void aSun::aSunCalcGeometricMeanLongitude(double T)
{
	aSunGeometricMeanLongitude = fmod(280.46646 + T * (36000.76983 + T * 0.0003032), 360.);

	//
	//	Correct for negative values...
	//
	if(aSunGeometricMeanLongitude < 0)
		aSunGeometricMeanLongitude += 360.;

	return;
}
