/*
 * aSunCalcEquationOfTheCenter.cpp
 *
 *  Created on: 11 Dec 2022
 *      Author: jole
 */
#include "aSun.h"
//
// TODO - describe what we're calculating here...
//	https://en.wikipedia.org/wiki/Equation_of_the_center
//
void aSun::aSunCalcEquationOfTheCenter(long double T)
{
		double M	=	aSunMeanAnomaly;

		aSunEquationOfTheCenter	=		(1.914602 - (0.004817 * T) - (0.000014 * T * T)) * sin(RADIANS(M))
									+	(0.019993 - (0.000101 * T)) * sin(RADIANS(2. * M))
									+	0.000289 * sin(RADIANS(3.* M));
}
