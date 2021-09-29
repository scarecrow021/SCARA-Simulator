#include <./BackEnd/SCARA.h>


SCARA::~SCARA()
{

}

void SCARA::CalculateFK(void)
{
	x1 = l1 * cos(M_PI * q1 / 180);
	y1 = l1 * sin(M_PI * q1 / 180);

	x2 = l1 * cos(M_PI * q1 / 180) + l2 * cos((M_PI * q1 / 180) + (M_PI * q2 / 180));
	y2 = l1 * sin(M_PI * q1 / 180) + l2 * sin((M_PI * q1 / 180) + (M_PI * q2 / 180));
}

void SCARA::SetLength(double length1, double length2)
{
	l1 = length1;
	l2 = length2;
}

void SCARA::SetCurrentAngles(double angle1, double angle2)
{
	q1 = angle1;
	q2 = angle2;
}

void SCARA::SetJointLimits(double q1Max, double q1Min, double q2Max, double q2Min)
{
	q1_max = q1Max;
	q1_min = q1Min;
	q2_max = q2Max;
	q2_min = q2Min;
}

void SCARA::CalculateWorkspace(void)
{
	// When q2 = q2_min
	theta1 = q1_min;
	workspaceBoundaryX.clear();
	workspaceBoundaryY.clear();
	while (theta1 != q1_max)
	{
		q1List.push_back(theta1);
		X = l1* cos(M_PI * theta1 / 180) + l2 * cos((M_PI * theta1 / 180) + (M_PI * q2_min / 180));
		Y = l1 * sin(M_PI * theta1 / 180) + l2 * sin((M_PI * theta1 / 180) + (M_PI * q2_min / 180));
		workspaceBoundaryX.push_back(X);
		workspaceBoundaryY.push_back(Y);
		theta1 = theta1 + 1;
	}
	std::cout << "Calc 1 done.." << std::endl;

	// When q2 = q2_max
	theta1 = q1_min;
	while (theta1 != q1_max)
	{
		q1List.push_back(theta1);
		X = l1 * cos(M_PI * theta1 / 180) + l2 * cos((M_PI * theta1 / 180) + (M_PI * q2_max / 180));
		Y = l1 * sin(M_PI * theta1 / 180) + l2 * sin((M_PI * theta1 / 180) + (M_PI * q2_max / 180));
		workspaceBoundaryX.push_back(X);
		workspaceBoundaryY.push_back(Y);
		theta1 = theta1 + 1;
	}
	std::cout << "Calc 2 done.." << std::endl;

	//------------------

	// When q1 = q1_min
	theta2 = q2_min;
	while (theta2 != q2_max)
	{
		q2List.push_back(theta2);
		X = l1 * cos(M_PI * q1_min / 180) + l2 * cos((M_PI * q1_min / 180) + (M_PI * theta2 / 180));
		Y = l1 * sin(M_PI * q1_min / 180) + l2 * sin((M_PI * q1_min / 180) + (M_PI * theta2 / 180));
		workspaceBoundaryX.push_back(X);
		workspaceBoundaryY.push_back(Y);
		theta2 = theta2 + 1;
	}
	std::cout << "Calc 3 done.." << std::endl;

	// When q1 = q1_max
	theta2 = q2_min;
	while (theta2 != q2_max)
	{
		q2List.push_back(theta2);
		X = l1 * cos(M_PI * q1_max / 180) + l2 * cos((M_PI * q1_max / 180) + (M_PI * theta2 / 180));
		Y = l1 * sin(M_PI * q1_max / 180) + l2 * sin((M_PI * q1_max / 180) + (M_PI * theta2 / 180));
		workspaceBoundaryX.push_back(X);
		workspaceBoundaryY.push_back(Y);
		theta2 = theta2 + 1;
	}
	std::cout << "Calc 4 done.." << std::endl;

	// For q2 = 0...
	theta1 = q1_min;
	if ((-180 < q2_min) && (q2_max < 180))
	{
		while (theta1 != q1_max)
		{
			X = l1 * cos(M_PI * theta1 / 180) + l2 * cos((M_PI * theta1 / 180));
			Y = l1 * sin(M_PI * theta1 / 180) + l2 * sin((M_PI * theta1 / 180));
			workspaceBoundaryX.push_back(X);
			workspaceBoundaryY.push_back(Y);
			theta1 = theta1 + 1;
		}
	}
	
	std::cout << "Calc 5 done.." << std::endl;
}
