/**
*	\class		SCARA
*	\brief		A class to define SCARA robot
*	\author		Soumik SARKAR
*	\version	SCARA-Simulator_v1
*	\date		08/09/2021
*/

#pragma once
#ifndef SCARA_H
#define SCARA_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <vector>

class SCARA
{
public:
	/* Public Properties Definitions */
	double l1, l2; // Lengths of the two arms of SCARA robot.
	double q1, q2; // Joint angles corresponding to Arm 1 and Arm 2
	double x0 = 0, y0 = 0; // Origin of SCARA
	double x1, y1, x2, y2; // Point 1 (x1,y1) and Point 2 (x2,y2) corresponding to arm 1 and 2 of length l1 and l2.
	double q1_max, q2_max; // Joints 1 and 2 upper limits.
	double q1_min, q2_min; // Joints 1 and 2 lower limits.

	// Workspace Calculation Variables

	std::vector<double> workspaceBoundaryX, workspaceBoundaryY;
	std::vector<double> q1List, q2List;
	double X, Y;
	double theta1, theta2;


	/* Public Functions Definitions */
	~SCARA(); // SCARA Destructor
	/**
	Calculates FK for SCARA
	\param void
	\return void
	*/
	void CalculateFK(void);

	/**
	Set Lengths
	\param l1, l2
	*/
	void SetLength(double, double);

	/**
	Set Current Joint Angles
	\param q1, q2
	*/
	void SetCurrentAngles(double, double);

	void SetJointLimits(double, double, double, double);

	void CalculateWorkspace(void);

};


#endif // SCARA_H


