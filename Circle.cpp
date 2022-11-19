#include "Circle.h"
#include "settings.h"
Circle::Circle(double x_radius, Point x_position, int convexNumber):Object(x_position, {})
{
    radius = x_radius;
    for (int i = 0; i < convexNumber; i++)
    {
        double _x = radius * cos((double)i / convexNumber * 2 * PI + PI / 4);
        double _y = radius * sin((double)i / convexNumber * 2 * PI + PI / 4);

        get_v_points().push_back({ _x, _y });
    }
}
