#include <iostream>
#include "MyVector.h"

int main()
{
	const int n = 5;
	MyVector<double> v = MyVector<double>(n);
	std::cout << "Dimensione: " << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		v[i] = i;
	for (int i = 0; i < v.size(); i++)
		std::cout << "[" << i << "]: " << v[i] << "\n";
	std::cout << "Dimensione: " << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		std::cout << "[" << i << "]: " << v[i] << "\n";

	v.push_back(101);
		
	// v.reserve(10);
	std::cout << "\n";
	for (int i = 0; i < v.size(); i++)
		std::cout << "[" << i << "]: " << v[i] << "\n";

	std::cout << "\n";		

	MyVector<std::string> v2 = MyVector<std::string>(n);

	for (int i = 0; i < v2.size(); i++)
		v2[i] = "apapapa";

	for (int i = 0; i < v2.size(); i++)
		std::cout << "[" << i << "]: " << v2[i] << "\n";
	return 0;	
}