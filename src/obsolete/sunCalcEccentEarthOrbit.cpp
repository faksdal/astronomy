/*
 * spCalcEccentEarthOrbit.cpp
 *
 *  Created on: 27 Nov 2022
 *      Author: jole
 *
 *      Calculating the eccentricity of the Earth's orbit to low accuracy as described in
 *      Jean Meeus' Astronomical Algorithms second edition 1998 p.163(25.4)
 *
 *      See: https://en.wikipedia.org/wiki/Orbital_eccentricity
 */


#include "sun.h"



//
// TODO - describe what we're calculating here...
//
void sun::sunCalcEccentEarthOrbit(void)
{
	double T = jdnGetJdnJulianCentury();

	sunEccentEarthOrbit	= 0.016708634 - (T * 0.000042037) - (0.0000001267 * T * T);
}
