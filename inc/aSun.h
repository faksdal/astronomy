/*
 * sunsLongitude.h
 *
 *  Created on: 16 Nov 2022
 *      Author: jole
 *

 *
 *
 *	****************************************************************************************************
 *	The file is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 *
 *	Character	Displayed	Alt Code
	Alpha			α	Alt 224
	Beta			β	Alt 225
	Gamma			Γ	Alt 226
	Delta			δ	Alt 235
	Epsilon			ε	Alt 238
	Theta			Θ	Alt 233
	Pi				π	Alt 227
	Mu				µ	Alt 230
	Uppercase Sigma	Σ	Alt 228
	Lowercase Sigma	σ	Alt 229
	Tau				τ	Alt 231
	Uppercase Phi	Φ	Alt 232
	Lowercase Phi	φ	Alt 237
	Omega			Ω	Alt 234
 *
 *	capital gamma	Γ	&#915; or &Gamma;
	capital delta	Δ	&#916; or &Delta;
	capital theta	Θ	&#920; or &Theta;
	capital lambda	Λ	&#923; or &Lamda;
	capital xi		Ξ	&#926; or &Xi;
	capital pi		Π	&#928; or &Pi;
	capital sigma	Σ	&#931; or &Sigma;
	capital phi		Φ	&#934; or &Phi;
	capital psi		Ψ	&#936; or &Psi;
	capital omega	Ω	&#937; or &Omega;
	small alpha		α	&#945; or &alpha;
	small beta		β	&#946; or &beta;
	small gamma		γ	&#947; or &gamma;
	small delta		δ	&#948; or &delta;
	small epsilon	ε	&#949; or &epsilon;
	small zeta		ζ	&#950; or &zeta;
	small eta		η	&#951; or &zeta;
	small theta		θ	&#952; or &theta;
	small iota		ι	&#953; or &iota;
	small kappa		κ	&#954; or &kappa;
	small lamda		λ	&#955; or &lambda;
	small mu		μ	&#956; or &mu;
	small nu		ν	&#957; or &nu;
	small xi		ξ	&#958; or &xi;
	small pi		π	&#960; or &pi;
	small rho		ρ	&#961; or &rho;
	small sigma		σ	&#963; or &sigma;
	small tau		τ	&#964; or &tau;
	small upsilon	υ	&#965; or &upsilon;
	small phi		φ	&#966; or &phi;
	small chi		χ	&#967; or &chi;
	small psi		ψ	&#968; or &psi;
	small omega		ω
 *
 */

#ifndef __aSun_h__
#define __aSun_h__

using namespace std;

#include <iomanip>
#include <iostream>

#include <math.h>

#include "julianDay.h"



class aSun : public julianDay {

	bool	aSunVerbose;
	short	aSunTimeZone, aSunFLOATWIDTH, aSunFLOATPRECISION;
	int		aSunDst;


	double	aSunLat, aSunLon;

	//
	//	Calculated properties of the Sun
	//	This values will give you the geocentric planetary positions
	//	See Meeus p.163
	//
	long double	aSunGeometricMeanLongitude;			//	Meeus p.163 (25.2)
	long double	aSunMeanAnomaly;					//	Meeus p.163 (25.3)
	long double	aSunEccentricityOfEarthsOrbit;		//	Meeus p.163 (25.4)
	long double	aSunEquationOfTheCenter;			//	Meeus p.164
	long double	aSunTrueGeometricLongitude;			//	Meeus p.164
	long double	aSunTrueAnomaly;					//	Meeus p.164
	long double	aSunRadiusVector;					//	Meeus p.164	(25.5)
	long double	aSunApparentLongitude;				//	Meeus p.164
	long double	aSunMeanObliquityOfTheEcliptic;		//	Meeus p.147 (22.2)
	long double	HA_aSunMeanObliquityOfTheEcliptic;	//	Meeus p.147 High accuracy (22.3)
	long double	aSunObliquityCorrection;			//
	long double	aSunRightAscension;					//
	long double	aSunDeclination;					//
	long double	aSunVariableY;						// See https://en.wikipedia.org/wiki/Equation_of_time
	long double	aSunEquationOfTime;					//	Meeus p.183 ()
	long double	aSunHaSunrise;						//
	long double	aSunLocalSolarNoon;					//
	long double	aSunLocalSunRise;					//
	long double	aSunLocalSunSet;					//


	//*************************************************************************
	//
	//	Private functions doing the calculations
	void	aSunCalcCelestial(long double T);
	//*************************************************************************

	//*************************************************************************
	void	aSunCalcGeometricMeanLongitude(long double T);
	void	aSunCalcMeanAnomaly(long double T);
	void	aSunCalcEccentricityOfEarthsOrbit(long double T);
	void	aSunCalcEquationOfTheCenter(long double T);
	void	aSunCalcTrueGeometricLongitude(void);
	void	aSunCalcTrueAnomaly(void);
	void	aSunCalcRadiusVector(void);
	void	aSunCalcApparentLongitude(long double T);
	void	aSunCalcMeanObliquityOfTheEcliptic(long double T);
	void	HA_aSunCalcMeanObliquityOfTheEcliptic(long double T);
	void	aSunCalcObliquityCorrection(long double T);
	void	aSunCalcRightAscension(void);
	void	aSunCalcDeclination(void);
	void	aSunCalcVariableY(void);
	void	aSunCalcEquationOfTime(void);


	//*************************************************************************
	//	Private, inline functions to calculate back and forth between radians and degrees
	//
	long double	RADIANS(long double degrees) {return (degrees * M_PI / 180);}
	long double	DEGREES(long double radians) {return (radians * 180 / M_PI);}
	//*************************************************************************

	char*	timeStringFromDecimal(long double time);



public:
	//
	//	Constructor and destructor
	//
	aSun(int _year, short _month, short _day, short _hour, short _minute, short _second, short _tz, double _lat, double _lon, int _dst, bool _verbose);
	//virtual 	~sunsLongitude();

	void	aSunPrintOutput(void);

	//***********************************************************************************
	//	Inline functions to retrieve data member values
	//
	double	aSunGetGeometricMeanLongitude(void)	{ return aSunGeometricMeanLongitude; }
	double	aSunGetMeanAnomaly(void)			{ return aSunMeanAnomaly; }
	//***********************************************************************************

};

#endif	//	__aSun_h__
