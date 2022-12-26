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
void aSun::HA_aSunCalcMeanObliquityOfTheEcliptic(long double T)
{
	double U = T/100.;

	HA_aSunMeanObliquityOfTheEcliptic	=		23 + (26/60) + (21.448/3600)
											-	(4680.93/3600) * U
											-	1.55 * U * U
											+	1999.25 * U * U * U
											-	51.38 * U * U * U * U
											-	249.67 * U * U * U * U * U
											-	39.05 * U * U * U * U * U * U
											+	7.12 * U * U * U * U * U * U * U
											+	27.87 * U * U * U * U * U * U * U * U
											+	5.79 * U * U * U * U * U * U * U * U * U
											+	2.45 * U * U * U * U * U * U * U * U * U * U;
}
