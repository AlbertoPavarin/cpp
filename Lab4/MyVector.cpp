#include <iostream>
#include <initializer_list>
#include "MyVector.h"

MyVector::MyVector(int size): sz (size){
	overw = false;
	sz = size;
	occupied = size;
	v = new double[size];
	if (v == nullptr)
		throw Invalid();
}

MyVector::MyVector(const MyVector& v2){
	double *tmp = new double[v2.sz];
	std::copy(v2.v, v2.v+sz, tmp);
	delete[] v;
	v = tmp;
	sz = v2.sz;
	occupied = v2.occupied;
	overw = v2.overw;
}

MyVector::MyVector(MyVector&& v2): sz{v2.sz}, v(v2.v){
	v2.sz = 0;
	v2.v = nullptr; 

}

MyVector::MyVector(std::initializer_list<double> lst): sz{static_cast<int>(lst.size())}, v{new double[sz]} {
	std::copy(lst.begin(), lst.end(), v);
	occupied = sz;
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

double& MyVector::operator[](int i) {
	return v[i];
}

double MyVector::operator[](int i) const {
	return v[i];
}

MyVector& MyVector::operator=(const MyVector& v2) {
	double *tmp = new double[v2.sz];
	std::copy(v2.v, v2.v+sz, tmp);
	delete[] v;
	v = tmp;
	sz = v2.sz;
	occupied = v2.occupied;
	overw = v2.overw;
	return *this;
}

MyVector& MyVector::operator=(MyVector&& v2) {
	delete[] v;
	v = v2.v;
	sz = v2.sz;
	v2.v = nullptr;
	v2.v = 0;
	return *this;
}

void MyVector::push_back(double el) {
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