#include "Object.h"
#include "settings.h"
#include "Circle.h"
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


int main()
{
    RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Arthas");
    window.setVerticalSyncEnabled(true);
    Circle z(150, { 250,250 }, 29);
	Object x({ 100, 100 }, { { 100, 100},{ 200, 100 },{ 200, 200} });
    Object y({ 10 - 30, 20 }, { { 100, 100},{ 200, 100 },{ 200, 200} });
    while (window.isOpen())
    {
        pollEvants(window);
        window.clear();
        z.draw(window);
        /*x.draw(window);
        y.draw(window);*/
        window.display();
    }   
}