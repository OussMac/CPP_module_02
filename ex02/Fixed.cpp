#include "Fixed.hpp"

const int Fixed::fractBits = 8;

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const int intValue)
{
    value = intValue << fractBits;
}

Fixed::Fixed(const float floatValue)
{
    value = (int)roundf(floatValue * (1 << fractBits));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        value = other.value;
    return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
    return value > other.value;
}

bool Fixed::operator<(const Fixed &other) const
{
    return value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const
{
    return value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
    value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    value++;
    return temp;
}

Fixed &Fixed::operator--()
{
    value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    value--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

int Fixed::getRawBits() const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)value / (float)(1 << fractBits);
}

int Fixed::toInt(void) const
{
    return value >> fractBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
