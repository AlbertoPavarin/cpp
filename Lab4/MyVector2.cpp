#include <iostream>

class MyVector
{
	class Invalid{};
	int sz;
	bool overw;
	int occupied;
	double *v;
public:
	// IMPLEMENTEARE INITIALIZED LIST
		MyVector(int size);
		int size() const;
		double& operator[](int i) const;
		double operator=(MyVector v2) const; // IMPLEMENTARE
		double& at(int i) const;
		void safe_set(double el);
		void push_back(double el);
		double pop_back();
		void reserve(int size);
		double safe_get(int i) const;
		~MyVector() { delete[] v; v = nullptr; }
	private:
		bool is_overwritten() const { return overw; };
		void resize(int size);
};

MyVector::MyVector(int size): sz (size){
	overw = false;
	sz = size;
	occupied = size;
	v = new double[size];
	if (v == nullptr)
		throw Invalid();
}

int MyVector::size() const
{
	if(is_overwritten()) 
		return occupied;
	else
		return sz; 
}

void MyVector::resize(int size){
	overw = true;
	double *tmp = new double[size];
	sz = size; 
	for (int i = 0; i < occupied; i++)
	{
		tmp[i] = v[i];
	}
	delete[] v;
	v = tmp;
}

double& MyVector::operator[](int i) const
{
	return v[i];
}

void MyVector::push_back(double el)
{
	if (sz == occupied)
	{
		resize(sz*2);
	}
	v[occupied++] = el;
}

void MyVector::reserve(int size){
	if (size <= sz)
		return;
	
	resize(size);
	std::cout << "Baby mi guarda mentre sono rollie\n";
};

double MyVector::pop_back(){
	overw = 1;
	if (occupied == 0)
		throw Invalid();
	return v[--occupied];
};

void MyVector::safe_set(double el){
	if (sz == occupied)
		throw Invalid();
	
	v[occupied++] = el;
}

double MyVector::safe_get(int i) const
{
	if (i >= size())
		throw Invalid();
	
	return v[i];
}

double& MyVector::at(int i) const {
	if (i >= occupied)
		throw Invalid();
	return v[i];
}

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
	for (int i = 0; i < v.size(); i++)
		std::cout << "[" << i << "]: " << v[i] << "\n";
	return 0;	
}