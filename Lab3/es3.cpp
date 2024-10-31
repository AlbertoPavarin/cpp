#include <iostream>

void print_reference(const int &i, const double &d);
void print_pointer(int *i, double *d);

int main()
{
	int x = 10;
	double y = 15;
	print_reference(x, y);
	std::cout << "\n\n";
	print_pointer(&x, &y);
	return 0;
}

void print_reference(const int &i, const double &d){
	std::cout << "Per reference: \n";
	std::cout << "Valori: " << i << " " << d << "\n";
}

void print_pointer(int *i, double *d){
	std::cout << "Per pointer: \n";
	std::cout << "Indirizzi: " << i << " " << d << "\n";
	std::cout << "Valori: " << *i << " " << *d << "\n";
}
