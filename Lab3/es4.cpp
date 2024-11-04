#include <iostream>

class MyVector
{
	class Invalid{};
	int sz;
	bool overw;
	int occupied;
	double *v;
	public:
		MyVector(int size);
		int size();
		double operator[](int i);
		void safe_set(double el);
		double safe_get(int i);
		~MyVector() { delete[] v; }
	private:
		bool is_overwritten() { return overw; };
};

MyVector::MyVector(int size): sz (size){
	overw = false;
	sz = size;
	occupied = 0;
	v = new double[size];
	if (v == nullptr)
		throw Invalid();
}

int MyVector::size()
{
	if(is_overwritten()) 
		return occupied;
	else
		return sz; 
}

double MyVector::operator[](int i)
{
	return v[i];
}

void MyVector::safe_set(double el)
{
	if (sz == occupied)
	{
		overw = true;
		double *tmp = new double[sz * 2];
		sz *= 2; 
		for (int i = 0; i < occupied; i++)
		{
			tmp[i] = v[i];
		}
		delete[] v;
		v = tmp;
	}
	v[occupied++] = el;
}

double MyVector::safe_get(int i)
{
	if (i >= size())
		throw Invalid();
	
	return v[i];
}

int main()
{
	const int n = 5;
	MyVector v = MyVector(n);
	std::cout << "Dimensione: " << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		std::cout << "[" << i << "]: " << v[i] << "\n";
	v.safe_set(1);
	v.safe_set(2);
	v.safe_set(3);
	v.safe_set(4);
	v.safe_set(5);
	v.safe_set(6);
	v.safe_set(7);
	v.safe_set(8);
	std::cout << "Dimensione: " << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		std::cout << "[" << i << "]: " << v[i] << "\n";

	std::cout << v.safe_get(4) << "\n";
	return 0;
}
