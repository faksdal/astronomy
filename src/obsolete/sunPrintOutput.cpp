//#include "sun.h"


/*
void sun::sunPrintOutput(void)
{
	//
	//	Fixes the floating point values on print, see: https://faculty.cs.niu.edu/~hutchins/csci241/output.htm
	//	Used in conjunction with setw() and setprecision()
	cout.setf(ios::fixed);

	//cout << endl;
	cout	<< "Date/time: " << jdnGetDayName() << " " << jdnGetJdnDay() << "/" <<  jdnGetJdnMonth() << "/" << jdnGetJdnYear() << " @ " << setw(2) << setfill('0') << jdnGetJdnHour() <<":" << setw(2) << setfill('0')<< jdnGetJdnMinute() << ":" << setw(2) << setfill('0')<< jdnGetJdnSecond() << endl;
	//cout	<< "Timezone: " << jdnGetJdnTz() << endl;
	//	TODO Correct the precision formatters for Lat/Lon print
	cout	<< "  Lat/Lon: " << setw(12) << setprecision(8) << sunLat << "°/" << setw(12) << setprecision(8) << sunLon << "°" << endl;
	//cout << endl;


	//
	// Custom grouping of large numbers, see: https://cplusplus.com/reference/locale/numpunct/grouping/
	//
	struct my_numpunct : std::numpunct<char> {
		// We want to group in numbers of three
		std::string do_grouping() const {return "\03";}
	};
	std::locale loc (std::cout.getloc(),new my_numpunct);
	std::cout.imbue(loc);
	//*************************************************************************************************


	cout	<< "      Julian Day Number (jdn): " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION) << setfill(' ') << jdnGetJdnJulianDay() << endl;
	cout	<< "    Julian Day Number at noon: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION) <<  jdnGetJdnNoon() << endl;
	cout	<< "               Julian Century: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION) << jdnGetJdnJulianCentury() << endl;
	cout	<< "       Julian Century at noon: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION) << jdnGetJdnJulianCenturyNoon() << endl;


	cout	<< endl << "Earth/Solar coordinates:" << endl;

	cout	<< "    Suns geometric mean longitude: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION) <<  sunGeomMeanLongSun << endl;
	cout	<< "      Suns geometric mean anomaly: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION) <<  sunGeomMeanAnomSun << endl;
	cout	<< "               sunEccentEarthOrbit: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION) <<  sunEccentEarthOrbit << endl;
	cout	<< "                     sunSunEqOfCtr: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION) <<  sunSunEqOfCtr << endl;
	cout	<< "                    sunSunTrueLong: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sunSunTrueLong << endl;
	cout	<< "                    sunSunTrueAnom: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sunSunTrueAnom << endl;
	cout	<< "                   sunSunRadVector: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sunSunRadVector << endl;
	cout	<< "                     sunSunAppLong: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sunSunAppLong << endl;
	cout	<< "              sunMeanObliqEcliptic: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sunMeanObliqEcliptic << endl;
	cout	<< "                      sunObliqCorr: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sunObliqCorr << endl;

	cout	<< "                     sunSunRtAscen: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sunSunRtAscen << endl;
	cout	<< "                      sunSunDeclin: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sunSunDeclin << endl;
	cout	<< "                           sunVarY: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sunVarY << endl;
	cout	<< "                       sunEqOfTime: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sunEqOfTime << endl;
	cout	<< "                      sunHaSunrise: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sunHaSunrise << endl;
	cout	<< "       sunLocalSolarNoon (decimal): " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sumLocalSolarNoon << endl;
	cout	<< "      sunLocalSolarNoon (hh:mm:ss): " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << timeStringFromDecimal(sunLocalSolarNoon) << endl;

	if(sunHaSunrise != -1){
		//cout	<< "                     localSunRise: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sunLocalSunRise << endl;
		cout	<< "          localSunRise (hh:mm:ss): " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << timeStringFromDecimal(sunLocalSunRise) << endl;
		//cout	<< "                      localSunSet: " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << sunLocalSunSet << endl;
		cout	<< "           localSunSet (hh:mm:ss): " << setw(sunFLOATWIDTH) << setprecision(sunFLOATPRECISION)  << timeStringFromDecimal(sunLocalSunSet) << endl;
	}
	else{
		cout << "     Sun above or below horizon\n";
	}

	cout << endl;

	return;

}
*/
