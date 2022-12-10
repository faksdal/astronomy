/*
 * sun.cpp
 *
 *  Created on: 29 May 2020
 *      Author: jole
 *
 *	This work is largely based on the work of Jean Meeus and his writing in the
 *	publication Astronomical Algorithms ISBN 0-943396-61-1
 *	It can be found here https://isbnsearch.org/isbn/0943396611
 *
  *	****************************************************************************************************
 *	The class is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 */

#include "sun.h"



sun::sun(int _year,
		 short _month,
		 short _day,
		 short _hour,
		 short _minute,
		 short _second,
		 short _tz,
		 double _lat,
		 double _lon,
		 int _dst,
		 bool _verbose) : julianDay(_year,
					                _month,
									_day,
									_hour,
									_minute,
									_second,
									_tz,
									_verbose)
{
	sunTz		= _tz;
	sunDst		= _dst;
	sunVerbose	= _verbose;

	sunLat		= _lat;
	sunLon		= _lon;

	//
	//	Run all calculations
	//
	//sunRunCalculations();
	//**********************

	sunFLOATWIDTH		= 25;
	sunFLOATPRECISION	= 15;

	return;
}



sun::~sun()
{
	return;
}
