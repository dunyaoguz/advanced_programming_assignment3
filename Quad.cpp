#include <array>
#include "Quad.h"

// default ctor
Quad::Quad(double x1 = 0.0, double x2 = 0.0, double x3 = 0.0, double x4 = 0.0)
{
    quad.at(0) = x1;
    quad.at(1) = x2;
    quad.at(2) = x3; 
    quad.at(3) = x4;
}

// accessors and mutators
static const double getTolerance()
{
    return Quad::tolerance;
}

void Quad::set(const Quad& someQuad)
{
    quad.at(0) = someQuad[1];
    quad.at(1) = someQuad[2];
    quad.at(2) = someQuad[3];
    quad.at(3) = someQuad[4];
}

// compound assignment operators
Quad& Quad::operator+=(const Quad& someQuad)
{
    quad.at(0) = quad.at(0) + someQuad[1];
    quad.at(1) = quad.at(1) + someQuad[2];
    quad.at(2) = quad.at(2) + someQuad[3];
    quad.at(3) = quad.at(3) + someQuad[4];
    return *this;
}

Quad& Quad::operator-=(const Quad& someQuad)
{
    quad.at(0) = quad.at(0) - someQuad[1];
    quad.at(1) = quad.at(1) - someQuad[2];
    quad.at(2) = quad.at(2) - someQuad[3];
    quad.at(3) = quad.at(3) - someQuad[4];
    return *this;
}

Quad& Quad::operator*=(const Quad& someQuad)
{
    quad.at(0) = quad.at(0) * someQuad[1] + quad.at(1) * someQuad[4];
    quad.at(1) = quad.at(0) * someQuad[2] + quad.at(1) * someQuad[3];
    quad.at(2) = quad.at(3) * someQuad[2] + quad.at(2) * someQuad[3];
    quad.at(3) = quad.at(3) * someQuad[1] + quad.at(2) * someQuad[4];
    return *this;
}

Quad Quad::inverse() const 
{
    Quad inversed = Quad(quad.at(2), -quad.at(1), quad.at(0), -quad.at(3));
    return inversed;
}

Quad& Quad::operator/=(const Quad& someQuad)
{
    Quad inversed = someQuad.inverse();
    *this *= inversed;
    return *this;
}

Quad& Quad::operator+=(const double& a)
{
    quad.at(0) = quad.at(0) + a;
    quad.at(1) = quad.at(1) + a;
    quad.at(2) = quad.at(2) + a;
    quad.at(3) = quad.at(3) + a;
    return *this;
}

Quad& Quad::operator-=(const double& a)
{
    quad.at(0) = quad.at(0) - a;
    quad.at(1) = quad.at(1) - a;
    quad.at(2) = quad.at(2) - a;
    quad.at(3) = quad.at(3) - a;
    return *this;
}

Quad& Quad::operator*=(const double& a)
{
    quad.at(0) = quad.at(0) * a;
    quad.at(1) = quad.at(1) * a;
    quad.at(2) = quad.at(2) * a;
    quad.at(3) = quad.at(3) * a;
    return *this;
}

Quad& Quad::operator/=(const double& a)
{
    if (a != 0) {
        quad.at(0) = quad.at(0) / a;
        quad.at(1) = quad.at(1) / a;
        quad.at(2) = quad.at(2) / a;
        quad.at(3) = quad.at(3) / a;
    }
    else 
    {
        throw std::runtime_error("Error: dividing by zero\n");
    }
    return *this;
}

// unary increment and decrement overloads
Quad Quad::operator-()
{
    Quad newQuad = *this *= -1.0;
    return newQuad;
}

Quad Quad::operator+()
{
    Quad newQuad = *this *= 1.0;
    return newQuad;
}

Quad& Quad::operator++()
{
    *this += 1.0;
    return *this;
}

Quad& Quad::operator--()
{
    *this -= 1.0;
    return *this;
}

Quad Quad::operator++(int)
{
    Quad temp = *this;
    ++*this;
    return temp;
}

Quad Quad::operator--(int)
{
    Quad temp = *this;
    --*this;
    return temp;
}

// subscript overload 
const double& Quad::operator[](size_t i) const
{
    if(i < 1 || i > 4) 
    {
        throw std::out_of_range("Error: index out of bounds");
    }
    else 
    {
        return quad.at(i-1);
    }
}

double& Quad::operator[](size_t i)
{
    if(i < 1 || i > 4) 
    {
        throw std::out_of_range("Error: index out of bounds");
    }
    else 
    {
        return quad.at(i-1);
    }
}

// function overload
double Quad::operator()() const
{
    return *std::max_element(quad.begin(), quad.end());
}

