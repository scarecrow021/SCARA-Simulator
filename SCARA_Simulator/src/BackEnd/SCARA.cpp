#include <./BackEnd/SCARA.h>


Scara::~Scara()
{

}

void Scara::CalculateFK(void)
{
	x1 = l1 * cos(M_PI * q1 / 180);
	y1 = l1 * sin(M_PI * q1 / 180);

	x2 = l1 * cos(M_PI * q1 / 180) + l2 * cos((M_PI * q1 / 180) + (M_PI * q2 / 180));
	y2 = l1 * sin(M_PI * q1 / 180) + l2 * sin((M_PI * q1 / 180) + (M_PI * q2 / 180));
}

void Scara::SetLength(double length1, double length2)
{
	l1 = length1;
	l2 = length2;
}

void Scara::SetCurrentAngles(double angle1, double angle2)
{
	q1 = angle1;
	q2 = angle2;
}

