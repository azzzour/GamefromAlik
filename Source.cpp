#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Point.cpp"
#define PI 3.1415926535
using namespace std;
using namespace sf;
void pollEvants(RenderWindow& window)
{
    Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case Event::MouseButtonPressed:
            cout << "Mouse pressed: " << endl;
            cout << "X: " << event.mouseButton.x << endl;
            cout << "Y: " << event.mouseButton.y << endl;
            break;
        case Event::MouseButtonReleased:
            cout << "Mouse released: " << endl;
            cout << "X: " << event.mouseButton.x << endl;
            cout << "Y: " << event.mouseButton.y << endl;
            break;
        case Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
}

void redrawFrame(RenderWindow& window, CircleShape& circle, Vertex (line)[])
{
    window.clear();
    window.draw(circle);
    window.draw(line,2,Lines);
    window.display();
}
int mapX = 10, mapY = 10, mapS = 50;
int map1[] =
{
    1, 1, 1, 1, 1, 1, 1, 1,1,1,
    1, 0, 0, 0, 0, 0, 0, 0,0,1,
    1, 1, 0, 1, 1, 0, 0, 0,0,1,
    1, 0, 0, 0, 1, 0, 0, 0,0,1,
    1, 0, 0, 0, 1, 0, 0, 0,0,1,
    1, 0, 0, 0, 0, 0, 0, 0,0,1,
    1, 0, 0, 0, 0, 0, 1, 0,0,1,
    1, 0, 0, 0, 0, 0, 1, 0,0,1,
    1, 0, 0, 0, 0, 0, 0, 0,0,1,
    1, 1, 1, 1, 1, 1, 1, 1,1,1
};

void draw2dmap(int map[],int mapX,int mapY, int mapS, RenderWindow& window)
{
    int x, y, x0, y0;
    for (y = 0; y < mapY; y++)
    {
        for (x = 0; x < mapX; x++)
        {
            ConvexShape squard(4);
            if (map[y * mapX + x] == 1)
                squard.setFillColor(Color::White);
            else 
                squard.setFillColor(Color::Black);
            x0 = x * mapS;
            y0 = y * mapS;
            squard.setPoint(0, sf::Vector2f(x0+1, y0 + 1));
            squard.setPoint(1, sf::Vector2f(x0 + 1, y0+mapS-1));
            squard.setPoint(2, sf::Vector2f(x0+mapS-1, y0+mapS-1));
            squard.setPoint(3, sf::Vector2f(x0+mapS-1, y0+1));
            window.draw(squard);
          
        }
    }
}

int main()
{
    float px;
    float py;
    float pdx;
    float pdy;
    float pa;
    px = 225;
    py = 225;
    pa = PI/2;
    pdx = cos(pa);
    pdy = sin(pa);
    Clock clock;
    RenderWindow window(sf::VideoMode(1000, 1000), "Arthas");
    window.setVerticalSyncEnabled(true);
    CircleShape circle(5);
    circle.setPosition(px,py);
    Vertex line[] =
    {
        Vertex(Vector2f(px+pdx*50, py+ pdy*50)),
        Vertex(Vector2f(px+5, py+5))
    };
    ConvexShape squard(4);
    squard.setPoint(0, { -90,0 });
    squard.setPoint(1, { 90, 0 });
    squard.setPoint(2, { 90, 60 });
    squard.setPoint(3, { -90, 60 });
    squard.setFillColor(Color::White);




    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asMilliseconds();
        clock.restart();
        time = time/800;
        pollEvants(window);
        /*redrawFrame(window, circle, line);*/
        window.clear(Color(80,80,80));
        draw2dmap(map1, mapX, mapY, mapS, window);
        window.draw(circle);
        window.draw(line, 2, Lines);
        window.display();
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            pa -= 2* time;
            if (pa < 0)
                pa += 2.0*PI;
            pdx = cos(pa);
            pdy = sin(pa);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            pa += 2* time;
            if (pa > 2*PI)
                pa -= 2 * PI;
            pdx = cos(pa);
            pdy = sin(pa);
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            px -= pdx*2;
            py -= pdy*2;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            {
                px += pdx*2;
                py += pdy*2;
            }
        }
        circle.setPosition(px, py);
        line[0] = Vertex(Vector2f(px+5-pdx*50, py+5-pdy*50));
        line[1] = Vertex(Vector2f(px+5, py+5));
    }
    return 0;
}