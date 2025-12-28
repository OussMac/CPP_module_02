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
    Fixed(const int intValue);
    Fixed(const float floatValue);
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    int  getRawBits() const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int   toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif