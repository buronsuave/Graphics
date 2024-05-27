#include "flyeye.h"

void drawFlyEye(sf::RenderWindow* window, FlyEye flyeye);
// void drawVertex(sf::RenderWindow* window, std::pair<double, double> coords, sf::Color color);
void drawEdge(sf::RenderWindow* window, std::pair<std::pair<double, double>, std::pair<double, double>> pair_coords, sf::Color color);

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Flyeye example");
    std::pair<int, int> o(300, 300);
    FlyEye flyeye(200, 8, 0, sf::Color::White, o);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                std::pair<int, int> newO = flyeye.getO();

                // Up
                if (event.key.code == sf::Keyboard::W)
                {
                    newO.second -= 5; // 5 is the fixed step
                    flyeye.setO(newO);
                }

                // Left
                else if (event.key.code == sf::Keyboard::A)
                {
                    newO.first -= 5;
                    flyeye.setO(newO);
                }

                // Down
                else if (event.key.code == sf::Keyboard::S)
                {
                    newO.second += 5;
                    flyeye.setO(newO);
                }

                // Right
                else if (event.key.code == sf::Keyboard::D)
                {
                    newO.first += 5;
                    flyeye.setO(newO);
                }

                // Clockwise rotation
                else if (event.key.code == sf::Keyboard::T)
                {
                    flyeye.setT(flyeye.getT() + M_PI/24);
                }

                // Anti clockwise rotation
                else if (event.key.code == sf::Keyboard::R)
                {
                    flyeye.setT(flyeye.getT() - M_PI/24);
                }

                // Zoom in
                else if (event.key.code == sf::Keyboard::Z)
                {
                    flyeye.setR(flyeye.getR() + 10);
                }

                // Zoom out
                else if (event.key.code == sf::Keyboard::X)
                {
                    flyeye.setR(flyeye.getR() - 10);
                }

                // Color 1 (white)
                else if (event.key.code == sf::Keyboard::Numpad1 || event.key.code == sf::Keyboard::Num1)
                {
                    flyeye.setC(sf::Color::White);
                }

                // Color 2 (green)
                else if (event.key.code == sf::Keyboard::Numpad2 || event.key.code == sf::Keyboard::Num2)
                {
                    flyeye.setC(sf::Color::Green);
                }

                // Color 3 (red)
                else if (event.key.code == sf::Keyboard::Numpad3 || event.key.code == sf::Keyboard::Num3)
                {
                    flyeye.setC(sf::Color::Red);
                }

                // Color 4 (blue)
                else if (event.key.code == sf::Keyboard::Numpad4 || event.key.code == sf::Keyboard::Num4)
                {
                    flyeye.setC(sf::Color::Blue);
                }

                // Color 5 (yellow)
                else if (event.key.code == sf::Keyboard::Numpad5 || event.key.code == sf::Keyboard::Num5)
                {
                    flyeye.setC(sf::Color::Yellow);
                }

                // Add vertex
                else if (event.key.code == sf::Keyboard::Add || event.key.code == sf::Keyboard::M)
                {
                    if (flyeye.getV() != 30)
                        flyeye.setV(flyeye.getV() + 1);
                }

                // Remove vertex
                else if (event.key.code == sf::Keyboard::Subtract || event.key.code == sf::Keyboard::N)
                {
                    if (flyeye.getV() != 5)
                        flyeye.setV(flyeye.getV() - 1);
                }
            }
        }

        window.clear();
        drawFlyEye(&window, flyeye);
        window.display();
    }

    return 0;
}

void drawFlyEye(sf::RenderWindow* window, FlyEye flyeye)
{
    // Retrieve values
    int v = flyeye.getV();
    std::vector<std::pair<int, int>> e = flyeye.getE();
    double r = flyeye.getR();
    double t = flyeye.getT();
    sf::Color c = flyeye.getC();
    std::pair<int, int> o = flyeye.getO();
    double t_in = 2*M_PI/v;

    // Compute vertices
    std::vector<std::pair<double, double>> vertices_coords;
    for (int i = 0; i < v; ++i)
    {
        std::pair<double, double> vertex_coords(r*cos(i*t_in + t) + o.first, -r*sin(i*t_in + t) + o.second);
        vertices_coords.push_back(vertex_coords);
    }

    // Draw vertices
    // for (auto vertex_coords:vertices_coords)
    //     drawVertex(window, vertex_coords, c);

    // Draw edges
    for (auto edge:e)
    {
        std::pair<std::pair<double, double>, std::pair<double, double>> pair_coords(
            vertices_coords[edge.first], 
            vertices_coords[edge.second]);
        drawEdge(window, pair_coords , c);
    }
}

// void drawVertex(sf::RenderWindow* window, std::pair<double, double> coords, sf::Color color)
// {
//     // Draw circle (vertex)
//     sf::CircleShape c(5.f);
//     c.setFillColor(color);
//     c.setOrigin(coords.first, coords.second);
//     window->draw(c);
// }

void drawEdge(sf::RenderWindow* window, std::pair<std::pair<double, double>, std::pair<double, double>> pair_coords, sf::Color color)
{
    // Draw line from pair one to pair two (edge)
    sf::Vertex l[2];
    l[0].position = sf::Vector2f(pair_coords.first.first, pair_coords.first.second);
    l[0].color = color;
    l[1].position = sf::Vector2f(pair_coords.second.first, pair_coords.second.second);
    l[1].color = color;
    window->draw(l, 2, sf::Lines);
}