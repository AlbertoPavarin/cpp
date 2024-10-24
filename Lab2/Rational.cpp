#include <iostream>

class Rational{
	int num;
	int den;
public:
	// FARE LISTE INIZIALIZZAZIONE
	Rational() { num = 0; den = 1; }; 
	Rational(int n) { num = n; den = 1; }; 
	Rational(int n, int d) { num = n; den = d; }; // CONTROLLO CON DENOMINATORE A 0
	double to_double() { return (double)num/(double)den; }; 	
	
	Rational operator+(const Rational& other);
	Rational operator+=(const Rational& other);
	
	Rational operator-(const Rational& other);
	Rational operator-=(const Rational& other);
	
	Rational operator*(const Rational& other);
	Rational operator*=(const Rational& other);
	
	Rational operator/(const Rational& other);
	Rational operator/=(const Rational& other);

private:
};

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
	return Rational((num*other.den + den*other.num), den*other.den);
}

Rational Rational::operator-=(const Rational& other){
	return Rational((num*other.den - den*other.num), den*other.den);
}

Rational Rational::operator*=(const Rational& other){
	return Rational(num*other.num, den*other.den);
}

Rational Rational::operator/=(const Rational& other){
	return Rational(num*other.den, den*other.num);
}

int main() {
	Rational r1 = Rational(1, 2);
	Rational r2 = Rational(3, 2);
	r1 = r1 + r2;
	std::cout << "R1:" << r1.to_double() << "\n";
	
	Rational r3 = Rational(1, 2);
	r3 += r2; 
	std::cout << "R3:" << r3.to_double() << "\n";
	
	return 0;
}
