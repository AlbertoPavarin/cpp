#include <iostream>
#include "MyVector.h"

int main()
{
	const int n = 5;
	MyVector v = MyVector(n);
	std::cout << "Dimensione: " << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		v[i] = i;
	for (int i = 0; i < v.size(); i++)
		std::cout << "[" << i << "]: " << v[i] << "\n";
	std::cout << "Dimensione: " << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		std::cout << "[" << i << "]: " << v[i] << "\n";

	v.pop_back();
		
	v.reserve(10);
	std::cout << "\n";
	for (int i = 0; i < v.size(); i++)
		std::cout << "[" << i << "]: " << v[i] << "\n";

	MyVector v2 = {1, 2, 3, 4};
	std::cout << "\n";
	v2.push_back(1);
	for (int i = 0; i < v2.size(); i++)
		std::cout << "[" << i << "]: " << v2[i] << "\n";
	v2 = v;
	for (int i = 0; i < v2.size(); i++)
		std::cout << "2[" << i << "]: " << v2[i] << "\n";
	
	v2.pop_back();
	std::cout << "\n";

	for (int i = 0; i < v2.size(); i++)
		std::cout << "[" << i << "]: " << v2[i] << "\n";
	std::cout << "\n";

	for (int i = 0; i < v.size(); i++)
		std::cout << "[" << i << "]: " << v[i] << "\n";
	return 0;	
}