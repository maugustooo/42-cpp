#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0){
}

Fixed::~Fixed(){
}

Fixed::Fixed(const int value){
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value){
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed){
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed){
	_fixedPointValue = fixed.getRawBits();
	return *this;
}

float Fixed::toFloat() const{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt() const{
	return _fixedPointValue >> _fractionalBits;
}


int Fixed::getRawBits() const{
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw){
	_fixedPointValue = raw;
}


bool Fixed::operator>(const Fixed &fixed){
	return _fixedPointValue > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed){
	return _fixedPointValue < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed){
	return _fixedPointValue >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed){
	return _fixedPointValue <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed){
	return _fixedPointValue == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed){
	return _fixedPointValue != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed){
	Fixed result;
	result.setRawBits(_fixedPointValue + fixed.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &fixed){
	Fixed result;
	result.setRawBits(_fixedPointValue - fixed.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &fixed){
	Fixed result;
	result.setRawBits((_fixedPointValue * fixed.getRawBits()) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &fixed){
	Fixed result;
	result.setRawBits((_fixedPointValue << _fractionalBits) / fixed.getRawBits());
	return result;
}

Fixed &Fixed::operator++(){
	_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed temp = *this;
	_fixedPointValue++;
	return temp;
}

Fixed &Fixed::operator--(){
	_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed temp = *this;
	_fixedPointValue--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	if (a.getRawBits() <= b.getRawBits())
		return a;
	else
		return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	if (a.getRawBits() <= b.getRawBits())
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	if (a.getRawBits() >= b.getRawBits())
		return a;
	else
		return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	if (a.getRawBits() >= b.getRawBits())
		return a;
	else
		return b;
}

std::ostream &operator<<(std::ostream &output, const Fixed &f){
	output << f.toFloat();
	return output;
}

