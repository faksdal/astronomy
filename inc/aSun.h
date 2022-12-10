/*
 * sunsLongitude.h
 *
 *  Created on: 16 Nov 2022
 *      Author: jole
 *

 *
 *
 *	****************************************************************************************************
 *	The file is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 */

#ifndef __aSun_h__
#define __aSun_h__

using namespace std;

#include <iomanip>
#include <iostream>

#include "julianDay.h"



class aSun : public julianDay {

	bool	aSunVerbose;
	short	aSunTimeZone, aSunFLOATWIDTH, aSunFLOATPRECISION;
	int		aSunDst;


	double	aSunLat, aSunLon;

	//
	//	Calculated properties of the Sun
	//	This values will give you the geocentric planetary positions
	//	See Meeus p.163
	//
	double	aSunGeometricMeanLongitude;		//	Meeus p.163 (25.2)
	double	aSunMeanAnomaly;				//	Meeus p.163 (25.3)
	double	aSunEccentricityOfEarthsOrbit;	//	Meeus p.163 (25.4)
	double	aSunEquationOfTheCenter;		//	Meeus p.164
	double	aSunTrueGeometricLongitude;		//	Meeus p.164
	double	aSunTrueAnomaly;				//	Meeus p.164
	double	aSunRadiusVector;				//	Meeus p.164	(25.5)


	//*************************************************************************
	void	aSunCalcGeometricMeanLongitude(double T);
	void	aSunCalcMeanAnomaly(double T);


	//*************************************************************************
	//	Private, inline functions to calculate back and forth between radians and degrees
	//
	double		RADIANS(double degrees) {return (degrees * M_PI / 180);}
	double		DEGREES(double radians) {return (radians * 180 / M_PI);}
	//***********************************************************************************



public:
	//
	//	Constructor and destructor
	//
	aSun(int _year, short _month, short _day, short _hour, short _minute, short _second, short _tz, double _lat, double _lon, int _dst, bool _verbose);
	//virtual 	~sunsLongitude();

	//***********************************************************************************
	//	Inline functions to retrieve data member values
	//
	double	aSunGetGeometricMeanLongitude(void)	{ return aSunGeometricMeanLongitude; }
	double	aSunGetMeanAnomaly(void)			{ return aSunMeanAnomaly; }
	//***********************************************************************************

};

#endif	//	__aSun_h__
