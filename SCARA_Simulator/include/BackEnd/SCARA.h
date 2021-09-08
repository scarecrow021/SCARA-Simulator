/**
*	\class		SCARA
*	\brief		A class to define SCARA robot
*	\author		Soumik SARKAR
*	\version	SCARA-Simulator_v1
*	\date		08/09/2021
*/

#pragma once
#ifndef SCARA
#define SCARA

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>

class Scara
{
public:
	/* Public Properties Definitions */
	double l1, l2; // Lengths of the two arms of SCARA robot.
	double q1, q2; // Joint angles corresponding to Arm 1 and Arm 2
	
private:
	/* Private Properties Definitions */
	double X0[2] = {0,0}; // Origin of SCARA
	double X1[2], X2[2]; // Point 1 (x1,y1) and Point 2 (x2,y2) corresponding to arm 1 and 2 of length l1 and l2.
	double q1_max, q2_max; // Joints 1 and 2 upper limits.
	double q1_min, q2_min; // Joints 1 and 2 lower limits.
};


#endif // SCARA

/*
void FK::calculateFK(void)
{
	x1 = l1 * cos(M_PI * q1 / 180);
	y1 = l1 * sin(M_PI * q1 / 180);

	x2 = l1 * cos(M_PI * q1 / 180) + l2 * cos((M_PI * q1 / 180) + (M_PI * q2 / 180));
	y2 = l1 * sin(M_PI * q1 / 180) + l2 * sin((M_PI * q1 / 180) + (M_PI * q2 / 180));
}

*/
