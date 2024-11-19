#include <iostream>
#include <initializer_list>

class MyVector
{
	class Invalid{};
	int sz;
	bool overw;
	int occupied;
	double *v;
public:
		MyVector(int size = 0);
		MyVector(std::initializer_list<double> lst);
		MyVector(const MyVector& v2);
		MyVector(MyVector&& v2);
		int size() const;
		double& operator[](int i);
		double operator[](int i) const;
		MyVector& operator=(const MyVector& v2);
		MyVector& operator=(MyVector&& v2);
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