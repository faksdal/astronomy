#include "aSun.h"



void aSun::aSunPrintOutput(void)
{
	//
	//	Fixes the floating point values on print, see: https://faculty.cs.niu.edu/~hutchins/csci241/output.htm
	//	Used in conjunction with setw() and setprecision()
	cout.setf(ios::fixed);

	//cout << endl;
	cout	<< "Date/time: " << jdnGetDayName()
			<< " " << jdnGetJdnDay()
			<< "/" <<  jdnGetJdnMonth()
			<< "/" << jdnGetJdnYear()
			<< " @ " << setw(2) << setfill('0') << jdnGetJdnHour()
			<<":" << setw(2) << setfill('0') << jdnGetJdnMinute()
			<< ":" << setw(2) << setfill('0') << jdnGetJdnSecond() << endl;

	cout	<< " Timezone: " << jdnGetJdnTz() << endl;
	//	TODO Correct the precision formatters for Lat/Lon print
	cout	<< "  Lat/Lon: " << setw(12) << setprecision(8) << aSunLat << "°/" << setw(12) << setprecision(8) << aSunLon << "°" << endl;
	cout << endl;


	//
	// Custom grouping of large numbers, see: https://cplusplus.com/reference/locale/numpunct/grouping/
	//
	struct my_numpunct : std::numpunct<char> {
		// We want to group in numbers of three
		std::string do_grouping() const {return "\03";}
	};
	std::locale loc (std::cout.getloc(),new my_numpunct);
	std::cout.imbue(loc);
	// *************************************************************************************************



	cout	<< "      Julian Day Number (jdn): " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION) << setfill(' ') << jdnGetJdnJulianDay() << endl;
	cout	<< "    Julian Day Number at noon: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION) <<  jdnGetJdnNoon() << endl;
	cout	<< "               Julian Century: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION) << jdnGetJdnJulianCentury() << endl;
	cout	<< "       Julian Century at noon: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION) << jdnGetJdnJulianCenturyNoon() << endl;


	cout	<< endl << "Earth/Solar coordinates:" << endl;

	cout	<< "                   Sun's geometric mean longitude: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION) <<  aSunGeometricMeanLongitude << "°" << endl;
	cout	<< "                     Sun's geometric mean anomaly: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION) <<  aSunMeanAnomaly << "°"  << endl;
	cout	<< "                    Eccentricity of Earth's orbit: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION) <<  aSunEccentricityOfEarthsOrbit << endl;

	cout	<< "                         Sun's equation of centre: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION) <<  aSunEquationOfTheCenter << "°"  << endl;
	cout	<< "                   Sun's true geometric longitude: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunTrueGeometricLongitude << "°"  << endl;
	cout	<< "                               Sun's true anomaly: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunTrueAnomaly << "°"  << endl;
	cout	<< "                              Sun's radius vector: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunRadiusVector << endl;
	cout	<< "                         Sun's apparent longitude: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunApparentLongitude << "°"   << endl;
	cout	<< "                   Mean obliquity of the ecliptic: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunMeanObliquityOfTheEcliptic << "°" << endl;
	//cout	<< "   Mean obliquity of the ecliptic (High Accuracy): " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << HA_aSunMeanObliquityOfTheEcliptic << "°" << endl;
	cout	<< "                             Obliquity correction: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunObliquityCorrection << "°" << endl;
	cout	<< "                            Sun's right ascension: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunRightAscension << "°" << endl;
	cout	<< "                                Sun's declination: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunDeclination << "°" << endl;
	cout	<< "                                       Variable Y: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunVariableY << endl;
	cout	<< "                                 Equation of time: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunEquationOfTime << endl;
	cout	<< "                            Hour angle at sunrise: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunHaSunrise << endl;
	//cout	<< "                      sunLocalSolarNoon (decimal): " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunLocalSolarNoon << endl;
	cout	<< "                      Local Solar Noon (hh:mm:ss): " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << timeStringFromDecimal(aSunLocalSolarNoon) << endl;

	if(aSunHaSunrise != -1){
		//cout	<< "                                     localSunRise: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunLocalSunRise << endl;
		cout	<< "                          localSunRise (hh:mm:ss): " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << timeStringFromDecimal(aSunLocalSunRise) << endl;
		//cout	<< "                                      localSunSet: " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << aSunLocalSunSet << endl;
		cout	<< "                           localSunSet (hh:mm:ss): " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << timeStringFromDecimal(aSunLocalSunSet) << endl;
		cout	<< "                             dayLength (hh:mm:ss): " << setw(aSunFLOATWIDTH) << setprecision(aSunFLOATPRECISION)  << timeStringFromDecimal((aSunLocalSunSet-aSunLocalSunRise)) << endl;
	}
	else{
		cout << "     Sun above or below horizon\n";
	}

	cout << endl;

	return;
}