double Quad::operator()(size_t i) const
{
    return quad.at(i);
}

double Quad::operator()(size_t i, size_t j) const
{
    if(quad.at(i) >= quad.at(j))
    {
        return quad.at(i);
    }
    return quad.at(j);
}

double Quad::operator()(size_t i, size_t j, size_t k) const
{
    std::array temp{quad.at(i), quad.at(j), quad.at(k)};
    return *std::max_element(temp.begin(), temp.end());
}

double Quad::operator()(size_t i, size_t j, size_t k, size_t l) const
{
    std::array temp{quad.at(i), quad.at(j), quad.at(k), quad.at(l)};
    return *std::max_element(temp.begin(), temp.end());
}

Quad Quad::absoluteValue() const
{
    Quad newQuad = Quad(std::abs(quad.at(0)), std::abs(quad.at(1)), std::abs(quad.at(2)), std::abs(quad.at(3)));
    return newQuad;
}


// basic arithmetic binary operators
Quad operator+(const Quad& firstQuad, const Quad& secondQuad)
{
    double index1 = firstQuad[1] + secondQuad[1];
    double index2 = firstQuad[2] + secondQuad[2];
    double index3 = firstQuad[3] + secondQuad[3];
    double index4 = firstQuad[4] + secondQuad[4];
    return Quad(index1, index2, index3, index4);
}

Quad operator-(const Quad& firstQuad, const Quad& secondQuad)
{
    double index1 = firstQuad[1] - secondQuad[1];
    double index2 = firstQuad[2] - secondQuad[2];
    double index3 = firstQuad[3] - secondQuad[3];
    double index4 = firstQuad[4] - secondQuad[4];
    return Quad(index1, index2, index3, index4);
}

Quad operator*(const Quad& firstQuad, const Quad& secondQuad)
{
    double index1 = firstQuad[1] * secondQuad[1] + firstQuad[2] * secondQuad[4];
    double index2 = firstQuad[1] * secondQuad[2] + firstQuad[2] * secondQuad[3];
    double index3 = firstQuad[4] * secondQuad[2] + firstQuad[3] * secondQuad[3];
    double index4 = firstQuad[4] * secondQuad[1] + firstQuad[3] * secondQuad[4];
    return Quad(index1, index2, index3, index4);
}

Quad operator/(const Quad& firstQuad, const Quad& secondQuad)
{
    Quad secondQuadInversed = secondQuad.inverse();
    return firstQuad * secondQuadInversed;
}

Quad operator+(const Quad& someQuad, const double& a)
{
    double index1 = someQuad[1] + a;
    double index2 = someQuad[2] + a;
    double index3 = someQuad[3] + a;
    double index4 = someQuad[4] + a;
    return Quad(index1, index2, index3, index4);
}

Quad operator-(const Quad& someQuad, const double& a)
{
    double index1 = someQuad[1] - a;
    double index2 = someQuad[2] - a;
    double index3 = someQuad[3] - a;
    double index4 = someQuad[4] - a;
    return Quad(index1, index2, index3, index4);
}

Quad operator*(const Quad& someQuad, const double& a)
{
    double index1 = someQuad[1] * a;
    double index2 = someQuad[2] * a;
    double index3 = someQuad[3] * a;
    double index4 = someQuad[4] * a;
    return Quad(index1, index2, index3, index4);
}

Quad operator/(const Quad& someQuad, const double& a)
{
    if (a != 0) {
        double index1 = someQuad[1] / a;
        double index2 = someQuad[2] / a;
        double index3 = someQuad[3] / a;
        double index4 = someQuad[4] / a;
        return Quad(index1, index2, index3, index4);
    }
    else 
    {
        throw std::runtime_error("Error: dividing by zero\n");
    }
}

Quad operator+(const double& a, const Quad& someQuad)
{
    return someQuad + a;
}

Quad operator-(const double& a, const Quad& someQuad)
{
    return someQuad - a;
}

Quad operator*(const double& a, const Quad& someQuad)
{
    return someQuad * a;
}

Quad operator/(const double& a, const Quad& someQuad)
{
    return someQuad / a;
}

// relational and equality operator overloads
bool operator==(const Quad&, const Quad&)
{

}
bool operator!=(const Quad&, const Quad&)
{

}
bool operator<(const Quad&, const Quad&)
{

}
bool operator<=(const Quad&, const Quad&)
{

}
bool operator>(const Quad&, const Quad&)
{

}
bool operator>=(const Quad&, const Quad&)
{

}

// output and input stream overloads
std::ostream &operator<<(std::ostream&, const Quad&)
{

}
std::istream &operator>>(std::istream&, Quad&)
{

}