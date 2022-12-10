/*
 * spCalcGeomMeanAnomSun.cpp
 *
 *  Created on: 26 Nov 2022
 *      Author: jole
 */


#include "sun.h"



//
//	TODO - describe what we're calculating here...
//
void sun::sunCalcGeomMeanAnomSun(void)
{
	double T = jdnGetJdnJulianCentury();

	//spGeomMeanAnomSun	= 357.52911 + T * (35999.05029 - 0.0001537 * T);
	sunGeomMeanAnomSun	= fmod((357.52911 + T * (35999.05029 - 0.0001537 * T)), 360.);
	// just some comment
}



