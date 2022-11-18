#include "Point.h"
#include <cmath>

Point Point::operator+(Point x)
{
	return Point(this->x + x.x, this->y + x.y);
}
Point Point::operator-(Point x)
{
	return Point(this->x - x.x, this->y - x.y);
}
Point Point::operator*(double x)
{
	return Point(this->x * x, this->y * x);
}
Point Point::operator/(double x)
{
	return Point(this->x / x, this->y / x);
}
Point& Point::operator=(Point x)
{
	this->x = x.x;
	this->y = x.y;
	return *this;
}
bool Point::operator==(Point x)
{
	return (this->x == x.x && this->y == x.y);
}
bool Point::operator!=(Point x)
{
	return (this->x != x.x || this->y != x.y);
}
bool Point::operator>(Point x)
{
	return (this->x > x.x && this->y > x.y);
}
bool Point::operator<(Point x)
{
	return (this->x < x.x && this->y < x.y);
}
bool Point::operator>=(Point x)
{
	return ((this->x > x.x && this->y > x.y) || (this->x == x.x && this->y == x.y));
}
bool Point::operator<=(Point x)
{
	return ((this->x < x.x && this->y < x.y) || (this->x == x.x && this->y == x.y));
}
