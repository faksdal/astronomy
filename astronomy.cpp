/*
 * main.cpp
 *
 *  Created on: 16 Nov 2022
 *      Author: jole
 *
 *      Driver file for classes jdnMeeus1998 and sp.
 *
 *      This file is used to test class jdnMeeus1998{} and class sp{}.
 *
 */

#include <iostream>
#include <iomanip>
#include <getopt.h>
#include <locale.h>

using namespace std;

//#include "printUsage.h"

#include "sun.h"
#include "julianDay.h"
#include "parseOptarg.h"



int main(int argc, char *argv[])
{

	bool	verbose = false;
	int		year, month, day, hour, minute, second, timezone, dst;
	double	lat, lon;



	//
	//	getopt variables
	//
	int		c, optionIndex;
	//float	input = 0L, output;

	//
	//	TODO Add proper switches as the projects goes along
	//
	char	*shortOptions = (char*)"d:t:vh";
	struct option	longOptions[] = {
					{"date",	required_argument,	NULL,	'd'},
					{"time",	required_argument,	NULL,	't'},
					{"tz",		required_argument,	NULL,	3},
					{"lat",		required_argument,	NULL,	4},
					{"lon",		required_argument,	NULL,	5},
					{"dst",		required_argument,	NULL,	6},
					{"verbose",	no_argument,		NULL, 'v'},
					{"help",	no_argument,		NULL,	'h'},
					//{"dow",		no_argument,		NULL,	'd'},
					{0, 0, 0, 0}
	};	//End of getopt()-variables

	//	Initialise command line variables to some default values, should the user fail to provide...
	//	This is for development purpose only, not to enter production code.
	year		= 2020;
	month		= 6;
	day			= 21;
	hour		= 10;
	minute		= 0;
	second		= 0;
	timezone	= 10;
	lat			= -37.81998;
	lon			= 144.983431;
	dst			= 0;



	//
	//	getopt() switch statement
	//
	//	TODO Im plement a proper help-screen for the user
	//
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
			switch(c){
				case 'd':	{
								year = atoi(optarg);
								parseOptarg(&optarg);
								month = atoi(optarg);
								parseOptarg(&optarg);
								day = atoi(optarg);
								// end of parsing optarg

								break;
							}
				case 't':	{
								hour = atoi(optarg);
								parseOptarg(&optarg);
								minute = atoi(optarg);
								parseOptarg(&optarg);
								second = atoi(optarg);
								// end of parsing optarg

								break;
							}
				case 3:		{
								timezone = atoi(optarg);

								break;
							}
				case 4:		{
								lat = atof(optarg);

								break;
				}
				case 5:		{
								lon = atof(optarg);

								break;
							}
				case 6:		{
								dst = atoi(optarg);

								break;
							}
				case 'v':	{
								verbose = true;

								break;
							}
				case 'h':	{
								//printUsage();
								cout << "Add some useful information on how to use this software..." << endl;
								exit(1);
							}
				default:	{
								printf("switch default\n");
								break;
							}
			}	//end of getopt() switch statement
		}	// end of while-loop




	// Try to allocate memory for an instance of class sunpos
	sun *sp = new sun(year, month, day, hour, minute, second, timezone, lat, lon, dst, verbose);

	//	handle any error that might occur
	if(!sp){
		cout << "Allocation failed: " << "memory Error" << '\n';
		exit(-1);
	}

	//
	//	Print something if the user sets the verbose switch
	//

	if(verbose){
		sp->sunPrintOutput();
		//cout << "Print something useless..." << endl;

		//cout << "The day is " << sp->jdnGetDayName() << ", day #" << sp->jdnGetDayOfTheYear() << endl;
	}



	/*
	julianDay	*jdn = new julianDay(year, month, day, hour, minute, second, timezone, verbose);
	if(!jdn){
			cout << "Allocation failed: " << "memory Error" << '\n';
			exit(-1);
	}	// if(!jd)

	if(verbose){
		//	TODO	Print some meaningful info to the user...
		//jd->jdnPrintOutput();
		cout << "Print some info about the calculation process..." << endl;

		cout << "Julian Day Number at noon (jdn): " << setw(25) << setprecision(15) << setfill(' ') << jdn->jdnGetJdnNoon() << endl;
		cout << "The day is " << jdn->jdnGetDayName() << ", day #" << jdn->jdnGetDayOfTheYear() << endl;

	}	// if(verbose)
	*/


	return 1;

}	//	int main(int argc, char *argv[])
