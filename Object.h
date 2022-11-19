#pragma once
#include <cmath>
#include <vector>
#include "Painter.h"
#include "Point.h"
#include <iostream>
using namespace std;
class Object : virtual public Painter
{
protected:
	vector<Point> v_points;
	Point position;
public:
	Object(Point x_position = { 0 , 0 }, vector<Point> points = {});
	Object(const Object& object);
	void draw(RenderTarget& window) override;
	vector<Point>& get_v_points();
	double p_x();
	double p_y();
};