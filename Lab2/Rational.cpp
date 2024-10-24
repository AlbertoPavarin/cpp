#include "Rational.h"
#include <iostream>

Rational::Rational(int n, int d) : num (n), den (d){
	if (!is_valid()) throw Invalid();
}

bool Rational::is_valid()
{ 
	if(den == 0)
		return false;
	
	return true;
}

Rational& Rational::operator=(const Rational& other){
	this->num = other.num;
	this->den = other.den;

	return *this;
}


Rational Rational::operator+(const Rational& other){
	return Rational((num*other.den + den*other.num), den*other.den);
}

Rational Rational::operator-(const Rational& other){
	return Rational((num*other.den - den*other.num), den*other.den);
}

Rational Rational::operator*(const Rational& other){
	return Rational(num*other.num, den*other.den);
}

Rational Rational::operator/(const Rational& other){
	return Rational(num*other.den, den*other.num);
}

Rational Rational::operator+=(const Rational& other){
	num = (num*other.den + den*other.num);
	den = den*other.den;
	return *this;
}

Rational Rational::operator-=(const Rational& other){
	num = (num*other.den - den*other.num);
	den = den*other.den;
	return *this;
}

Rational Rational::operator*=(const Rational& other){
	num = num*other.num;
	den = den*other.den;
	return *this;
}

Rational Rational::operator/=(const Rational& other){
	num = num*other.den;
	den = den*other.num;
	return *this;
}

bool Rational::operator==(Rational& other){
	if (this->to_double() == other.to_double())
		return true;

	return false;
}

bool Rational::operator<(Rational& other){
	if (this->to_double() < other.to_double())
		return true;

	return false;
}

bool Rational::operator>(Rational& other){
	if (this->to_double() > other.to_double())
		return true;

	return false;
}

std::ostream& operator<<(std::ostream& os, Rational r)
{
	return os << r.getNum() << "/" << r.getDen() << '\n';
}