#include <iostream>
#include <vector>

void print(std::string s, std::vector<int>& v);
void fibonacci(int x, int y, std::vector<int>& v, int n);

int main()
{
	int n = 50;
	std::string s = "Ora stampo il vettore: ";
	std::vector<int> v;
	fibonacci(3, 5, v, n);
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

void fibonacci(int x, int y, std::vector<int>& v, int n)
{
	v.clear();
	static int start = 2;
	v.push_back(x);
	v.push_back(y);
	for (int i = start; i < n; i++){
		int next = v[i-1] + v[i-2];
		if (next < 0)
			return;
		v.push_back(next);
	}
}
