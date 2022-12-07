/*
 * runCalculations.cpp
 *
 *  Created on: 3 Dec 2022
 *      Author: jole
 */
#include "sun.h"



//
//	Run all calculations
//
void sun::sunRunCalculations(void)
{
	cout << "Running calculations..." << endl;


	//double	tempJC = jdnGetJdnJulianCentury();
	//jdnSetJdnJulianCentury(jdnGetJdnJulianCenturyNoon());

	sunCalcGeomMeanLongSun();
	/*sunCalcGeomMeanAnomSun();
	sunCalcEccentEarthOrbit();
	sunCalcSunEqOfCtr();
	sunCalcSunTrueLong();
	sunCalcSunTrueAnom();
	sunCalcSunRadVector();
	sunCalcSunAppLong();
	sunCalcMeanObliqEcliptic();
	sunCalcObliqCorr();
	sunCalcSunRtAscen();
	sunCalcSunDeclin();



	sunCalcVarY();
	sunCalcEqOfTime();
	sunCalcHaSunrise();
	sunCalcLocalSolarNoon();
	sunCalcLocalSunRise();
	sunCalcLocalSunSet();

	jdnSetJdnJulianCentury(tempJC);

	sunCalcGeomMeanLongSun();
	sunCalcGeomMeanAnomSun();
	sunCalcEccentEarthOrbit();
	sunCalcSunEqOfCtr();
	sunCalcSunTrueLong();
	sunCalcSunTrueAnom();
	sunCalcSunRadVector();
	sunCalcSunAppLong();
	sunCalcMeanObliqEcliptic();
	sunCalcObliqCorr();
	sunCalcSunRtAscen();
	*/

	return;

}
