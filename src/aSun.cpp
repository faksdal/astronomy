/*
 * sunsLongitude.cpp
 *
 *  Created on: 16 Nov 2022
 *      Author: jole
 *
 *	This class calculates and holds the calculated value for when the Sun crosses the meridian, e.g.
 *
 *
 *
 *	****************************************************************************************************
 *	The file is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 */

//#include "aSun.h"
#include "aSun.h"



aSun::aSun(	int		_year,
			short	_month,
			short	_day,
			short	_hour,
			short	_minute,
			short	_second,
			short	_tz,
			double	_lat,
			double	_lon,
			int		_dst,
			bool	_verbose) : julianDay(	_year,
											_month,
											_day,
											_hour,
											_minute,
											_second,
											_tz,
											_verbose)
{

	aSunFLOATWIDTH		= 30;
	aSunFLOATPRECISION	= 15;

	aSunLat	= _lat;
	aSunLon	= _lon;

	long double T = jdnGetJdnJulianCentury();
	//T = jdnGetJdnJulianCenturyNoon();
	aSunCalcCelestial(T);






	return;
}
