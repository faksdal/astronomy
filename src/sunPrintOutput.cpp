#include "sun.h"



void sun::sunPrintOutput(void)
{
	//
	//	Fixes the floating point values on print, see: https://faculty.cs.niu.edu/~hutchins/csci241/output.htm
	//	Used in conjunction with setw() and setprecision()
	cout.setf(ios::fixed);

	//cout << endl;
	cout	<< "Date/time: " << jdnGetJdnDay() << "/" <<  jdnGetJdnMonth() << "/" << jdnGetJdnYear() << " @ " << setw(2) << setfill('0') << jdnGetJdnHour() <<":" << setw(2) << setfill('0')<< jdnGetJdnMinute() << ":" << setw(2) << setfill('0')<< jdnGetJdnSecond() << endl;
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
	/*cout	<< "      Suns geometric mean anomaly: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION) <<  spGeomMeanAnomSun << endl;
	cout	<< "               spEccentEarthOrbit: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION) <<  spEccentEarthOrbit << endl;
	cout	<< "                     spSunEqOfCtr: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION) <<  spSunEqOfCtr << endl;
	cout	<< "                    spSunTrueLong: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spSunTrueLong << endl;
	cout	<< "                    spSunTrueAnom: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spSunTrueAnom << endl;
	cout	<< "                   spSunRadVector: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spSunRadVector << endl;
	cout	<< "                     spSunAppLong: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spSunAppLong << endl;
	cout	<< "              spMeanObliqEcliptic: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spMeanObliqEcliptic << endl;
	cout	<< "                      spObliqCorr: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spObliqCorr << endl;

	cout	<< "                     spSunRtAscen: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spSunRtAscen << endl;
	cout	<< "                      spSunDeclin: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spSunDeclin << endl;
	cout	<< "                           spVarY: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spVarY << endl;
	cout	<< "                       spEqOfTime: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spEqOfTime << endl;
	cout	<< "                      spHaSunrise: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spHaSunrise << endl;
	cout	<< "       spLocalSolarNoon (decimal): " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spLocalSolarNoon << endl;
	cout	<< "      spLocalSolarNoon (hh:mm:ss): " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << timeStringFromDecimal(spLocalSolarNoon) << endl;

	if(spHaSunrise != -1){
		//cout	<< "                     localSunRise: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spLocalSunRise << endl;
		cout	<< "          localSunRise (hh:mm:ss): " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << timeStringFromDecimal(spLocalSunRise) << endl;
		//cout	<< "                      localSunSet: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << spLocalSunSet << endl;
		cout	<< "           localSunSet (hh:mm:ss): " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION)  << timeStringFromDecimal(spLocalSunSet) << endl;
	}
	else{
		cout << "     Sun above or below horizon\n";
	}
	*/
	cout << endl;

	return;

}
