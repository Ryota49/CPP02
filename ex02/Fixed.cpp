#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << _fractionalbits;
} 

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << _fractionalbits));
}

int Fixed::getRawBits() const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

int Fixed::toInt(void) const
{
    return (this->_value >> _fractionalbits);
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_value) / (1 << _fractionalbits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->_value < other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->_value <= other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->_value >= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->_value != other._value);
}

Fixed   Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed   Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed&  Fixed::operator++(void)
{
    this->_value += 1;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_value += 1;  
    return (temp);        
}

Fixed&  Fixed::operator--(void)
{
    this->_value -= 1;
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_value -= 1;
    return (temp);
}

Fixed&   Fixed::min(Fixed &a, Fixed &b)
{
    return (b < a) ? b : a;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (b < a) ? b : a;
}

Fixed&  Fixed::max(Fixed &a, Fixed &b)
{
    return (a < b) ? b : a;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a < b) ? b : a;
}