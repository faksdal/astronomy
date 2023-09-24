/*
 * aSunCalcCelestial.cpp
 *
 *  Created on: 23 Dec 2022
 *      Author: jole
 */
#include "aSun.h"
//
// TODO - describe what we're calculating here...
//
void aSun::aSunCalcCelestial(long double T)
{
	//*************************************************************************
	//
	//	Calculate the Sun's mean geometric longitude
	//
	aSunGeometricMeanLongitude = fmod((long double)280.4664567 + T * ((long double)36000.76983 + T * (long double)0.0003032), (long double)360.);
	//aSunGeometricMeanLongitude = fmod(280.4664567 + T * (36000.76983 + T * 0.0003032), 360.);
	//
	//	Correct for negative values...
	//
	if(aSunGeometricMeanLongitude < 0)
		aSunGeometricMeanLongitude += 360.;
	//aSunCalcGeometricMeanLongitude(T);
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate the mean anomaly of the Sun
	//
	aSunMeanAnomaly = fmod(((long double)357.52911 + T * ((long double)35999.05029 - (long double)0.0001537 * T)), (long double)360.);
	//
	//	Correct for negative values...
	//
	if(aSunMeanAnomaly < 0)
		aSunMeanAnomaly += 360.;
	//aSunCalcMeanAnomaly(T);
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate the eccentricity of Earths orbit around the Sun
	//
	aSunEccentricityOfEarthsOrbit = 0.016708634 - (T * 0.000042037) - (0.0000001267 * T * T);
	//aSunCalcEccentricityOfEarthsOrbit(T);
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate the Sun's equation of center
	//
	long double M	=	aSunMeanAnomaly;

	aSunEquationOfTheCenter	=		(1.914602 - (0.004817 * T) - (0.000014 * T * T)) * sin(RADIANS(M))
								+	(0.019993 - (0.000101 * T)) * sin(RADIANS(2. * M))
								+	0.000289 * sin(RADIANS(3.* M));
	//aSunCalcEquationOfTheCenter(T);
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate the true geometric longitude of the Sun
	aSunTrueGeometricLongitude = aSunEquationOfTheCenter + aSunGeometricMeanLongitude;
	//
	//aSunCalcTrueGeometricLongitude();
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate the true anomaly of the Sun
	aSunTrueAnomaly = fmod((aSunMeanAnomaly + aSunEquationOfTheCenter), (long double)360);
	//
	//aSunCalcTrueAnomaly();
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate the Sun's radius vector, e.g. the ditance from center of the Sun to the center of Earth
	long double e = aSunEccentricityOfEarthsOrbit;

	aSunRadiusVector =	(1.000001018 * (1. - e * e)) /
						(1. + e * cos(RADIANS(aSunTrueAnomaly)));
	//
	//aSunCalcRadiusVector();
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate the Sun's apparent longitude λ (lambda)
	//
	aSunApparentLongitude	=		aSunTrueGeometricLongitude
								-	0.00569
								-	(0.00478 * sin(RADIANS(125.04 - 1934.136 * T)));
	//aSunCalcApparentLongitude(T);
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate the mean obliquity of the ecliptic
	//
	aSunMeanObliquityOfTheEcliptic	= 23. + (26. + ((21.448 - T * (46.815 + T * (0.00059 - T * 0.001813)))) / 60.) / 60.;
	//aSunCalcMeanObliquityOfTheEcliptic(T);
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate the mean obliquity of the ecliptic the high accuracy
	//
	long double U = T/100.;

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
	//HA_aSunCalcMeanObliquityOfTheEcliptic(T);
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate the obliquity correction
	//
	aSunObliquityCorrection	=		aSunMeanObliquityOfTheEcliptic
								+	(long double)0.00256 * cos(RADIANS((long double)125.04 - (long double)1934.136 * T));

	/*
	 *
	 * see: https://gml.noaa.gov/grad/solcalc/main.js
	 *
	 * function calcObliquityCorrection(t) {
		var e0 = calcMeanObliquityOfEcliptic(t);
		var omega = 125.04 - 1934.136 * t;
		var e = e0 + 0.00256 * Math.cos(degToRad(omega));
		return e;		// in degrees
	}
	 */
	//aSunCalcObliquityCorrection(T);
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate the Sun's right ascension
	//
	aSunRightAscension	= DEGREES(atan2(cos(RADIANS(aSunObliquityCorrection)) * sin(RADIANS(aSunApparentLongitude)),
				              cos(RADIANS(aSunApparentLongitude))));
	//	Correct for negative values...
	//
	if(aSunRightAscension < 0)
		aSunRightAscension += 360.;
	//
	//aSunCalcRightAscension();
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate the Sun's declination
	//
	aSunDeclination	= DEGREES(asin(sin(RADIANS(aSunObliquityCorrection)) *
		                      sin(RADIANS(aSunApparentLongitude))));
	//aSunCalcDeclination();
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate variable Y
	aSunVariableY	=		tan(RADIANS(aSunObliquityCorrection/2.))
						*	tan(RADIANS(aSunObliquityCorrection/2.));
	//
	//aSunCalcVariableY();
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate the equation of time
	//
	aSunEquationOfTime	=	4. * DEGREES(aSunVariableY * sin(2. * RADIANS(aSunGeometricMeanLongitude)) -
							2. * aSunEccentricityOfEarthsOrbit *
							sin(RADIANS(aSunMeanAnomaly)) +
							4. * aSunEccentricityOfEarthsOrbit * aSunVariableY *
							sin(RADIANS(aSunMeanAnomaly)) *
							cos(2. * RADIANS(aSunGeometricMeanLongitude)) -
							0.5 * aSunVariableY * aSunVariableY *
							sin(4 * RADIANS(aSunGeometricMeanLongitude)) -
							1.25 * aSunEccentricityOfEarthsOrbit * aSunEccentricityOfEarthsOrbit *
							sin(2. * RADIANS(aSunMeanAnomaly)));
	//	aSunCalcEquationOfTime();
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate HASunrise
	//
	aSunHaSunrise	=	DEGREES(acos(cos(RADIANS(90.833))
					/	(cos(RADIANS(aSunLat))
					*	cos(RADIANS(aSunDeclination)))
					-	tan(RADIANS(aSunLat))
					*	tan(RADIANS(aSunDeclination))));

		if(isnan(aSunHaSunrise)){
			aSunHaSunrise = -1.;
			cout << "No sunrise/sunset!" << endl;
		}
	//	Calculate HASunrise
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate Local Solar Noon
	//
	aSunLocalSolarNoon	= (720. + (aSunDst) - (4. * aSunLon) - aSunEquationOfTime + (aSunTimeZone * 60.)) / 1440.;
	//
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate local sunrise time
	//
	aSunLocalSunRise		= aSunLocalSolarNoon - ((aSunHaSunrise * 4.) / 1440.);
	//
	//*************************************************************************


	//*************************************************************************
	//
	//	Calculate local sunset time
	//
	aSunLocalSunSet = aSunLocalSolarNoon + ((aSunHaSunrise * 4.) / 1440.);
	//
	//*************************************************************************

}	//	void aSun::aSunCalcCelestial(long double T)
