#include <iostream>
#include <vector>

void print(std::string s, std::vector<int>& v);

int main()
{
	std::string s = "Ora stampo il vettore: ";
	std::vector<int> v {1, 2, 3};
	print(s, v);
	return 0;
}

void print(std::string s, std::vector<int>& v)
{
	std::cout << s << "\n";
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
		
	std::cout << "\n";
}
