/*
 * aSunCalcRightAscension.cpp
 *
 *  Created on: 12 Dec 2022
 *      Author: jole
 */
#include "aSun.h"
//
// TODO - describe what we're calculating here...
//
void aSun::aSunCalcRightAscension(void)
{
	aSunRightAscension	= DEGREES(atan2(cos(RADIANS(aSunObliquityCorrection)) * sin(RADIANS(aSunApparentLongitude)),
				              cos(RADIANS(aSunApparentLongitude))));

	//
	//	Correct for negative values...
	//
	if(aSunRightAscension < 0)
		aSunRightAscension += 360.;

}
