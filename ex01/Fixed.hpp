#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

    private:
        int _value;
        static const int _fractionalbits = 8;

    public:
        Fixed();
        Fixed(const Fixed &other);          
        Fixed &operator=(const Fixed &other);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();
        int  getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif