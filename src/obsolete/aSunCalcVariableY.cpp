/*
 * spCalcVarY.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */
#include "aSun.h"



//
// TODO - describe what we're calculating here...
//
void aSun::aSunCalcVariableY(void)
{
	aSunVariableY	=		tan(RADIANS(aSunObliquityCorrection/2.))
						*	tan(RADIANS(aSunObliquityCorrection/2.));


}
