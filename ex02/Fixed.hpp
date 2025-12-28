#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 value;
    static const int    fractBits;

public:
    // Constructors
    Fixed();
    Fixed(const int intValue);
    Fixed(const float floatValue);
    Fixed(const Fixed &other);

    // Destructor
    ~Fixed();

    // Assignment
    Fixed &operator=(const Fixed &other);

    // Comparison operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment / decrement
    Fixed &operator++();    // pre-increment
    Fixed operator++(int);  // post-increment
    Fixed &operator--();    // pre-decrement
    Fixed operator--(int);  // post-decrement

    // Min / max
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    // Getters
    int  getRawBits() const;
    void setRawBits(int const raw);

    // Conversions
    float toFloat(void) const;
    int   toInt(void) const;
};

// Stream operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
