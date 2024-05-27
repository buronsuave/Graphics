#include "flyeye.h"

FlyEye::FlyEye(double r, int v, double t, sf::Color c, std::pair<int, int> o)
{
    this->r = r;
    this->v = v;
    this->build_e();
    this->t = t;
    this->c = c;
    this->o = o;
}

void FlyEye::build_e()
{
    this->e.clear();
    for (int i = 0; i < this->v-1; ++i)
    {
        for (int j = i+1; j < this->v; ++j)
        {
            if (this->v % 2 == 0 && j-i == this->v/2) continue;
            std::pair<int, int> ed(i, j);
            this->e.push_back(ed);
        }
    }
}

double FlyEye::getR()
{
    return this->r;
}

int FlyEye::getV()
{
    return this->v;
}

std::vector<std::pair<int, int>> FlyEye::getE()
{
    return this->e;
}

double FlyEye::getT()
{
    return this->t;
}

sf::Color FlyEye::getC()
{
    return this->c;
}

std::pair<int, int> FlyEye::getO()
{
    return this->o;
}

void FlyEye::setR(double r)
{
    this->r = r;
}

void FlyEye::setV(int v)
{
    this->v = v;
    this->build_e();
}

void FlyEye::setT(double t)
{
    this->t = t;
}

void FlyEye::setC(sf::Color c)
{
    this->c = c;
}

void FlyEye::setO(std::pair<int, int> o)
{
    this->o = o;
}
