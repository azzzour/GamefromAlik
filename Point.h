#pragma once
struct Point
{
	double x;
	double y;
	Point() = default;
	Point(double x1, double y1)
	{
		x = x1;
		y = y1;
	}
	Point operator+(Point x);
	Point operator-(Point x);
	Point operator*(double num);
	Point operator/(double num);
	Point& operator=(Point x);
	bool operator==(Point x);
	bool operator!=(Point x);
	bool operator>(Point x);
	bool operator<(Point x);
	bool operator>=(Point x);
	bool operator<=(Point x);

};