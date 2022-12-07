/*
 * sun.h
 *
 *  Created on: 16 Nov 2022
 *      Author: jole
 *
 *  Class sunpos builds on class jdnMeeus1998, and calculates the suns position based on the Julian Day Number from
 *  the jdn class.
 *
 *  Constructor parameters, inherited from class jdn:
 * 		jdnYear:	the year as an integer, i.e. 2022 or -1, and so forth...
 * 		jdnMonth:	the month as a short, 1 = January, 2 = February and so forth...
 * 		jdnDay:		the day of the month
 *		jdnHour:	the hour of the day, 0-23, local time
 *		jdnMinute:	the minute of the hour 0-59, local time
 *		jdnSecond:	the second of the minute, 0-59, local time
 *
 *	Constructor parameters, native:
 *		tz:			timezone
 *  	dst:		daylight savings time, minutes (e.g. 0 or 60)
 *		lat:		the latitude we want to calculate for, given as decimal degrees, dd.ddddd°
 *		lon:		the longitude we want to calculate, given as decimal degrees, dd.ddddd°
 *
 *
 *	Data members:
 *  	geomMeanLongSun:
 *		geomMeanAnomSun:
 *		eccentEarthOrbit:
 *		sunEqOfCtr:
 *		sunTrueLong:
 *		sunTrueAnom:
 *		sunRadVector:
 *		sunAppLong:
 *		meanObliqEcliptic:
 *		obliqCorr:
 *		sunRtAscen:
 *		sunDeclin:
 *		varY:
 *		eqOfTime:
 *		haSunrise:
 *		localSolarNoon:
 *		localSunRise:
 *		localSunSet:
 *
 *
 *
 *	****************************************************************************************************
 *	The file is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 */

#ifndef __sun_h__
#define __sun_h__

using namespace std;

#include <iomanip>
#include <iostream>

#include "julianDay.h"



class sun : public julianDay {

	short		sunTz;
	int			sunDst, sunFLOATWIDTH, sunFLOATPRECISION;
	bool		sunVerbose;


	double		sunGeomMeanLongSun,
				sunGeomMeanAnomSun,
				sunEccentEarthOrbit,
				sunSunEqOfCtr,
				sunSunTrueLong,
				sunSunTrueAnom,
				sunSunRadVector,
				sunSunAppLong,
				sunMeanObliqEcliptic,
				sunObliqCorr,
				sunSunRtAscen,
				sunSunDeclin,
				sunVarY,
				sunEqOfTime,
				sunHaSunrise,
				sunLocalSolarNoon,
				sunLocalSunRise,
				sunLocalSunSet,
				sunLat,
				sunLon;



	//
	//	Private, inline functions to calculate back and forth between radians and degrees
	//
	double		RADIANS(double degrees) {return (degrees * M_PI / 180);}
	double		DEGREES(double radians) {return (radians * 180 / M_PI);}
	//***********************************************************************************

	void		sunRunCalculations(void);

	//
	//	Functions to calculate the different elements in the object.
	//	They are saved in separate source-files.
	//

	void	sunCalcGeomMeanLongSun(void);
	/*
	void	sunCalcGeomMeanAnomSun(void);
	void	sunCalcEccentEarthOrbit(void);
	void	sunCalcSunEqOfCtr(void);
	void	sunCalcSunTrueLong(void);
	void	sunCalcSunTrueAnom(void);
	void	sunCalcSunRadVector(void);
	void	sunCalcSunAppLong(void);
	void	sunCalcMeanObliqEcliptic(void);
	void	sunCalcObliqCorr(void);
	void	sunCalcSunRtAscen(void);
	void	sunCalcSunDeclin(void);
	void	sunCalcVarY(void);
	void	sunCalcEqOfTime(void);
	void	sunCalcHaSunrise(void);
	void	sunCalcLocalSolarNoon(void);
	void	sunCalcLocalSunRise(void);
	void	sunCalcLocalSunSet(void);
	*/
	//****************************************************************


public:
	//
	//	Constructor and destructor
	//
				sun(int _year, short _month, short _day, short _hour, short _minute, short _second, short _tz, double _lat, double _lon, int _dst, bool _verbose);
	virtual 	~sun();

	//
	//	Not needed at the moment! Inline functions to retrieve data member values
	//

	double	sunGetGeomMeanLongSun(void)		{ return sunGeomMeanLongSun; }
	/*
	double	sunGetGeomMeanAnomSun(void)		{ return sunGeomMeanAnomSun; }
	double	sunGetEccentEarthOrbit(void)	{ return sunEccentEarthOrbit; }
	double	sunGetSunEqOfCtr(void)			{ return sunSunEqOfCtr; }
	double	sunGetSunTrueLong(void)			{ return sunSunTrueLong; }
	double	sunGetSunTrueAnom(void)			{ return sunSunTrueAnom; }
	double	sunGetSunRadVector(void)		{ return sunSunRadVector; }
	double	sunGetSunLat(void)				{ return sunLat; }
	double	sunGetsunLon(void)				{ return sunLon; }
	double	sunGetSunAppLong(void)			{ return sunSunAppLong; }
	double	sunGetMeanObliqEcliptic(void)	{ return sunMeanObliqEcliptic; }
	double	sunGetObliqCorr(void)			{ return sunObliqCorr; }
	double	sunGetSunRtAscen(void)			{ return sunSunRtAscen; }
	double	sunGetSunDeclin(void)			{ return sunSunDeclin; }
	double	sunGetVarY(void)				{ return sunVarY; }
	double	sunGetEqOfTime(void)			{ return sunEqOfTime; }
	double	sunGetHaSunrise(void)			{ return sunHaSunrise; }
	double	sunGetLocalSolarNoon(void)		{ return sunLocalSolarNoon; }
	double	sunGetLocalSunRise(void)		{ return sunLocalSunRise; }
	double	sunGetLocalSunSet(void)			{ return sunLocalSunSet; }
	*/


	//
	//	Function to print calculated date to stdout (terminal)
	//
	void sunPrintOutput(void);

	//
	//	Formatting fraction of a day into hh:mm:ss
	//
	//char*	timeStringFromDecimal(double time);


};	//	class sun

#endif	//	__sun_h__
