/*
 * sunCalcSunEqOfCtr.cpp
 *
 *  Created on: 28 Nov 2022
 *      Author: jole
 *
 *      
 *
 */

#include "sun.h"



//
// TODO - describe what we're calculating here...
//
void sun::sunCalcSunEqOfCtr(void)
{
	double T	=	jdnGetJdnJulianCentury();
	double M	=	sunGeomMeanAnomSun;

	sunSunEqOfCtr	=		(1.914602 - (0.004817 * T) - (0.000014 * T * T)) * sin(RADIANS(M))
						+	(0.019993 - (0.000101 * T)) * sin(RADIANS(2. * M))
						+	0.000289 * sin(RADIANS(3.* M));

}
