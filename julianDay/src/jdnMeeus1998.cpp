/*
 * jdn.cpp
 *
 *	Created on: 16 Oct 2022
 *	Author: jole
 *      
 *	Class julianDay calculates the Julian Day Number for the given date and time.
 *
 *	This work is largely based on the work of Jean Meeus and his writing in the
 *	publication Astronomical Algorithms ISBN 0-943396-61-1
 *	It can be found here https://isbnsearch.org/isbn/0943396611
 *	
 *	The work also includes resources I found here:
 *		- https://www.ladybug.tools/ladybug-web/solar-calculator-noaa/noaa-sandbox-r2.html
 *		- https://gml.noaa.gov/grad/solcalc/main.js
 *		- https://en.wikipedia.org/wiki/Julian_day#Julian_day_number_calculation
 *		  
 *	****************************************************************************************************
 *	The class is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 */


#include "jdnMeeus1998.h"

//#include <math.h>
//#include <stdio.h>
//#include <string>
#include <iostream>

using namespace std;


/*
jdnMeeus1998::jdnMeeus1998(int year, short month, short day, short hour, short minute, short second, short tz, bool verbose)
{
	//
	//	initialise parameters into the class members
	//
	jdnYear		= year;
	jdnMonth	= month;
	jdnDay		= day;

	jdnHour		= hour;
	jdnMinute	= minute;
	jdnSecond	= second;

	jdnTz		= tz;

	jdnJ2000	= 2451545.;

	//
	// These are to be calculated, so we'll initialise them to NIL
	//
	jdnJulianDay			= 0.;
	jdnJulianCentury		= 0.;
	jdnJulianCenturyNoon	= 0.;
	jdnJdnNoon				= 0.;

	jdnVerbose = verbose;

	jdnParseDate();
	jdnCalculateJdn();

	jdnFLOATWIDTH		= 25;
	jdnFLOATPRECISION	= 15;
}



jdnMeeus1998::~jdnMeeus1998() {
	// Empty destructor
}
*/
