#pragma once
#include "settings.h"
#include "Object.h"
class Circle : public Object
{
private:
	double radius = 0;
public:
	explicit Circle(double x_radius = 0.5, Point x_position = { 0, 0 }, int convexNumber = CIRCLE_CONVEX_NUMBER);

};