#include <iostream>

class Rational{
	int num;
	int den;
public:
    class Invalid{};
	Rational() { num = 0; den = 1; }; 
	Rational(int n) : num (n) { num = n; den = 1; }; 
	Rational(int n, int d);

    int getDen() { return den; };
    int getNum() { return num; };
	double to_double() const { return (double)num/(double)den; }; 	
    
    Rational& operator=(const Rational& other);

	Rational operator+(const Rational& other);
	Rational operator+(int i);
	Rational operator+=(const Rational& other);
	
	Rational operator-(const Rational& other);
	Rational operator-=(const Rational& other);
	
	Rational operator*(const Rational& other);
	Rational operator*=(const Rational& other);
	
	Rational operator/(const Rational& other);
	Rational operator/=(const Rational& other);

	bool operator==(Rational& other);
    bool operator>(Rational& other);
    bool operator<(Rational& other);

private:
    bool is_valid();
};

std::ostream& operator<<(std::ostream& os, const Rational r);
// Rational operator+(Rational& r, int i);