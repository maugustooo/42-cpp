#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value){
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed){
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed){
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointValue = fixed.getRawBits();
	return *this;
}

float Fixed::toFloat() const{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt() const{
	return _fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &output, const Fixed &f){
	output << f.toFloat();
	return output;
}

int Fixed::getRawBits() const{
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw){
	_fixedPointValue = raw;
}

