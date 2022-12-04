/*
 *
 *	jdn.h
 *	created 16 Nov 2022 by jole
 *
 *	References:
 *		https://isbnsearch.org/isbn/0943396611
 *		https://observablehq.com/@danleesmith/meeus-solar-position-calculations
 *
 *	class jdnMeeus1998 holds an instance of a julian day number calculated from the date provided to the constructor
 *	The class accepts dates from both Julian and Gregorian calendars
 *
 *	Constructor parameters:
 * 		jdnYear:	the year as an integer, i.e. 2022 or -1
 * 		jdnMonth:	the month as a short, 1 = January, 2 = February and so forth
 * 		jdnDay:		the day of the month
 *		jdnHour:	the hour of the day, 0-23, local time
 *		jdnMinute:	the minute of the hour 0-59, local time
 *		jdnSecond:	the second of the minute, 0-59, local time
 *
 *	Data members:
 *		jdnGregorianDate:	holds true if the date provided is Gregorian, e.g. after Oct. 15th 1582. Otherwise it holds false
 *		jdnValidDate:		upon the transition from Julian to Gregorian calendars, there are 10 dates in our history that doesn't exist
 *							these dates are 5th - 14th Oct. 1582
 *		jdnJulianDay:		lorem ipsum
 *		jdnJulianCentury:	lorem ipsum
 *		T:					lorem ipsum
 *		jdnMeeus:			lorem ipsum
 *
 *	****************************************************************************************************
 *	The class is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 *
*/

#ifndef __jdnMeeus1998_h__
#define __jdnMeeus1998_h__

using namespace std;

#include <math.h>
#include <iomanip>
#include <iostream>



class jdnMeeus1998 {

	/*
	bool	jdnGregorianDate, jdnValidDate, jdnVerbose;
	short	jdnDay, jdnMonth, jdnHour, jdnMinute, jdnSecond, jdnTz, jdnFLOATWIDTH, jdnFLOATPRECISION;
	int		jdnYear;
	double	jdnJ2000;

	double	jdnJulianDay, jdnJulianCentury, jdnJdnNoon, jdnJulianCenturyNoon;

	void	jdnParseDate(void);
	void	jdnCalculateJdn(void);
	*/


public:
	/*
	jdnMeeus1998(int year, short month, short day, short hour, short minute, short second, short tz, bool verbose);
	virtual ~jdnMeeus1998();


	//
	// inline public functions providing data member values
	//
	int		jdnGetJdnYear(void)					{ return jdnYear; }
	short	jdnGetJdnMonth(void)				{ return jdnMonth; }
	short	jdnGetJdnDay(void)					{ return jdnDay; }
	short	jdnGetJdnHour(void)					{ return jdnHour; }
	short	jdnGetJdnMinute(void)				{ return jdnMinute; }
	short	jdnGetJdnSecond(void)				{ return jdnSecond; }
	short	jdnGetJdnTz(void)					{ return jdnTz; }
	double	jdnGetJdnJulianDay(void)			{ return jdnJulianDay; }
	double	jdnGetJdnNoon(void)					{ return jdnJdnNoon; }
	double	jdnGetJdnJulianCentury(void)		{ return jdnJulianCentury; }
	double	jdnGetJdnJulianCenturyNoon(void)	{ return jdnJulianCenturyNoon; }
	//***************************************************************************

	void	jdnSetJdnJulianCentury(double _jdnJulianCentury) {jdnJulianCentury = _jdnJulianCentury;}
	void	jdnSetJdnJulianCenturyNoon(double _jdnJulianCenturyNoon){jdnJulianCenturyNoon =_jdnJulianCenturyNoon;}

	//
	//	print-to-screen routines
	//
	void jdnPrintOutput(void);
	*/

};

#endif // __jdnMeeus1998_h__
