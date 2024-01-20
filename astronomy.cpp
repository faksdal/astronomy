/*
 * main.cpp
 *
 *  Created on: 16 Nov 2022
 *      Author: jole
 *
 *      Driver program for testing my astronomy structures
 *
 * 
 *
 */
#include <iostream>
#include <iomanip>
#include <getopt.h>
#include <locale.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

#include "aSun.h"
#include "julianDay.h"
#include "printUsage.h"
#include "parseOptarg.h"



int main(int argc, char *argv[])
{

	bool	verbose = false, timeSupplied = false;
	bool	dateSupplied = false;
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
					{"verbose",	no_argument,		NULL,	'v'},
					{"help",	no_argument,		NULL,	'h'},
					//{"dow",		no_argument,		NULL,	'd'},
					{0, 0, 0, 0}
	};	//End of getopt()-variables

	//	Initialise command line variables to some default values, should the user fail to provide...
	//	This is for development purpose only, not to enter production code.
	//year		= 2024;
	//month		= 1;
	//day			= 21;
	//hour		= 12;
	//minute		= 0;
	//second		= 0;
	timezone	= 1;
	lat			= 64.68055000;	//	Oppi Leite
	lon			= 11.29132222;	//	Oppi Leite
	dst			= 0;



	//
	//	getopt() switch statement
	//
	//	TODO Implement a proper help-screen for the user
	//
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
			switch(c){
				case 'd':	{
								year = atoi(optarg);
								//cout << "optarg: " << optarg << endl;
								//cout << "Year: " << year << endl;
								parseOptarg(&optarg);
								month = atoi(optarg);
								//cout << "Month: " << month << endl;
								parseOptarg(&optarg);
								day = atoi(optarg);
								// end of parsing optarg
								dateSupplied = true;

								break;
							}
				case 't':	{
								hour = atoi(optarg);
								parseOptarg(&optarg);
								minute = atoi(optarg);
								parseOptarg(&optarg);
								second = atoi(optarg);
								// end of parsing optarg
								timeSupplied = true;

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
								printUsage();
								exit(1);
							}
				default:	{
								cout << "Switch default\n" << endl;
								break;
							}
			}	//end of getopt() switch statement
		}	// end of while-loop

	if(!dateSupplied){
		cout << "Date not supplied, using system date..." << endl;

		time_t current = time(NULL);
		struct tm* current_s = localtime(&current);

		day		= current_s->tm_mday;
		month	= ++current_s->tm_mon;
		year	= 1900 + current_s->tm_year;

		cout << "Day: " << day << ", month: " << month << ", year: " << year << endl;
	}

	if(!timeSupplied){
			cout << "Time not supplied, using system time..." << endl;

			time_t current = time(NULL);
			struct tm* current_s = localtime(&current);

			hour	= current_s->tm_hour;
			minute	= current_s->tm_min;
			second	= current_s->tm_sec;

			cout << "Time: " << hour << ":" << minute << ":" << second << endl;
		}


	aSun *sun = new aSun(year, month, day, hour, minute, second, timezone, lat, lon, dst, verbose);

	sun->aSunPrintOutput();

	return 0;
}	//	int main(int argc, char *argv[])
