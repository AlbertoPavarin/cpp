#include "Rational.h"
#include <iostream>

int main() {
	Rational r1 = Rational(1, 2);
	Rational r2 = Rational(3, 2);
	r1 = r1 + r2;
	std::cout << "R1: " << r1;
	
	Rational r3 = Rational(1, 2);
	r3 /= r2; 
	std::cout << "R3: " << r3;

	Rational r4 = Rational(3, 2);
	std::cout << "R4: " << r4;
    std::cout << "R4 == R2: " << (r4 == r2) << "\n";

    Rational r5 = Rational(1, 2);
	std::cout << "R5: " << r5;
    Rational r6 = r5;
    std::cout << "R6: " << r6;

    std::cout << "R5 > R4: " << (r5 > r4) << "\n";
    std::cout << "R5 < R4: " << (r5 < r4) << "\n";
	return 0;
}