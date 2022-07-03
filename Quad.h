#ifndef QUAD_H_
#define QUAD_H_
#include <array>
#include <iostream>

class Quad
{
    public:
        // static members
        static inline const double tolerance{ 1.0E-6 };

        // default ctor
        Quad(double x1 = 0.0, double x2 = 0.0, double x3 = 0.0, double x4 = 0.0);

        // big five
        Quad(const Quad&) = default;
        Quad(Quad&&) = default;
        Quad& operator=(const Quad&) = default;
        Quad& operator=(Quad&&) = default;        
        ~Quad() = default;
        
        // accessors and mutators
        Quad get() const;
        void set(const Quad&);

        // compound assignment operators
        Quad& operator+=(const Quad&);
        Quad& operator-=(const Quad&);
        Quad& operator*=(const Quad&);
        Quad& operator/=(const Quad&);

        Quad& operator+=(const double&);
        Quad& operator-=(const double&);
        Quad& operator*=(const double&);
        Quad& operator/=(const double&);

        // unary increment and decrement overloads
        Quad operator-();
        Quad operator+();
        Quad& operator++();
        Quad& operator--();
        const Quad operator++(int);
        const Quad operator--(int);

        // subscript overload 
        const double& operator[](size_t) const;
        double& operator[](size_t);

        // function overload
        double& operator()() const;
        double& operator()(size_t) const;
        double& operator()(size_t, size_t) const;
        double& operator()(size_t, size_t, size_t) const;
        double& operator()(size_t, size_t, size_t, size_t) const;

        Quad absoluteValue() const;

    private:
        std::array<double, 4> quad{};

        
};

// basic arithmetic binary operators
Quad operator+(const Quad&, const Quad&);
Quad operator-(const Quad&, const Quad&);
Quad operator*(const Quad&, const Quad&);
Quad operator/(const Quad&, const Quad&);

Quad operator+(const Quad&, const double&);
Quad operator-(const Quad&, const double&);
Quad operator*(const Quad&, const double&);
Quad operator/(const Quad&, const double&);

double operator+(const double&, const Quad&);
double operator-(const double&, const Quad&);
double operator*(const double&, const Quad&);
double operator/(const double&, const Quad&);

// relational and equality operator overloads
bool operator==(const Quad&, const Quad&);
bool operator!=(const Quad&, const Quad&);
bool operator<(const Quad&, const Quad&);
bool operator<=(const Quad&, const Quad&);
bool operator>(const Quad&, const Quad&);
bool operator>=(const Quad&, const Quad&);

// output and input stream overloads
std::ostream &operator<<(std::ostream&, const Quad&);
std::istream &operator>>(std::istream&, Quad&);

#endif