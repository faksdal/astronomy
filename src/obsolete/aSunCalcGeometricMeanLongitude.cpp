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

void aSun::aSunCalcGeometricMeanLongitude(long double T)
{
	//aSunGeometricMeanLongitude = fmod(280.46646 + T * (36000.76983 + T * 0.0003032), 360.);
	aSunGeometricMeanLongitude = fmod(280.4664567 + T * (36000.76983 + T * 0.0003032), 360.);

	cout << "geomeanlong: " << aSunGeometricMeanLongitude << endl;

	//
	//	Correct for negative values...
	//
	if(aSunGeometricMeanLongitude < 0)
		aSunGeometricMeanLongitude += 360.;

	cout << "geomeanlong: " << aSunGeometricMeanLongitude << endl;
	return;
}
