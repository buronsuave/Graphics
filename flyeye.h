#ifndef FLYEYE_H
#define FLYEYE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>

class FlyEye
{
    private:
    double r;                               // radius
    int v;                                  // vertices
    std::vector<std::pair<int, int>> e;     // edges
    double t;                               // rotation
    sf::Color c;                            // color
    std::pair<int, int> o;                  // center coords
    void build_e();

    public:
    // constructor
    FlyEye(double r, int v, double t, sf::Color c, std::pair<int, int> o);

    // getters
    double getR();
    int getV();
    std::vector<std::pair<int, int>> getE();
    double getT();
    sf::Color getC();
    std::pair<int, int> getO();

    // setters
    void setR(double);
    void setV(int);
    void setT(double);
    void setC(sf::Color);
    void setO(std::pair<int, int>);
};


#endif
