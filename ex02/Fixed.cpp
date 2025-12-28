#include "Fixed.hpp"

const int Fixed::fractBits = 8;

Fixed::Fixed() : value(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
    // std::cout << "Int constructor called" << std::endl;
    value = intValue << fractBits;
}

Fixed::Fixed(const float floatValue)
{
    // std::cout << "Float constructor called" << std::endl;
    value = (int)roundf(floatValue * (1 << fractBits));
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
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
