#include "Object.h"

Object::Object(Point x_position, vector<Point> points)
{
	position = x_position;
	v_points = points;
}
Object::Object(const Object& object)
{
	position = object.position;
	v_points = object.v_points;
}
vector<Point>& Object::get_v_points()
{
	return v_points;
}
double Object::p_x()
{
	return position.x;
}
double Object::p_y()
{
	return position.y;
}
void Object::draw(RenderTarget& window)
{
	ConvexShape x;
	vector<Point> p = get_v_points();
	x.setPointCount(p.size());
	for (int i = 0; i < p.size(); i++)
	{
		x.setPoint(i,Vector2f((float)p[i].x, (float)p[i].y));
		x.setOutlineColor(Color::White);
		x.setFillColor({ 255, 174, 174, 255 });
		x.setOutlineThickness(3);
		x.setPosition((float)p_x(), (float)p_y());
	}
	window.draw(x);
}